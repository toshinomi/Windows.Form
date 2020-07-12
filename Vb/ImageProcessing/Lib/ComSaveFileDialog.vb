Imports System.IO
Imports System.Text

''' <summary>
''' ファイルセーブのロジック
''' </summary>
Public Class ComSaveFileDialog
    Protected mSaveFileDialog As SaveFileDialog

    ''' <summary>
    ''' ファイル名称
    ''' </summary>
    Public Property FileName() As String
        Set(value As String)
            mSaveFileDialog.FileName = value
        End Set
        Get
            Return mSaveFileDialog.FileName
        End Get
    End Property

    ''' <summary>
    ''' ファイルダイアログに表示される初期ディレクトリ
    ''' </summary>
    Public Property InitialDirectory() As String
        Set(value As String)
            mSaveFileDialog.InitialDirectory = value
        End Set
        Get
            Return mSaveFileDialog.InitialDirectory
        End Get
    End Property

    ''' <summary>
    ''' ファイルの種類のフィルタ
    ''' </summary>
    Public Property Filter() As String
        Set(value As String)
            mSaveFileDialog.Filter = value
        End Set
        Get
            Return mSaveFileDialog.Filter
        End Get
    End Property

    ''' <summary>
    ''' 現在選択中のフィルタのインデックス
    ''' </summary>
    Public Property FilterIndex() As Integer
        Set(value As Integer)
            mSaveFileDialog.FilterIndex = value
        End Set
        Get
            Return mSaveFileDialog.FilterIndex
        End Get
    End Property

    ''' <summary>
    ''' ファイルダイアログに表示されるタイトル
    ''' </summary>
    Public Property Title() As String
        Set(value As String)
            mSaveFileDialog.Title = value
        End Set
        Get
            Return mSaveFileDialog.Title
        End Get
    End Property

    ''' <summary>
    ''' 存在しないファイルを指定した場合に警告を表示するかどうかの値
    ''' </summary>
    Public Property CheckFileExists() As Boolean
        Set(value As Boolean)
            mSaveFileDialog.CheckFileExists = value
        End Set
        Get
            Return mSaveFileDialog.CheckFileExists
        End Get
    End Property

    ''' <summary>
    ''' 無効なパスとファイルを入力した場合に警告を表示するかどうかの値
    ''' </summary>
    Public Property CheckPathExists() As Boolean
        Set(value As Boolean)
            mSaveFileDialog.CheckPathExists = value
        End Set
        Get
            Return mSaveFileDialog.CheckPathExists
        End Get
    End Property

    ''' <summary>
    ''' コンストラクタ
    ''' </summary>
    Public Sub New()
        mSaveFileDialog = New SaveFileDialog()
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
        Dim result = False

        If (mSaveFileDialog.ShowDialog() = DialogResult.OK) Then
            result = True
        End If

        Return result
    End Function

    ''' <summary>
    ''' ストリームの書込み
    ''' </summary>
    ''' <param name="fileName">ファイル名称</param>
    ''' <returns>実行結果 成功/失敗</returns>
    Public Function SreamWrite(fileName As String)
        Dim stream As Stream
        Dim result = True
        Try
            stream = mSaveFileDialog.OpenFile()
        Catch ex As Exception
            result = False
            Return result
        End Try
        Dim streamWriter = New StreamWriter(stream, Encoding.GetEncoding("UTF-8"))
        streamWriter.Write(fileName)
        streamWriter.Close()
        stream.Close()

        Return result
    End Function
End Class