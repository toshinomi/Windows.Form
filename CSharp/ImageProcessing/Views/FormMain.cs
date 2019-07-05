using System;
using System.Drawing;
using System.Windows.Forms;
using System.Threading;
using System.Drawing.Imaging;
using System.Diagnostics;
using System.Threading.Tasks;
using System.IO;

namespace ImageProcessing
{
    public partial class FormMain : Form
    {
        private Bitmap m_bitmap;
        private EdgeDetection m_edgeDetection;
        private string m_strOpenFileName;
        private CancellationTokenSource m_tokenSource;
        private FormHistgram m_histgram;

        public FormMain()
        {
            InitializeComponent();

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

            toolTipBtnSaveImage.InitialDelay = 1000;
            toolTipBtnSaveImage.ReshowDelay = 1000;
            toolTipBtnSaveImage.AutoPopDelay = 10000;
            toolTipBtnSaveImage.ShowAlways = false;
            toolTipBtnSaveImage.SetToolTip(btnSaveImage, "Saving image.");

            toolTipBtnShowHistgram.InitialDelay = 1000;
            toolTipBtnShowHistgram.ReshowDelay = 1000;
            toolTipBtnShowHistgram.AutoPopDelay = 10000;
            toolTipBtnShowHistgram.ShowAlways = false;
            toolTipBtnShowHistgram.SetToolTip(btnShowHistgram, "Show Histgram.");

            return;
        }


        ~FormMain()
        {
            m_bitmap= null;
            m_tokenSource = null;
        }

        public void SetButtonEnable()
        {
            btnFileSelect.Enabled = true;
            btnAllClear.Enabled = true;
            btnStart.Enabled = true;
            btnStop.Enabled = false;

            return;
        }

        public void SetTextTime(long _lTime)
        {
            textBoxTime.Text = _lTime.ToString();

            return;
        }

        public void SetPictureBoxStatus()
        {
            pictureBoxStatus.Visible = false;

            return;
        }

        public async Task<bool> TaskWorkImageProcessing()
        {
            m_tokenSource = new CancellationTokenSource();
            CancellationToken token = m_tokenSource.Token;
            bool bRst = await Task.Run(() => m_edgeDetection.GoImgProc(token));
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
            ComOpenFileDialog openFileDlg = new ComOpenFileDialog();
            openFileDlg.Filter = "JPG|*.jpg|PNG|*.png";
            openFileDlg.Title = "Open the file";
            if (openFileDlg.ShowDialog() == true)
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

                if (m_histgram == null)
                {
                    m_histgram = new FormHistgram();
                }

                m_histgram.BitmapOrg = (Bitmap)new Bitmap(m_strOpenFileName).Clone();
                m_histgram.BitmapAfter = (Bitmap)m_edgeDetection.Bitmap.Clone();
                if (m_histgram.IsOpen == true)
                {
                    m_histgram.DrawHistgram();
                }
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

            if (m_histgram != null)
            {
                m_histgram.Close();
            }

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
                pictureBoxAfter.Image = m_edgeDetection.Bitmap;

                stopwatch.Stop();

                Invoke(new Action<long>(SetTextTime), stopwatch.ElapsedMilliseconds);

                m_histgram.BitmapOrg = (Bitmap)new Bitmap(m_strOpenFileName).Clone();
                m_histgram.BitmapAfter = (Bitmap)m_edgeDetection.Bitmap.Clone();
                if (m_histgram.IsOpen == true)
                {
                    m_histgram.DrawHistgram();
                }
            }
            Invoke(new Action(SetPictureBoxStatus));
            Invoke(new Action(SetButtonEnable));

            stopwatch = null;
            m_tokenSource = null;

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

        private void OnClickBtnSaveImage(object sender, EventArgs e)
        {
            ComSaveFileDialog saveDialog = new ComSaveFileDialog();
            saveDialog.Filter = "PNG|*.png";
            saveDialog.Title = "Save the file";
            if (saveDialog.ShowDialog() == true)
            {
                string strFileName = saveDialog.FileName;
                var bitmap = (Bitmap)m_edgeDetection.Bitmap.Clone();
                if (bitmap != null)
                {
                    bitmap.Save(strFileName, System.Drawing.Imaging.ImageFormat.Png);
                    bitmap.Dispose();
                }
            }

            return;
        }

        private void OnClickBtnShowHistgram(object sender, EventArgs e)
        {
            if (m_bitmap == null)
            {
                return;
            }

            if (m_histgram != null)
            {
                m_histgram.Close();
                m_histgram = null;
                m_histgram = new FormHistgram();
            }

            m_histgram.BitmapOrg = (Bitmap)new Bitmap(m_strOpenFileName).Clone();
            m_histgram.BitmapAfter = (Bitmap)m_edgeDetection.Bitmap.Clone();
            m_histgram.DrawHistgram();
            m_histgram.IsOpen = true;
            m_histgram.Show();

            return;
        }
    }
}