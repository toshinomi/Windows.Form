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
        Me.toolTipBtnStop = New System.Windows.Forms.ToolTip(Me.components)
        Me.labelTime = New System.Windows.Forms.Label()
        Me.labelTimeUnit = New System.Windows.Forms.Label()
        Me.groupBoxProcessingInfo = New System.Windows.Forms.GroupBox()
        Me.textBoxTime = New System.Windows.Forms.TextBox()
        Me.toolTipBtnStart = New System.Windows.Forms.ToolTip(Me.components)
        Me.toolTipBtnAllClear = New System.Windows.Forms.ToolTip(Me.components)
        Me.pictureBoxStatus = New System.Windows.Forms.PictureBox()
        Me.labelAfterImage = New System.Windows.Forms.Label()
        Me.pictureBoxAfter = New System.Windows.Forms.PictureBox()
        Me.toolTipBtnFileSelect = New System.Windows.Forms.ToolTip(Me.components)
        Me.labelOriginalImage = New System.Windows.Forms.Label()
        Me.groupBoxImageOutput = New System.Windows.Forms.GroupBox()
        Me.pictureBoxOriginal = New System.Windows.Forms.PictureBox()
        Me.btnStop = New System.Windows.Forms.Button()
        Me.btnAllClear = New System.Windows.Forms.Button()
        Me.btnStart = New System.Windows.Forms.Button()
        Me.groupBoxOperation = New System.Windows.Forms.GroupBox()
        Me.btnFileSelect = New System.Windows.Forms.Button()
        Me.groupBoxProcessingInfo.SuspendLayout()
        CType(Me.pictureBoxStatus, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.pictureBoxAfter, System.ComponentModel.ISupportInitialize).BeginInit()
        Me.groupBoxImageOutput.SuspendLayout()
        CType(Me.pictureBoxOriginal, System.ComponentModel.ISupportInitialize).BeginInit()
        Me.groupBoxOperation.SuspendLayout()
        Me.SuspendLayout()
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
        'groupBoxProcessingInfo
        '
        Me.groupBoxProcessingInfo.Controls.Add(Me.labelTime)
        Me.groupBoxProcessingInfo.Controls.Add(Me.labelTimeUnit)
        Me.groupBoxProcessingInfo.Controls.Add(Me.textBoxTime)
        Me.groupBoxProcessingInfo.Font = New System.Drawing.Font("MS UI Gothic", 15.75!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(128, Byte))
        Me.groupBoxProcessingInfo.Location = New System.Drawing.Point(12, 441)
        Me.groupBoxProcessingInfo.Name = "groupBoxProcessingInfo"
        Me.groupBoxProcessingInfo.Size = New System.Drawing.Size(249, 113)
        Me.groupBoxProcessingInfo.TabIndex = 4
        Me.groupBoxProcessingInfo.TabStop = False
        Me.groupBoxProcessingInfo.Text = "Processing Infomation"
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
        Me.labelAfterImage.Location = New System.Drawing.Point(536, 35)
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
        Me.labelOriginalImage.Location = New System.Drawing.Point(19, 35)
        Me.labelOriginalImage.Name = "labelOriginalImage"
        Me.labelOriginalImage.Size = New System.Drawing.Size(132, 21)
        Me.labelOriginalImage.TabIndex = 0
        Me.labelOriginalImage.Text = "Original Image"
        '
        'groupBoxImageOutput
        '
        Me.groupBoxImageOutput.Controls.Add(Me.pictureBoxStatus)
        Me.groupBoxImageOutput.Controls.Add(Me.labelAfterImage)
        Me.groupBoxImageOutput.Controls.Add(Me.pictureBoxAfter)
        Me.groupBoxImageOutput.Controls.Add(Me.labelOriginalImage)
        Me.groupBoxImageOutput.Controls.Add(Me.pictureBoxOriginal)
        Me.groupBoxImageOutput.Font = New System.Drawing.Font("MS UI Gothic", 15.75!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(128, Byte))
        Me.groupBoxImageOutput.Location = New System.Drawing.Point(267, 15)
        Me.groupBoxImageOutput.Name = "groupBoxImageOutput"
        Me.groupBoxImageOutput.Size = New System.Drawing.Size(1065, 539)
        Me.groupBoxImageOutput.TabIndex = 5
        Me.groupBoxImageOutput.TabStop = False
        Me.groupBoxImageOutput.Text = "Image Output"
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
        'btnStop
        '
        Me.btnStop.BackColor = System.Drawing.Color.White
        Me.btnStop.Enabled = False
        Me.btnStop.FlatStyle = System.Windows.Forms.FlatStyle.Popup
        Me.btnStop.Font = New System.Drawing.Font("MS UI Gothic", 15.75!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(128, Byte))
        Me.btnStop.Location = New System.Drawing.Point(41, 285)
        Me.btnStop.Name = "btnStop"
        Me.btnStop.Size = New System.Drawing.Size(154, 68)
        Me.btnStop.TabIndex = 4
        Me.btnStop.Text = "Stop"
        Me.btnStop.UseVisualStyleBackColor = False
        '
        'btnAllClear
        '
        Me.btnAllClear.BackColor = System.Drawing.Color.White
        Me.btnAllClear.FlatStyle = System.Windows.Forms.FlatStyle.Popup
        Me.btnAllClear.Font = New System.Drawing.Font("MS UI Gothic", 15.75!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(128, Byte))
        Me.btnAllClear.Location = New System.Drawing.Point(41, 120)
        Me.btnAllClear.Name = "btnAllClear"
        Me.btnAllClear.Size = New System.Drawing.Size(154, 68)
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
        Me.btnStart.Location = New System.Drawing.Point(41, 202)
        Me.btnStart.Name = "btnStart"
        Me.btnStart.Size = New System.Drawing.Size(154, 68)
        Me.btnStart.TabIndex = 2
        Me.btnStart.Text = "Start" & Global.Microsoft.VisualBasic.ChrW(13) & Global.Microsoft.VisualBasic.ChrW(10)
        Me.btnStart.UseVisualStyleBackColor = False
        '
        'groupBoxOperation
        '
        Me.groupBoxOperation.Controls.Add(Me.btnStop)
        Me.groupBoxOperation.Controls.Add(Me.btnAllClear)
        Me.groupBoxOperation.Controls.Add(Me.btnStart)
        Me.groupBoxOperation.Controls.Add(Me.btnFileSelect)
        Me.groupBoxOperation.Font = New System.Drawing.Font("MS UI Gothic", 15.75!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(128, Byte))
        Me.groupBoxOperation.Location = New System.Drawing.Point(12, 15)
        Me.groupBoxOperation.Name = "groupBoxOperation"
        Me.groupBoxOperation.Size = New System.Drawing.Size(249, 408)
        Me.groupBoxOperation.TabIndex = 3
        Me.groupBoxOperation.TabStop = False
        Me.groupBoxOperation.Text = "Operation"
        '
        'btnFileSelect
        '
        Me.btnFileSelect.BackColor = System.Drawing.Color.White
        Me.btnFileSelect.FlatStyle = System.Windows.Forms.FlatStyle.Popup
        Me.btnFileSelect.Font = New System.Drawing.Font("MS UI Gothic", 15.75!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(128, Byte))
        Me.btnFileSelect.Location = New System.Drawing.Point(41, 36)
        Me.btnFileSelect.Name = "btnFileSelect"
        Me.btnFileSelect.Size = New System.Drawing.Size(154, 68)
        Me.btnFileSelect.TabIndex = 0
        Me.btnFileSelect.Text = "File Select..."
        Me.btnFileSelect.UseVisualStyleBackColor = False
        '
        'FormMain
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 12.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.BackColor = System.Drawing.Color.LightSteelBlue
        Me.ClientSize = New System.Drawing.Size(1344, 569)
        Me.Controls.Add(Me.groupBoxProcessingInfo)
        Me.Controls.Add(Me.groupBoxImageOutput)
        Me.Controls.Add(Me.groupBoxOperation)
        Me.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle
        Me.Icon = CType(resources.GetObject("$this.Icon"), System.Drawing.Icon)
        Me.MaximizeBox = False
        Me.Name = "FormMain"
        Me.Text = "Image Processing"
        Me.groupBoxProcessingInfo.ResumeLayout(False)
        Me.groupBoxProcessingInfo.PerformLayout()
        CType(Me.pictureBoxStatus, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.pictureBoxAfter, System.ComponentModel.ISupportInitialize).EndInit()
        Me.groupBoxImageOutput.ResumeLayout(False)
        Me.groupBoxImageOutput.PerformLayout()
        CType(Me.pictureBoxOriginal, System.ComponentModel.ISupportInitialize).EndInit()
        Me.groupBoxOperation.ResumeLayout(False)
        Me.ResumeLayout(False)

    End Sub

    Private WithEvents toolTipBtnStop As ToolTip
    Private WithEvents labelTime As Label
    Private WithEvents labelTimeUnit As Label
    Private WithEvents groupBoxProcessingInfo As GroupBox
    Private WithEvents textBoxTime As TextBox
    Private WithEvents toolTipBtnStart As ToolTip
    Private WithEvents toolTipBtnAllClear As ToolTip
    Private WithEvents pictureBoxStatus As PictureBox
    Private WithEvents labelAfterImage As Label
    Private WithEvents pictureBoxAfter As PictureBox
    Private WithEvents toolTipBtnFileSelect As ToolTip
    Private WithEvents labelOriginalImage As Label
    Private WithEvents groupBoxImageOutput As GroupBox
    Private WithEvents pictureBoxOriginal As PictureBox
    Private WithEvents btnStop As Button
    Private WithEvents btnAllClear As Button
    Private WithEvents btnStart As Button
    Private WithEvents groupBoxOperation As GroupBox
    Private WithEvents btnFileSelect As Button
End Class
