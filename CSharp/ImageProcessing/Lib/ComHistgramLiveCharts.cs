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
        get { return base.mHistgram; }
    }

    /// <summary>
    /// オリジナルのビットマップ
    /// </summary>
    public Bitmap BitmapOrg
    {
        set { base.mBitmapOrg = value; }
        get { return base.mBitmapOrg; }
    }

    /// <summary>
    /// 画像処理後のビットマップ
    /// </summary>
    public Bitmap BitmapAfter
    {
        set { base.mBitmapAfter = value; }
        get { return base.mBitmapAfter; }
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

        var lineSeriesChartOriginal = new LineSeries()
        {
            Values = new ChartValues<int>(),
            Title = "Original Image"
        };
        var lineSeriesChartAfter = new LineSeries()
        {
            Values = new ChartValues<int>(),
            Title = "After Image"
        };

        for (int index = 0; index < (base.mHistgram.Length >> 1); index++)
        {
            lineSeriesChartOriginal.Values.Add(mHistgram[(int)ComInfo.PictureType.Original, index]);
            lineSeriesChartAfter.Values.Add(mHistgram[(int)ComInfo.PictureType.After, index]);
        }

        var items = new List<LineSeries>
        {
            lineSeriesChartOriginal,
            lineSeriesChartAfter
        };

        return items;
    }
}