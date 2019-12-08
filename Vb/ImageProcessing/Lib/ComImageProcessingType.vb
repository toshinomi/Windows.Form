''' <summary>
''' 画像処理設定のロジック
''' </summary>
Public Class ComImageProcessingType
    Private m_nId As Integer
    Private m_strName As String

    ''' <summary>
    ''' ID
    ''' </summary>
    Public Property Id() As Integer
        Get
            Return m_nId
        End Get
        Set(ByVal value As Integer)
            m_nId = value
        End Set
    End Property

    ''' <summary>
    ''' 名称
    ''' </summary>
    Public Property Name() As String
        Get
            Return m_strName
        End Get
        Set(ByVal value As String)
            m_strName = value
        End Set
    End Property

    ''' <summary>
    ''' コンストラクタ
    ''' </summary>
    Public Sub New()
    End Sub

    ''' <summary>
    ''' コンストラクタ
    ''' </summary>
    ''' <param name="_nId">ID</param>
    ''' <param name="_strNmae">名称</param>
    Public Sub New(ByVal _nId As Integer, ByVal _strNmae As String)
        m_nId = _nId
        m_strName = _strNmae
    End Sub

    ''' <summary>
    ''' デスクトラクタ
    ''' </summary>
    Protected Overrides Sub Finalize()
        MyBase.Finalize()
    End Sub

    ''' <summary>
    ''' クローン
    ''' </summary>
    ''' <returns>画像処理設定のクローン</returns>
    Public Function Clone() As Object
        Return MemberwiseClone()
    End Function
End Class