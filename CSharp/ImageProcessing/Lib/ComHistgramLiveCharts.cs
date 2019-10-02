using LiveCharts;
using LiveCharts.Wpf;
using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Media.Imaging;

class ComHistgramLiveCharts : ComCharts
{
    public int[,] Histgram
    {
        get { return base.m_nHistgram; }
    }

    public Bitmap BitmapOrg
    {
        set { base.m_bitmapOrg = value; }
        get { return base.m_bitmapOrg; }
    }

    public Bitmap BitmapAfter
    {
        set { base.m_bitmapAfter = value; }
        get { return base.m_bitmapAfter; }
    }

    public ComHistgramLiveCharts()
    {
    }

    ~ComHistgramLiveCharts()
    {
    }

    public List<LineSeries> DrawHistgram()
    {
        base.InitHistgram();

        base.CalHistgram();

        LineSeries lineSeriesChart1 = new LineSeries()
        {
            Values = new ChartValues<int>(),
            Title = "Histgram Original"
        };
        LineSeries lineSeriesChart2 = new LineSeries()
        {
            Values = new ChartValues<int>(),
            Title = "Histgram After"
        };

        for (int nIdx = 0; nIdx < (base.m_nHistgram.Length >> 1); nIdx++)
        {
            lineSeriesChart1.Values.Add(m_nHistgram[(int)ComInfo.PictureType.Original, nIdx]);
            lineSeriesChart2.Values.Add(m_nHistgram[(int)ComInfo.PictureType.After, nIdx]);
        }

        List<LineSeries> items = new List<LineSeries>();
        items.Add(lineSeriesChart1);
        items.Add(lineSeriesChart2);

        return items;
    }
}