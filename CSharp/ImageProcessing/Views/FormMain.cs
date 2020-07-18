using System;
using System.Drawing;
using System.Windows.Forms;
using System.Threading;
using System.Drawing.Imaging;
using System.Diagnostics;
using System.Threading.Tasks;
using System.IO;
using System.Windows.Media.Imaging;

namespace ImageProcessing
{
    /// <summary>
    /// MainFormのロジック
    /// </summary>
    public partial class FormMain : Form
    {
        private Bitmap mBitmap;
        private ImageProcessing mImageProcessing;
        private string mOpenFileName;
        private CancellationTokenSource mTokenSource;
        private string mCurrentImageProcessingName;
#if CHART_LIVE_CHART
        private FormHistgramLiveCharts mHistgram;
#elif CHART_OXY_PLOT
        private FormHistgramOxyPlot mHistgram;
#else
        private FormHistgramOxyPlot mHistgram;
#endif

        /// <summary>
        /// コンストラクタ
        /// </summary>
        public FormMain()
        {
            InitializeComponent();

            btnFileSelect.Enabled = true;
            btnAllClear.Enabled = true;
            btnStart.Enabled = false;
            btnStop.Enabled = false;
            btnSaveImage.Enabled = false;

            pictureBoxStatus.Visible = false;

            SetToolTip();

            mBitmap = null;
            mTokenSource = null;
            mImageProcessing = null;

            mCurrentImageProcessingName = Properties.Settings.Default.ImageTypeSelectName;
            this.Text = "Image Processing ( " + mCurrentImageProcessingName + " )";

            sliderThresh.Enabled = mCurrentImageProcessingName == ComInfo.IMG_NAME_BINARIZATION;
        }

        /// <summary>
        /// デスクトラクタ
        /// </summary>
        ~FormMain()
        {
            mBitmap = null;
            mTokenSource = null;
            mImageProcessing = null;
        }

        /// <summary>
        /// ビットマップを取得する
        /// </summary>
        /// <returns>ビットマップ</returns>
        public Bitmap GetBitmap()
        {
            return mImageProcessing.Bitmap; ;
        }

        /// <summary>
        /// 対象の画像処理オブジェクトを実行する
        /// </summary>
        /// <param name="comImageProcessingInfo">画像処理の設定</param>
        /// <param name="token">キャンセルトークン</param>
        /// <returns>画像処理の実行結果 成功/失敗</returns>
        public bool GoImageProcessing(ComImageProcessingInfo comImageProcessingInfo, CancellationToken token)
        {
            mImageProcessing.Thresh = comImageProcessingInfo.BinarizationInfo.Thresh;
            bool result = mImageProcessing.GoImageProcessing(mCurrentImageProcessingName, token);

            return result;
        }

        /// <summary>
        /// ツールチップの設定
        /// </summary>
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

        /// <summary>
        /// ボタンのEnableを制御する
        /// </summary>
        public void SetButtonEnable()
        {
            btnFileSelect.Enabled = true;
            btnAllClear.Enabled = true;
            btnStart.Enabled = true;
            btnStop.Enabled = false;

            return;
        }

        /// <summary>
        /// 時間を表示するテキストボックスに時間を設定する
        /// </summary>
        /// <param name="time">時間</param>
        public void SetTextTime(long time)
        {
            textBoxTime.Text = time.ToString();

            return;
        }

        /// <summary>
        /// 画像処理の実行中に表示する画像をOFFする
        /// </summary>
        public void SetPictureBoxStatus()
        {
            pictureBoxStatus.Visible = false;

            return;
        }

        /// <summary>
        /// 画像処理実行用のタスク
        /// </summary>
        /// <returns>画像処理の実行結果 成功/失敗</returns>
        public async Task<bool> TaskWorkImageProcessing()
        {
            mTokenSource = new CancellationTokenSource();
            var token = mTokenSource.Token;
            var imageProcessingInfo = new ComImageProcessingInfo();
            var binarizationInfo = new BinarizationInfo
            {
                Thresh = (byte)sliderThresh.Value
            };
            imageProcessingInfo.CurrentImageProcessingName = mCurrentImageProcessingName;
            imageProcessingInfo.BinarizationInfo = binarizationInfo;
            bool result = await Task.Run(() => GoImageProcessing(imageProcessingInfo, token));
            return result;
        }

        /// <summary>
        /// イメージのロード処理
        /// </summary>
        public void LoadImage()
        {
            mBitmap = new Bitmap(mOpenFileName);
            mImageProcessing = new ImageProcessing(mBitmap);

            return;
        }

        /// <summary>
        /// Formのクローズイベント
        /// </summary>
        /// <param name="sender">オブジェクト</param>
        /// <param name="e">FormClosingイベントのデータ</param>
        public void OnFormClosingFormMain(object sender, FormClosingEventArgs e)
        {
            if (mTokenSource != null)
            {
                e.Cancel = true;
            }

            if (mHistgram != null)
            {
                mHistgram.Close();
                mHistgram = null;
            }

            return;
        }

        /// <summary>
        /// ファイル選択ボタンのクリックイベント
        /// </summary>
        /// <param name="sender">オブジェクト</param>
        /// <param name="e">イベントのデータ</param>
        public void OnClickBtnFileSelect(object sender, EventArgs e)
        {
            var openFileDlg = new ComOpenFileDialog
            {
                Filter = "JPG|*.jpg|PNG|*.png",
                Title = "Open the file"
            };
            if (openFileDlg.ShowDialog() == true)
            {
                pictureBoxOriginal.Image = null;
                pictureBoxAfter.Image = null;
                mOpenFileName = openFileDlg.FileName;
                try
                {
                    LoadImage();
                }
                catch (Exception)
                {
                    MessageBox.Show(this, "Open File Error", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                    return;
                }
                pictureBoxOriginal.ImageLocation = mOpenFileName;
                btnStart.Enabled = true;
                textBoxTime.Text = "";

                if (mHistgram == null)
                {
#if CHART_LIVE_CHART
                    mHistgram = new FormHistgramLiveCharts();
#elif CHART_OXY_PLOT
                    mHistgram = new FormHistgramOxyPlot();
#else
                    mHistgram = new FormHistgramOxyPlot();
#endif
                }
                else
                {
                    mHistgram.Close();
                    mHistgram = null;

#if CHART_LIVE_CHART
                    mHistgram = new FormHistgramLiveCharts();
#elif CHART_OXY_PLOT
                    mHistgram = new FormHistgramOxyPlot();
#else
                    mHistgram = new FormHistgramOxyPlot();
#endif
                }

                mHistgram.BitmapOrg = (Bitmap)new Bitmap(mOpenFileName).Clone();
                if (GetBitmap() != null)
                {
                    mHistgram.BitmapAfter = (Bitmap)GetBitmap().Clone();
                }
                mHistgram.DrawHistgram();
                mHistgram.IsOpen = true;
                mHistgram.Show();
            }
            return;
        }

        /// <summary>
        /// オールクリアボタンのクリックイベント
        /// </summary>
        /// <param name="sender">オブジェクト</param>
        /// <param name="e">イベントのデータ</param>
        private void OnClickBtnAllClear(object sender, EventArgs e)
        {
            pictureBoxOriginal.ImageLocation = null;
            pictureBoxAfter.Image = null;

            mBitmap = null;
            mOpenFileName = "";

            textBoxTime.Text = "";

            btnFileSelect.Enabled = true;
            btnAllClear.Enabled = true;
            btnStart.Enabled = false;
            btnSaveImage.Enabled = false;

            if (mHistgram != null)
            {
                mHistgram.Close();
            }

            return;
        }

        /// <summary>
        /// スタートボタンのクリックイベント
        /// </summary>
        /// <param name="sender">オブジェクト</param>
        /// <param name="e">イベントのデータ</param>
        private async void OnClickBtnStart(object sender, EventArgs e)
        {
            pictureBoxAfter.Image = null;

            btnFileSelect.Enabled = false;
            btnAllClear.Enabled = false;
            btnStart.Enabled = false;
            menuMain.Enabled = false;

            textBoxTime.Text = "";

            pictureBoxStatus.Visible = true;

            LoadImage();

            Stopwatch stopwatch = new Stopwatch();
            stopwatch.Start();
            btnStop.Enabled = true;
            btnSaveImage.Enabled = false;
            btnShowHistgram.Enabled = false;
            bool bResult = await TaskWorkImageProcessing();
            if (bResult)
            {
                pictureBoxOriginal.ImageLocation = mOpenFileName;
                pictureBoxAfter.Image = GetBitmap();

                stopwatch.Stop();

                Invoke(new Action<long>(SetTextTime), stopwatch.ElapsedMilliseconds);
                btnSaveImage.Enabled = true;

                mHistgram.BitmapOrg = (Bitmap)new Bitmap(mOpenFileName).Clone();
                if (GetBitmap() != null)
                {
                    mHistgram.BitmapAfter = (Bitmap)GetBitmap().Clone();
                }
                if (mHistgram.IsOpen == true)
                {
                    mHistgram.DrawHistgram();
                }
            }
            Invoke(new Action(SetPictureBoxStatus));
            Invoke(new Action(SetButtonEnable));
            menuMain.Enabled = true;
            btnShowHistgram.Enabled = true;

            stopwatch = null;
            mTokenSource = null;

            return;
        }

        /// <summary>
        /// ストップボタンのクリックイベント
        /// </summary>
        /// <param name="sender">オブジェクト</param>
        /// <param name="e">イベントのデータ</param>
        private void OnClickBtnStop(object sender, EventArgs e)
        {
            if (mTokenSource != null)
            {
                mTokenSource.Cancel();
            }

            return;
        }

        ///// <summary>
        ///// 画像処理のオブジェクトからイメージの取得
        ///// </summary>
        ///// <returns>ビットマップ</returns>
        //public Bitmap GetImage()
        //{
        //    Bitmap bitmap = mImageProcessing.Bitmap;

        //    return bitmap == null ? bitmap : (Bitmap)bitmap.Clone();
        //}

        /// <summary>
        /// イメージの保存ボタンのクリックイベント
        /// </summary>
        /// <param name="sender">オブジェクト</param>
        /// <param name="e">イベントのデータ</param>
        private void OnClickBtnSaveImage(object sender, EventArgs e)
        {
            var saveDialog = new ComSaveFileDialog
            {
                Filter = "PNG|*.png",
                Title = "Save the file"
            };
            if (saveDialog.ShowDialog() == true)
            {
                string fileName = saveDialog.FileName;
                var bitmap = (Bitmap)GetBitmap().Clone();
                if (bitmap != null)
                {
                    try
                    {
                        bitmap.Save(fileName, System.Drawing.Imaging.ImageFormat.Png);
                    }
                    catch (Exception)
                    {
                        MessageBox.Show(this, "Save Image File Error", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                    }
                    bitmap.Dispose();
                }
            }

            return;
        }

        /// <summary>
        /// ヒストグラム表示ボタンのクリックイベント
        /// </summary>
        /// <param name="sender">オブジェクト</param>
        /// <param name="e">イベントのデータ</param>
        private void OnClickBtnShowHistgram(object sender, EventArgs e)
        {
            if (mBitmap == null)
            {
                return;
            }

            if (mHistgram != null)
            {
                mHistgram.Close();
                mHistgram = null;
#if CHART_LIVE_CHART
                mHistgram = new FormHistgramLiveCharts();
#elif CHART_OXY_PLOT
                mHistgram = new FormHistgramOxyPlot();
#else
                mHistgram = new FormHistgramOxyPlot();
#endif
            }

            mHistgram.BitmapOrg = (Bitmap)new Bitmap(mOpenFileName).Clone();
            if (GetBitmap() != null)
            {
                mHistgram.BitmapAfter = (Bitmap)GetBitmap().Clone();
            }
            mHistgram.DrawHistgram();
            mHistgram.IsOpen = true;
            mHistgram.Show();

            return;
        }

        /// <summary>
        /// メニューのクリックイベント
        /// </summary>
        /// <param name="sender">オブジェクト</param>
        /// <param name="e">イベントのデータ</param>
        private void OnClickMenu(object sender, EventArgs e)
        {
            ToolStripMenuItem menuItem = (ToolStripMenuItem)sender;

            switch (menuItem.Text)
            {
                case ComInfo.MENU_FILE_END:
                    Close();
                    break;
                case ComInfo.MENU_SETTING_IMAGE_PROCESSING:
                    ShowSettingImageProcessing();
                    break;
                default:
                    break;
            }

            return;
        }

        /// <summary>
        /// 設定画面の処理
        /// </summary>
        public void ShowSettingImageProcessing()
        {
            FormSettingImageProcessing formSettingImageProcessing = new FormSettingImageProcessing();
            var dialogResult = formSettingImageProcessing.ShowDialog();

            if (dialogResult == DialogResult.OK)
            {
                mCurrentImageProcessingName = (string)formSettingImageProcessing.CmbBoxImageProcessingType.SelectedItem;
                this.Text = "Image Processing ( " + mCurrentImageProcessingName + " )";

                sliderThresh.Enabled = mCurrentImageProcessingName == ComInfo.IMG_NAME_BINARIZATION;

                pictureBoxAfter.Image = null;
                btnSaveImage.Enabled = false;
                if (mOpenFileName != null)
                {
                    mBitmap = new Bitmap(mOpenFileName);
                    mImageProcessing = new ImageProcessing(mBitmap);
                }
                if (mHistgram != null && mHistgram?.IsOpen == true)
                {
                    OnClickBtnShowHistgram(this, null);
                }
            }

            return;
        }

        /// <summary>
        /// 2値化の閾値のスライダのスクロールイベント
        /// </summary>
        /// <param name="sender">オブジェクト</param>
        /// <param name="e">イベントのデータ</param>
        private void OnScrollSliderThresh(object sender, EventArgs e)
        {
            var trackBar = (TrackBar)sender;
            labelValue.Text = trackBar.Value.ToString();
        }

        /// <summary>
        /// 2値化の閾値のスライダのキーアップイベント
        /// </summary>
        /// <param name="sender">オブジェクト</param>
        /// <param name="e">キーイベントのデータ</param>
        private void OnSliderPreviewKeyUp(object sender, KeyEventArgs e)
        {
            if (pictureBoxAfter.Image != null)
            {
                ParamAjust();
            }
        }

        /// <summary>
        /// 2値化の閾値のスライダのマウスアップイベント
        /// </summary>
        /// <param name="sender">オブジェクト</param>
        /// <param name="e">マウスボタンイベントのデータ</param>
        private void OnSliderMouseUp(object sender, MouseEventArgs e)
        {
            if (pictureBoxAfter.Image != null)
            {
                ParamAjust();
            }
        }

        /// <summary>
        /// 2値化のスライダを調整したときの処理
        /// </summary>
        private async void ParamAjust()
        {
            pictureBoxAfter.Image = null;

            btnFileSelect.Enabled = false;
            btnAllClear.Enabled = false;
            btnStart.Enabled = false;
            menuMain.Enabled = false;

            LoadImage();

            btnStop.Enabled = true;
            btnSaveImage.Enabled = false;
            bool bResult = await TaskWorkImageProcessing();
            if (bResult)
            {
                pictureBoxOriginal.ImageLocation = mOpenFileName;
                pictureBoxAfter.Image = GetBitmap();

                btnSaveImage.Enabled = true;

                mHistgram.BitmapOrg = (Bitmap)new Bitmap(mOpenFileName).Clone();
                if (GetBitmap() != null)
                {
                    mHistgram.BitmapAfter = (Bitmap)GetBitmap().Clone();
                }
                if (mHistgram.IsOpen == true)
                {
                    mHistgram.DrawHistgram();
                }
            }
            Invoke(new Action(SetButtonEnable));
            menuMain.Enabled = true;
            btnShowHistgram.Enabled = true;

            mTokenSource = null;

            return;
        }
    }
}