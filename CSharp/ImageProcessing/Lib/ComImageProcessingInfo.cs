using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

/// <summary>
/// 画像処理の設定管理のロジック
/// </summary>
public class ComImageProcessingInfo
{
    /// <summary>
    /// 現在の画像処理の名称
    /// </summary>
    public string CurrentImageProcessingName { set; get; }

    /// <summary>
    /// エッジ検出の設定
    /// </summary>
    public EdgeDetectionInfo EdgeDetectoinInfo { set; get; }

    /// <summary>
    /// グレースケールの設定
    /// </summary>
    public GrayScaleInfo GrayScaleInfo { set; get; }

    /// <summary>
    /// 2値化の設定
    /// </summary>
    public BinarizationInfo BinarizationInfo { set; get; }

    /// <summary>
    /// グレースケール2次微分の設定
    /// </summary>
    public GrayScale2DiffInfo GrayScale2DiffInfo { set; get; }

    /// <summary>
    /// 色反転の設定
    /// </summary>
    public ColorReversalInfo ColorReversalInfo { set; get; }

    /// <summary>
    /// コンストラクタ
    /// </summary>
    public ComImageProcessingInfo()
    {
        EdgeDetectoinInfo = new EdgeDetectionInfo();
        GrayScaleInfo = new GrayScaleInfo();
        BinarizationInfo = new BinarizationInfo();
        GrayScale2DiffInfo = new GrayScale2DiffInfo();
        ColorReversalInfo = new ColorReversalInfo();
    }

    /// <summary>
    /// デスクトラクタ
    /// </summary>
    ~ComImageProcessingInfo()
    {
    }
}

/// <summary>
/// エッジ検出の設定管理のロジック
/// </summary>
public class EdgeDetectionInfo
{
    /// <summary>
    /// コンストラクタ
    /// </summary>
    public EdgeDetectionInfo()
    {
    }

    /// <summary>
    /// デスクトラクタ
    /// </summary>
    ~EdgeDetectionInfo()
    {
    }
}

/// <summary>
/// グレースケールの設定管理のロジック
/// </summary>
public class GrayScaleInfo
{
    /// <summary>
    /// コンストラクタ
    /// </summary>
    public GrayScaleInfo()
    {
    }

    /// <summary>
    /// デスクトラクタ
    /// </summary>
    ~GrayScaleInfo()
    {
    }
}

/// <summary>
/// 2値化の設定管理のロジック
/// </summary>
public class BinarizationInfo
{
    /// <summary>
    /// 閾値
    /// </summary>
    public byte Thresh { set; get; }

    /// <summary>
    /// コンストラクタ
    /// </summary>
    public BinarizationInfo()
    {
    }

    /// <summary>
    /// デスクトラクタ
    /// </summary>
    ~BinarizationInfo()
    {
    }
}

/// <summary>
/// グレースケール2次微分の設定管理のロジック
/// </summary>
public class GrayScale2DiffInfo
{
    /// <summary>
    /// コンストラクタ
    /// </summary>
    public GrayScale2DiffInfo()
    {
    }

    /// <summary>
    /// デスクトラクタ
    /// </summary>
    ~GrayScale2DiffInfo()
    {
    }
}

/// <summary>
/// 色反転の設定管理のロジック
/// </summary>
public class ColorReversalInfo
{
    /// <summary>
    /// コンストラクタ
    /// </summary>
    public ColorReversalInfo()
    {
    }

    /// <summary>
    /// デスクトラクタ
    /// </summary>
    ~ColorReversalInfo()
    {
    }
}