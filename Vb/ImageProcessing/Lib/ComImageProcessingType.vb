Public Class ComImageProcessingType
    Private m_nId As Integer
    Private m_strName As String

    Public Property Id() As Integer
        Get
            Return m_nId
        End Get
        Set(ByVal value As Integer)
            m_nId = value
        End Set
    End Property

    Public Property Name() As String
        Get
            Return m_strName
        End Get
        Set(ByVal value As String)
            m_strName = value
        End Set
    End Property

    Public Sub New()

    End Sub

    Public Sub New(ByVal _nId As Integer, ByVal _strNmae As String)
        m_nId = _nId
        m_strName = _strNmae
    End Sub

    Public Function Clone() As Object
        Return MemberwiseClone()
    End Function

End Class