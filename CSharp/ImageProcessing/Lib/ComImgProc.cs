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
    protected Bitmap m_bitmap;
    protected Bitmap m_bitmapAfter;

    /// <summary>
    /// コンストラクタ
    /// </summary>
    /// <param name="bitmap">ビットマップ</param>
    public ComImageProcessing(Bitmap bitmap)
    {
        m_bitmap = bitmap;
    }

    /// <summary>
    /// デスクトラクタ
    /// </summary>
    ~ComImageProcessing()
    {
        m_bitmap = null;
        m_bitmapAfter = null;
    }

    /// <summary>
    /// 初期化
    /// </summary>
    virtual public void Init()
    {
        m_bitmap = null;
        m_bitmapAfter = null;
    }

    /// <summary>
    /// ビットマップ
    /// </summary>
    public Bitmap Bitmap
    {
        set { m_bitmap = value; }
        get { return m_bitmap; }
    }

    /// <summary>
    /// 画像処理後のビットマップ
    /// </summary>
    public Bitmap BitmapAfter
    {
        set { m_bitmapAfter = value; }
        get { return m_bitmapAfter; }
    }

    /// <summary>
    /// 画像処理実行の抽象
    /// </summary>
    /// <param name="imageProcessingName">画像処理オブジェクトの名称</param>
    /// <param name="token">キャンセルトークン</param>
    /// <returns>実行結果 成功/失敗</returns>
    abstract public bool GoImageProcessing(string imageProcessingName, CancellationToken token);
}