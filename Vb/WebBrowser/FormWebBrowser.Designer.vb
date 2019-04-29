<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()>
Partial Class FormWebBrowser
    Inherits System.Windows.Forms.Form

    'フォームがコンポーネントの一覧をクリーンアップするために dispose をオーバーライドします。
    <System.Diagnostics.DebuggerNonUserCode()>
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
    <System.Diagnostics.DebuggerStepThrough()>
    Private Sub InitializeComponent()
        Dim resources As System.ComponentModel.ComponentResourceManager = New System.ComponentModel.ComponentResourceManager(GetType(FormWebBrowser))
        Me.panelUrl = New System.Windows.Forms.Panel()
        Me.buttonRefresh = New System.Windows.Forms.Button()
        Me.buttonForward = New System.Windows.Forms.Button()
        Me.buttonBack = New System.Windows.Forms.Button()
        Me.labelUrl = New System.Windows.Forms.Label()
        Me.textUrl = New System.Windows.Forms.TextBox()
        Me.panelWebBrowser = New System.Windows.Forms.Panel()
        Me.webBrowser = New System.Windows.Forms.WebBrowser()
        Me.panelUrl.SuspendLayout()
        Me.panelWebBrowser.SuspendLayout()
        Me.SuspendLayout()
        '
        'panelUrl
        '
        Me.panelUrl.Controls.Add(Me.buttonRefresh)
        Me.panelUrl.Controls.Add(Me.buttonForward)
        Me.panelUrl.Controls.Add(Me.buttonBack)
        Me.panelUrl.Controls.Add(Me.labelUrl)
        Me.panelUrl.Controls.Add(Me.textUrl)
        Me.panelUrl.Dock = System.Windows.Forms.DockStyle.Top
        Me.panelUrl.Location = New System.Drawing.Point(0, 0)
        Me.panelUrl.Margin = New System.Windows.Forms.Padding(2)
        Me.panelUrl.Name = "panelUrl"
        Me.panelUrl.Size = New System.Drawing.Size(480, 45)
        Me.panelUrl.TabIndex = 0
        '
        'buttonRefresh
        '
        Me.buttonRefresh.Image = CType(resources.GetObject("buttonRefresh.Image"), System.Drawing.Image)
        Me.buttonRefresh.Location = New System.Drawing.Point(88, 0)
        Me.buttonRefresh.Margin = New System.Windows.Forms.Padding(2)
        Me.buttonRefresh.Name = "buttonRefresh"
        Me.buttonRefresh.Size = New System.Drawing.Size(45, 43)
        Me.buttonRefresh.TabIndex = 3
        Me.buttonRefresh.UseVisualStyleBackColor = True
        '
        'buttonForward
        '
        Me.buttonForward.Image = CType(resources.GetObject("buttonForward.Image"), System.Drawing.Image)
        Me.buttonForward.Location = New System.Drawing.Point(44, 0)
        Me.buttonForward.Margin = New System.Windows.Forms.Padding(2)
        Me.buttonForward.Name = "buttonForward"
        Me.buttonForward.Size = New System.Drawing.Size(45, 43)
        Me.buttonForward.TabIndex = 2
        Me.buttonForward.UseVisualStyleBackColor = True
        '
        'buttonBack
        '
        Me.buttonBack.Image = CType(resources.GetObject("buttonBack.Image"), System.Drawing.Image)
        Me.buttonBack.Location = New System.Drawing.Point(0, 0)
        Me.buttonBack.Margin = New System.Windows.Forms.Padding(2)
        Me.buttonBack.Name = "buttonBack"
        Me.buttonBack.Size = New System.Drawing.Size(45, 43)
        Me.buttonBack.TabIndex = 1
        Me.buttonBack.UseVisualStyleBackColor = True
        '
        'labelUrl
        '
        Me.labelUrl.AutoSize = True
        Me.labelUrl.Location = New System.Drawing.Point(136, 6)
        Me.labelUrl.Margin = New System.Windows.Forms.Padding(2, 0, 2, 0)
        Me.labelUrl.Name = "labelUrl"
        Me.labelUrl.Size = New System.Drawing.Size(27, 12)
        Me.labelUrl.TabIndex = 4
        Me.labelUrl.Text = "URL"
        '
        'textUrl
        '
        Me.textUrl.Anchor = CType(((System.Windows.Forms.AnchorStyles.Bottom Or System.Windows.Forms.AnchorStyles.Left) _
            Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles)
        Me.textUrl.Location = New System.Drawing.Point(136, 23)
        Me.textUrl.Margin = New System.Windows.Forms.Padding(2)
        Me.textUrl.Name = "textUrl"
        Me.textUrl.Size = New System.Drawing.Size(336, 19)
        Me.textUrl.TabIndex = 5
        Me.textUrl.Text = "https://www.bing.com/"
        '
        'panelWebBrowser
        '
        Me.panelWebBrowser.Controls.Add(Me.webBrowser)
        Me.panelWebBrowser.Dock = System.Windows.Forms.DockStyle.Fill
        Me.panelWebBrowser.Location = New System.Drawing.Point(0, 45)
        Me.panelWebBrowser.Margin = New System.Windows.Forms.Padding(2)
        Me.panelWebBrowser.Name = "panelWebBrowser"
        Me.panelWebBrowser.Size = New System.Drawing.Size(480, 255)
        Me.panelWebBrowser.TabIndex = 6
        '
        'webBrowser
        '
        Me.webBrowser.Dock = System.Windows.Forms.DockStyle.Fill
        Me.webBrowser.Location = New System.Drawing.Point(0, 0)
        Me.webBrowser.Margin = New System.Windows.Forms.Padding(2)
        Me.webBrowser.MinimumSize = New System.Drawing.Size(12, 13)
        Me.webBrowser.Name = "webBrowser"
        Me.webBrowser.ScriptErrorsSuppressed = True
        Me.webBrowser.Size = New System.Drawing.Size(480, 255)
        Me.webBrowser.TabIndex = 7
        '
        'FromWebBrowser
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 12.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(480, 300)
        Me.Controls.Add(Me.panelWebBrowser)
        Me.Controls.Add(Me.panelUrl)
        Me.Icon = CType(resources.GetObject("$this.Icon"), System.Drawing.Icon)
        Me.Name = "FromWebBrowser"
        Me.Text = "https://www.bing.com/"
        Me.panelUrl.ResumeLayout(False)
        Me.panelUrl.PerformLayout()
        Me.panelWebBrowser.ResumeLayout(False)
        Me.ResumeLayout(False)

    End Sub

    Friend WithEvents panelUrl As Panel
    Friend WithEvents panelWebBrowser As Panel
    Friend WithEvents textUrl As TextBox
    Friend WithEvents webBrowser As Windows.Forms.WebBrowser
    Friend WithEvents buttonBack As Button
    Friend WithEvents buttonForward As Button
    Friend WithEvents buttonRefresh As Button
    Friend WithEvents labelUrl As Label
End Class
