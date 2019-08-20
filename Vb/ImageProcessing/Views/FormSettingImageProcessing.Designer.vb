<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class FormSettingImageProcessing
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
        Dim resources As System.ComponentModel.ComponentResourceManager = New System.ComponentModel.ComponentResourceManager(GetType(FormSettingImageProcessing))
        Me.btnOk = New System.Windows.Forms.Button()
        Me.btnCancel = New System.Windows.Forms.Button()
        Me.cmbBoxImageProcessingType = New System.Windows.Forms.ComboBox()
        Me.labelImageProcessingType = New System.Windows.Forms.Label()
        Me.SuspendLayout()
        '
        'btnOk
        '
        Me.btnOk.BackColor = System.Drawing.SystemColors.Window
        Me.btnOk.Font = New System.Drawing.Font("MS UI Gothic", 15.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(128, Byte))
        Me.btnOk.Location = New System.Drawing.Point(215, 213)
        Me.btnOk.Name = "btnOk"
        Me.btnOk.Size = New System.Drawing.Size(126, 37)
        Me.btnOk.TabIndex = 7
        Me.btnOk.Text = "OK"
        Me.btnOk.UseVisualStyleBackColor = False
        '
        'btnCancel
        '
        Me.btnCancel.BackColor = System.Drawing.SystemColors.Window
        Me.btnCancel.Font = New System.Drawing.Font("MS UI Gothic", 15.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(128, Byte))
        Me.btnCancel.Location = New System.Drawing.Point(347, 213)
        Me.btnCancel.Name = "btnCancel"
        Me.btnCancel.Size = New System.Drawing.Size(126, 37)
        Me.btnCancel.TabIndex = 6
        Me.btnCancel.Text = "Cancel"
        Me.btnCancel.UseVisualStyleBackColor = False
        '
        'cmbBoxImageProcessingType
        '
        Me.cmbBoxImageProcessingType.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList
        Me.cmbBoxImageProcessingType.Font = New System.Drawing.Font("MS UI Gothic", 15.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(128, Byte))
        Me.cmbBoxImageProcessingType.FormattingEnabled = True
        Me.cmbBoxImageProcessingType.Location = New System.Drawing.Point(229, 15)
        Me.cmbBoxImageProcessingType.Name = "cmbBoxImageProcessingType"
        Me.cmbBoxImageProcessingType.Size = New System.Drawing.Size(244, 28)
        Me.cmbBoxImageProcessingType.TabIndex = 5
        '
        'labelImageProcessingType
        '
        Me.labelImageProcessingType.Font = New System.Drawing.Font("MS UI Gothic", 15.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(128, Byte))
        Me.labelImageProcessingType.Location = New System.Drawing.Point(12, 10)
        Me.labelImageProcessingType.Margin = New System.Windows.Forms.Padding(5, 0, 5, 0)
        Me.labelImageProcessingType.Name = "labelImageProcessingType"
        Me.labelImageProcessingType.Size = New System.Drawing.Size(209, 36)
        Me.labelImageProcessingType.TabIndex = 4
        Me.labelImageProcessingType.Text = "Image Processing Type"
        Me.labelImageProcessingType.TextAlign = System.Drawing.ContentAlignment.MiddleLeft
        '
        'FormSettingImageProcessing
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 12.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.BackColor = System.Drawing.Color.LightSteelBlue
        Me.ClientSize = New System.Drawing.Size(484, 261)
        Me.Controls.Add(Me.btnOk)
        Me.Controls.Add(Me.btnCancel)
        Me.Controls.Add(Me.cmbBoxImageProcessingType)
        Me.Controls.Add(Me.labelImageProcessingType)
        Me.Icon = CType(resources.GetObject("$this.Icon"), System.Drawing.Icon)
        Me.Name = "FormSettingImageProcessing"
        Me.Text = "Setting Image Processing"
        Me.ResumeLayout(False)

    End Sub

    Private WithEvents btnOk As Button
    Private WithEvents btnCancel As Button
    Private WithEvents cmbBoxImageProcessingType As ComboBox
    Private WithEvents labelImageProcessingType As Label
End Class
