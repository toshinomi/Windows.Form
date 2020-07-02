using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

/// <summary>
/// 画像処理の共通のロジック
/// </summary>
abstract public class ComImageProcessing
{
    protected Bitmap mBitmap;

    /// <summary>
    /// コンストラクタ
    /// </summary>
    /// <param name="bitmap">ビットマップ</param>
    public ComImageProcessing(Bitmap bitmap)
    {
        mBitmap = bitmap;
    }

    /// <summary>
    /// デスクトラクタ
    /// </summary>
    ~ComImageProcessing()
    {
        mBitmap = null;
    }

    /// <summary>
    /// 初期化
    /// </summary>
    virtual public void Init()
    {
        mBitmap = null;
    }

    /// <summary>
    /// ビットマップ
    /// </summary>
    public Bitmap Bitmap
    {
        set { mBitmap = value; }
        get { return mBitmap; }
    }

    /// <summary>
    /// 画像処理実行の抽象
    /// </summary>
    /// <param name="imageProcessingName">画像処理オブジェクトの名称</param>
    /// <param name="token">キャンセルトークン</param>
    /// <returns>実行結果 成功/失敗</returns>
    abstract public bool GoImageProcessing(string imageProcessingName, CancellationToken token);
}