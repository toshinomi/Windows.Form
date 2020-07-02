using LiveCharts;
using LiveCharts.Wpf;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Drawing.Imaging;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ImageProcessing
{
    /// <summary>
    /// FormHistgramLiveCharts のロジック
    /// </summary>
    public partial class FormHistgramLiveCharts : Form
    {
        private readonly ComHistgramLiveCharts mHistgramChart;

        /// <summary>
        /// オリジナルのビットマップ
        /// </summary>
        public Bitmap BitmapOrg
        {
            set { mHistgramChart.BitmapOrg = value; }
            get { return mHistgramChart.BitmapOrg; }
        }

        /// <summary>
        /// 画像処理後のビットマップ
        /// </summary>
        public Bitmap BitmapAfter
        {
            set { mHistgramChart.BitmapAfter = value; }
            get { return mHistgramChart.BitmapAfter; }
        }

        /// <summary>
        /// Formのオープン状態
        /// </summary>
        public bool IsOpen { set; get; }

        /// <summary>
        /// コンストラクタ
        /// </summary>
        public FormHistgramLiveCharts()
        {
            InitializeComponent();

            mHistgramChart = new ComHistgramLiveCharts();
        }

        /// <summary>
        /// グラフの描画
        /// </summary>
        public void DrawHistgram()
        {
            var items = mHistgramChart.DrawHistgram();

            chart.Series.Clear();
            for (int index = 0; index < items.Count; index++)
            {
                chart.Series.Add(items[index]);
            }

            return;
        }

        /// <summary>
        /// Formのクローズ処理
        /// </summary>
        /// <param name="sender">オブジェクト</param>
        /// <param name="e">FormClosingイベントのデータ</param>
        private void OnFormClosingFormHistgramLiveCharts(object sender, FormClosingEventArgs e)
        {
            IsOpen = false;

            return;
        }

        /// <summary>
        /// メニューのクリック
        /// </summary>
        /// <param name="sender">オブジェクト</param>
        /// <param name="e">イベントのデータ</param>
        public void OnClickMenu(object sender, EventArgs e)
        {
            string menuTitle = sender.ToString();

            switch (menuTitle)
            {
                case ComInfo.MENU_SAVE_CSV:
                    SaveCsv();
                    break;
                default:
                    break;
            }

            return;
        }

        /// <summary>
        /// CSVファイル保存
        /// </summary>
        public void SaveCsv()
        {
            if (!mHistgramChart.SaveCsv())
            {
                MessageBox.Show(this, "Save CSV File Error", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }

            return;
        }
    }
}