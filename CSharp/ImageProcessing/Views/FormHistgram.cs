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
    public partial class FormHistgram : Form
    {
        private int[,] m_nHistgram = new int[2, 256];
        private Bitmap m_bitmapOrg;
        private Bitmap m_bitmapAfter;
        private bool m_bIsOpen;

        public Bitmap BitmapOrg
        {
            set { m_bitmapOrg = value; }
            get { return m_bitmapOrg; }
        }

        public Bitmap BitmapAfter
        {
            set { m_bitmapAfter = value; }
            get { return m_bitmapAfter; }
        }

        public bool IsOpen
        {
            set { m_bIsOpen = value; }
            get { return m_bIsOpen; }
        }

        public FormHistgram()
        {
            InitializeComponent();
        }

        public void DrawHistgram()
        {
            InitHistgram();

            CalHistgram();

            LineSeries lineSeriesChart1 = new LineSeries()
            {
                Values = new ChartValues<int>(),
                Title = "Histgram"
            };
            LineSeries lineSeriesChart2 = new LineSeries()
            {
                Values = new ChartValues<int>(),
                Title = "Histgram"
            };

            for (int nIdx = 0; nIdx < (m_nHistgram.Length >> 1); nIdx++)
            {
                lineSeriesChart1.Values.Add(m_nHistgram[0, nIdx]);
                lineSeriesChart2.Values.Add(m_nHistgram[1, nIdx]);
            }
            chart.Series.Clear();
            chart.Series.Add(lineSeriesChart1);
            chart.Series.Add(lineSeriesChart2);

            return;
        }

        public void CalHistgram()
        {
            int nWidthSize = m_bitmapOrg.Width;
            int nHeightSize = m_bitmapOrg.Height;

            BitmapData bitmapDataOrg = m_bitmapOrg.LockBits(new Rectangle(0, 0, nWidthSize, nHeightSize), ImageLockMode.ReadWrite, PixelFormat.Format32bppArgb);
            BitmapData bitmapDataAfter = m_bitmapAfter.LockBits(new Rectangle(0, 0, nWidthSize, nHeightSize), ImageLockMode.ReadWrite, PixelFormat.Format32bppArgb);

            int nIdxWidth;
            int nIdxHeight;

            unsafe
            {
                for (nIdxHeight = 0; nIdxHeight < nHeightSize; nIdxHeight++)
                {
                    for (nIdxWidth = 0; nIdxWidth < nWidthSize; nIdxWidth++)
                    {
                        byte* pPixel = (byte*)bitmapDataOrg.Scan0 + nIdxHeight * bitmapDataOrg.Stride + nIdxWidth * 4;
                        byte nGrayScale = (byte)((pPixel[(int)ComInfo.Pixel.B] + pPixel[(int)ComInfo.Pixel.G] + pPixel[(int)ComInfo.Pixel.R]) / 3);

                        m_nHistgram[0, nGrayScale] += 1;

                        if (m_bitmapAfter != null)
                        {
                            pPixel = (byte*)bitmapDataAfter.Scan0 + nIdxHeight * bitmapDataAfter.Stride + nIdxWidth * 4;
                            nGrayScale = (byte)((pPixel[(int)ComInfo.Pixel.B] + pPixel[(int)ComInfo.Pixel.G] + pPixel[(int)ComInfo.Pixel.R]) / 3);

                            m_nHistgram[1, nGrayScale] += 1;
                        }
                    }
                }
                m_bitmapOrg.UnlockBits(bitmapDataOrg);
                m_bitmapAfter.UnlockBits(bitmapDataAfter);
            }
        }

        public void InitHistgram()
        {
            for (int nIdx = 0; nIdx < (m_nHistgram.Length >> 1); nIdx++)
            {
                m_nHistgram[0, nIdx] = 0;
                m_nHistgram[1, nIdx] = 0;
            }
        }
    }
}
