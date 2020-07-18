Imports System.Threading
Imports System.Runtime.InteropServices.Marshal
Imports System.Drawing.Imaging

''' <summary>
''' グレースケールのロジック
''' </summary>
Public Class GrayScale
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
    ''' グレースケールの実行
    ''' </summary>
    ''' <param name="bitmap">ビットマップ</param>
    ''' <param name="token">キャンセルトークン</param>
    ''' <returns>実行結果 成功/失敗</returns>
    Public Function ImageProcessing(ByRef bitmap As Bitmap, token As CancellationToken) As Boolean
        Dim result = True

        Dim widthSize = bitmap.Width
        Dim heightSize = bitmap.Height

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
                Dim pixelB As Integer = ReadByte(bitmapData.Scan0, position + ComInfo.Pixel.B)
                Dim pixelG As Integer = ReadByte(bitmapData.Scan0, position + ComInfo.Pixel.G)
                Dim pixelR As Integer = ReadByte(bitmapData.Scan0, position + ComInfo.Pixel.R)

                Dim grayScale As Integer = (pixelB + pixelG + pixelR) / 3
                WriteByte(bitmapData.Scan0, position + ComInfo.Pixel.B, CByte(grayScale))
                WriteByte(bitmapData.Scan0, position + ComInfo.Pixel.G, CByte(grayScale))
                WriteByte(bitmapData.Scan0, position + ComInfo.Pixel.R, CByte(grayScale))
            Next
        Next
        bitmap.UnlockBits(bitmapData)

        Return result
    End Function
End Class