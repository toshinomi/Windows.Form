Imports System.Threading

''' <summary>
''' 画像処理の共通のロジック
''' </summary>
Public MustInherit Class ComImageProcessing
    Protected mBitmap As Bitmap

    ''' <summary>
    ''' コンストラクタ
    ''' </summary>
    ''' <param name="bitmap">ビットマップ</param>
    Public Sub New(bitmap As Bitmap)
        mBitmap = bitmap
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
    Public Overridable Sub Init()
        mBitmap = Nothing
    End Sub

    ''' <summary>
    ''' ビットマップ
    ''' </summary>
    Public Property Bitmap() As Bitmap
        Get
            Return mBitmap
        End Get
        Set(ByVal value As Bitmap)
            mBitmap = value
        End Set
    End Property

    ''' <summary>
    ''' 画像処理実行の抽象
    ''' </summary>
    ''' <param name="imageProcessingName">画像処理オブジェクトの名称</param>
    ''' <param name="token">キャンセルトークン</param>
    ''' <returns>実行結果 成功/失敗</returns>
    Public MustOverride Function GoImageProcessing(imageProcessingName As String, token As CancellationToken) As Boolean
End Class