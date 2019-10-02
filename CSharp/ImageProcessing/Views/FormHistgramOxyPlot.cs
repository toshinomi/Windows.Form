using System;
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
    public partial class FormHistgramOxyPlot : Form
    {
        private int[,] m_nHistgram = new int[(int)ComInfo.PictureType.MAX, ComInfo.RGB_MAX];
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

        public FormHistgramOxyPlot()
        {
            InitializeComponent();

            chart.Model = new OxyPlot.PlotModel { PlotType = OxyPlot.PlotType.XY };
        }
    }
}
