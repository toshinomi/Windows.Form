Imports System.Threading
Imports System.Runtime.InteropServices.Marshal
Imports System.Drawing.Imaging

''' <summary>
''' グレースケール2次微分のロジック
''' </summary>
Public Class GrayScale2Diff
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
    ''' グレースケール2次微分の実行
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

                Dim blue As Long = 0
                Dim green As Long = 0
                Dim red As Long = 0
                Dim averageGrayScale As Double = 0.0
                Dim indexWidthMask As Integer
                Dim indexHightMask As Integer

                For indexHightMask = 0 To maskSize - 1 Step 1
                    For indexWidthMask = 0 To maskSize - 1 Step 1
                        If (indexWidth + indexWidthMask > 0 And
                            indexWidth + indexWidthMask < widthSize And
                            indexHeight + indexHightMask > 0 And
                            indexHeight + indexHightMask < heightSize) Then

                            Dim positionMaskArea As Integer = (indexHeight + indexHightMask) * bitmapData.Stride + (indexWidth + indexWidthMask) * 4

                            blue = ReadByte(bitmapData.Scan0, positionMaskArea + ComInfo.Pixel.B) * mask(indexWidthMask, indexHightMask)
                            green = ReadByte(bitmapData.Scan0, positionMaskArea + ComInfo.Pixel.G) * mask(indexWidthMask, indexHightMask)
                            red = ReadByte(bitmapData.Scan0, positionMaskArea + ComInfo.Pixel.R) * mask(indexWidthMask, indexHightMask)

                            Dim gray = (blue + green + red) / 3
                            averageGrayScale = (averageGrayScale + gray) / 2
                        End If
                    Next
                Next
                Dim grayScale As Byte = ComFunc.DoubleToByte(averageGrayScale)

                WriteByte(bitmapData.Scan0, position + ComInfo.Pixel.B, grayScale)
                WriteByte(bitmapData.Scan0, position + ComInfo.Pixel.G, grayScale)
                WriteByte(bitmapData.Scan0, position + ComInfo.Pixel.R, grayScale)
            Next
        Next
        bitmap.UnlockBits(bitmapData)

        Return result
    End Function
End Class