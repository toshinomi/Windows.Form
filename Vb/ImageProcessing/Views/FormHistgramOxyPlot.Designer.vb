<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class FormHistgramOxyPlot
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
        Dim resources As System.ComponentModel.ComponentResourceManager = New System.ComponentModel.ComponentResourceManager(GetType(FormHistgramOxyPlot))
        Me.chart = New OxyPlot.WindowsForms.PlotView()
        Me.ContextMenuStrip1 = New System.Windows.Forms.ContextMenuStrip(Me.components)
        Me.SaveCsvToolStripMenuItem = New System.Windows.Forms.ToolStripMenuItem()
        Me.ContextMenuStrip1.SuspendLayout()
        Me.SuspendLayout()
        '
        'chart
        '
        Me.chart.Location = New System.Drawing.Point(12, 12)
        Me.chart.Name = "chart"
        Me.chart.PanCursor = System.Windows.Forms.Cursors.Hand
        Me.chart.Size = New System.Drawing.Size(776, 426)
        Me.chart.TabIndex = 0
        Me.chart.Text = "chart"
        Me.chart.ZoomHorizontalCursor = System.Windows.Forms.Cursors.SizeWE
        Me.chart.ZoomRectangleCursor = System.Windows.Forms.Cursors.SizeNWSE
        Me.chart.ZoomVerticalCursor = System.Windows.Forms.Cursors.SizeNS
        '
        'ContextMenuStrip1
        '
        Me.ContextMenuStrip1.Items.AddRange(New System.Windows.Forms.ToolStripItem() {Me.SaveCsvToolStripMenuItem})
        Me.ContextMenuStrip1.Name = "ContextMenuStrip1"
        Me.ContextMenuStrip1.Size = New System.Drawing.Size(128, 26)
        '
        'SaveCsvToolStripMenuItem
        '
        Me.SaveCsvToolStripMenuItem.Name = "SaveCsvToolStripMenuItem"
        Me.SaveCsvToolStripMenuItem.Size = New System.Drawing.Size(127, 22)
        Me.SaveCsvToolStripMenuItem.Text = "Save Csv..."
        '
        'FormHistgramOxyPlot
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 12.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.BackColor = System.Drawing.Color.LightSteelBlue
        Me.ClientSize = New System.Drawing.Size(800, 450)
        Me.ContextMenuStrip = Me.ContextMenuStrip1
        Me.Controls.Add(Me.chart)
        Me.Icon = CType(resources.GetObject("$this.Icon"), System.Drawing.Icon)
        Me.Name = "FormHistgramOxyPlot"
        Me.Text = "Histgram"
        Me.ContextMenuStrip1.ResumeLayout(False)
        Me.ResumeLayout(False)

    End Sub

    Friend WithEvents chart As OxyPlot.WindowsForms.PlotView
    Friend WithEvents ContextMenuStrip1 As ContextMenuStrip
    Friend WithEvents SaveCsvToolStripMenuItem As ToolStripMenuItem
End Class
