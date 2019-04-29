Public Class FormWebBrowser
    Private Const HOME_URL As String = "https://www.bing.com/"
    Private m_strUrl As String
    Private m_toolTip As ToolTip

    Public Sub New()

        ' この呼び出しはデザイナーで必要です。
        InitializeComponent()

        m_strUrl = ""

        ' InitializeComponent() 呼び出しの後で初期化を追加します。
    End Sub

    Protected Overrides Sub Finalize()
        m_toolTip = Nothing
    End Sub

    Private Sub OnFormClosedFormWebBrowser(sender As Object, e As FormClosedEventArgs) Handles MyBase.FormClosed

    End Sub

    Private Sub OnLoadFormWebBrowser(sender As Object, e As EventArgs) Handles MyBase.Load
        SetInitToolTip()
        HomeWebBrowser()
    End Sub

    Private Sub OnClickBack(sender As Object, e As EventArgs) Handles buttonBack.Click
        If (webBrowser.CanGoBack = True) Then
            webBrowser.GoBack()
        End If
    End Sub

    Private Sub OnClickForward(sender As Object, e As EventArgs) Handles buttonForward.Click
        If (webBrowser.CanGoForward = True) Then
            webBrowser.GoForward()
        End If
    End Sub

    Private Sub OnClickRefresh(sender As Object, e As EventArgs) Handles buttonRefresh.Click
        webBrowser.Refresh()
    End Sub

    Private Sub OnKeyDownTextUrl(sender As Object, e As KeyEventArgs) Handles textUrl.KeyDown
        If (e.KeyCode = Keys.Enter) Then
            m_strUrl = textUrl.Text
            webBrowser.Navigate(m_strUrl)
        End If
    End Sub

    Private Sub OnNavigatedWebBrowser(sender As Object, e As WebBrowserNavigatedEventArgs) Handles webBrowser.Navigated
        textUrl.Text = webBrowser.Url.AbsoluteUri
        Me.Text = webBrowser.Url.AbsoluteUri
    End Sub

    Public Sub SetInitToolTip()
        m_toolTip = New ToolTip()
        m_toolTip.SetToolTip(textUrl, "URL入力後、Enterキーを押してください!!!")
    End Sub

    Public Sub HomeWebBrowser()
        Dim uri As New Uri(HOME_URL)
        webBrowser.Navigate(uri)
        textUrl.Text = m_strUrl
        Me.Text = m_strUrl
    End Sub
End Class