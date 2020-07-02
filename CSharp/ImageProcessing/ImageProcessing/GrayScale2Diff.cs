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
/// グレースケール2次微分のロジック
/// </summary>
class GrayScale2Diff
{
    /// <summary>
    /// コンストラクタ
    /// </summary>
    public GrayScale2Diff()
    {
    }

    /// <summary>
    /// デスクトラクタ
    /// </summary>
    ~GrayScale2Diff()
    {
    }

    /// <summary>
    /// グレースケール2次微分の実行
    /// </summary>
    /// <param name="bitmap">ビットマップ</param>
    /// <param name="token">キャンセルトークン</param>
    /// <returns>実行結果 成功/失敗</returns>
    public bool ImageProcessing(ref Bitmap bitmap, CancellationToken token)
    {
        bool result = true;

        short[,] nMask =
        {
            {1,  1, 1},
            {1, -8, 1},
            {1,  1, 1}
        };

        int widthSize = bitmap.Width;
        int heightSize = bitmap.Height;
        int maskSize = nMask.GetLength(0);

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

                    long blue = 0;
                    long green = 0;
                    long red = 0;
                    double averageGrayScale = 0.0;
                    int indexWidthMask;
                    int indexHightMask;


                    for (indexHightMask = 0; indexHightMask < maskSize; indexHightMask++)
                    {
                        for (indexWidthMask = 0; indexWidthMask < maskSize; indexWidthMask++)
                        {
                            if (indexWidth + indexWidthMask > 0 &&
                                indexWidth + indexWidthMask < widthSize &&
                                indexHeight + indexHightMask > 0 &&
                                indexHeight + indexHightMask < heightSize)
                            {
                                byte* pixelMaskArea = (byte*)bitmapData.Scan0 + (indexHeight + indexHightMask) * bitmapData.Stride + (indexWidth + indexWidthMask) * 4;

                                blue = pixelMaskArea[(int)ComInfo.Pixel.B] * nMask[indexWidthMask, indexHightMask];
                                green = pixelMaskArea[(int)ComInfo.Pixel.G] * nMask[indexWidthMask, indexHightMask];
                                red = pixelMaskArea[(int)ComInfo.Pixel.R] * nMask[indexWidthMask, indexHightMask];

                                double gray = (blue + green + red) / 3;
                                averageGrayScale = (averageGrayScale + gray) / 2;
                            }
                        }
                    }
                    byte grayScale = ComFunc.DoubleToByte(averageGrayScale);

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