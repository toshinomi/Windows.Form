''' <summary>
''' 画像処理の設定管理のロジック
''' </summary>
Public Class ComImageProcessingInfo
    ''' <summary>
    ''' 現在の画像処理の名称
    ''' </summary>
    Public Property CurrentImageProcessingName() As String

    ''' <summary>
    ''' エッジ検出の設定
    ''' </summary>
    Public Property EdgeDetectoinInfo() As EdgeDetectionInfo

    ''' <summary>
    ''' グレースケールの設定
    ''' </summary>
    Public Property GrayScaleInfo() As GrayScaleInfo

    ''' <summary>
    ''' 2値化の設定
    ''' </summary>
    Public Property BinarizationInfo() As BinarizationInfo

    ''' <summary>
    ''' グレースケール2次微分の設定
    ''' </summary>
    Public Property GrayScale2DiffInfo() As GrayScale2DiffInfo

    ''' <summary>
    ''' 色反転の設定
    ''' </summary>
    Public Property ColorReversalInfo() As ColorReversalInfo

    ''' <summary>
    ''' コンストラクタ
    ''' </summary>
    Public Sub New()
        EdgeDetectoinInfo = New EdgeDetectionInfo()
        GrayScaleInfo = New GrayScaleInfo()
        BinarizationInfo = New BinarizationInfo()
        GrayScale2DiffInfo = New GrayScale2DiffInfo()
        ColorReversalInfo = New ColorReversalInfo()
    End Sub

    ''' <summary>
    ''' デスクトラクタ
    ''' </summary>
    Protected Overrides Sub Finalize()
        MyBase.Finalize()
    End Sub
End Class

''' <summary>
''' エッジ検出の設定管理のロジック
''' </summary>
Public Class EdgeDetectionInfo
    ''' <summary>
    ''' コンストラクタ
    ''' </summary>
    Public Sub New()
    End Sub

    ''' <summary>
    ''' デスクトラクタ
    ''' </summary>
    Protected Overrides Sub Finalize()
    End Sub
End Class

''' <summary>
''' グレースケールの設定管理のロジック
''' </summary>
Public Class GrayScaleInfo
    ''' <summary>
    ''' コンストラクタ
    ''' </summary>
    Public Sub New()
    End Sub

    ''' <summary>
    ''' デスクトラクタ
    ''' </summary>
    Protected Overrides Sub Finalize()
    End Sub
End Class

''' <summary>
''' 2値化の設定管理のロジック
''' </summary>
Public Class BinarizationInfo
    ''' <summary>
    ''' 閾値
    ''' </summary>
    Public Property Thresh() As Byte

    ''' <summary>
    ''' コンストラクタ
    ''' </summary>
    Public Sub New()
    End Sub

    ''' <summary>
    ''' デスクトラクタ
    ''' </summary>
    Protected Overrides Sub Finalize()
    End Sub
End Class

''' <summary>
''' グレースケール2次微分の設定管理のロジック
''' </summary>
Public Class GrayScale2DiffInfo
    ''' <summary>
    ''' コンストラクタ
    ''' </summary>
    Public Sub New()
    End Sub

    ''' <summary>
    ''' デスクトラクタ
    ''' </summary>
    Protected Overrides Sub Finalize()
    End Sub
End Class

''' <summary>
''' 色反転の設定管理のロジック
''' </summary>
Public Class ColorReversalInfo
    ''' <summary>
    ''' コンストラクタ
    ''' </summary>
    Public Sub New()
    End Sub

    ''' <summary>
    ''' デスクトラクタ
    ''' </summary>
    Protected Overrides Sub Finalize()
    End Sub
End Class