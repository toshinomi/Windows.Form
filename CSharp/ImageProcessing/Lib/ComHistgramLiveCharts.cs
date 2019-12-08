using LiveCharts;
using LiveCharts.Wpf;
using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Media.Imaging;

/// <summary>
/// ライブチャートのヒストグラム表示のロジック
/// </summary>
class ComHistgramLiveCharts : ComCharts
{
    /// <summary>
    /// ヒストグラム用の2次元配列データ　配列の1次元：オリジナルのデータ、配列の2次元：画像処理後のデータ
    /// </summary>
    public int[,] Histgram
    {
        get { return base.m_nHistgram; }
    }

    /// <summary>
    /// オリジナルのビットマップ
    /// </summary>
    public Bitmap BitmapOrg
    {
        set { base.m_bitmapOrg = value; }
        get { return base.m_bitmapOrg; }
    }

    /// <summary>
    /// 画像処理後のビットマップ
    /// </summary>
    public Bitmap BitmapAfter
    {
        set { base.m_bitmapAfter = value; }
        get { return base.m_bitmapAfter; }
    }

    /// <summary>
    /// コンストラクタ
    /// </summary>
    public ComHistgramLiveCharts()
    {
    }

    /// <summary>
    /// デスクトラクタ
    /// </summary>
    ~ComHistgramLiveCharts()
    {
    }

    /// <summary>
    /// ヒストグラムの描画データ処理
    /// </summary>
    /// <returns>ヒストグラムのデータ</returns>
    public List<LineSeries> DrawHistgram()
    {
        base.InitHistgram();

        base.CalHistgram();

        LineSeries lineSeriesChart1 = new LineSeries()
        {
            Values = new ChartValues<int>(),
            Title = "Original Image"
        };
        LineSeries lineSeriesChart2 = new LineSeries()
        {
            Values = new ChartValues<int>(),
            Title = "After Image"
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