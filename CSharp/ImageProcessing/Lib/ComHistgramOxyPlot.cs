using OxyPlot;
using OxyPlot.Series;
using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

/// <summary>
/// OXYプロットのヒストグラム表示のロジック
/// </summary>
class ComHistgramOxyPlot : ComCharts
{
    /// <summary>
    /// プロットモデル
    /// </summary>
    public PlotModel PModel { get; set; }

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
    public ComHistgramOxyPlot()
    {
        PModel = new PlotModel();
    }

    /// <summary>
    /// デスクトラクタ
    /// </summary>
    ~ComHistgramOxyPlot()
    {
    }

    /// <summary>
    /// ヒストグラムの描画データ処理
    /// </summary>
    /// <returns>ヒストグラムのデータ</returns>
    public PlotModel DrawHistgram()
    {
        base.InitHistgram();

        base.CalHistgram();

        var dataList1 = new List<DataPoint>();
        for (int nIdx = 0; nIdx < (m_nHistgram.Length >> 1); nIdx++)
        {
            var dataPoint = new DataPoint(nIdx, base.m_nHistgram[(int)ComInfo.PictureType.Original, nIdx]);
            dataList1.Add(dataPoint);
        }
        var series1 = new LineSeries
        {
            Title = "Original",
            ItemsSource = dataList1,
        };
        PModel.Series.Add(series1);

        var dataList2 = new List<DataPoint>();
        for (int nIdx = 0; nIdx < (m_nHistgram.Length >> 1); nIdx++)
        {
            var dataPoint = new DataPoint(nIdx, base.m_nHistgram[(int)ComInfo.PictureType.After, nIdx]);
            dataList2.Add(dataPoint);
        }
        var series2 = new LineSeries
        {
            Title = "After",
            ItemsSource = dataList2,
        };
        PModel.Series.Add(series2);

        return PModel;
    }
}