Imports System.Threading
Imports System.Runtime.InteropServices.Marshal
Imports System.Drawing.Imaging

''' <summary>
''' 画像処理のロジック
''' </summary>
Public Class ImageProcessing : Inherits ComImgProc
    ''' <summary>
    ''' コンストラクタ
    ''' </summary>
    ''' <param name="_bitmap">ビットマップ</param>
    Public Sub New(bitmap As Bitmap)
    End Sub

    ''' <summary>
    ''' デスクトラクタ
    ''' </summary>
    Protected Overrides Sub Finalize()
    End Sub
End Class
