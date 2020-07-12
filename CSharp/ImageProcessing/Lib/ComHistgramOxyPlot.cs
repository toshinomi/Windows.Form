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
    public PlotModel PlotModel { get; set; }

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
    public ComHistgramOxyPlot()
    {
        PlotModel = new PlotModel();
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

        var dataListOriginal = new List<DataPoint>();
        for (int index = 0; index < (mHistgram.Length >> 1); index++)
        {
            var dataPoint = new DataPoint(index, base.mHistgram[(int)ComInfo.PictureType.Original, index]);
            dataListOriginal.Add(dataPoint);
        }
        var seriesOriginal = new LineSeries
        {
            Title = "Original",
            ItemsSource = dataListOriginal,
        };
        PlotModel.Series.Add(seriesOriginal);

        var dataListAfter = new List<DataPoint>();
        for (int index = 0; index < (mHistgram.Length >> 1); index++)
        {
            var dataPoint = new DataPoint(index, base.mHistgram[(int)ComInfo.PictureType.After, index]);
            dataListAfter.Add(dataPoint);
        }
        var seriesAfter = new LineSeries
        {
            Title = "After",
            ItemsSource = dataListAfter,
        };
        PlotModel.Series.Add(seriesAfter);

        return PlotModel;
    }
}