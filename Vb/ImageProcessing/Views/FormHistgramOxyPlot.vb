Public Class FormHistgramOxyPlot
    Private m_histgramChart As ComHistgramOxyPlot
    Private m_bIsOpen As Boolean

    Public Property BitmapOrg() As Bitmap
        Set(value As Bitmap)
            m_histgramChart.BitmapOrg = value
        End Set
        Get
            Return m_histgramChart.BitmapOrg
        End Get
    End Property

    Public Property BitmapAfter() As Bitmap
        Set(value As Bitmap)
            m_histgramChart.BitmapAfter = value
        End Set
        Get
            Return m_histgramChart.BitmapAfter
        End Get
    End Property

    Public Property IsOpen() As Boolean
        Set(value As Boolean)
            m_bIsOpen = value
        End Set
        Get
            Return m_bIsOpen
        End Get
    End Property

    Public Sub New()

        ' この呼び出しはデザイナーで必要です。
        InitializeComponent()

        ' InitializeComponent() 呼び出しの後で初期化を追加します。

        m_histgramChart = New ComHistgramOxyPlot()
    End Sub

    Public Sub DrawHistgram()
        If (chart.Model IsNot Nothing) Then
            chart.Model.Series.Clear()
            chart.Model = Nothing
        End If
        chart.Model = m_histgramChart.DrawHistgram()

        Return
    End Sub

    Private Sub FormHistgramOxyPlot_FormClosing(sender As Object, e As FormClosingEventArgs) Handles MyBase.FormClosing
        m_bIsOpen = False

        Return
    End Sub

    Private Sub OnClickMenu(sender As Object, e As EventArgs) Handles SaveCsvToolStripMenuItem.Click
        Dim strHeader As String = sender.ToString()

        Select Case (strHeader)
            Case ComInfo.MENU_SAVE_FILE
                SaveCsv()
            Case Else
        End Select
    End Sub

    Public Sub SaveCsv()
        If (m_histgramChart.SaveCsv() = False) Then
            MessageBox.Show(Me, "Save CSV File Error", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error)
        End If
    End Sub
End Class