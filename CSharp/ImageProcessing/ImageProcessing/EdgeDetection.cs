using System;
using System.Collections.Generic;
using System.Drawing;
using System.Drawing.Imaging;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

/// <summary>
/// エッジ検出のロジック
/// </summary>
public class EdgeDetection
{
    /// <summary>
    /// コンストラクタ
    /// </summary>
    public EdgeDetection()
    {
    }

    /// <summary>
    /// デスクトラクタ
    /// </summary>
    ~EdgeDetection()
    {
    }

    /// <summary>
    /// エッジ検出の実行
    /// </summary>
    /// <param name="bitmap">ビットマップ</param>
    /// <param name="token">キャンセルトークン</param>
    /// <returns>実行結果 成功/失敗</returns>
    public bool ImageProcessing(ref Bitmap bitmap, CancellationToken token)
    {
        bool result = true;

        short[,] mask =
        {
            {1,  1, 1},
            {1, -8, 1},
            {1,  1, 1}
        };

        int widthSize = bitmap.Width;
        int heightSize = bitmap.Height;
        int maskSize = mask.GetLength(0);

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

                    long totalBlue = 0;
                    long totalGreen = 0;
                    long totalRed = 0;
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

                                totalBlue += pixelMaskArea[(int)ComInfo.Pixel.B] * mask[indexWidthMask, indexHightMask];
                                totalGreen += pixelMaskArea[(int)ComInfo.Pixel.G] * mask[indexWidthMask, indexHightMask];
                                totalRed += pixelMaskArea[(int)ComInfo.Pixel.R] * mask[indexWidthMask, indexHightMask];
                            }
                        }
                    }
                    pixel[(int)ComInfo.Pixel.B] = ComFunc.LongToByte(totalBlue);
                    pixel[(int)ComInfo.Pixel.G] = ComFunc.LongToByte(totalGreen);
                    pixel[(int)ComInfo.Pixel.R] = ComFunc.LongToByte(totalRed);
                }
            }
            bitmap.UnlockBits(bitmapData);
        }

        return result;
    }
}