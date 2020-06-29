using System;
using System.Collections.Generic;
using System.Drawing;
using System.Drawing.Imaging;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows;

/// <summary>
/// 2値化のロジック
/// </summary>
class Binarization
{
    /// <summary>
    /// コンストラクタ
    /// </summary>
    public Binarization()
    {
    }

    /// <summary>
    /// デスクトラクタ
    /// </summary>
    ~Binarization()
    {
    }

    /// <summary>
    /// 2値化の実行
    /// </summary>
    /// <param name="bitmap">ビットマップ</param>
    /// <param name="token">キャンセルトークン</param>
    /// <param name="thresh">閾値</param>
    /// <returns>実行結果 成功/失敗</returns>
    public bool ImageProcessing(ref Bitmap bitmap, CancellationToken token, byte thresh)
    {
        bool bRst = true;

        int nWidthSize = bitmap.Width;
        int nHeightSize = bitmap.Height;

        var bitmapData = bitmap.LockBits(new Rectangle(0, 0, nWidthSize, nHeightSize), ImageLockMode.ReadWrite, PixelFormat.Format32bppArgb);

        int nIdxWidth;
        int nIdxHeight;

        unsafe
        {
            for (nIdxHeight = 0; nIdxHeight < nHeightSize; nIdxHeight++)
            {
                if (token.IsCancellationRequested)
                {
                    bRst = false;
                    break;
                }

                for (nIdxWidth = 0; nIdxWidth < nWidthSize; nIdxWidth++)
                {
                    if (token.IsCancellationRequested)
                    {
                        bRst = false;
                        break;
                    }

                    byte* pPixel = (byte*)bitmapData.Scan0 + nIdxHeight * bitmapData.Stride + nIdxWidth * 4;
                    byte nGrayScale = (byte)((pPixel[(int)ComInfo.Pixel.B] + pPixel[(int)ComInfo.Pixel.G] + pPixel[(int)ComInfo.Pixel.R]) / 3);

                    byte nBinarization = nGrayScale >= thresh ? (byte)255 : (byte)0;
                    pPixel[(int)ComInfo.Pixel.B] = nBinarization;
                    pPixel[(int)ComInfo.Pixel.G] = nBinarization;
                    pPixel[(int)ComInfo.Pixel.R] = nBinarization;
                }
            }
            bitmap.UnlockBits(bitmapData);
        }

        return bRst;
    }
}