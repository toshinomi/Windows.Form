Imports System.Drawing.Imaging
Imports System.Threading
Imports System.Runtime.InteropServices.Marshal

''' <summary>
''' エッジ検出のロジック
''' </summary>
Public Class EdgeDetection
    ''' <summary>
    ''' コンストラクタ
    ''' </summary>
    Public Sub New()
    End Sub

    ''' <summary>
    ''' デスクトラクタ
    ''' </summary>
    Protected Overrides Sub Finalize()
        MyBase.Finalize()
    End Sub

    ''' <summary>
    ''' エッジ検出の実行
    ''' </summary>
    ''' <param name="bitmap">ビットマップ</param>
    ''' <param name="token">キャンセルトークン</param>
    ''' <returns>実行結果 成功/失敗</returns>
    Public Function ImageProcessing(ByRef bitmap As Bitmap, token As CancellationToken) As Boolean
        Dim result = True

        Dim mask =
        {
            {1, 1, 1},
            {1, -8, 1},
            {1, 1, 1}
        }

        Dim widthSize = bitmap.Width
        Dim heightSize = bitmap.Height
        Dim maskSize = mask.GetLength(0)

        Dim bitmapData = bitmap.LockBits(New Rectangle(0, 0, widthSize, heightSize), ImageLockMode.ReadWrite, PixelFormat.Format32bppArgb)

        Dim indexWidth As Integer
        Dim indexHeight As Integer

        For indexHeight = 0 To heightSize - 1 Step 1
            If (token.IsCancellationRequested) Then
                result = False
                Exit For
            End If

            For indexWidth = 0 To widthSize - 1 Step 1
                If (token.IsCancellationRequested) Then
                    result = False
                    Exit For
                End If

                Dim position = indexHeight * bitmapData.Stride + indexWidth * 4
                Dim pixelB = ReadByte(bitmapData.Scan0, position + ComInfo.Pixel.B)
                Dim pixelG = ReadByte(bitmapData.Scan0, position + ComInfo.Pixel.G)
                Dim pixelR = ReadByte(bitmapData.Scan0, position + ComInfo.Pixel.R)
                Dim pixelA = ReadByte(bitmapData.Scan0, position + ComInfo.Pixel.A)

                Dim totalBlue As Long = 0
                Dim totalGreen As Long = 0
                Dim totalRed As Long = 0

                Dim indexWidthMask As Integer
                Dim indexHightMask As Integer

                For indexHightMask = 0 To maskSize - 1 Step 1
                    For indexWidthMask = 0 To maskSize - 1 Step 1
                        If (indexWidth + indexWidthMask > 0 And
                            indexWidth + indexWidthMask < widthSize And
                            indexHeight + indexHightMask > 0 And
                            indexHeight + indexHightMask < heightSize) Then

                            Dim positionMaskArea = (indexHeight + indexHightMask) * bitmapData.Stride + (indexWidth + indexWidthMask) * 4

                            totalBlue += ReadByte(bitmapData.Scan0, positionMaskArea + ComInfo.Pixel.B) * mask(indexWidthMask, indexHightMask)
                            totalGreen += ReadByte(bitmapData.Scan0, positionMaskArea + ComInfo.Pixel.G) * mask(indexWidthMask, indexHightMask)
                            totalRed += ReadByte(bitmapData.Scan0, positionMaskArea + ComInfo.Pixel.R) * mask(indexWidthMask, indexHightMask)
                        End If
                    Next
                Next
                WriteByte(bitmapData.Scan0, position + ComInfo.Pixel.B, ComFunc.LongToByte(totalBlue))
                WriteByte(bitmapData.Scan0, position + ComInfo.Pixel.G, ComFunc.LongToByte(totalGreen))
                WriteByte(bitmapData.Scan0, position + ComInfo.Pixel.R, ComFunc.LongToByte(totalRed))
            Next
        Next
        bitmap.UnlockBits(bitmapData)

        Return result
    End Function
End Class