﻿using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ImageProcessing
{
    /// <summary>
    /// FormHistgramOxyPlot のロジック
    /// </summary>
    public partial class FormHistgramOxyPlot : Form
    {
        private ComHistgramOxyPlot m_histgramChart;
        private bool m_bIsOpen;

        /// <summary>
        /// オリジナルのビットマップ
        /// </summary>
        public Bitmap BitmapOrg
        {
            set { m_histgramChart.BitmapOrg = value; }
            get { return m_histgramChart.BitmapOrg; }
        }

        /// <summary>
        /// 画像処理後のビットマップ
        /// </summary>
        public Bitmap BitmapAfter
        {
            set { m_histgramChart.BitmapAfter = value; }
            get { return m_histgramChart.BitmapAfter; }
        }

        /// <summary>
        /// Formのオープン状態
        /// </summary>
        public bool IsOpen
        {
            set { m_bIsOpen = value; }
            get { return m_bIsOpen; }
        }

        /// <summary>
        /// コンストラクタ
        /// </summary>
        public FormHistgramOxyPlot()
        {
            InitializeComponent();

            m_histgramChart = new ComHistgramOxyPlot();
        }

        /// <summary>
        /// グラフの描画
        /// </summary>
        public void DrawHistgram()
        {
            if (chart.Model != null)
            {
                chart.Model.Series.Clear();
                chart.Model = null;
            }
            chart.Model = m_histgramChart.DrawHistgram();

            return;
        }

        /// <summary>
        /// Formのクローズ処理
        /// </summary>
        /// <param name="sender">オブジェクト</param>
        /// <param name="e">FormClosingイベントのデータ</param>
        private void OnFormClosingFormHistgramOxyPlot(object sender, FormClosingEventArgs e)
        {
            m_bIsOpen = false;

            return;
        }

        /// <summary>
        /// メニューのクリック
        /// </summary>
        /// <param name="sender">オブジェクト</param>
        /// <param name="e">イベントのデータ</param>
        public void OnClickMenu(object sender, EventArgs e)
        {
            string strHeader = sender.ToString();

            switch (strHeader)
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
            if (!m_histgramChart.SaveCsv())
            {
                MessageBox.Show(this, "Save CSV File Error", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }

            return;
        }
    }
}
