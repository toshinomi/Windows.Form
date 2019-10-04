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
    public partial class FormHistgramLiveCharts : Form
    {
        private ComHistgramLiveCharts m_histgramChart;
        private bool m_bIsOpen;

        public Bitmap BitmapOrg
        {
            set { m_histgramChart.BitmapOrg = value; }
            get { return m_histgramChart.BitmapOrg; }
        }

        public Bitmap BitmapAfter
        {
            set { m_histgramChart.BitmapAfter = value; }
            get { return m_histgramChart.BitmapAfter; }
        }

        public bool IsOpen
        {
            set { m_bIsOpen = value; }
            get { return m_bIsOpen; }
        }

        public FormHistgramLiveCharts()
        {
            InitializeComponent();

            m_histgramChart = new ComHistgramLiveCharts();
        }

        public void DrawHistgram()
        {
            List<LineSeries> items = new List<LineSeries>();
            items = m_histgramChart.DrawHistgram();

            chart.Series.Clear();
            for (int nIdx = 0; nIdx < items.Count; nIdx++)
            {
                chart.Series.Add(items[nIdx]);
            }

            return;
        }

        private void OnFormClosingFormHistgramLiveCharts(object sender, FormClosingEventArgs e)
        {
            m_bIsOpen = false;

            return;
        }

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