Imports System.Threading

''' <summary>
''' 画像処理の共通のロジック
''' </summary>
Public MustInherit Class ComImgProc
    Protected m_bitmap As Bitmap
    Protected m_bitmapAfter As Bitmap

    ''' <summary>
    ''' コンストラクタ
    ''' </summary>
    ''' <param name="_bitmap">ビットマップ</param>
    Public Sub New(ByVal _bitmap As Bitmap)
        m_bitmap = _bitmap
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
        m_bitmap = Nothing
        m_bitmapAfter = Nothing
    End Sub

    ''' <summary>
    ''' ビットマップ
    ''' </summary>
    Public Property Bitmap() As Bitmap
        Get
            Return m_bitmap
        End Get
        Set(ByVal value As Bitmap)
            m_bitmap = value
        End Set
    End Property

    ''' <summary>
    ''' 画像処理後のビットマップ
    ''' </summary>
    Public Property BitmapAfter() As Bitmap
        Get
            Return m_bitmapAfter
        End Get
        Set(ByVal value As Bitmap)
            m_bitmapAfter = value
        End Set
    End Property

    ''' <summary>
    ''' 画像処理実行の抽象
    ''' </summary>
    ''' <param name="_token">キャンセルトークン</param>
    ''' <returns>実行結果 成功/失敗</returns>
    Public MustOverride Function GoImgProc(ByVal _token As CancellationToken) As Boolean
End Class