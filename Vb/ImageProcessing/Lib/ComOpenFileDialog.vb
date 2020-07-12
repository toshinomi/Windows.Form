''' <summary>
''' ファイルオープンのロジック
''' </summary>
Public Class ComOpenFileDialog
    Protected mOpenFileDialog As OpenFileDialog

    ''' <summary>
    ''' ファイル名称
    ''' </summary>
    Public Property FileName() As String
        Set(value As String)
            mOpenFileDialog.FileName = value
        End Set
        Get
            Return mOpenFileDialog.FileName
        End Get
    End Property

    ''' <summary>
    ''' ファイルダイアログに表示される初期ディレクトリ
    ''' </summary>
    Public Property InitialDirectory() As String
        Set(value As String)
            mOpenFileDialog.InitialDirectory = value
        End Set
        Get
            Return mOpenFileDialog.InitialDirectory
        End Get
    End Property

    ''' <summary>
    ''' ファイルの種類のフィルタ
    ''' </summary>
    Public Property Filter() As String
        Set(value As String)
            mOpenFileDialog.Filter = value
        End Set
        Get
            Return mOpenFileDialog.Filter
        End Get
    End Property

    ''' <summary>
    ''' 現在選択中のフィルタのインデックス
    ''' </summary>
    Public Property FilterIndex() As Integer
        Set(value As Integer)
            mOpenFileDialog.FilterIndex = value
        End Set
        Get
            Return mOpenFileDialog.FilterIndex
        End Get
    End Property

    ''' <summary>
    ''' ファイルダイアログに表示されるタイトル
    ''' </summary>
    Public Property Title() As String
        Set(value As String)
            mOpenFileDialog.Title = value
        End Set
        Get
            Return mOpenFileDialog.Title
        End Get
    End Property

    ''' <summary>
    ''' 存在しないファイルを指定した場合に警告を表示するかどうかの値
    ''' </summary>
    Public Property CheckFileExists() As Boolean
        Set(value As Boolean)
            mOpenFileDialog.CheckFileExists = value
        End Set
        Get
            Return mOpenFileDialog.CheckFileExists
        End Get
    End Property

    ''' <summary>
    ''' 無効なパスとファイルを入力した場合に警告を表示するかどうかの値
    ''' </summary>
    Public Property CheckPathExists() As Boolean
        Set(value As Boolean)
            mOpenFileDialog.CheckPathExists = value
        End Set
        Get
            Return mOpenFileDialog.CheckPathExists
        End Get
    End Property

    ''' <summary>
    ''' コンストラクタ
    ''' </summary>
    Public Sub New()
        mOpenFileDialog = New OpenFileDialog()
    End Sub

    ''' <summary>
    ''' デスクトラクタ
    ''' </summary>
    Protected Overrides Sub Finalize()
        MyBase.Finalize()
    End Sub

    ''' <summary>
    ''' ダイアログの表示
    ''' </summary>
    ''' <returns>結果 成功/失敗</returns>
    Public Function ShowDialog() As Boolean
        Dim result As Boolean = False

        If (mOpenFileDialog.ShowDialog() = DialogResult.OK) Then
            result = True
        End If

        Return result
    End Function
End Class