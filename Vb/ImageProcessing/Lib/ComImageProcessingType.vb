''' <summary>
''' 画像処理設定のロジック
''' </summary>
Public Class ComImageProcessingType
    ''' <summary>
    ''' ID
    ''' </summary>
    Public Property Id() As Integer

    ''' <summary>
    ''' 名称
    ''' </summary>
    Public Property Name() As String

    ''' <summary>
    ''' コンストラクタ
    ''' </summary>
    Public Sub New()
    End Sub

    ''' <summary>
    ''' コンストラクタ
    ''' </summary>
    ''' <param name="id">ID</param>
    ''' <param name="name">名称</param>
    Public Sub New(ByVal id As Integer, name As String)
        Me.Id = id
        Me.Name = name
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