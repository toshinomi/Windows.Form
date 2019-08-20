<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class FormMain
    Inherits System.Windows.Forms.Form

    'フォームがコンポーネントの一覧をクリーンアップするために dispose をオーバーライドします。
    <System.Diagnostics.DebuggerNonUserCode()> _
    Protected Overrides Sub Dispose(ByVal disposing As Boolean)
        Try
            If disposing AndAlso components IsNot Nothing Then
                components.Dispose()
            End If
        Finally
            MyBase.Dispose(disposing)
        End Try
    End Sub

    'Windows フォーム デザイナーで必要です。
    Private components As System.ComponentModel.IContainer

    'メモ: 以下のプロシージャは Windows フォーム デザイナーで必要です。
    'Windows フォーム デザイナーを使用して変更できます。  
    'コード エディターを使って変更しないでください。
    <System.Diagnostics.DebuggerStepThrough()> _
    Private Sub InitializeComponent()
        Me.components = New System.ComponentModel.Container()
        Dim resources As System.ComponentModel.ComponentResourceManager = New System.ComponentModel.ComponentResourceManager(GetType(FormMain))
        Me.groupBoxProcessingInfo = New System.Windows.Forms.GroupBox()
        Me.labelTime = New System.Windows.Forms.Label()
        Me.labelTimeUnit = New System.Windows.Forms.Label()
        Me.textBoxTime = New System.Windows.Forms.TextBox()
        Me.toolTipBtnStop = New System.Windows.Forms.ToolTip(Me.components)
        Me.labelThresh = New System.Windows.Forms.Label()
        Me.toolTipBtnShowHistgram = New System.Windows.Forms.ToolTip(Me.components)
        Me.fileFToolStripMenuItem = New System.Windows.Forms.ToolStripMenuItem()
        Me.endXToolStripMenuItem = New System.Windows.Forms.ToolStripMenuItem()
        Me.labelValue = New System.Windows.Forms.Label()
        Me.sliderThresh = New System.Windows.Forms.TrackBar()
        Me.pictureBoxStatus = New System.Windows.Forms.PictureBox()
        Me.labelAfterImage = New System.Windows.Forms.Label()
        Me.pictureBoxAfter = New System.Windows.Forms.PictureBox()
        Me.labelOriginalImage = New System.Windows.Forms.Label()
        Me.settingOToolStripMenuItem = New System.Windows.Forms.ToolStripMenuItem()
        Me.imageProcessingToolStripMenuItem = New System.Windows.Forms.ToolStripMenuItem()
        Me.toolTipBtnSaveImage = New System.Windows.Forms.ToolTip(Me.components)
        Me.menuMain = New System.Windows.Forms.MenuStrip()
        Me.pictureBoxOriginal = New System.Windows.Forms.PictureBox()
        Me.toolTipBtnAllClear = New System.Windows.Forms.ToolTip(Me.components)
        Me.toolTipBtnFileSelect = New System.Windows.Forms.ToolTip(Me.components)
        Me.groupBoxImageOutput = New System.Windows.Forms.GroupBox()
        Me.btnShowHistgram = New System.Windows.Forms.Button()
        Me.btnSaveImage = New System.Windows.Forms.Button()
        Me.btnStop = New System.Windows.Forms.Button()
        Me.btnAllClear = New System.Windows.Forms.Button()
        Me.btnStart = New System.Windows.Forms.Button()
        Me.groupBoxOperation = New System.Windows.Forms.GroupBox()
        Me.btnFileSelect = New System.Windows.Forms.Button()
        Me.toolTipBtnStart = New System.Windows.Forms.ToolTip(Me.components)
        Me.groupBoxProcessingInfo.SuspendLayout()
        CType(Me.sliderThresh, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.pictureBoxStatus, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.pictureBoxAfter, System.ComponentModel.ISupportInitialize).BeginInit()
        Me.menuMain.SuspendLayout()
        CType(Me.pictureBoxOriginal, System.ComponentModel.ISupportInitialize).BeginInit()
        Me.groupBoxImageOutput.SuspendLayout()
        Me.groupBoxOperation.SuspendLayout()
        Me.SuspendLayout()
        '
        'groupBoxProcessingInfo
        '
        Me.groupBoxProcessingInfo.Controls.Add(Me.labelTime)
        Me.groupBoxProcessingInfo.Controls.Add(Me.labelTimeUnit)
        Me.groupBoxProcessingInfo.Controls.Add(Me.textBoxTime)
        Me.groupBoxProcessingInfo.Font = New System.Drawing.Font("MS UI Gothic", 15.75!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(128, Byte))
        Me.groupBoxProcessingInfo.Location = New System.Drawing.Point(12, 486)
        Me.groupBoxProcessingInfo.Name = "groupBoxProcessingInfo"
        Me.groupBoxProcessingInfo.Size = New System.Drawing.Size(249, 113)
        Me.groupBoxProcessingInfo.TabIndex = 5
        Me.groupBoxProcessingInfo.TabStop = False
        Me.groupBoxProcessingInfo.Text = "Processing Infomation"
        '
        'labelTime
        '
        Me.labelTime.AutoSize = True
        Me.labelTime.Location = New System.Drawing.Point(37, 32)
        Me.labelTime.Name = "labelTime"
        Me.labelTime.Size = New System.Drawing.Size(52, 21)
        Me.labelTime.TabIndex = 3
        Me.labelTime.Text = "Time"
        '
        'labelTimeUnit
        '
        Me.labelTimeUnit.AutoSize = True
        Me.labelTimeUnit.Location = New System.Drawing.Point(208, 63)
        Me.labelTimeUnit.Name = "labelTimeUnit"
        Me.labelTimeUnit.Size = New System.Drawing.Size(35, 21)
        Me.labelTimeUnit.TabIndex = 5
        Me.labelTimeUnit.Text = "ms"
        '
        'textBoxTime
        '
        Me.textBoxTime.Location = New System.Drawing.Point(41, 56)
        Me.textBoxTime.Name = "textBoxTime"
        Me.textBoxTime.ReadOnly = True
        Me.textBoxTime.Size = New System.Drawing.Size(154, 28)
        Me.textBoxTime.TabIndex = 4
        Me.textBoxTime.TextAlign = System.Windows.Forms.HorizontalAlignment.Right
        '
        'labelThresh
        '
        Me.labelThresh.Font = New System.Drawing.Font("MS UI Gothic", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(128, Byte))
        Me.labelThresh.Location = New System.Drawing.Point(653, 26)
        Me.labelThresh.Name = "labelThresh"
        Me.labelThresh.Size = New System.Drawing.Size(150, 28)
        Me.labelThresh.TabIndex = 10
        Me.labelThresh.Text = "Threshold( 0 - 255 )"
        Me.labelThresh.TextAlign = System.Drawing.ContentAlignment.MiddleLeft
        '
        'fileFToolStripMenuItem
        '
        Me.fileFToolStripMenuItem.DropDownItems.AddRange(New System.Windows.Forms.ToolStripItem() {Me.endXToolStripMenuItem})
        Me.fileFToolStripMenuItem.Name = "fileFToolStripMenuItem"
        Me.fileFToolStripMenuItem.Size = New System.Drawing.Size(51, 20)
        Me.fileFToolStripMenuItem.Text = "File(&F)"
        '
        'endXToolStripMenuItem
        '
        Me.endXToolStripMenuItem.Name = "endXToolStripMenuItem"
        Me.endXToolStripMenuItem.Size = New System.Drawing.Size(109, 22)
        Me.endXToolStripMenuItem.Text = "End(&X)"
        '
        'labelValue
        '
        Me.labelValue.Font = New System.Drawing.Font("MS UI Gothic", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(128, Byte))
        Me.labelValue.Location = New System.Drawing.Point(998, 26)
        Me.labelValue.Name = "labelValue"
        Me.labelValue.Size = New System.Drawing.Size(40, 28)
        Me.labelValue.TabIndex = 9
        Me.labelValue.Text = "0"
        Me.labelValue.TextAlign = System.Drawing.ContentAlignment.MiddleLeft
        '
        'sliderThresh
        '
        Me.sliderThresh.AutoSize = False
        Me.sliderThresh.Location = New System.Drawing.Point(809, 28)
        Me.sliderThresh.Maximum = 255
        Me.sliderThresh.Name = "sliderThresh"
        Me.sliderThresh.Size = New System.Drawing.Size(183, 28)
        Me.sliderThresh.TabIndex = 8
        '
        'pictureBoxStatus
        '
        Me.pictureBoxStatus.Image = CType(resources.GetObject("pictureBoxStatus.Image"), System.Drawing.Image)
        Me.pictureBoxStatus.Location = New System.Drawing.Point(696, 180)
        Me.pictureBoxStatus.Name = "pictureBoxStatus"
        Me.pictureBoxStatus.Size = New System.Drawing.Size(202, 200)
        Me.pictureBoxStatus.TabIndex = 7
        Me.pictureBoxStatus.TabStop = False
        '
        'labelAfterImage
        '
        Me.labelAfterImage.AutoSize = True
        Me.labelAfterImage.Font = New System.Drawing.Font("MS UI Gothic", 15.75!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(128, Byte))
        Me.labelAfterImage.Location = New System.Drawing.Point(536, 28)
        Me.labelAfterImage.Name = "labelAfterImage"
        Me.labelAfterImage.Size = New System.Drawing.Size(111, 21)
        Me.labelAfterImage.TabIndex = 1
        Me.labelAfterImage.Text = "After Image"
        '
        'pictureBoxAfter
        '
        Me.pictureBoxAfter.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D
        Me.pictureBoxAfter.Location = New System.Drawing.Point(540, 63)
        Me.pictureBoxAfter.Name = "pictureBoxAfter"
        Me.pictureBoxAfter.Size = New System.Drawing.Size(498, 456)
        Me.pictureBoxAfter.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom
        Me.pictureBoxAfter.TabIndex = 6
        Me.pictureBoxAfter.TabStop = False
        '
        'labelOriginalImage
        '
        Me.labelOriginalImage.AutoSize = True
        Me.labelOriginalImage.Font = New System.Drawing.Font("MS UI Gothic", 15.75!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(128, Byte))
        Me.labelOriginalImage.Location = New System.Drawing.Point(19, 28)
        Me.labelOriginalImage.Name = "labelOriginalImage"
        Me.labelOriginalImage.Size = New System.Drawing.Size(132, 21)
        Me.labelOriginalImage.TabIndex = 0
        Me.labelOriginalImage.Text = "Original Image"
        '
        'settingOToolStripMenuItem
        '
        Me.settingOToolStripMenuItem.DropDownItems.AddRange(New System.Windows.Forms.ToolStripItem() {Me.imageProcessingToolStripMenuItem})
        Me.settingOToolStripMenuItem.Name = "settingOToolStripMenuItem"
        Me.settingOToolStripMenuItem.Size = New System.Drawing.Size(73, 20)
        Me.settingOToolStripMenuItem.Text = "Setting(&O)"
        '
        'imageProcessingToolStripMenuItem
        '
        Me.imageProcessingToolStripMenuItem.Name = "imageProcessingToolStripMenuItem"
        Me.imageProcessingToolStripMenuItem.Size = New System.Drawing.Size(180, 22)
        Me.imageProcessingToolStripMenuItem.Text = "Image Processing"
        '
        'menuMain
        '
        Me.menuMain.Items.AddRange(New System.Windows.Forms.ToolStripItem() {Me.fileFToolStripMenuItem, Me.settingOToolStripMenuItem})
        Me.menuMain.Location = New System.Drawing.Point(0, 0)
        Me.menuMain.Name = "menuMain"
        Me.menuMain.Size = New System.Drawing.Size(1344, 24)
        Me.menuMain.TabIndex = 7
        Me.menuMain.Text = "menuStrip1"
        '
        'pictureBoxOriginal
        '
        Me.pictureBoxOriginal.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D
        Me.pictureBoxOriginal.Location = New System.Drawing.Point(23, 63)
        Me.pictureBoxOriginal.Name = "pictureBoxOriginal"
        Me.pictureBoxOriginal.Size = New System.Drawing.Size(498, 456)
        Me.pictureBoxOriginal.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom
        Me.pictureBoxOriginal.TabIndex = 4
        Me.pictureBoxOriginal.TabStop = False
        '
        'groupBoxImageOutput
        '
        Me.groupBoxImageOutput.Controls.Add(Me.labelThresh)
        Me.groupBoxImageOutput.Controls.Add(Me.labelValue)
        Me.groupBoxImageOutput.Controls.Add(Me.sliderThresh)
        Me.groupBoxImageOutput.Controls.Add(Me.pictureBoxStatus)
        Me.groupBoxImageOutput.Controls.Add(Me.labelAfterImage)
        Me.groupBoxImageOutput.Controls.Add(Me.pictureBoxAfter)
        Me.groupBoxImageOutput.Controls.Add(Me.labelOriginalImage)
        Me.groupBoxImageOutput.Controls.Add(Me.pictureBoxOriginal)
        Me.groupBoxImageOutput.Font = New System.Drawing.Font("MS UI Gothic", 15.75!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(128, Byte))
        Me.groupBoxImageOutput.Location = New System.Drawing.Point(267, 60)
        Me.groupBoxImageOutput.Name = "groupBoxImageOutput"
        Me.groupBoxImageOutput.Size = New System.Drawing.Size(1065, 539)
        Me.groupBoxImageOutput.TabIndex = 6
        Me.groupBoxImageOutput.TabStop = False
        Me.groupBoxImageOutput.Text = "Image Output"
        '
        'btnShowHistgram
        '
        Me.btnShowHistgram.BackColor = System.Drawing.Color.White
        Me.btnShowHistgram.FlatStyle = System.Windows.Forms.FlatStyle.Popup
        Me.btnShowHistgram.Font = New System.Drawing.Font("MS UI Gothic", 15.75!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(128, Byte))
        Me.btnShowHistgram.Location = New System.Drawing.Point(29, 328)
        Me.btnShowHistgram.Name = "btnShowHistgram"
        Me.btnShowHistgram.Size = New System.Drawing.Size(192, 40)
        Me.btnShowHistgram.TabIndex = 6
        Me.btnShowHistgram.Text = "Show Histgram..."
        Me.btnShowHistgram.UseVisualStyleBackColor = False
        '
        'btnSaveImage
        '
        Me.btnSaveImage.BackColor = System.Drawing.Color.White
        Me.btnSaveImage.FlatStyle = System.Windows.Forms.FlatStyle.Popup
        Me.btnSaveImage.Font = New System.Drawing.Font("MS UI Gothic", 15.75!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(128, Byte))
        Me.btnSaveImage.Location = New System.Drawing.Point(29, 272)
        Me.btnSaveImage.Name = "btnSaveImage"
        Me.btnSaveImage.Size = New System.Drawing.Size(192, 40)
        Me.btnSaveImage.TabIndex = 5
        Me.btnSaveImage.Text = "Save Image..."
        Me.btnSaveImage.UseVisualStyleBackColor = False
        '
        'btnStop
        '
        Me.btnStop.BackColor = System.Drawing.Color.White
        Me.btnStop.Enabled = False
        Me.btnStop.FlatStyle = System.Windows.Forms.FlatStyle.Popup
        Me.btnStop.Font = New System.Drawing.Font("MS UI Gothic", 15.75!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(128, Byte))
        Me.btnStop.Location = New System.Drawing.Point(29, 217)
        Me.btnStop.Name = "btnStop"
        Me.btnStop.Size = New System.Drawing.Size(192, 40)
        Me.btnStop.TabIndex = 4
        Me.btnStop.Text = "Stop"
        Me.btnStop.UseVisualStyleBackColor = False
        '
        'btnAllClear
        '
        Me.btnAllClear.BackColor = System.Drawing.Color.White
        Me.btnAllClear.FlatStyle = System.Windows.Forms.FlatStyle.Popup
        Me.btnAllClear.Font = New System.Drawing.Font("MS UI Gothic", 15.75!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(128, Byte))
        Me.btnAllClear.Location = New System.Drawing.Point(29, 102)
        Me.btnAllClear.Name = "btnAllClear"
        Me.btnAllClear.Size = New System.Drawing.Size(192, 40)
        Me.btnAllClear.TabIndex = 1
        Me.btnAllClear.Text = "All Clear"
        Me.btnAllClear.UseVisualStyleBackColor = False
        '
        'btnStart
        '
        Me.btnStart.BackColor = System.Drawing.Color.White
        Me.btnStart.Enabled = False
        Me.btnStart.FlatStyle = System.Windows.Forms.FlatStyle.Popup
        Me.btnStart.Font = New System.Drawing.Font("MS UI Gothic", 15.75!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(128, Byte))
        Me.btnStart.Location = New System.Drawing.Point(29, 157)
        Me.btnStart.Name = "btnStart"
        Me.btnStart.Size = New System.Drawing.Size(192, 40)
        Me.btnStart.TabIndex = 2
        Me.btnStart.Text = "Start" & Global.Microsoft.VisualBasic.ChrW(13) & Global.Microsoft.VisualBasic.ChrW(10)
        Me.btnStart.UseVisualStyleBackColor = False
        '
        'groupBoxOperation
        '
        Me.groupBoxOperation.Controls.Add(Me.btnShowHistgram)
        Me.groupBoxOperation.Controls.Add(Me.btnSaveImage)
        Me.groupBoxOperation.Controls.Add(Me.btnStop)
        Me.groupBoxOperation.Controls.Add(Me.btnAllClear)
        Me.groupBoxOperation.Controls.Add(Me.btnStart)
        Me.groupBoxOperation.Controls.Add(Me.btnFileSelect)
        Me.groupBoxOperation.Font = New System.Drawing.Font("MS UI Gothic", 15.75!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(128, Byte))
        Me.groupBoxOperation.Location = New System.Drawing.Point(12, 60)
        Me.groupBoxOperation.Name = "groupBoxOperation"
        Me.groupBoxOperation.Size = New System.Drawing.Size(249, 408)
        Me.groupBoxOperation.TabIndex = 4
        Me.groupBoxOperation.TabStop = False
        Me.groupBoxOperation.Text = "Operation"
        '
        'btnFileSelect
        '
        Me.btnFileSelect.BackColor = System.Drawing.Color.White
        Me.btnFileSelect.FlatStyle = System.Windows.Forms.FlatStyle.Popup
        Me.btnFileSelect.Font = New System.Drawing.Font("MS UI Gothic", 15.75!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(128, Byte))
        Me.btnFileSelect.Location = New System.Drawing.Point(29, 47)
        Me.btnFileSelect.Name = "btnFileSelect"
        Me.btnFileSelect.Size = New System.Drawing.Size(192, 40)
        Me.btnFileSelect.TabIndex = 0
        Me.btnFileSelect.Text = "File Select..."
        Me.btnFileSelect.UseVisualStyleBackColor = False
        '
        'FormMain
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 12.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.BackColor = System.Drawing.Color.LightSteelBlue
        Me.ClientSize = New System.Drawing.Size(1344, 611)
        Me.Controls.Add(Me.groupBoxProcessingInfo)
        Me.Controls.Add(Me.menuMain)
        Me.Controls.Add(Me.groupBoxImageOutput)
        Me.Controls.Add(Me.groupBoxOperation)
        Me.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle
        Me.Icon = CType(resources.GetObject("$this.Icon"), System.Drawing.Icon)
        Me.MaximizeBox = False
        Me.Name = "FormMain"
        Me.Text = "Image Processing"
        Me.groupBoxProcessingInfo.ResumeLayout(False)
        Me.groupBoxProcessingInfo.PerformLayout()
        CType(Me.sliderThresh, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.pictureBoxStatus, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.pictureBoxAfter, System.ComponentModel.ISupportInitialize).EndInit()
        Me.menuMain.ResumeLayout(False)
        Me.menuMain.PerformLayout()
        CType(Me.pictureBoxOriginal, System.ComponentModel.ISupportInitialize).EndInit()
        Me.groupBoxImageOutput.ResumeLayout(False)
        Me.groupBoxImageOutput.PerformLayout()
        Me.groupBoxOperation.ResumeLayout(False)
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub

    Private WithEvents groupBoxProcessingInfo As GroupBox
    Private WithEvents labelTime As Label
    Private WithEvents labelTimeUnit As Label
    Private WithEvents textBoxTime As TextBox
    Private WithEvents toolTipBtnStop As ToolTip
    Private WithEvents labelThresh As Label
    Private WithEvents toolTipBtnShowHistgram As ToolTip
    Private WithEvents fileFToolStripMenuItem As ToolStripMenuItem
    Private WithEvents endXToolStripMenuItem As ToolStripMenuItem
    Private WithEvents labelValue As Label
    Private WithEvents sliderThresh As TrackBar
    Private WithEvents pictureBoxStatus As PictureBox
    Private WithEvents labelAfterImage As Label
    Private WithEvents pictureBoxAfter As PictureBox
    Private WithEvents labelOriginalImage As Label
    Private WithEvents settingOToolStripMenuItem As ToolStripMenuItem
    Private WithEvents imageProcessingToolStripMenuItem As ToolStripMenuItem
    Private WithEvents toolTipBtnSaveImage As ToolTip
    Private WithEvents menuMain As MenuStrip
    Private WithEvents pictureBoxOriginal As PictureBox
    Private WithEvents toolTipBtnAllClear As ToolTip
    Private WithEvents toolTipBtnFileSelect As ToolTip
    Private WithEvents groupBoxImageOutput As GroupBox
    Private WithEvents btnShowHistgram As Button
    Private WithEvents btnSaveImage As Button
    Private WithEvents btnStop As Button
    Private WithEvents btnAllClear As Button
    Private WithEvents btnStart As Button
    Private WithEvents groupBoxOperation As GroupBox
    Private WithEvents btnFileSelect As Button
    Private WithEvents toolTipBtnStart As ToolTip
End Class
