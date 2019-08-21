Imports System.Windows.Media.Imaging
Imports ImageProcessing

Public Class FormHistgram
    Protected m_nHistgram(ComInfo.PictureType.MAX - 1, ComInfo.RGB_MAX - 1) As Integer
    Protected m_bitmap As BitmapImage
    Protected m_wbitmap As WriteableBitmap

    Public Sub New()

        ' この呼び出しはデザイナーで必要です。
        InitializeComponent()

        ' InitializeComponent() 呼び出しの後で初期化を追加します。

    End Sub
End Class