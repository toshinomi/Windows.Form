Imports System.Drawing.Imaging
Imports System.Threading
Imports System.Runtime.InteropServices.Marshal

Namespace ImageProcessing
    Public Class EdgeDetection
        Private Const m_nMaskSize As Integer = 3
        Private m_nFilterMax As UInt32
        Private m_bitmap As Bitmap

        Public Sub New(_bitmap As Bitmap)
            m_nFilterMax = 1
            m_bitmap = _bitmap
        End Sub

        Public Sub New(_bitmap As Bitmap, _filterMax As UInt32)
            m_nFilterMax = 1
            m_bitmap = _bitmap
        End Sub

        Protected Overrides Sub Finalize()
            MyBase.Finalize()

            m_bitmap = Nothing
        End Sub

        Public Function GetBitmap() As Bitmap
            Return m_bitmap
        End Function


        Public Sub SetBitmap(_bitmap As Bitmap)
            m_bitmap = _bitmap
        End Sub

        Public Function GoEdgeDetection(_token As CancellationToken) As Boolean
            Dim bRst As Boolean = True

            Dim dMask As Double(,) =
            {
                {1.0, 1.0, 1.0},
                {1.0, -8.0, 1.0},
                {1.0, 1.0, 1.0}
            }

            Dim nWidthSize As Integer = m_bitmap.Width
            Dim nHeightSize As Integer = m_bitmap.Height
            Dim nMasksize As Integer = dMask.GetLength(0)

            Dim bitmapData As BitmapData = m_bitmap.LockBits(New Rectangle(0, 0, nWidthSize, nHeightSize), ImageLockMode.ReadWrite, PixelFormat.Format32bppArgb)

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
                    Dim bytePixelB As Byte = ReadByte(pAdr, nPos + ComInfo.Pixel.B)
                    Dim bytePixelG As Byte = ReadByte(pAdr, nPos + ComInfo.Pixel.G)
                    Dim bytePixelR As Byte = ReadByte(pAdr, nPos + ComInfo.Pixel.R)
                    Dim bytePixelA As Byte = ReadByte(pAdr, nPos + ComInfo.Pixel.A)

                    Dim dCalB As Double = 0.0
                    Dim dCalG As Double = 0.0
                    Dim dCalR As Double = 0.0
                    Dim dCalA As Double = 0.0

                    Dim nIdxWidthMask As Integer
                    Dim nIdxHightMask As Integer
                    Dim nFilter As Integer = 0

                    While nFilter < m_nFilterMax
                        For nIdxHightMask = 0 To nMasksize - 1 Step 1
                            For nIdxWidthMask = 0 To nMasksize - 1 Step 1
                                If (nIdxWidth + nIdxWidthMask > 0 And
                                    nIdxWidth + nIdxWidthMask < nWidthSize And
                                    nIdxHeight + nIdxHightMask > 0 And
                                    nIdxHeight + nIdxHightMask < nHeightSize) Then

                                    Dim pAdr2 As IntPtr = bitmapData.Scan0
                                    Dim nPos2 As Integer = (nIdxHeight + nIdxHightMask) * bitmapData.Stride + (nIdxWidth + nIdxWidthMask) * 4

                                    dCalB += ReadByte(pAdr2, nPos2 + ComInfo.Pixel.B) * dMask(nIdxWidthMask, nIdxHightMask)
                                    dCalG += ReadByte(pAdr2, nPos2 + ComInfo.Pixel.G) * dMask(nIdxWidthMask, nIdxHightMask)
                                    dCalR += ReadByte(pAdr2, nPos2 + ComInfo.Pixel.R) * dMask(nIdxWidthMask, nIdxHightMask)
                                    dCalA += ReadByte(pAdr2, nPos2 + ComInfo.Pixel.A) * dMask(nIdxWidthMask, nIdxHightMask)
                                End If
                            Next
                        Next
                        nFilter += 1
                    End While
                    WriteByte(pAdr, nPos + ComInfo.Pixel.B, ComFunc.DoubleToByte(dCalB))
                    WriteByte(pAdr, nPos + ComInfo.Pixel.G, ComFunc.DoubleToByte(dCalG))
                    WriteByte(pAdr, nPos + ComInfo.Pixel.R, ComFunc.DoubleToByte(dCalR))
                    WriteByte(pAdr, nPos + ComInfo.Pixel.A, ComFunc.DoubleToByte(dCalA))
                Next
            Next
            m_bitmap.UnlockBits(bitmapData)

            Return bRst
        End Function
    End Class
End Namespace