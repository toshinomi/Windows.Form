Imports System.Threading
Imports System.Runtime.InteropServices.Marshal
Imports System.Drawing.Imaging

''' <summary>
''' 画像処理のロジック
''' </summary>
Public Class ImageProcessing : Inherits ComImageProcessing
    Private ReadOnly arrayImageProcessing(ComInfo.ImageProcessingType.MAX) As Object

    ''' <summary>
    ''' 閾値
    ''' </summary>
    Public Property Thresh As Byte

    ''' <summary>
    ''' コンストラクタ
    ''' </summary>
    ''' <param name="bitmap">ビットマップ</param>
    Public Sub New(bitmap As Bitmap)
        MyBase.New(bitmap)
        Dim edgeDetection = New EdgeDetection()
        arrayImageProcessing(ComInfo.ImageProcessingType.EdgeDetection) = edgeDetection
        Dim grayScale = New GrayScale()
        arrayImageProcessing(ComInfo.ImageProcessingType.GrayScale) = grayScale
        Dim binarization = New Binarization()
        arrayImageProcessing(ComInfo.ImageProcessingType.Binarization) = binarization
        Dim grayScale2Diff = New GrayScale2Diff()
        arrayImageProcessing(ComInfo.ImageProcessingType.GrayScale2Diff) = grayScale2Diff
        Dim colorReversal = New ColorReversal()
        arrayImageProcessing(ComInfo.ImageProcessingType.ColorReversal) = colorReversal
    End Sub

    ''' <summary>
    ''' デスクトラクタ
    ''' </summary>
    Protected Overrides Sub Finalize()
    End Sub

    ''' <summary>
    ''' 初期化
    ''' </summary>
    Public Overrides Sub Init()
        MyBase.Init()
    End Sub

    ''' <summary>
    ''' 画像処理の実行
    ''' </summary>
    ''' <param name="imageProcessingName">画像処理オブジェクトの名称</param>
    ''' <param name="token">キャンセルトークン</param>
    ''' <returns>実行結果 成功/失敗</returns>
    Public Overrides Function GoImageProcessing(imageProcessingName As String, token As CancellationToken) As Boolean
        Dim result = False

        Dim index As Integer
        Select Case imageProcessingName
            Case ComInfo.IMG_NAME_EDGE_DETECTION
                index = ComInfo.ImageProcessingType.EdgeDetection
                Dim edgeDetection As EdgeDetection = arrayImageProcessing(index)
                result = edgeDetection.ImageProcessing(MyBase.mBitmap, token)
            Case ComInfo.IMG_NAME_GRAY_SCALE
                index = ComInfo.ImageProcessingType.GrayScale
                Dim grayScale As GrayScale = arrayImageProcessing(index)
                result = grayScale.ImageProcessing(MyBase.mBitmap, token)
            Case ComInfo.IMG_NAME_BINARIZATION
                index = ComInfo.ImageProcessingType.Binarization
                Dim binarization As Binarization = arrayImageProcessing(index)
                result = binarization.ImageProcessing(MyBase.mBitmap, token, Thresh)
            Case ComInfo.IMG_NAME_GRAY_SCALE_2DIFF
                index = ComInfo.ImageProcessingType.GrayScale2Diff
                Dim grayScale2Diff As GrayScale = arrayImageProcessing(index)
                result = grayScale2Diff.ImageProcessing(MyBase.mBitmap, token)
            Case ComInfo.IMG_NAME_COLOR_REVERSAL
                index = ComInfo.ImageProcessingType.ColorReversal
                Dim colorReversal As ColorReversal = arrayImageProcessing(index)
                result = colorReversal.ImageProcessing(MyBase.mBitmap, token)
            Case Else
        End Select

        Return result
    End Function
End Class
