Imports System.Threading

Public Class FormMain
    Private m_bitmap As Bitmap
    'Private m_edgeDetection As EdgeDetection
    Private m_imgProc As Object
    Private m_strOpenFileName As String
    Private m_tokenSource As CancellationTokenSource
    Private m_strCurImgName As String
    Private m_histgram As FormHistgram

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
        m_imgProc = Nothing

        m_strCurImgName = My.Settings.ImgTypeSelectName
        Me.Text = "Image Processing ( " + m_strCurImgName + " )"

        sliderThresh.Enabled = If(m_strCurImgName = ComInfo.IMG_NAME_BINARIZATION, True, False)
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

        toolTipBtnSaveImage.InitialDelay = 1000
        toolTipBtnSaveImage.ReshowDelay = 1000
        toolTipBtnSaveImage.AutoPopDelay = 10000
        toolTipBtnSaveImage.ShowAlways = False
        toolTipBtnSaveImage.SetToolTip(btnSaveImage, "Saving image.")

        toolTipBtnShowHistgram.InitialDelay = 1000
        toolTipBtnShowHistgram.ReshowDelay = 1000
        toolTipBtnShowHistgram.AutoPopDelay = 10000
        toolTipBtnShowHistgram.ShowAlways = False
        toolTipBtnShowHistgram.SetToolTip(btnShowHistgram, "Show Histgram.")

        Return
    End Sub

    Protected Overrides Sub Finalize()
        MyBase.Finalize()

        m_bitmap = Nothing
        m_tokenSource = Nothing
        m_imgProc = Nothing
    End Sub

    Public Function SelectLoadImage(_strImgName As String) As Boolean
        Dim bRst As Boolean = True

        If (m_imgProc IsNot Nothing) Then
            m_imgProc = Nothing
        End If

        Select Case _strImgName
            Case ComInfo.IMG_NAME_EDGE_DETECTION
                m_imgProc = New EdgeDetection(m_bitmap)
            Case ComInfo.IMG_NAME_GRAY_SCALE
                m_imgProc = New GrayScale(m_bitmap)
            Case ComInfo.IMG_NAME_BINARIZATION
                m_imgProc = New Binarization(m_bitmap)
            Case ComInfo.IMG_NAME_GRAY_SCALE_2DIFF
                m_imgProc = New GrayScale2Diff(m_bitmap)
            Case ComInfo.IMG_NAME_COLOR_REVERSAL
                m_imgProc = New ColorReversal(m_bitmap)
            Case Else
        End Select

        Return bRst
    End Function

    Public Function SelectGetBitmap(_strImgName As String) As Bitmap
        Dim bitmap As Bitmap = Nothing

        Select Case _strImgName
            Case ComInfo.IMG_NAME_EDGE_DETECTION
                Dim edge As EdgeDetection = m_imgProc
                bitmap = edge.BitmapAfter
            Case ComInfo.IMG_NAME_GRAY_SCALE
                Dim gray As GrayScale = m_imgProc
                bitmap = gray.BitmapAfter
            Case ComInfo.IMG_NAME_BINARIZATION
                Dim binarization As Binarization = m_imgProc
                bitmap = binarization.BitmapAfter
            Case ComInfo.IMG_NAME_GRAY_SCALE_2DIFF
                Dim gray2Diff As GrayScale2Diff = m_imgProc
                bitmap = gray2Diff.BitmapAfter
            Case ComInfo.IMG_NAME_COLOR_REVERSAL
                Dim colorReversal As ColorReversal = m_imgProc
                bitmap = colorReversal.BitmapAfter
            Case Else
        End Select

        Return bitmap
    End Function

    Public Function SelectGoImgProc(_comImgInfo As ComImgInfo, _token As CancellationToken) As Boolean
        Dim bRst As Boolean = True

        Select Case _comImgInfo.CurImgName
            Case ComInfo.IMG_NAME_EDGE_DETECTION
                Dim edge As EdgeDetection = m_imgProc
                bRst = edge.GoImgProc(_token)
            Case ComInfo.IMG_NAME_GRAY_SCALE
                Dim gray As GrayScale = m_imgProc
                bRst = gray.GoImgProc(_token)
            Case ComInfo.IMG_NAME_BINARIZATION
                Dim Binarization As Binarization = m_imgProc
                Binarization.Thresh = _comImgInfo.BinarizationInfo.Thresh
                bRst = Binarization.GoImgProc(_token)
            Case ComInfo.IMG_NAME_GRAY_SCALE_2DIFF
                Dim gray2Diff As GrayScale2Diff = m_imgProc
                bRst = gray2Diff.GoImgProc(_token)
            Case ComInfo.IMG_NAME_COLOR_REVERSAL
                Dim ColorReversal As ColorReversal = m_imgProc
                bRst = ColorReversal.GoImgProc(_token)
            Case Else
        End Select

        Return bRst
    End Function

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
        Dim imgInfo As ComImgInfo = New ComImgInfo()
        Dim binarizationInfo As ComBinarizationInfo = New ComBinarizationInfo()
        binarizationInfo.Thresh = sliderThresh.Value
        imgInfo.CurImgName = m_strCurImgName
        imgInfo.BinarizationInfo = binarizationInfo
        Dim bRst As Task(Of Boolean) = Task.Run(Function() SelectGoImgProc(imgInfo, token))
        Return bRst
    End Function

    Public Sub LoadImage()
        m_bitmap = New Bitmap(m_strOpenFileName)
        SelectLoadImage(m_strCurImgName)

        Return
    End Sub

    Public Sub OnFormClosingFormMain(sender As Object, e As FormClosingEventArgs) Handles MyBase.FormClosing
        If (m_tokenSource IsNot Nothing) Then
            e.Cancel = True
        End If
        Return
    End Sub

    Private Sub OnClickBtnFileSelect(sender As Object, e As EventArgs) Handles btnFileSelect.Click
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

            If (m_histgram Is Nothing) Then
                m_histgram = New FormHistgram()
            Else
                m_histgram.Close()
                m_histgram = Nothing
                m_histgram = New FormHistgram()
            End If

            m_histgram.BitmapOrg = New Bitmap(m_strOpenFileName).Clone()
            If (SelectGetBitmap(m_strCurImgName) IsNot Nothing) Then
                m_histgram.BitmapAfter = SelectGetBitmap(m_strCurImgName).Clone()
            End If
            m_histgram.DrawHistgram()
            m_histgram.IsOpen = True
            m_histgram.Show()
        End If
        Return
    End Sub

    Private Sub OnClickBtnAllClear(sender As Object, e As EventArgs) Handles btnAllClear.Click
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

    Private Async Sub OnClickBtnStart(sender As Object, e As EventArgs) Handles btnStart.Click
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
            pictureBoxAfter.Image = SelectGetBitmap(m_strCurImgName)

            Stopwatch.Stop()

            Invoke(New Action(Of Long)(AddressOf SetTextTime), Stopwatch.ElapsedMilliseconds)
        End If
        Invoke(New Action(AddressOf SetPictureBoxStatus))
        Invoke(New Action(AddressOf SetButtonEnable))

        Stopwatch = Nothing
        m_tokenSource = Nothing
        'm_bitmap = Nothing

        Return
    End Sub

    Private Sub OnClickBtnStop(sender As Object, e As EventArgs) Handles btnStop.Click
        If (m_tokenSource IsNot Nothing) Then
            m_tokenSource.Cancel()
        End If

        Return
    End Sub

    Private Sub OnClickMenu(sender As Object, e As EventArgs) Handles imageProcessingToolStripMenuItem.Click, endXToolStripMenuItem.Click
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

    Public Function GetImage(_strImgName As String) As Bitmap
        Dim Bitmap As Bitmap = Nothing

        Select Case m_strCurImgName
            Case ComInfo.IMG_NAME_EDGE_DETECTION
                Dim edge As EdgeDetection = m_imgProc
                If (edge IsNot Nothing) Then
                    Bitmap = edge.BitmapAfter
                End If
            Case ComInfo.IMG_NAME_GRAY_SCALE
                Dim gray As GrayScale = m_imgProc
                If (gray IsNot Nothing) Then
                    Bitmap = gray.BitmapAfter
                End If
            Case ComInfo.IMG_NAME_BINARIZATION
                Dim binarization As Binarization = m_imgProc
                If (binarization IsNot Nothing) Then
                    Bitmap = binarization.BitmapAfter
                End If
            Case ComInfo.IMG_NAME_GRAY_SCALE_2DIFF
                Dim gray2Diff As GrayScale2Diff = m_imgProc
                If (gray2Diff IsNot Nothing) Then
                    Bitmap = gray2Diff.BitmapAfter
                End If
            Case ComInfo.IMG_NAME_COLOR_REVERSAL
                Dim colorReversal As ColorReversal = m_imgProc
                If (colorReversal IsNot Nothing) Then
                    Bitmap = colorReversal.BitmapAfter
                End If
            Case Else
        End Select

        Return If(Bitmap Is Nothing, Bitmap, Bitmap.Clone())
    End Function

    Private Sub OnClickBtnSaveImage(sender As Object, e As EventArgs) Handles btnSaveImage.Click
        Dim saveDialog = New ComSaveFileDialog()
        saveDialog.Filter = "PNG|*.png"
        saveDialog.Title = "Save the file"
        If (saveDialog.ShowDialog() = True) Then
            Dim strFileName = saveDialog.FileName
            Dim bitmap As Bitmap = GetImage(m_strCurImgName)
            If (bitmap IsNot Nothing) Then
                Try
                    bitmap.Save(strFileName, System.Drawing.Imaging.ImageFormat.Png)
                Catch ex As Exception
                    MessageBox.Show(Me, "Save Image File Error", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error)
                End Try
                bitmap.Dispose()
            End If
        End If

        Return
    End Sub

    Private Sub OnClickBtnShowHistgram(sender As Object, e As EventArgs) Handles btnShowHistgram.Click
        If (m_bitmap Is Nothing) Then
            Return
        End If

        If (m_histgram IsNot Nothing) Then
            m_histgram.Close()
            m_histgram = Nothing
            m_histgram = New FormHistgram()
        End If

        m_histgram.BitmapOrg = New Bitmap(m_strOpenFileName).Clone()
        If (SelectGetBitmap(m_strCurImgName) IsNot Nothing) Then
            m_histgram.BitmapAfter = SelectGetBitmap(m_strCurImgName).Clone()
        End If
        m_histgram.DrawHistgram()
        m_histgram.IsOpen = True
        m_histgram.Show()

        Return
    End Sub

    Private Sub OnScrollSliderThresh(sender As Object, e As EventArgs) Handles sliderThresh.Scroll
        Dim trackBar As TrackBar = sender
        labelValue.Text = trackBar.Value.ToString()
    End Sub

    Private Sub OnSliderPreviewKeyUp(sender As Object, e As PreviewKeyDownEventArgs) Handles sliderThresh.PreviewKeyDown
        If (pictureBoxAfter.Image IsNot Nothing) Then
            ParamAjust()
        End If
    End Sub

    Private Sub OnSliderMouseUp(sender As Object, e As MouseEventArgs) Handles sliderThresh.MouseUp
        If (pictureBoxAfter.Image IsNot Nothing) Then
            ParamAjust()
        End If
    End Sub

    Private Async Sub ParamAjust()
        pictureBoxAfter.Image = Nothing

        btnFileSelect.Enabled = False
        btnAllClear.Enabled = False
        btnStart.Enabled = False
        menuMain.Enabled = False

        LoadImage()

        btnStop.Enabled = True
        btnSaveImage.Enabled = False
        Dim bResult As Boolean = Await TaskWorkImageProcessing()
        If (bResult) Then
            pictureBoxOriginal.ImageLocation = m_strOpenFileName
            pictureBoxAfter.Image = SelectGetBitmap(m_strCurImgName)

            btnSaveImage.Enabled = True

            m_histgram.BitmapOrg = New Bitmap(m_strOpenFileName).Clone()
            If (SelectGetBitmap(m_strCurImgName) IsNot Nothing) Then
                m_histgram.BitmapAfter = SelectGetBitmap(m_strCurImgName).Clone()
            End If
            If (m_histgram.IsOpen = True) Then
                m_histgram.DrawHistgram()
            End If
        End If
        Invoke(New Action(AddressOf SetButtonEnable))
        menuMain.Enabled = True
        btnShowHistgram.Enabled = True

        m_tokenSource = Nothing

        Return
    End Sub
End Class