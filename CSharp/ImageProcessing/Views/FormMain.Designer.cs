using System;
using System.Windows.Forms;

namespace ImageProcessing
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
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(FormMain));
            this.btnFileSelect = new System.Windows.Forms.Button();
            this.groupBoxOperation = new System.Windows.Forms.GroupBox();
            this.btnSaveImage = new System.Windows.Forms.Button();
            this.btnStop = new System.Windows.Forms.Button();
            this.btnAllClear = new System.Windows.Forms.Button();
            this.btnStart = new System.Windows.Forms.Button();
            this.groupBoxImageOutput = new System.Windows.Forms.GroupBox();
            this.pictureBoxStatus = new System.Windows.Forms.PictureBox();
            this.labelAfterImage = new System.Windows.Forms.Label();
            this.pictureBoxAfter = new System.Windows.Forms.PictureBox();
            this.labelOriginalImage = new System.Windows.Forms.Label();
            this.pictureBoxOriginal = new System.Windows.Forms.PictureBox();
            this.toolTipBtnFileSelect = new System.Windows.Forms.ToolTip(this.components);
            this.toolTipBtnAllClear = new System.Windows.Forms.ToolTip(this.components);
            this.toolTipBtnStart = new System.Windows.Forms.ToolTip(this.components);
            this.groupBoxProcessingInfo = new System.Windows.Forms.GroupBox();
            this.labelTime = new System.Windows.Forms.Label();
            this.labelTimeUnit = new System.Windows.Forms.Label();
            this.textBoxTime = new System.Windows.Forms.TextBox();
            this.toolTipBtnStop = new System.Windows.Forms.ToolTip(this.components);
            this.groupBoxOperation.SuspendLayout();
            this.groupBoxImageOutput.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBoxStatus)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBoxAfter)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBoxOriginal)).BeginInit();
            this.groupBoxProcessingInfo.SuspendLayout();
            this.SuspendLayout();
            // 
            // btnFileSelect
            // 
            this.btnFileSelect.BackColor = System.Drawing.Color.White;
            this.btnFileSelect.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.btnFileSelect.Font = new System.Drawing.Font("MS UI Gothic", 15.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(128)));
            this.btnFileSelect.Location = new System.Drawing.Point(41, 36);
            this.btnFileSelect.Name = "btnFileSelect";
            this.btnFileSelect.Size = new System.Drawing.Size(154, 40);
            this.btnFileSelect.TabIndex = 0;
            this.btnFileSelect.Text = "File Select...";
            this.btnFileSelect.UseVisualStyleBackColor = false;
            this.btnFileSelect.Click += new System.EventHandler(this.OnClickBtnFileSelect);
            // 
            // groupBoxOperation
            // 
            this.groupBoxOperation.Controls.Add(this.btnSaveImage);
            this.groupBoxOperation.Controls.Add(this.btnStop);
            this.groupBoxOperation.Controls.Add(this.btnAllClear);
            this.groupBoxOperation.Controls.Add(this.btnStart);
            this.groupBoxOperation.Controls.Add(this.btnFileSelect);
            this.groupBoxOperation.Font = new System.Drawing.Font("MS UI Gothic", 15.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(128)));
            this.groupBoxOperation.Location = new System.Drawing.Point(12, 12);
            this.groupBoxOperation.Name = "groupBoxOperation";
            this.groupBoxOperation.Size = new System.Drawing.Size(249, 408);
            this.groupBoxOperation.TabIndex = 0;
            this.groupBoxOperation.TabStop = false;
            this.groupBoxOperation.Text = "Operation";
            // 
            // btnSaveImage
            // 
            this.btnSaveImage.BackColor = System.Drawing.Color.White;
            this.btnSaveImage.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.btnSaveImage.Font = new System.Drawing.Font("MS UI Gothic", 15.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(128)));
            this.btnSaveImage.Location = new System.Drawing.Point(41, 263);
            this.btnSaveImage.Name = "btnSaveImage";
            this.btnSaveImage.Size = new System.Drawing.Size(154, 40);
            this.btnSaveImage.TabIndex = 5;
            this.btnSaveImage.Text = "Save Image...";
            this.btnSaveImage.UseVisualStyleBackColor = false;
            this.btnSaveImage.Click += new System.EventHandler(this.OnClickBtnSaveImage);
            // 
            // btnStop
            // 
            this.btnStop.BackColor = System.Drawing.Color.White;
            this.btnStop.Enabled = false;
            this.btnStop.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.btnStop.Font = new System.Drawing.Font("MS UI Gothic", 15.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(128)));
            this.btnStop.Location = new System.Drawing.Point(41, 207);
            this.btnStop.Name = "btnStop";
            this.btnStop.Size = new System.Drawing.Size(154, 40);
            this.btnStop.TabIndex = 4;
            this.btnStop.Text = "Stop";
            this.btnStop.UseVisualStyleBackColor = false;
            this.btnStop.Click += new System.EventHandler(this.OnClickBtnStop);
            // 
            // btnAllClear
            // 
            this.btnAllClear.BackColor = System.Drawing.Color.White;
            this.btnAllClear.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.btnAllClear.Font = new System.Drawing.Font("MS UI Gothic", 15.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(128)));
            this.btnAllClear.Location = new System.Drawing.Point(41, 92);
            this.btnAllClear.Name = "btnAllClear";
            this.btnAllClear.Size = new System.Drawing.Size(154, 40);
            this.btnAllClear.TabIndex = 1;
            this.btnAllClear.Text = "All Clear";
            this.btnAllClear.UseVisualStyleBackColor = false;
            this.btnAllClear.Click += new System.EventHandler(this.OnClickBtnAllClear);
            // 
            // btnStart
            // 
            this.btnStart.BackColor = System.Drawing.Color.White;
            this.btnStart.Enabled = false;
            this.btnStart.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.btnStart.Font = new System.Drawing.Font("MS UI Gothic", 15.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(128)));
            this.btnStart.Location = new System.Drawing.Point(41, 147);
            this.btnStart.Name = "btnStart";
            this.btnStart.Size = new System.Drawing.Size(154, 40);
            this.btnStart.TabIndex = 2;
            this.btnStart.Text = "Start\r\n";
            this.btnStart.UseVisualStyleBackColor = false;
            this.btnStart.Click += new System.EventHandler(this.OnClickBtnStart);
            // 
            // groupBoxImageOutput
            // 
            this.groupBoxImageOutput.Controls.Add(this.pictureBoxStatus);
            this.groupBoxImageOutput.Controls.Add(this.labelAfterImage);
            this.groupBoxImageOutput.Controls.Add(this.pictureBoxAfter);
            this.groupBoxImageOutput.Controls.Add(this.labelOriginalImage);
            this.groupBoxImageOutput.Controls.Add(this.pictureBoxOriginal);
            this.groupBoxImageOutput.Font = new System.Drawing.Font("MS UI Gothic", 15.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(128)));
            this.groupBoxImageOutput.Location = new System.Drawing.Point(267, 12);
            this.groupBoxImageOutput.Name = "groupBoxImageOutput";
            this.groupBoxImageOutput.Size = new System.Drawing.Size(1065, 539);
            this.groupBoxImageOutput.TabIndex = 2;
            this.groupBoxImageOutput.TabStop = false;
            this.groupBoxImageOutput.Text = "Image Output";
            // 
            // pictureBoxStatus
            // 
            this.pictureBoxStatus.Image = ((System.Drawing.Image)(resources.GetObject("pictureBoxStatus.Image")));
            this.pictureBoxStatus.Location = new System.Drawing.Point(696, 180);
            this.pictureBoxStatus.Name = "pictureBoxStatus";
            this.pictureBoxStatus.Size = new System.Drawing.Size(202, 200);
            this.pictureBoxStatus.TabIndex = 7;
            this.pictureBoxStatus.TabStop = false;
            // 
            // labelAfterImage
            // 
            this.labelAfterImage.AutoSize = true;
            this.labelAfterImage.Font = new System.Drawing.Font("MS UI Gothic", 15.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(128)));
            this.labelAfterImage.Location = new System.Drawing.Point(536, 35);
            this.labelAfterImage.Name = "labelAfterImage";
            this.labelAfterImage.Size = new System.Drawing.Size(111, 21);
            this.labelAfterImage.TabIndex = 1;
            this.labelAfterImage.Text = "After Image";
            // 
            // pictureBoxAfter
            // 
            this.pictureBoxAfter.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.pictureBoxAfter.Location = new System.Drawing.Point(540, 63);
            this.pictureBoxAfter.Name = "pictureBoxAfter";
            this.pictureBoxAfter.Size = new System.Drawing.Size(498, 456);
            this.pictureBoxAfter.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.pictureBoxAfter.TabIndex = 6;
            this.pictureBoxAfter.TabStop = false;
            // 
            // labelOriginalImage
            // 
            this.labelOriginalImage.AutoSize = true;
            this.labelOriginalImage.Font = new System.Drawing.Font("MS UI Gothic", 15.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(128)));
            this.labelOriginalImage.Location = new System.Drawing.Point(19, 35);
            this.labelOriginalImage.Name = "labelOriginalImage";
            this.labelOriginalImage.Size = new System.Drawing.Size(132, 21);
            this.labelOriginalImage.TabIndex = 0;
            this.labelOriginalImage.Text = "Original Image";
            // 
            // pictureBoxOriginal
            // 
            this.pictureBoxOriginal.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.pictureBoxOriginal.Location = new System.Drawing.Point(23, 63);
            this.pictureBoxOriginal.Name = "pictureBoxOriginal";
            this.pictureBoxOriginal.Size = new System.Drawing.Size(498, 456);
            this.pictureBoxOriginal.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.pictureBoxOriginal.TabIndex = 4;
            this.pictureBoxOriginal.TabStop = false;
            // 
            // groupBoxProcessingInfo
            // 
            this.groupBoxProcessingInfo.Controls.Add(this.labelTime);
            this.groupBoxProcessingInfo.Controls.Add(this.labelTimeUnit);
            this.groupBoxProcessingInfo.Controls.Add(this.textBoxTime);
            this.groupBoxProcessingInfo.Font = new System.Drawing.Font("MS UI Gothic", 15.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(128)));
            this.groupBoxProcessingInfo.Location = new System.Drawing.Point(12, 438);
            this.groupBoxProcessingInfo.Name = "groupBoxProcessingInfo";
            this.groupBoxProcessingInfo.Size = new System.Drawing.Size(249, 113);
            this.groupBoxProcessingInfo.TabIndex = 1;
            this.groupBoxProcessingInfo.TabStop = false;
            this.groupBoxProcessingInfo.Text = "Processing Infomation";
            // 
            // labelTime
            // 
            this.labelTime.AutoSize = true;
            this.labelTime.Location = new System.Drawing.Point(37, 32);
            this.labelTime.Name = "labelTime";
            this.labelTime.Size = new System.Drawing.Size(52, 21);
            this.labelTime.TabIndex = 3;
            this.labelTime.Text = "Time";
            // 
            // labelTimeUnit
            // 
            this.labelTimeUnit.AutoSize = true;
            this.labelTimeUnit.Location = new System.Drawing.Point(208, 63);
            this.labelTimeUnit.Name = "labelTimeUnit";
            this.labelTimeUnit.Size = new System.Drawing.Size(35, 21);
            this.labelTimeUnit.TabIndex = 5;
            this.labelTimeUnit.Text = "ms";
            // 
            // textBoxTime
            // 
            this.textBoxTime.Location = new System.Drawing.Point(41, 56);
            this.textBoxTime.Name = "textBoxTime";
            this.textBoxTime.ReadOnly = true;
            this.textBoxTime.Size = new System.Drawing.Size(154, 28);
            this.textBoxTime.TabIndex = 4;
            this.textBoxTime.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            // 
            // FormMain
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.LightSteelBlue;
            this.ClientSize = new System.Drawing.Size(1344, 569);
            this.Controls.Add(this.groupBoxProcessingInfo);
            this.Controls.Add(this.groupBoxImageOutput);
            this.Controls.Add(this.groupBoxOperation);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MaximizeBox = false;
            this.Name = "FormMain";
            this.Text = "Image Processing";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.OnFormClosingFormMain);
            this.groupBoxOperation.ResumeLayout(false);
            this.groupBoxImageOutput.ResumeLayout(false);
            this.groupBoxImageOutput.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBoxStatus)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBoxAfter)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBoxOriginal)).EndInit();
            this.groupBoxProcessingInfo.ResumeLayout(false);
            this.groupBoxProcessingInfo.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button btnFileSelect;
        private GroupBox groupBoxOperation;
        private GroupBox groupBoxImageOutput;
        private Label labelAfterImage;
        private PictureBox pictureBoxAfter;
        private Label labelOriginalImage;
        private PictureBox pictureBoxOriginal;
        private ToolTip toolTipBtnFileSelect;
        private Button btnStart;
        private Button btnAllClear;
        private ToolTip toolTipBtnAllClear;
        private ToolTip toolTipBtnStart;
        private GroupBox groupBoxProcessingInfo;
        private TextBox textBoxTime;
        private Label labelTimeUnit;
        private Label labelTime;
        private PictureBox pictureBoxStatus;
        private Button btnStop;
        private ToolTip toolTipBtnStop;
        private Button btnSaveImage;
    }
}

