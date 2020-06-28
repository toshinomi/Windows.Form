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
/// 画像処理のロジック
/// </summary>
namespace ImageProcessing
{
    class ImageProcessing : ComImageProcessing
    {
        private readonly ProdessingArray[] array = new ProdessingArray[(int)ComInfo.ImgProcType.MAX];

        /// <summary>
        /// 閾値
        /// </summary>
        public byte Thresh { set; get; }

        /// <summary>
        /// コンストラクタ
        /// </summary>
        /// <param name="bitmap">ビットマップ</param>
        public ImageProcessing(Bitmap bitmap) : base(bitmap)
        {
            array[(int)ComInfo.ImgProcType.EdgeDetection].processing = EdgeDetection;
            array[(int)ComInfo.ImgProcType.GrayScale].processing = GrayScale;
            array[(int)ComInfo.ImgProcType.Binarization].processing = Binarization;
            array[(int)ComInfo.ImgProcType.GrayScale2Diff].processing = GrayScale2Diff;
            array[(int)ComInfo.ImgProcType.ColorReversal].processing = ColorReversal;
        }

        /// <summary>
        /// デスクトラクタ
        /// </summary>
        ~ImageProcessing()
        {
        }

        /// <summary>
        /// 初期化
        /// </summary>
        public override void Init()
        {
            base.Init();
        }

        private delegate bool Processing(CancellationToken _token);

        private struct ProdessingArray
        {
            public Processing processing;
        }

        /// <summary>
        /// エッジ検出の実行
        /// </summary>
        /// <param name="token">キャンセルトークン</param>
        /// <returns>実行結果 成功/失敗</returns>
        private bool EdgeDetection(CancellationToken token)
        {
            bool bRst = true;

            short[,] nMask =
            {
                {1,  1, 1},
                {1, -8, 1},
                {1,  1, 1}
            };

            int nWidthSize = base.m_bitmap.Width;
            int nHeightSize = base.m_bitmap.Height;
            int nMasksize = nMask.GetLength(0);

            base.m_bitmapAfter = new Bitmap(base.m_bitmap);

            BitmapData bitmapData = base.m_bitmapAfter.LockBits(new Rectangle(0, 0, nWidthSize, nHeightSize), ImageLockMode.ReadWrite, PixelFormat.Format32bppArgb);

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

                        long dCalB = 0;
                        long dCalG = 0;
                        long dCalR = 0;
                        int nIdxWidthMask;
                        int nIdxHightMask;

                        for (nIdxHightMask = 0; nIdxHightMask < nMasksize; nIdxHightMask++)
                        {
                            for (nIdxWidthMask = 0; nIdxWidthMask < nMasksize; nIdxWidthMask++)
                            {
                                if (nIdxWidth + nIdxWidthMask > 0 &&
                                    nIdxWidth + nIdxWidthMask < nWidthSize &&
                                    nIdxHeight + nIdxHightMask > 0 &&
                                    nIdxHeight + nIdxHightMask < nHeightSize)
                                {
                                    byte* pPixel2 = (byte*)bitmapData.Scan0 + (nIdxHeight + nIdxHightMask) * bitmapData.Stride + (nIdxWidth + nIdxWidthMask) * 4;

                                    dCalB += pPixel2[(int)ComInfo.Pixel.B] * nMask[nIdxWidthMask, nIdxHightMask];
                                    dCalG += pPixel2[(int)ComInfo.Pixel.G] * nMask[nIdxWidthMask, nIdxHightMask];
                                    dCalR += pPixel2[(int)ComInfo.Pixel.R] * nMask[nIdxWidthMask, nIdxHightMask];
                                }
                            }
                        }
                        pPixel[(int)ComInfo.Pixel.B] = ComFunc.LongToByte(dCalB);
                        pPixel[(int)ComInfo.Pixel.G] = ComFunc.LongToByte(dCalG);
                        pPixel[(int)ComInfo.Pixel.R] = ComFunc.LongToByte(dCalR);
                    }
                }
                base.m_bitmapAfter.UnlockBits(bitmapData);
            }

            return bRst;
        }

        /// <summary>
        /// グレースケールの実行
        /// </summary>
        /// <param name="token">キャンセルトークン</param>
        /// <returns>実行結果 成功/失敗</returns>
        private bool GrayScale(CancellationToken token)
        {
            bool bRst = true;

            int nWidthSize = base.m_bitmap.Width;
            int nHeightSize = base.m_bitmap.Height;

            base.m_bitmapAfter = new Bitmap(base.m_bitmap);

            BitmapData bitmapData = base.m_bitmapAfter.LockBits(new Rectangle(0, 0, nWidthSize, nHeightSize), ImageLockMode.ReadWrite, PixelFormat.Format32bppArgb);

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

                        pPixel[(int)ComInfo.Pixel.B] = nGrayScale;
                        pPixel[(int)ComInfo.Pixel.G] = nGrayScale;
                        pPixel[(int)ComInfo.Pixel.R] = nGrayScale;
                    }
                }
                base.m_bitmapAfter.UnlockBits(bitmapData);
            }

            return bRst;
        }

        /// <summary>
        /// 2値化の実行
        /// </summary>
        /// <param name="token">キャンセルトークン</param>
        /// <returns>実行結果 成功/失敗</returns>
        private bool Binarization(CancellationToken token)
        {
            bool bRst = true;

            int nWidthSize = base.m_bitmap.Width;
            int nHeightSize = base.m_bitmap.Height;

            base.m_bitmapAfter = new Bitmap(base.m_bitmap);

            BitmapData bitmapData = base.m_bitmapAfter.LockBits(new Rectangle(0, 0, nWidthSize, nHeightSize), ImageLockMode.ReadWrite, PixelFormat.Format32bppArgb);

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

                        byte nBinarization = nGrayScale >= Thresh ? (byte)255 : (byte)0;
                        pPixel[(int)ComInfo.Pixel.B] = nBinarization;
                        pPixel[(int)ComInfo.Pixel.G] = nBinarization;
                        pPixel[(int)ComInfo.Pixel.R] = nBinarization;
                    }
                }
                base.m_bitmapAfter.UnlockBits(bitmapData);
            }

            return bRst;
        }

        /// <summary>
        /// グレースケール2次微分の実行
        /// </summary>
        /// <param name="token">キャンセルトークン</param>
        /// <returns>実行結果 成功/失敗</returns>
        private bool GrayScale2Diff(CancellationToken token)
        {
            bool bRst = true;

            short[,] nMask =
            {
                {1,  1, 1},
                {1, -8, 1},
                {1,  1, 1}
            };

            int nWidthSize = base.m_bitmap.Width;
            int nHeightSize = base.m_bitmap.Height;
            int nMasksize = nMask.GetLength(0);

            base.m_bitmapAfter = new Bitmap(base.m_bitmap);

            BitmapData bitmapData = base.m_bitmapAfter.LockBits(new Rectangle(0, 0, nWidthSize, nHeightSize), ImageLockMode.ReadWrite, PixelFormat.Format32bppArgb);

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

                        long lCalB = 0;
                        long lCalG = 0;
                        long lCalR = 0;
                        double dCalAve = 0.0;
                        int nIdxWidthMask;
                        int nIdxHightMask;


                        for (nIdxHightMask = 0; nIdxHightMask < nMasksize; nIdxHightMask++)
                        {
                            for (nIdxWidthMask = 0; nIdxWidthMask < nMasksize; nIdxWidthMask++)
                            {
                                if (nIdxWidth + nIdxWidthMask > 0 &&
                                    nIdxWidth + nIdxWidthMask < nWidthSize &&
                                    nIdxHeight + nIdxHightMask > 0 &&
                                    nIdxHeight + nIdxHightMask < nHeightSize)
                                {
                                    byte* pPixel2 = (byte*)bitmapData.Scan0 + (nIdxHeight + nIdxHightMask) * bitmapData.Stride + (nIdxWidth + nIdxWidthMask) * 4;

                                    lCalB = pPixel2[(int)ComInfo.Pixel.B] * nMask[nIdxWidthMask, nIdxHightMask];
                                    lCalG = pPixel2[(int)ComInfo.Pixel.G] * nMask[nIdxWidthMask, nIdxHightMask];
                                    lCalR = pPixel2[(int)ComInfo.Pixel.R] * nMask[nIdxWidthMask, nIdxHightMask];

                                    double dcalGray = (lCalB + lCalG + lCalR) / 3;
                                    dCalAve = (dCalAve + dcalGray) / 2;
                                }
                            }
                        }
                        byte nGrayScale = ComFunc.DoubleToByte(dCalAve);

                        pPixel[(int)ComInfo.Pixel.B] = nGrayScale;
                        pPixel[(int)ComInfo.Pixel.G] = nGrayScale;
                        pPixel[(int)ComInfo.Pixel.R] = nGrayScale;
                    }
                }
                base.m_bitmapAfter.UnlockBits(bitmapData);
            }

            return bRst;
        }

        /// <summary>
        /// 色反転の実行
        /// </summary>
        /// <param name="token">キャンセルトークン</param>
        /// <returns>実行結果 成功/失敗</returns>
        private bool ColorReversal(CancellationToken token)
        {
            bool bRst = true;

            int nWidthSize = base.m_bitmap.Width;
            int nHeightSize = base.m_bitmap.Height;

            base.m_bitmapAfter = new Bitmap(base.m_bitmap);

            BitmapData bitmapData = base.m_bitmapAfter.LockBits(new Rectangle(0, 0, nWidthSize, nHeightSize), ImageLockMode.ReadWrite, PixelFormat.Format32bppArgb);

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

                        pPixel[(int)ComInfo.Pixel.B] = (byte)(255 - pPixel[(int)ComInfo.Pixel.B]);
                        pPixel[(int)ComInfo.Pixel.G] = (byte)(255 - pPixel[(int)ComInfo.Pixel.G]);
                        pPixel[(int)ComInfo.Pixel.R] = (byte)(255 - pPixel[(int)ComInfo.Pixel.R]);
                    }
                }
                base.m_bitmapAfter.UnlockBits(bitmapData);
            }

            return bRst;
        }

        /// <summary>
        /// 画像処理の実行
        /// </summary>
        /// <param name="imageProcessingName">画像処理オブジェクトの名称</param>
        /// <param name="token">キャンセルトークン</param>
        /// <returns>実行結果 成功/失敗</returns>
        public override bool GoImageProcessing(string imageProcessingName, CancellationToken token)
        {
            int index = 0;

            switch (imageProcessingName)
            {
                case ComInfo.IMG_NAME_EDGE_DETECTION:
                    index = (int)ComInfo.ImgProcType.EdgeDetection;
                    break;
                case ComInfo.IMG_NAME_GRAY_SCALE:
                    index = (int)ComInfo.ImgProcType.GrayScale;
                    break;
                case ComInfo.IMG_NAME_BINARIZATION:
                    index = (int)ComInfo.ImgProcType.Binarization;
                    break;
                case ComInfo.IMG_NAME_GRAY_SCALE_2DIFF:
                    index = (int)ComInfo.ImgProcType.GrayScale2Diff;
                    break;
                case ComInfo.IMG_NAME_COLOR_REVERSAL:
                    index = (int)ComInfo.ImgProcType.ColorReversal;
                    break;
                default:
                    break;
            }

            return array[index].processing(token);
        }
    }
}