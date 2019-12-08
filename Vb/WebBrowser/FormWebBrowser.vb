''' <summary>
''' FormWebBrowserのロジック
''' </summary>
Public Class FormWebBrowser
    Private Const HOME_URL As String = "https://www.bing.com/"
    Private m_strUrl As String
    Private m_toolTip As ToolTip

    ''' <summary>
    ''' コンストラクタ
    ''' </summary>
    Public Sub New()

        ' この呼び出しはデザイナーで必要です。
        InitializeComponent()

        m_strUrl = ""

        ' InitializeComponent() 呼び出しの後で初期化を追加します。
    End Sub

    ''' <summary>
    ''' デスクトラクタ
    ''' </summary>
    Protected Overrides Sub Finalize()
        m_toolTip = Nothing
    End Sub

    ''' <summary>
    ''' Formのクローズイベント
    ''' </summary>
    ''' <param name="sender">オブジェクト</param>
    ''' <param name="e">FormClosedイベントのデータ</param>
    Private Sub OnFormClosedFormWebBrowser(sender As Object, e As FormClosedEventArgs) Handles MyBase.FormClosed

    End Sub

    ''' <summary>
    ''' FormWebBrowserのロードイベント
    ''' </summary>
    ''' <param name="sender">オブジェクト</param>
    ''' <param name="e">イベントのデータ</param>
    Private Sub OnLoadFormWebBrowser(sender As Object, e As EventArgs) Handles MyBase.Load
        SetInitToolTip()
        HomeWebBrowser()
    End Sub

    ''' <summary>
    ''' 前のページに戻すクリックイベント
    ''' </summary>
    ''' <param name="sender">オブジェクト</param>
    ''' <param name="e">イベントのデータ</param>
    Private Sub OnClickBack(sender As Object, e As EventArgs) Handles buttonBack.Click
        If (webBrowser.CanGoBack = True) Then
            webBrowser.GoBack()
        End If
    End Sub

    ''' <summary>
    ''' 次のページに移動クリックイベント
    ''' </summary>
    ''' <param name="sender">オブジェクト</param>
    ''' <param name="e">イベントのデータ</param>
    Private Sub OnClickForward(sender As Object, e As EventArgs) Handles buttonForward.Click
        If (webBrowser.CanGoForward = True) Then
            webBrowser.GoForward()
        End If
    End Sub

    ''' <summary>
    ''' 更新のクリックイベント
    ''' </summary>
    ''' <param name="sender">オブジェクト</param>
    ''' <param name="e">イベントのデータ</param>
    Private Sub OnClickRefresh(sender As Object, e As EventArgs) Handles buttonRefresh.Click
        webBrowser.Refresh()
    End Sub

    ''' <summary>
    ''' URL入力のテキストボックスのキーダウンイベント
    ''' </summary>
    ''' <param name="sender">オブジェクト</param>
    ''' <param name="e">キーイベントのデータ</param>
    Private Sub OnKeyDownTextUrl(sender As Object, e As KeyEventArgs) Handles textUrl.KeyDown
        If (e.KeyCode = Keys.Enter) Then
            m_strUrl = textUrl.Text
            webBrowser.Navigate(m_strUrl)
        End If
    End Sub

    ''' <summary>
    ''' WebBrowserのNavigatedイベント
    ''' </summary>
    ''' <param name="sender">オブジェクト</param>
    ''' <param name="e">WebBrowserNavigatedイベントのデータ</param>
    Private Sub OnNavigatedWebBrowser(sender As Object, e As WebBrowserNavigatedEventArgs) Handles webBrowser.Navigated
        textUrl.Text = webBrowser.Url.AbsoluteUri
        Me.Text = webBrowser.Url.AbsoluteUri
    End Sub

    ''' <summary>
    ''' ツールチップの設定
    ''' </summary>
    Public Sub SetInitToolTip()
        m_toolTip = New ToolTip()
        m_toolTip.SetToolTip(textUrl, "URL入力後、Enterキーを押してください!!!")
    End Sub

    ''' <summary>
    ''' ホームの処理
    ''' </summary>
    Public Sub HomeWebBrowser()
        Dim uri As New Uri(HOME_URL)
        webBrowser.Navigate(uri)
        textUrl.Text = m_strUrl
        Me.Text = m_strUrl
    End Sub
End Class