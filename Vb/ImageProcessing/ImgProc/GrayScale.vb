Imports System.Threading
Imports System.Runtime.InteropServices.Marshal
Imports System.Drawing.Imaging

''' <summary>
''' グレースケールのロジック
''' </summary>
Public Class GrayScale : Inherits ComImgProc
    ''' <summary>
    ''' コンストラクタ
    ''' </summary>
    ''' <param name="_bitmap">ビットマップ</param>
    Public Sub New(_bitmap As Bitmap)
        MyBase.New(_bitmap)
    End Sub

    ''' <summary>
    ''' デスクトラクタ
    ''' </summary>
    Protected Overrides Sub Finalize()
        MyBase.Finalize()
    End Sub

    ''' <summary>
    ''' 初期化
    ''' </summary>
    Public Overrides Sub Init()
        MyBase.Init()
    End Sub

    ''' <summary>
    ''' グレースケールの実行
    ''' </summary>
    ''' <param name="_token">キャンセルトークン</param>
    ''' <returns>実行結果 成功/失敗</returns>
    Public Overrides Function GoImgProc(_token As CancellationToken) As Boolean
        Dim bRst As Boolean = True

        Dim nWidthSize As Integer = MyBase.m_bitmap.Width
        Dim nHeightSize As Integer = MyBase.m_bitmap.Height

        MyBase.m_bitmapAfter = New Bitmap(MyBase.m_bitmap)

        Dim bitmapData As BitmapData = MyBase.m_bitmapAfter.LockBits(New Rectangle(0, 0, nWidthSize, nHeightSize), ImageLockMode.ReadWrite, PixelFormat.Format32bppArgb)

        Dim nIdxWidth As Integer
        Dim nIdxHeight As Integer

        For nIdxHeight = 0 To nHeightSize - 1 Step 1
            If (_token.IsCancellationRequested) Then
                bRst = False
                Exit For
            End If

            For nIdxWidth = 0 To nWidthSize - 1 Step 1
                If (_token.IsCancellationRequested) Then
                    bRst = False
                    Exit For
                End If

                Dim pAdr As IntPtr = bitmapData.Scan0
                Dim nPos As Integer = nIdxHeight * bitmapData.Stride + nIdxWidth * 4
                Dim nPixelB As Integer = ReadByte(pAdr, nPos + ComInfo.Pixel.B)
                Dim nPixelG As Integer = ReadByte(pAdr, nPos + ComInfo.Pixel.G)
                Dim nPixelR As Integer = ReadByte(pAdr, nPos + ComInfo.Pixel.R)

                Dim nGrayScale As Integer = (nPixelB + nPixelG + nPixelR) / 3
                WriteByte(pAdr, nPos + ComInfo.Pixel.B, CByte(nGrayScale))
                WriteByte(pAdr, nPos + ComInfo.Pixel.G, CByte(nGrayScale))
                WriteByte(pAdr, nPos + ComInfo.Pixel.R, CByte(nGrayScale))
            Next
        Next
        MyBase.m_bitmapAfter.UnlockBits(bitmapData)

        Return bRst
    End Function
End Class