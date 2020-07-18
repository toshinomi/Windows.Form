Imports System.Threading

''' <summary>
''' MainFormのロジック
''' </summary>
Public Class FormMain
    Private mBitmap As Bitmap
    Private mImageProcessing As ImageProcessing
    Private mOpenFileName As String
    Private mTokenSource As CancellationTokenSource
    Private mCurrentImageProcessingName As String
#If CHART_LIVE_CHART Then
    Private mHistgram As FormHistgramLiveCharts
#ElseIf CHART_OXY_PLOT Then
    private mHistgram As FormHistgramOxyPlot
#Else
    Private mHistgram As FormHistgramOxyPlot
#End If

    ''' <summary>
    ''' コンストラクタ
    ''' </summary>
    Public Sub New()

        ' この呼び出しはデザイナーで必要です。
        InitializeComponent()

        ' InitializeComponent() 呼び出しの後で初期化を追加します。

        btnFileSelect.Enabled = True
        btnAllClear.Enabled = True
        btnStart.Enabled = False
        btnStop.Enabled = False
        btnSaveImage.Enabled = False

        pictureBoxStatus.Visible = False

        SetToolTip()

        mBitmap = Nothing
        mTokenSource = Nothing
        mImageProcessing = Nothing

        mCurrentImageProcessingName = My.Settings.ImgTypeSelectName
        Me.Text = "Image Processing ( " + mCurrentImageProcessingName + " )"

        sliderThresh.Enabled = If(mCurrentImageProcessingName = ComInfo.IMG_NAME_BINARIZATION, True, False)
    End Sub

    ''' <summary>
    ''' デスクトラクタ
    ''' </summary>
    Protected Overrides Sub Finalize()
        mBitmap = Nothing
        mTokenSource = Nothing
        mImageProcessing = Nothing

        MyBase.Finalize()
    End Sub

    ''' <summary>
    ''' 対象の画像処理オブジェクトからWriteableBitmapを取得する
    ''' </summary>
    ''' <returns>Writeableなビットマップ</returns>
    Public Function GetBitmap() As Bitmap
        Return mImageProcessing.Bitmap
    End Function

    ''' <summary>
    ''' 対象の画像処理オブジェクトを実行する
    ''' </summary>
    ''' <param name="comImageProcessingInfo">画像処理の設定</param>
    ''' <param name="token">キャンセルトークン</param>
    ''' <returns>画像処理の実行結果 成功/失敗</returns>
    Public Function GoImageProcessing(comImageProcessingInfo As ComImageProcessingInfo, token As CancellationToken) As Boolean
        mImageProcessing.Thresh = comImageProcessingInfo.BinarizationInfo.Thresh
        Dim result = mImageProcessing.GoImageProcessing(mCurrentImageProcessingName, token)

        Return result
    End Function

    ''' <summary>
    ''' ツールチップの設定
    ''' </summary>
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

    ''' <summary>
    ''' ボタンのEnableを制御する
    ''' </summary>
    Public Sub SetButtonEnable()
        btnFileSelect.Enabled = True
        btnAllClear.Enabled = True
        btnStart.Enabled = True
        btnStop.Enabled = False

        Return
    End Sub

    ''' <summary>
    ''' 時間を表示するテキストボックスに時間を設定する
    ''' </summary>
    Public Sub SetTextTime(_lTime As Long)
        textBoxTime.Text = _lTime.ToString()

        Return
    End Sub

    ''' <summary>
    ''' 画像処理の実行中に表示する画像をOFFする
    ''' </summary>
    Public Sub SetPictureBoxStatus()
        pictureBoxStatus.Visible = False

        Return
    End Sub

    ''' <summary>
    ''' 画像処理実行用のタスク
    ''' </summary>
    ''' <returns>画像処理の実行結果 成功/失敗</returns>
    Public Function TaskWorkImageProcessing()
        mTokenSource = New CancellationTokenSource()
        Dim token = mTokenSource.Token
        Dim imageProcessingInfo = New ComImageProcessingInfo()
        Dim binarizationInfo = New BinarizationInfo()
        binarizationInfo.Thresh = sliderThresh.Value
        imageProcessingInfo.CurrentImageProcessingName = mCurrentImageProcessingName
        imageProcessingInfo.BinarizationInfo = binarizationInfo
        Dim result As Task(Of Boolean) = Task.Run(Function() GoImageProcessing(imageProcessingInfo, token))
        Return result
    End Function

    ''' <summary>
    ''' イメージのロード処理
    ''' </summary>
    Public Sub LoadImage()
        mBitmap = New Bitmap(mOpenFileName)
        mImageProcessing = New ImageProcessing(mBitmap)

        Return
    End Sub

    ''' <summary>
    ''' Formのクローズイベント
    ''' </summary>
    ''' <param name="sender">オブジェクト</param>
    ''' <param name="e">FormClosingイベントのデータ</param>
    Public Sub OnFormClosingFormMain(sender As Object, e As FormClosingEventArgs) Handles MyBase.FormClosing
        If (mTokenSource IsNot Nothing) Then
            e.Cancel = True
        End If

        If (mHistgram IsNot Nothing) Then
            mHistgram.Close()
            mHistgram = Nothing
        End If
        Return
    End Sub

    ''' <summary>
    ''' ファイル選択ボタンのクリックイベント
    ''' </summary>
    ''' <param name="sender">オブジェクト</param>
    ''' <param name="e">イベントのデータ</param>
    Private Sub OnClickBtnFileSelect(sender As Object, e As EventArgs) Handles btnFileSelect.Click
        Dim openFileDlg = New ComOpenFileDialog()
        openFileDlg.Filter = "JPG|*.jpg|PNG|*.png"
        openFileDlg.Title = "Open the file"
        If (openFileDlg.ShowDialog() = True) Then
            pictureBoxOriginal.Image = Nothing
            pictureBoxAfter.Image = Nothing
            mOpenFileName = openFileDlg.FileName
            Try
                LoadImage()
            Catch ex As Exception
                MessageBox.Show(Me, "Open File Error", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error)
                Return
            End Try
            pictureBoxOriginal.ImageLocation = mOpenFileName
            btnStart.Enabled = True
            textBoxTime.Text = ""

            If (mHistgram Is Nothing) Then
#If CHART_LIVE_CHART Then
                m_histgram = New FormHistgramLiveCharts()
#ElseIf CHART_OXY_PLOT Then
                m_histgram = New FormHistgramOxyPlot()
#Else
                mHistgram = New FormHistgramOxyPlot()
#End If
            Else
                mHistgram.Close()
                mHistgram = Nothing
#If CHART_LIVE_CHART Then
                mHistgram = New FormHistgramLiveCharts()
#ElseIf CHART_OXY_PLOT Then
                mHistgram = New FormHistgramOxyPlot()
#Else
                mHistgram = New FormHistgramOxyPlot()
#End If
            End If

            mHistgram.BitmapOrg = New Bitmap(mOpenFileName).Clone()
            If (GetBitmap() IsNot Nothing) Then
                mHistgram.BitmapAfter = DirectCast(GetBitmap().Clone(), Bitmap)
            End If
            mHistgram.DrawHistgram()
            mHistgram.IsOpen = True
            mHistgram.Show()
        End If
        Return
    End Sub

    ''' <summary>
    ''' オールクリアボタンのクリックイベント
    ''' </summary>
    ''' <param name="sender">オブジェクト</param>
    ''' <param name="e">イベントのデータ</param>
    Private Sub OnClickBtnAllClear(sender As Object, e As EventArgs) Handles btnAllClear.Click
        pictureBoxOriginal.ImageLocation = Nothing
        pictureBoxAfter.Image = Nothing

        mBitmap = Nothing
        mOpenFileName = ""

        textBoxTime.Text = ""

        btnFileSelect.Enabled = True
        btnAllClear.Enabled = True
        btnStart.Enabled = False
        btnSaveImage.Enabled = False

        If (mHistgram IsNot Nothing) Then
            mHistgram.Close()
        End If

        Return
    End Sub

    ''' <summary>
    ''' スタートボタンのクリックイベント
    ''' </summary>
    ''' <param name="sender">オブジェクト</param>
    ''' <param name="e">イベントのデータ</param>
    Private Async Sub OnClickBtnStart(sender As Object, e As EventArgs) Handles btnStart.Click
        pictureBoxAfter.Image = Nothing

        btnFileSelect.Enabled = False
        btnAllClear.Enabled = False
        btnStart.Enabled = False
        menuMain.Enabled = False

        textBoxTime.Text = ""

        pictureBoxStatus.Visible = True

        LoadImage()

        Dim Stopwatch = New Stopwatch()
        Stopwatch.Start()
        btnStop.Enabled = True
        btnSaveImage.Enabled = False
        btnShowHistgram.Enabled = False
        Dim bResult As Boolean = Await TaskWorkImageProcessing()
        If (bResult) Then
            pictureBoxOriginal.ImageLocation = mOpenFileName
            pictureBoxAfter.Image = GetBitmap()

            Stopwatch.Stop()

            Invoke(New Action(Of Long)(AddressOf SetTextTime), Stopwatch.ElapsedMilliseconds)
            btnSaveImage.Enabled = True

            mHistgram.BitmapOrg = New Bitmap(mOpenFileName).Clone()
            If (GetBitmap() IsNot Nothing) Then
                mHistgram.BitmapAfter = DirectCast(GetBitmap().Clone(), Bitmap)
            End If
            If (mHistgram.IsOpen = True) Then
                mHistgram.DrawHistgram()
            End If
        End If
        Invoke(New Action(AddressOf SetPictureBoxStatus))
        Invoke(New Action(AddressOf SetButtonEnable))
        menuMain.Enabled = True
        btnShowHistgram.Enabled = True

        Stopwatch = Nothing
        mTokenSource = Nothing

        Return
    End Sub

    ''' <summary>
    ''' ストップボタンのクリックイベント
    ''' </summary>
    ''' <param name="sender">オブジェクト</param>
    ''' <param name="e">イベントのデータ</param>
    Private Sub OnClickBtnStop(sender As Object, e As EventArgs) Handles btnStop.Click
        If (mTokenSource IsNot Nothing) Then
            mTokenSource.Cancel()
        End If

        Return
    End Sub

    ''' <summary>
    ''' イメージの保存ボタンのクリックイベント
    ''' </summary>
    ''' <param name="sender">オブジェクト</param>
    ''' <param name="e">イベントのデータ</param>
    Private Sub OnClickBtnSaveImage(sender As Object, e As EventArgs) Handles btnSaveImage.Click
        Dim saveDialog = New ComSaveFileDialog()
        saveDialog.Filter = "PNG|*.png"
        saveDialog.Title = "Save the file"
        If (saveDialog.ShowDialog() = True) Then
            Dim fileName = saveDialog.FileName
            Dim bitmap As Bitmap = GetBitmap().Clone
            If (bitmap IsNot Nothing) Then
                Try
                    bitmap.Save(fileName, System.Drawing.Imaging.ImageFormat.Png)
                Catch ex As Exception
                    MessageBox.Show(Me, "Save Image File Error", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error)
                End Try
                bitmap.Dispose()
            End If
        End If

        Return
    End Sub

    ''' <summary>
    ''' ヒストグラム表示ボタンのクリックイベント
    ''' </summary>
    ''' <param name="sender">オブジェクト</param>
    ''' <param name="e">イベントのデータ</param>
    Private Sub OnClickBtnShowHistgram(sender As Object, e As EventArgs) Handles btnShowHistgram.Click
        If (mBitmap Is Nothing) Then
            Return
        End If

        If (mHistgram IsNot Nothing) Then
            mHistgram.Close()
            mHistgram = Nothing
#If CHART_LIVE_CHART Then
            mHistgram = New FormHistgramLiveCharts()
#ElseIf CHART_OXY_PLOT Then
            mHistgram = New FormHistgramOxyPlot()
#Else
            mHistgram = New FormHistgramOxyPlot()
#End If
        End If

        mHistgram.BitmapOrg = New Bitmap(mOpenFileName).Clone()
        If (GetBitmap() IsNot Nothing) Then
            mHistgram.BitmapAfter = DirectCast(GetBitmap().Clone(), Bitmap)
        End If
        mHistgram.DrawHistgram()
        mHistgram.IsOpen = True
        mHistgram.Show()

        Return
    End Sub

    ''' <summary>
    ''' メニューのクリックイベント
    ''' </summary>
    ''' <param name="sender">オブジェクト</param>
    ''' <param name="e">イベントのデータ</param>
    Private Sub OnClickMenu(sender As Object, e As EventArgs) Handles imageProcessingToolStripMenuItem.Click, endXToolStripMenuItem.Click
        Dim menuItem = DirectCast(sender, ToolStripItem)

        Select Case menuItem.Text
            Case ComInfo.MENU_FILE_END
                Close()
            Case ComInfo.MENU_SETTING_IMAGE_PROCESSING
                ShowSettingImageProcessing()
            Case Else
        End Select
    End Sub

    ''' <summary>
    ''' 設定画面の処理
    ''' </summary>
    Public Sub ShowSettingImageProcessing()
        Dim win = New FormSettingImageProcessing()
        Dim dialogResult = win.ShowDialog()

        If (dialogResult = DialogResult.OK) Then
            mCurrentImageProcessingName = win.ComboBoxImageProcessingType.SelectedItem
            Me.Text = "Image Processing ( " + mCurrentImageProcessingName + " )"

            sliderThresh.Enabled = If(mCurrentImageProcessingName = ComInfo.IMG_NAME_BINARIZATION, True, False)

            pictureBoxAfter.Image = Nothing
            btnSaveImage.Enabled = False
            If (mOpenFileName IsNot Nothing) Then
                mBitmap = New Bitmap(mOpenFileName)
                mImageProcessing = New ImageProcessing(mBitmap)
            End If
            If (mHistgram IsNot Nothing And mHistgram?.IsOpen = True) Then
                OnClickBtnShowHistgram(Me, Nothing)
            End If
        End If
    End Sub

    ''' <summary>
    ''' 2値化の閾値のスライダのスクロールイベント
    ''' </summary>
    ''' <param name="sender">オブジェクト</param>
    ''' <param name="e">イベントのデータ</param>
    Private Sub OnScrollSliderThresh(sender As Object, e As EventArgs) Handles sliderThresh.Scroll
        Dim trackBar = DirectCast(sender, TrackBar)
        labelValue.Text = trackBar.Value.ToString()
    End Sub

    ''' <summary>
    ''' 2値化の閾値のスライダのキーアップイベント
    ''' </summary>
    ''' <param name="sender">オブジェクト</param>
    ''' <param name="e">キーイベントのデータ</param>
    Private Sub OnSliderPreviewKeyUp(sender As Object, e As PreviewKeyDownEventArgs) Handles sliderThresh.PreviewKeyDown
        If (pictureBoxAfter.Image IsNot Nothing) Then
            ParamAjust()
        End If
    End Sub

    ''' <summary>
    ''' 2値化の閾値のスライダのマウスアップイベント
    ''' </summary>
    ''' <param name="sender">オブジェクト</param>
    ''' <param name="e">マウスボタンイベントのデータ</param>
    Private Sub OnSliderMouseUp(sender As Object, e As MouseEventArgs) Handles sliderThresh.MouseUp
        If (pictureBoxAfter.Image IsNot Nothing) Then
            ParamAjust()
        End If
    End Sub

    ''' <summary>
    ''' 2値化のスライダを調整したときの処理
    ''' </summary>
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
            pictureBoxOriginal.ImageLocation = mOpenFileName
            pictureBoxAfter.Image = GetBitmap()

            btnSaveImage.Enabled = True

            mHistgram.BitmapOrg = New Bitmap(mOpenFileName).Clone()
            If (GetBitmap() IsNot Nothing) Then
                mHistgram.BitmapAfter = DirectCast(GetBitmap().Clone(), Bitmap)
            End If
            If (mHistgram.IsOpen = True) Then
                mHistgram.DrawHistgram()
            End If
        End If
        Invoke(New Action(AddressOf SetButtonEnable))
        menuMain.Enabled = True
        btnShowHistgram.Enabled = True

        mTokenSource = Nothing

        Return
    End Sub
End Class