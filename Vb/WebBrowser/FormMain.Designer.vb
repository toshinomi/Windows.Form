<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()>
Partial Class FormMain
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
        Me.MenuStrip = New System.Windows.Forms.MenuStrip()
        Me.menuFile = New System.Windows.Forms.ToolStripMenuItem()
        Me.menuFile_NewOpen = New System.Windows.Forms.ToolStripMenuItem()
        Me.menuFile_End = New System.Windows.Forms.ToolStripMenuItem()
        Me.menuWindow = New System.Windows.Forms.ToolStripMenuItem()
        Me.menuWindow_Cascade = New System.Windows.Forms.ToolStripMenuItem()
        Me.menuWindow_TileHorizontal = New System.Windows.Forms.ToolStripMenuItem()
        Me.menuWindow_TileVertical = New System.Windows.Forms.ToolStripMenuItem()
        Me.MenuStrip.SuspendLayout()
        Me.SuspendLayout()
        '
        'MenuStrip
        '
        Me.MenuStrip.Items.AddRange(New System.Windows.Forms.ToolStripItem() {Me.menuFile, Me.menuWindow})
        Me.MenuStrip.Location = New System.Drawing.Point(0, 0)
        Me.MenuStrip.Name = "MenuStrip"
        Me.MenuStrip.Size = New System.Drawing.Size(480, 24)
        Me.MenuStrip.TabIndex = 1
        Me.MenuStrip.Text = "MenuStrip1"
        '
        'menuFile
        '
        Me.menuFile.DropDownItems.AddRange(New System.Windows.Forms.ToolStripItem() {Me.menuFile_NewOpen, Me.menuFile_End})
        Me.menuFile.Name = "menuFile"
        Me.menuFile.Size = New System.Drawing.Size(67, 20)
        Me.menuFile.Text = "ファイル(&F)"
        '
        'menuFile_NewOpen
        '
        Me.menuFile_NewOpen.Name = "menuFile_NewOpen"
        Me.menuFile_NewOpen.ShortcutKeys = CType((System.Windows.Forms.Keys.Control Or System.Windows.Forms.Keys.N), System.Windows.Forms.Keys)
        Me.menuFile_NewOpen.Size = New System.Drawing.Size(227, 22)
        Me.menuFile_NewOpen.Text = "新規ウィンドウを開く(&N)"
        '
        'menuFile_End
        '
        Me.menuFile_End.Name = "menuFile_End"
        Me.menuFile_End.ShortcutKeys = CType((System.Windows.Forms.Keys.Alt Or System.Windows.Forms.Keys.F4), System.Windows.Forms.Keys)
        Me.menuFile_End.Size = New System.Drawing.Size(227, 22)
        Me.menuFile_End.Text = "終了(&X)"
        '
        'menuWindow
        '
        Me.menuWindow.DropDownItems.AddRange(New System.Windows.Forms.ToolStripItem() {Me.menuWindow_Cascade, Me.menuWindow_TileHorizontal, Me.menuWindow_TileVertical})
        Me.menuWindow.Name = "menuWindow"
        Me.menuWindow.Size = New System.Drawing.Size(80, 20)
        Me.menuWindow.Text = "ウィンドウ(&W)"
        '
        'menuWindow_Cascade
        '
        Me.menuWindow_Cascade.Name = "menuWindow_Cascade"
        Me.menuWindow_Cascade.ShortcutKeys = CType(((System.Windows.Forms.Keys.Control Or System.Windows.Forms.Keys.Alt) _
            Or System.Windows.Forms.Keys.E), System.Windows.Forms.Keys)
        Me.menuWindow_Cascade.Size = New System.Drawing.Size(244, 22)
        Me.menuWindow_Cascade.Text = "重ねて表示(&E)"
        '
        'menuWindow_TileHorizontal
        '
        Me.menuWindow_TileHorizontal.Name = "menuWindow_TileHorizontal"
        Me.menuWindow_TileHorizontal.ShortcutKeys = CType(((System.Windows.Forms.Keys.Control Or System.Windows.Forms.Keys.Alt) _
            Or System.Windows.Forms.Keys.H), System.Windows.Forms.Keys)
        Me.menuWindow_TileHorizontal.Size = New System.Drawing.Size(244, 22)
        Me.menuWindow_TileHorizontal.Text = "上下に並べて表示(&H)"
        '
        'menuWindow_TileVertical
        '
        Me.menuWindow_TileVertical.Name = "menuWindow_TileVertical"
        Me.menuWindow_TileVertical.ShortcutKeys = CType(((System.Windows.Forms.Keys.Control Or System.Windows.Forms.Keys.Alt) _
            Or System.Windows.Forms.Keys.T), System.Windows.Forms.Keys)
        Me.menuWindow_TileVertical.Size = New System.Drawing.Size(244, 22)
        Me.menuWindow_TileVertical.Text = "左右に並べて表示(&T)"
        '
        'FromMain
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 12.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(480, 300)
        Me.Controls.Add(Me.MenuStrip)
        Me.IsMdiContainer = True
        Me.MainMenuStrip = Me.MenuStrip
        Me.Name = "FromMain"
        Me.Text = "Form1"
        Me.MenuStrip.ResumeLayout(False)
        Me.MenuStrip.PerformLayout()
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub

    Friend WithEvents MenuStrip As MenuStrip
    Friend WithEvents menuFile As ToolStripMenuItem
    Friend WithEvents menuFile_NewOpen As ToolStripMenuItem
    Friend WithEvents menuFile_End As ToolStripMenuItem
    Friend WithEvents menuWindow As ToolStripMenuItem
    Friend WithEvents menuWindow_Cascade As ToolStripMenuItem
    Friend WithEvents menuWindow_TileHorizontal As ToolStripMenuItem
    Friend WithEvents menuWindow_TileVertical As ToolStripMenuItem
End Class
