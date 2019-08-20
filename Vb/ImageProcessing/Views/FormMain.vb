Imports System.Threading
Imports ImageProcessing.ImageProcessing

Public Class FormMain
    Private m_bitmap As Bitmap
    Private m_edgeDetection As EdgeDetection
    Private m_strOpenFileName As String
    Private m_tokenSource As CancellationTokenSource
    Private m_strCurImgName As String

    Public Sub New()

        ' この呼び出しはデザイナーで必要です。
        InitializeComponent()

        ' InitializeComponent() 呼び出しの後で初期化を追加します。

        btnFileSelect.Enabled = True
        btnAllClear.Enabled = True
        btnStart.Enabled = False
        btnStop.Enabled = False

        pictureBoxStatus.Visible = False

        SetToolTip()

        m_bitmap = Nothing
        m_tokenSource = Nothing
        m_edgeDetection = Nothing
    End Sub

    Public Sub SetToolTip()
        toolTipBtnFileSelect.InitialDelay = 1000
        toolTipBtnFileSelect.ReshowDelay = 1000
        toolTipBtnFileSelect.AutoPopDelay = 10000
        toolTipBtnFileSelect.ShowAlways = False
        toolTipBtnFileSelect.SetToolTip(btnFileSelect, "Please select a file to open.\nDisplay the image on the original image.")

        toolTipBtnAllClear.InitialDelay = 1000
        toolTipBtnAllClear.ReshowDelay = 1000
        toolTipBtnAllClear.AutoPopDelay = 10000
        toolTipBtnAllClear.ShowAlways = False
        toolTipBtnAllClear.SetToolTip(btnAllClear, "Clear the display.")

        toolTipBtnStart.InitialDelay = 1000
        toolTipBtnStart.ReshowDelay = 1000
        toolTipBtnStart.AutoPopDelay = 10000
        toolTipBtnStart.ShowAlways = False
        toolTipBtnStart.SetToolTip(btnStart, "Perform unstable filter processing.")

        toolTipBtnStop.InitialDelay = 1000
        toolTipBtnStop.ReshowDelay = 1000
        toolTipBtnStop.AutoPopDelay = 10000
        toolTipBtnStop.ShowAlways = False
        toolTipBtnStop.SetToolTip(btnStop, "Processing stop.")

        Return
    End Sub

    Protected Overrides Sub Finalize()
        MyBase.Finalize()

        m_bitmap = Nothing
        m_tokenSource = Nothing
    End Sub

    Public Sub SetButtonEnable()
        btnFileSelect.Enabled = True
        btnAllClear.Enabled = True
        btnStart.Enabled = True
        btnStop.Enabled = False

        Return
    End Sub

    Public Sub SetTextTime(_lTime As Long)
        textBoxTime.Text = _lTime.ToString()

        Return
    End Sub

    Public Sub SetPictureBoxStatus()
        pictureBoxStatus.Visible = False

        Return
    End Sub

    Public Function TaskWorkImageProcessing()
        m_tokenSource = New CancellationTokenSource()
        Dim token As CancellationToken = m_tokenSource.Token
        Dim bRst As Task(Of Boolean) = Task.Run(Function() m_edgeDetection.GoImgProc(token))
        Return bRst
    End Function

    Public Sub LoadImage()
        m_bitmap = New Bitmap(m_strOpenFileName)
        m_edgeDetection = New EdgeDetection(m_bitmap)

        Return
    End Sub

    Public Sub OnFormClosingFormMain(sender As Object, e As FormClosingEventArgs)
        If (m_tokenSource IsNot Nothing) Then
            e.Cancel = True
        End If
        Return
    End Sub

    Private Sub OnClickBtnFileSelect(sender As Object, e As EventArgs)
        Dim openFileDlg As ComOpenFileDialog = New ComOpenFileDialog()
        openFileDlg.Filter = "JPG|*.jpg|PNG|*.png"
        openFileDlg.Title = "Open the file"
        If (openFileDlg.ShowDialog() = True) Then
            pictureBoxOriginal.Image = Nothing
            pictureBoxAfter.Image = Nothing
            m_strOpenFileName = openFileDlg.FileName
            Try
                LoadImage()
            Catch ex As Exception
                MessageBox.Show(Me, "Open File Error", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error)
                Return
            End Try
            pictureBoxOriginal.ImageLocation = m_strOpenFileName
            btnStart.Enabled = True
            textBoxTime.Text = ""
        End If
        Return
    End Sub

    Private Sub OnClickBtnAllClear(sender As Object, e As EventArgs)
        pictureBoxOriginal.ImageLocation = Nothing
        pictureBoxAfter.Image = Nothing

        m_bitmap = Nothing
        m_strOpenFileName = ""

        textBoxTime.Text = ""

        btnFileSelect.Enabled = True
        btnAllClear.Enabled = True
        btnStart.Enabled = False

        Return
    End Sub

    Private Async Sub OnClickBtnStart(sender As Object, e As EventArgs)
        pictureBoxAfter.Image = Nothing

        btnFileSelect.Enabled = False
        btnAllClear.Enabled = False
        btnStart.Enabled = False

        textBoxTime.Text = ""

        pictureBoxStatus.Visible = True

        LoadImage()

        Dim Stopwatch As Stopwatch = New Stopwatch()
        Stopwatch.Start()
        btnStop.Enabled = True
        Dim bResult As Boolean = Await TaskWorkImageProcessing()
        If (bResult) Then
            pictureBoxOriginal.ImageLocation = m_strOpenFileName
            pictureBoxAfter.Image = m_edgeDetection.Bitmap

            Stopwatch.Stop()

            Invoke(New Action(Of Long)(AddressOf SetTextTime), Stopwatch.ElapsedMilliseconds)
        End If
        Invoke(New Action(AddressOf SetPictureBoxStatus))
        Invoke(New Action(AddressOf SetButtonEnable))

        Stopwatch = Nothing
        m_tokenSource = Nothing
        m_bitmap = Nothing

        Return
    End Sub

    Private Sub OnClickBtnStop(sender As Object, e As EventArgs)
        If (m_tokenSource IsNot Nothing) Then
            m_tokenSource.Cancel()
        End If

        Return
    End Sub

    Private Sub OnClickMenu(sender As Object, e As EventArgs) Handles imageProcessingToolStripMenuItem.Click
        Dim menuItem As ToolStripItem = sender
        Dim strText As String = menuItem.Text

        Select Case strText
            Case ComInfo.MENU_FILE_END
                Close()
            Case ComInfo.MENU_SETTING_IMAGE_PROCESSING
                ShowSettingImageProcessing()
            Case Else
        End Select
    End Sub

    Public Sub ShowSettingImageProcessing()
        Dim win = New FormSettingImageProcessing()
        Dim dialogResult = win.ShowDialog()

        If (dialogResult = DialogResult.OK) Then
            m_strCurImgName = win.ComboBoxImageProcessingType.SelectedItem
            Me.Text = "Image Processing ( " + m_strCurImgName + " )"

            sliderThresh.Enabled = If(m_strCurImgName = ComInfo.IMG_NAME_BINARIZATION, True, False)

            pictureBoxAfter.Image = Nothing
            btnSaveImage.Enabled = False
        End If
    End Sub
End Class