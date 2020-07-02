using System;
using System.Collections.Generic;
using System.Drawing;
using System.Drawing.Imaging;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

/// <summary>
/// グレースケールのロジック
/// </summary>
class GrayScale
{
    /// <summary>
    /// コンストラクタ
    /// </summary>
    public GrayScale()
    {
    }

    /// <summary>
    /// デスクトラクタ
    /// </summary>
    ~GrayScale()
    {
    }

    /// <summary>
    /// グレースケールの実行
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
                    byte grayScale = (byte)((pixel[(int)ComInfo.Pixel.B] + pixel[(int)ComInfo.Pixel.G] + pixel[(int)ComInfo.Pixel.R]) / 3);

                    pixel[(int)ComInfo.Pixel.B] = grayScale;
                    pixel[(int)ComInfo.Pixel.G] = grayScale;
                    pixel[(int)ComInfo.Pixel.R] = grayScale;
                }
            }
            bitmap.UnlockBits(bitmapData);
        }
            
        return result;
    }
}