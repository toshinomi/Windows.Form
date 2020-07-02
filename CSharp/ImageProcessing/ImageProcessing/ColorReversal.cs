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
/// 色反転のロジック
/// </summary>
class ColorReversal
{
    /// <summary>
    /// コンストラクタ
    /// </summary>
    public ColorReversal()
    {
    }

    /// <summary>
    /// デスクトラクタ
    /// </summary>
    ~ColorReversal()
    {
    }

    /// <summary>
    /// 色反転の実行
    /// </summary>
    /// <param name="bitmap">ビットマップ</param>
    /// <param name="token">キャンセルトークン</param>
    /// <returns>実行結果 成功/失敗</returns>
    public bool ImageProcessing(ref Bitmap bitmap, CancellationToken token)
    {
        bool result = true;

        int widthSize = bitmap.Width;
        int heightSize = bitmap.Height;

        var bitmapData = bitmap.LockBits(new Rectangle(0, 0, widthSize, heightSize), ImageLockMode.ReadWrite, PixelFormat.Format32bppArgb);

        int indexWidth;
        int indexHeight;

        unsafe
        {
            for (indexHeight = 0; indexHeight < heightSize; indexHeight++)
            {
                if (token.IsCancellationRequested)
                {
                    result = false;
                    break;
                }

                for (indexWidth = 0; indexWidth < widthSize; indexWidth++)
                {
                    if (token.IsCancellationRequested)
                    {
                        result = false;
                        break;
                    }

                    byte* pixel = (byte*)bitmapData.Scan0 + indexHeight * bitmapData.Stride + indexWidth * 4;

                    pixel[(int)ComInfo.Pixel.B] = (byte)(255 - pixel[(int)ComInfo.Pixel.B]);
                    pixel[(int)ComInfo.Pixel.G] = (byte)(255 - pixel[(int)ComInfo.Pixel.G]);
                    pixel[(int)ComInfo.Pixel.R] = (byte)(255 - pixel[(int)ComInfo.Pixel.R]);
                }
            }
            bitmap.UnlockBits(bitmapData);
        }

        return result;
    }
}