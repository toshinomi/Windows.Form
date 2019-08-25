﻿Imports System.Threading
Imports System.Runtime.InteropServices.Marshal
Imports System.Drawing.Imaging

Public Class GrayScale2Diff : Inherits ComImgProc
    Public Sub New(_bitmap As Bitmap)
        MyBase.New(_bitmap)
    End Sub

    Public Overrides Function GoImgProc(_token As CancellationToken) As Boolean
        Dim bRst As Boolean = True

        Dim nMask As Short(,) =
        {
            {1, 1, 1},
            {1, -8, 1},
            {1, 1, 1}
        }

        Dim nWidthSize As Integer = MyBase.m_bitmap.Width
        Dim nHeightSize As Integer = MyBase.m_bitmap.Height
        Dim nMasksize As Integer = nMask.GetLength(0)

        MyBase.m_bitmapAfter = New Bitmap(MyBase.m_bitmap)

        Dim bitmapData As BitmapData = MyBase.m_bitmapAfter.LockBits(New Rectangle(0, 0, nWidthSize, nHeightSize), ImageLockMode.ReadWrite, PixelFormat.Format32bppArgb)

        Dim nIdxWidth As Integer
        Dim nIdxHeight As Integer

        For nIdxHeight = 0 To nHeightSize - 1 Step 1
            For nIdxWidth = 0 To nWidthSize - 1 Step 1
                If (_token.IsCancellationRequested) Then
                    bRst = False
                    Exit For
                End If

                Dim pAdr As IntPtr = bitmapData.Scan0
                Dim nPos As Integer = nIdxHeight * bitmapData.Stride + nIdxWidth * 4
                Dim nPixelB As Byte = ReadByte(pAdr, nPos + ComInfo.Pixel.B)
                Dim nPixelG As Byte = ReadByte(pAdr, nPos + ComInfo.Pixel.G)
                Dim nPixelR As Byte = ReadByte(pAdr, nPos + ComInfo.Pixel.R)

                Dim lCalB As Long = 0
                Dim lCalG As Long = 0
                Dim lCalR As Long = 0
                Dim dCalAve As Double = 0.0
                Dim nIdxWidthMask As Integer
                Dim nIdxHightMask As Integer

                For nIdxHightMask = 0 To nMasksize - 1 Step 1
                    For nIdxWidthMask = 0 To nMasksize - 1 Step 1
                        If (nIdxWidth + nIdxWidthMask > 0 And
                            nIdxWidth + nIdxWidthMask < nWidthSize And
                            nIdxHeight + nIdxHightMask > 0 And
                            nIdxHeight + nIdxHightMask < nHeightSize) Then

                            Dim pAdr2 As IntPtr = bitmapData.Scan0
                            Dim nPos2 As Integer = (nIdxHeight + nIdxHightMask) * bitmapData.Stride + (nIdxWidth + nIdxWidthMask) * 4

                            lCalB = ReadByte(pAdr2, nPos2 + ComInfo.Pixel.B) * nMask(nIdxWidthMask, nIdxHightMask)
                            lCalG = ReadByte(pAdr2, nPos2 + ComInfo.Pixel.G) * nMask(nIdxWidthMask, nIdxHightMask)
                            lCalR = ReadByte(pAdr2, nPos2 + ComInfo.Pixel.R) * nMask(nIdxWidthMask, nIdxHightMask)

                            Dim dcalGray As Double = (lCalB + lCalG + lCalR) / 3
                            dCalAve = (dCalAve + dcalGray) / 2
                        End If
                    Next
                Next
                Dim nGrayScale As Byte = ComFunc.DoubleToByte(dCalAve)

                WriteByte(pAdr, nPos + ComInfo.Pixel.B, nGrayScale)
                WriteByte(pAdr, nPos + ComInfo.Pixel.G, nGrayScale)
                WriteByte(pAdr, nPos + ComInfo.Pixel.R, nGrayScale)
            Next
        Next
        MyBase.m_bitmapAfter.UnlockBits(bitmapData)

        Return bRst
    End Function
End Class