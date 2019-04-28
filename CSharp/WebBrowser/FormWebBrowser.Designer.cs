namespace WebBrowser
{
    partial class FormWebBrowser
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(FormWebBrowser));
            this.panelUrl = new System.Windows.Forms.Panel();
            this.label1 = new System.Windows.Forms.Label();
            this.buttonRefresh = new System.Windows.Forms.Button();
            this.buttonForward = new System.Windows.Forms.Button();
            this.buttonBack = new System.Windows.Forms.Button();
            this.textUrl = new System.Windows.Forms.TextBox();
            this.panelWebBrowser = new System.Windows.Forms.Panel();
            this.webBrowser = new System.Windows.Forms.WebBrowser();
            this.panelUrl.SuspendLayout();
            this.panelWebBrowser.SuspendLayout();
            this.SuspendLayout();
            // 
            // panelUrl
            // 
            this.panelUrl.Controls.Add(this.label1);
            this.panelUrl.Controls.Add(this.buttonRefresh);
            this.panelUrl.Controls.Add(this.buttonForward);
            this.panelUrl.Controls.Add(this.buttonBack);
            this.panelUrl.Controls.Add(this.textUrl);
            this.panelUrl.Dock = System.Windows.Forms.DockStyle.Top;
            this.panelUrl.Location = new System.Drawing.Point(0, 0);
            this.panelUrl.Margin = new System.Windows.Forms.Padding(2);
            this.panelUrl.Name = "panelUrl";
            this.panelUrl.Size = new System.Drawing.Size(480, 45);
            this.panelUrl.TabIndex = 0;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(136, 6);
            this.label1.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(27, 12);
            this.label1.TabIndex = 4;
            this.label1.Text = "URL";
            // 
            // buttonRefresh
            // 
            this.buttonRefresh.Image = ((System.Drawing.Image)(resources.GetObject("buttonRefresh.Image")));
            this.buttonRefresh.Location = new System.Drawing.Point(88, 0);
            this.buttonRefresh.Margin = new System.Windows.Forms.Padding(2);
            this.buttonRefresh.Name = "buttonRefresh";
            this.buttonRefresh.Size = new System.Drawing.Size(45, 43);
            this.buttonRefresh.TabIndex = 3;
            this.buttonRefresh.UseVisualStyleBackColor = true;
            this.buttonRefresh.Click += new System.EventHandler(this.OnClickRefresh);
            // 
            // buttonForward
            // 
            this.buttonForward.Image = ((System.Drawing.Image)(resources.GetObject("buttonForward.Image")));
            this.buttonForward.Location = new System.Drawing.Point(44, 0);
            this.buttonForward.Margin = new System.Windows.Forms.Padding(2);
            this.buttonForward.Name = "buttonForward";
            this.buttonForward.Size = new System.Drawing.Size(45, 43);
            this.buttonForward.TabIndex = 2;
            this.buttonForward.UseVisualStyleBackColor = true;
            this.buttonForward.Click += new System.EventHandler(this.OnClickForward);
            // 
            // buttonBack
            // 
            this.buttonBack.Image = ((System.Drawing.Image)(resources.GetObject("buttonBack.Image")));
            this.buttonBack.Location = new System.Drawing.Point(0, 0);
            this.buttonBack.Margin = new System.Windows.Forms.Padding(2);
            this.buttonBack.Name = "buttonBack";
            this.buttonBack.Size = new System.Drawing.Size(45, 43);
            this.buttonBack.TabIndex = 1;
            this.buttonBack.UseVisualStyleBackColor = true;
            this.buttonBack.Click += new System.EventHandler(this.OnClickBack);
            // 
            // textUrl
            // 
            this.textUrl.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.textUrl.Location = new System.Drawing.Point(136, 23);
            this.textUrl.Margin = new System.Windows.Forms.Padding(2);
            this.textUrl.Name = "textUrl";
            this.textUrl.Size = new System.Drawing.Size(338, 19);
            this.textUrl.TabIndex = 0;
            this.textUrl.Text = "https://www.google.co.jp/";
            this.textUrl.KeyDown += new System.Windows.Forms.KeyEventHandler(this.OnKeyDownTextUrl);
            // 
            // panelWebBrowser
            // 
            this.panelWebBrowser.Controls.Add(this.webBrowser);
            this.panelWebBrowser.Dock = System.Windows.Forms.DockStyle.Fill;
            this.panelWebBrowser.Location = new System.Drawing.Point(0, 45);
            this.panelWebBrowser.Margin = new System.Windows.Forms.Padding(2);
            this.panelWebBrowser.Name = "panelWebBrowser";
            this.panelWebBrowser.Size = new System.Drawing.Size(480, 255);
            this.panelWebBrowser.TabIndex = 1;
            // 
            // webBrowser
            // 
            this.webBrowser.Dock = System.Windows.Forms.DockStyle.Fill;
            this.webBrowser.Location = new System.Drawing.Point(0, 0);
            this.webBrowser.Margin = new System.Windows.Forms.Padding(2);
            this.webBrowser.MinimumSize = new System.Drawing.Size(12, 13);
            this.webBrowser.Name = "webBrowser";
            this.webBrowser.ScriptErrorsSuppressed = true;
            this.webBrowser.Size = new System.Drawing.Size(480, 255);
            this.webBrowser.TabIndex = 0;
            this.webBrowser.Navigated += new System.Windows.Forms.WebBrowserNavigatedEventHandler(this.OnNavigatedWebBrowser);
            // 
            // FormWebBrowser
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.AutoScroll = true;
            this.ClientSize = new System.Drawing.Size(480, 300);
            this.Controls.Add(this.panelWebBrowser);
            this.Controls.Add(this.panelUrl);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Margin = new System.Windows.Forms.Padding(2);
            this.Name = "FormWebBrowser";
            this.Text = "https://www.google.co.jp/";
            this.FormClosed += new System.Windows.Forms.FormClosedEventHandler(this.OnFormClosedFormWebBrowser);
            this.Load += new System.EventHandler(this.OnLoadFormWebBrowser);
            this.panelUrl.ResumeLayout(false);
            this.panelUrl.PerformLayout();
            this.panelWebBrowser.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Panel panelUrl;
        private System.Windows.Forms.Panel panelWebBrowser;
        private System.Windows.Forms.TextBox textUrl;
        private System.Windows.Forms.WebBrowser webBrowser;
        private System.Windows.Forms.Button buttonBack;
        private System.Windows.Forms.Button buttonForward;
        private System.Windows.Forms.Button buttonRefresh;
        private System.Windows.Forms.Label label1;
    }
}