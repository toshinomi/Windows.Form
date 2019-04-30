using System;
using System.Drawing;
using System.Windows.Forms;
using System.Threading;
using System.Drawing.Imaging;
using System.Diagnostics;
using System.Threading.Tasks;

namespace ImageProcessing
{
    public partial class FormMain : Form
    {
        private Bitmap m_bitmap;

        private EdgeDetection m_edgeDetection;


        private string m_strOpenFileName;
        private CancellationTokenSource m_tokenSource;

        public FormMain()
        {
            InitializeComponent();

            SetFormMain();

            btnFileSelect.Enabled = true;
            btnAllClear.Enabled = true;
            btnStart.Enabled = false;
            btnStop.Enabled = false;

            pictureBoxStatus.Visible = false;

            SetToolTip();

            m_bitmap = null;
            m_tokenSource = null;
            m_edgeDetection = null;
        }

        public void SetFormMain()
        {
            this.FormBorderStyle = FormBorderStyle.FixedSingle;
            this.MaximizeBox = false;

            return;
        }

        public void SetToolTip()
        {
            toolTipBtnFileSelect.InitialDelay = 1000;
            toolTipBtnFileSelect.ReshowDelay = 1000;
            toolTipBtnFileSelect.AutoPopDelay = 10000;
            toolTipBtnFileSelect.ShowAlways = false;
            toolTipBtnFileSelect.SetToolTip(btnFileSelect, "Please select a file to open.\nDisplay the image on the original image.");

            toolTipBtnAllClear.InitialDelay = 1000;
            toolTipBtnAllClear.ReshowDelay = 1000;
            toolTipBtnAllClear.AutoPopDelay = 10000;
            toolTipBtnAllClear.ShowAlways = false;
            toolTipBtnAllClear.SetToolTip(btnAllClear, "Clear the display.");

            toolTipBtnStart.InitialDelay = 1000;
            toolTipBtnStart.ReshowDelay = 1000;
            toolTipBtnStart.AutoPopDelay = 10000;
            toolTipBtnStart.ShowAlways = false;
            toolTipBtnStart.SetToolTip(btnStart, "Perform unstable filter processing.");

            toolTipBtnStop.InitialDelay = 1000;
            toolTipBtnStop.ReshowDelay = 1000;
            toolTipBtnStop.AutoPopDelay = 10000;
            toolTipBtnStop.ShowAlways = false;
            toolTipBtnStop.SetToolTip(btnStop, "Processing stop.");

            return;
        }


        ~FormMain()
        {
            //m_dMask = null;
            m_bitmap= null;
            m_tokenSource = null;
        }

        public void SetButtonEnable()
        {
            btnFileSelect.Enabled = true;
            btnAllClear.Enabled = true;
            btnStart.Enabled = true;
            btnStop.Enabled = false;
        }

        public void SetTextTime(long lTime)
        {
            textBoxTime.Text = lTime.ToString();
        }

        public void SetPictureBoxStatus()
        {
            pictureBoxStatus.Visible = false;
        }

        public async Task<bool> TaskWorkImageProcessing()
        {
            m_tokenSource = new CancellationTokenSource();
            CancellationToken token = m_tokenSource.Token;
            bool bRst = await Task.Run(() => m_edgeDetection.GoEdgeDetection(token));
            return bRst;
        }

        public void LoadImage()
        {
            m_bitmap = new Bitmap(m_strOpenFileName);
            m_edgeDetection = new EdgeDetection(m_bitmap);

            return;
        }

        public void OnFormClosingFormMain(object sender, FormClosingEventArgs e)
        {
            if (m_tokenSource != null)
            {
                e.Cancel = true;
            }
            return;
        }

        public void OnClickBtnFileSelect(object sender, EventArgs e)
        {
            OpenFileDialog openFileDlg = new OpenFileDialog();

            openFileDlg.FileName = "default.jpg";
            openFileDlg.InitialDirectory = @"C:\";
            openFileDlg.Filter = "All Files(*.*)|*.*";
            openFileDlg.FilterIndex = 1;
            openFileDlg.Title = "Please select a file to open";
            openFileDlg.RestoreDirectory = true;
            openFileDlg.CheckFileExists = true;
            openFileDlg.CheckPathExists = true;

            if (openFileDlg.ShowDialog() == DialogResult.OK)
            {
                pictureBoxOriginal.Image = null;
                pictureBoxAfter.Image = null;
                m_strOpenFileName = openFileDlg.FileName;
                try
                {
                    LoadImage();
                }
                catch (Exception)
                {
                    MessageBox.Show(this, "Open File Error", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                    return;
                }
                pictureBoxOriginal.ImageLocation = m_strOpenFileName;
                btnStart.Enabled = true;
                textBoxTime.Text = "";
            }
            return;
        }

        private void OnClickBtnAllClear(object sender, EventArgs e)
        {
            pictureBoxOriginal.ImageLocation = null;
            pictureBoxAfter.Image = null;

            m_bitmap = null;
            m_strOpenFileName = "";

            textBoxTime.Text = "";

            btnFileSelect.Enabled = true;
            btnAllClear.Enabled = true;
            btnStart.Enabled = false;

            return;
        }

        private async void OnClickBtnStart(object sender, EventArgs e)
        {
            pictureBoxAfter.Image = null;

            btnFileSelect.Enabled = false;
            btnAllClear.Enabled = false;
            btnStart.Enabled = false;

            textBoxTime.Text = "";

            pictureBoxStatus.Visible = true;

            LoadImage();

            Stopwatch stopwatch = new Stopwatch();
            stopwatch.Start();
            btnStop.Enabled = true;
            bool bResult = await TaskWorkImageProcessing();
            if (bResult)
            {
                pictureBoxOriginal.ImageLocation = m_strOpenFileName;
                pictureBoxAfter.Image = m_edgeDetection.GetBitmapImage();

                stopwatch.Stop();

                Invoke(new Action<long>(SetTextTime), stopwatch.ElapsedMilliseconds);
            }
            Invoke(new Action(SetPictureBoxStatus));
            Invoke(new Action(SetButtonEnable));

            stopwatch = null;
            m_tokenSource = null;
            m_bitmap = null;

            return;
        }

        private void OnClickBtnStop(object sender, EventArgs e)
        {
            if (m_tokenSource != null)
            {
                m_tokenSource.Cancel();
            }

            return;
        }
    }
}