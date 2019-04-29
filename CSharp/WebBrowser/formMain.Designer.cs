namespace WebBrowser
{
    partial class FormMain
    {
        /// <summary>
        /// 必要なデザイナー変数です。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 使用中のリソースをすべてクリーンアップします。
        /// </summary>
        /// <param name="disposing">マネージド リソースを破棄する場合は true を指定し、その他の場合は false を指定します。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows フォーム デザイナーで生成されたコード

        /// <summary>
        /// デザイナー サポートに必要なメソッドです。このメソッドの内容を
        /// コード エディターで変更しないでください。
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(FormMain));
            this.menuStrip = new System.Windows.Forms.MenuStrip();
            this.menuFile = new System.Windows.Forms.ToolStripMenuItem();
            this.menuFile_NewOpen = new System.Windows.Forms.ToolStripMenuItem();
            this.menuFile_End = new System.Windows.Forms.ToolStripMenuItem();
            this.menuWindow = new System.Windows.Forms.ToolStripMenuItem();
            this.menuWindow_Cascade = new System.Windows.Forms.ToolStripMenuItem();
            this.menuWindow_TileHorizontal = new System.Windows.Forms.ToolStripMenuItem();
            this.menuWindow_TileVertical = new System.Windows.Forms.ToolStripMenuItem();
            this.menuStrip.SuspendLayout();
            this.SuspendLayout();
            // 
            // menuStrip
            // 
            this.menuStrip.ImageScalingSize = new System.Drawing.Size(24, 24);
            this.menuStrip.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.menuFile,
            this.menuWindow});
            this.menuStrip.Location = new System.Drawing.Point(0, 0);
            this.menuStrip.Name = "menuStrip";
            this.menuStrip.Padding = new System.Windows.Forms.Padding(4, 1, 0, 1);
            this.menuStrip.Size = new System.Drawing.Size(480, 24);
            this.menuStrip.TabIndex = 1;
            this.menuStrip.Text = "menuStrip1";
            // 
            // menuFile
            // 
            this.menuFile.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.menuFile_NewOpen,
            this.menuFile_End});
            this.menuFile.Name = "menuFile";
            this.menuFile.Size = new System.Drawing.Size(67, 22);
            this.menuFile.Text = "ファイル(&F)";
            // 
            // menuFile_NewOpen
            // 
            this.menuFile_NewOpen.Name = "menuFile_NewOpen";
            this.menuFile_NewOpen.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.N)));
            this.menuFile_NewOpen.Size = new System.Drawing.Size(227, 22);
            this.menuFile_NewOpen.Text = "新規ウィンドウを開く(&N)";
            this.menuFile_NewOpen.Click += new System.EventHandler(this.OnClickMenuFileNewOpen);
            // 
            // menuFile_End
            // 
            this.menuFile_End.Name = "menuFile_End";
            this.menuFile_End.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Alt | System.Windows.Forms.Keys.F4)));
            this.menuFile_End.Size = new System.Drawing.Size(227, 22);
            this.menuFile_End.Text = "終了(&X)";
            this.menuFile_End.Click += new System.EventHandler(this.OnClickMenuFileEnd);
            // 
            // menuWindow
            // 
            this.menuWindow.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.menuWindow_Cascade,
            this.menuWindow_TileHorizontal,
            this.menuWindow_TileVertical});
            this.menuWindow.Name = "menuWindow";
            this.menuWindow.Size = new System.Drawing.Size(80, 22);
            this.menuWindow.Text = "ウィンドウ(&W)";
            // 
            // menuWindow_Cascade
            // 
            this.menuWindow_Cascade.Name = "menuWindow_Cascade";
            this.menuWindow_Cascade.ShortcutKeys = ((System.Windows.Forms.Keys)(((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.Alt) 
            | System.Windows.Forms.Keys.E)));
            this.menuWindow_Cascade.Size = new System.Drawing.Size(244, 22);
            this.menuWindow_Cascade.Text = "重ねて表示(&E)";
            this.menuWindow_Cascade.Click += new System.EventHandler(this.OnClickMenuWindowCascade);
            // 
            // menuWindow_TileHorizontal
            // 
            this.menuWindow_TileHorizontal.Name = "menuWindow_TileHorizontal";
            this.menuWindow_TileHorizontal.ShortcutKeys = ((System.Windows.Forms.Keys)(((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.Alt) 
            | System.Windows.Forms.Keys.H)));
            this.menuWindow_TileHorizontal.Size = new System.Drawing.Size(244, 22);
            this.menuWindow_TileHorizontal.Text = "上下に並べて表示(&H)";
            this.menuWindow_TileHorizontal.Click += new System.EventHandler(this.OnClickMenuWindowTileHorizontal);
            // 
            // menuWindow_TileVertical
            // 
            this.menuWindow_TileVertical.Name = "menuWindow_TileVertical";
            this.menuWindow_TileVertical.ShortcutKeys = ((System.Windows.Forms.Keys)(((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.Alt) 
            | System.Windows.Forms.Keys.T)));
            this.menuWindow_TileVertical.Size = new System.Drawing.Size(244, 22);
            this.menuWindow_TileVertical.Text = "左右に並べて表示(&T)";
            this.menuWindow_TileVertical.Click += new System.EventHandler(this.OnClickMenuWindowTileVertical);
            // 
            // FormMain
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.Control;
            this.ClientSize = new System.Drawing.Size(480, 300);
            this.Controls.Add(this.menuStrip);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.IsMdiContainer = true;
            this.MainMenuStrip = this.menuStrip;
            this.Margin = new System.Windows.Forms.Padding(2);
            this.Name = "FormMain";
            this.FormClosed += new System.Windows.Forms.FormClosedEventHandler(this.OnFormClosedFormMain);
            this.Load += new System.EventHandler(this.OnLoadFormMain);
            this.menuStrip.ResumeLayout(false);
            this.menuStrip.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.MenuStrip menuStrip;
        private System.Windows.Forms.ToolStripMenuItem menuFile;
        private System.Windows.Forms.ToolStripMenuItem menuFile_NewOpen;
        private System.Windows.Forms.ToolStripMenuItem menuWindow;
        private System.Windows.Forms.ToolStripMenuItem menuWindow_Cascade;
        private System.Windows.Forms.ToolStripMenuItem menuWindow_TileHorizontal;
        private System.Windows.Forms.ToolStripMenuItem menuWindow_TileVertical;
        private System.Windows.Forms.ToolStripMenuItem menuFile_End;
    }
}

