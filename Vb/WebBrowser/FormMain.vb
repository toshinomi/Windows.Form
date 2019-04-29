Public Class FormMain
    Private m_nCountWebBrowser As UInt32
    Private m_listWebBrowser As Dictionary(Of UInt32, FormWebBrowser)

    Public Sub New()

        ' この呼び出しはデザイナーで必要です。
        InitializeComponent()

        ' InitializeComponent() 呼び出しの後で初期化を追加します。

        m_listWebBrowser = New Dictionary(Of UInt32, FormWebBrowser)()

    End Sub

    Protected Overrides Sub Finalize()
        m_listWebBrowser.Clear()
        m_listWebBrowser = Nothing
        m_nCountWebBrowser = 0
    End Sub

    Private Sub OnLoadFormMain(sender As Object, e As EventArgs) Handles MyBase.Load
        SetFormMain()
        SetFormChild()
    End Sub

    Private Sub OnClickMenuFileNewOpen(sender As Object, e As EventArgs) Handles menuFile_NewOpen.Click
        SetFormChild()
    End Sub

    Private Sub OnClickMenuWindowCascade(sender As Object, e As EventArgs) Handles menuWindow_Cascade.Click
        Me.LayoutMdi(MdiLayout.Cascade)
    End Sub

    Private Sub OnClickMenuWindowTileHorizontal(sender As Object, e As EventArgs) Handles menuWindow_TileHorizontal.Click
        Me.LayoutMdi(MdiLayout.TileHorizontal)
    End Sub

    Private Sub OnClickMenuWindowTileVertical(sender As Object, e As EventArgs) Handles menuWindow_TileVertical.Click
        Me.LayoutMdi(MdiLayout.TileVertical)
    End Sub

    Private Sub OnClickMenuFileEnd(sender As Object, e As EventArgs) Handles menuFile_End.Click
        For Each nKey As UInt32 In m_listWebBrowser.Keys
            Dim Form As FormWebBrowser = m_listWebBrowser(nKey)
            Form = Nothing
        Next
        Me.Close()
    End Sub

    Private Sub OnFormClosedFormMain(sender As Object, e As FormClosedEventArgs) Handles MyBase.FormClosed
        m_listWebBrowser.Clear()
        m_listWebBrowser = Nothing
    End Sub

    Public Sub SetFormMain()
        Me.Size = New Size(1000, 600)
    End Sub

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

    Public Function GetFormWebBrowser(ByVal nKey As UInt32) As FormWebBrowser
        Return m_listWebBrowser(nKey)
    End Function

    Public Sub RemoveListWebBrowser(ByVal nKey As UInt32)
        m_listWebBrowser.Remove(nKey)
    End Sub

End Class