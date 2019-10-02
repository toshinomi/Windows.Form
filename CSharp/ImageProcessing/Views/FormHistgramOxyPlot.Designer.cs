namespace ImageProcessing
{
    partial class FormHistgramOxyPlot
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(FormHistgramOxyPlot));
            this.chart = new OxyPlot.WindowsForms.PlotView();
            this.SuspendLayout();
            // 
            // chart
            // 
            this.chart.Location = new System.Drawing.Point(12, 12);
            this.chart.Name = "chart";
            this.chart.PanCursor = System.Windows.Forms.Cursors.Hand;
            this.chart.Size = new System.Drawing.Size(776, 426);
            this.chart.TabIndex = 0;
            this.chart.Text = "plotView1";
            this.chart.ZoomHorizontalCursor = System.Windows.Forms.Cursors.SizeWE;
            this.chart.ZoomRectangleCursor = System.Windows.Forms.Cursors.SizeNWSE;
            this.chart.ZoomVerticalCursor = System.Windows.Forms.Cursors.SizeNS;
            // 
            // FormHistgramOxyPlot
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.LightSteelBlue;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.chart);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Name = "FormHistgramOxyPlot";
            this.Text = "Histgram";
            this.ResumeLayout(false);

        }

        #endregion

        private OxyPlot.WindowsForms.PlotView chart;
    }
}