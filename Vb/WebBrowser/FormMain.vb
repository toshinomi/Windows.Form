''' <summary>
''' MainFormのロジック
''' </summary>
Public Class FormMain
    Private m_nCountWebBrowser As UInt32
    Private m_listWebBrowser As Dictionary(Of UInt32, FormWebBrowser)

    ''' <summary>
    ''' コンストラクタ
    ''' </summary>
    Public Sub New()

        ' この呼び出しはデザイナーで必要です。
        InitializeComponent()

        ' InitializeComponent() 呼び出しの後で初期化を追加します。

        m_listWebBrowser = New Dictionary(Of UInt32, FormWebBrowser)()

    End Sub

    ''' <summary>
    ''' デスクトラクタ
    ''' </summary>
    Protected Overrides Sub Finalize()
        m_listWebBrowser.Clear()
        m_listWebBrowser = Nothing
        m_nCountWebBrowser = 0
    End Sub

    ''' <summary>
    ''' FormMainのロードイベント
    ''' </summary>
    ''' <param name="sender">オブジェクト</param>
    ''' <param name="e">イベントのデータ</param>
    Private Sub OnLoadFormMain(sender As Object, e As EventArgs) Handles MyBase.Load
        SetFormMain()
        SetFormChild()
    End Sub

    ''' <summary>
    ''' メニューの新規ウィンドウを開くのクリックイベント
    ''' </summary>
    ''' <param name="sender">オブジェクト</param>
    ''' <param name="e">イベントのデータ</param>
    Private Sub OnClickMenuFileNewOpen(sender As Object, e As EventArgs) Handles menuFile_NewOpen.Click
        SetFormChild()
    End Sub

    ''' <summary>
    ''' メニューの重ねて表示のクリックイベント
    ''' </summary>
    ''' <param name="sender">オブジェクト</param>
    ''' <param name="e">イベントのデータ</param>
    Private Sub OnClickMenuWindowCascade(sender As Object, e As EventArgs) Handles menuWindow_Cascade.Click
        Me.LayoutMdi(MdiLayout.Cascade)
    End Sub

    ''' <summary>
    ''' メニューの上下に並べて表示のクリックイベント
    ''' </summary>
    ''' <param name="sender">オブジェクト</param>
    ''' <param name="e">イベントのデータ</param>
    Private Sub OnClickMenuWindowTileHorizontal(sender As Object, e As EventArgs) Handles menuWindow_TileHorizontal.Click
        Me.LayoutMdi(MdiLayout.TileHorizontal)
    End Sub

    ''' <summary>
    ''' メニューの左右に並べて表示のクリックイベント
    ''' </summary>
    ''' <param name="sender">オブジェクト</param>
    ''' <param name="e">イベントのデータ</param>
    Private Sub OnClickMenuWindowTileVertical(sender As Object, e As EventArgs) Handles menuWindow_TileVertical.Click
        Me.LayoutMdi(MdiLayout.TileVertical)
    End Sub

    ''' <summary>
    ''' メニューの終了のクリックイベント
    ''' </summary>
    ''' <param name="sender">オブジェクト</param>
    ''' <param name="e">イベントのデータ</param>
    Private Sub OnClickMenuFileEnd(sender As Object, e As EventArgs) Handles menuFile_End.Click
        For Each nKey As UInt32 In m_listWebBrowser.Keys
            Dim Form As FormWebBrowser = m_listWebBrowser(nKey)
            Form = Nothing
        Next
        Me.Close()
    End Sub

    ''' <summary>
    ''' Formのクローズイベント
    ''' </summary>
    ''' <param name="sender">オブジェクト</param>
    ''' <param name="e">FormClosedイベントのデータ</param>
    Private Sub OnFormClosedFormMain(sender As Object, e As FormClosedEventArgs) Handles MyBase.FormClosed
        m_listWebBrowser.Clear()
        m_listWebBrowser = Nothing
    End Sub

    ''' <summary>
    ''' FormMainの設定
    ''' </summary>
    Public Sub SetFormMain()
        Me.Size = New Size(1000, 600)
    End Sub

    ''' <summary>
    ''' FormMainの子ウィンドウの設定
    ''' </summary>
    Public Sub SetFormChild()
        Dim form As New FormWebBrowser()
        form.MdiParent = Me
        form.WindowState = FormWindowState.Minimized
        form.Show()
        form.Name = m_nCountWebBrowser.ToString()
        form.WindowState = FormWindowState.Maximized
        m_listWebBrowser.Add(UInt32.Parse(form.Name), form)
        m_nCountWebBrowser += 1
    End Sub

    ''' <summary>
    ''' Webブラウザの情報の取得
    ''' </summary>
    ''' <param name="nKey">キー</param>
    ''' <returns>Webブラウザ情報</returns>
    Public Function GetFormWebBrowser(ByVal nKey As UInt32) As FormWebBrowser
        Return m_listWebBrowser(nKey)
    End Function

    ''' <summary>
    ''' Webブラウザの情報の削除
    ''' </summary>
    ''' <param name="nKey">キー</param>
    Public Sub RemoveListWebBrowser(ByVal nKey As UInt32)
        m_listWebBrowser.Remove(nKey)
    End Sub
End Class