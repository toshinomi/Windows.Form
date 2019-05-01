using System;
using System.Collections.Generic;
using System.Drawing;
using System.Drawing.Imaging;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace ImageProcessing
{
    public class EdgeDetection
    {
        private const int m_nMaskSize = 3;
        private uint m_nFilterMax;
        private Bitmap m_bitmap;

        public EdgeDetection(Bitmap _bitmap)
        {
            m_nFilterMax = 1;
            m_bitmap = _bitmap;
        }

        public EdgeDetection(Bitmap _bitmap, uint _filterMax)
        {
            m_nFilterMax = _filterMax;
            m_bitmap = _bitmap;
        }

        ~EdgeDetection()
        {
            m_bitmap = null;
        }

        public Bitmap GetBitmap()
        {
            return m_bitmap;
        }

        public void SetBitmap(Bitmap _bitmap)
        {
            m_bitmap = _bitmap;
        }

        public bool GoEdgeDetection(CancellationToken _token)
        {
            bool bRst = true;

            double[,] dMask =
            {
                {1.0,  1.0, 1.0},
                {1.0, -8.0, 1.0},
                {1.0,  1.0, 1.0}
            };

            int nWidthSize = m_bitmap.Width;
            int nHeightSize = m_bitmap.Height;
            int nMasksize = dMask.GetLength(0);

            BitmapData bitmapData = m_bitmap.LockBits(new Rectangle(0, 0, nWidthSize, nHeightSize), ImageLockMode.ReadWrite, PixelFormat.Format32bppArgb);

            int nIdxWidth;
            int nIdxHeight;

            unsafe
            {
                for (nIdxHeight = 0; nIdxHeight < nHeightSize; nIdxHeight++)
                {
                    for (nIdxWidth = 0; nIdxWidth < nWidthSize; nIdxWidth++)
                    {
                        if (_token.IsCancellationRequested)
                        {
                            bRst = false;
                            break;
                        }

                        byte* pPixel = (byte*)bitmapData.Scan0 + nIdxHeight * bitmapData.Stride + nIdxWidth * 4;

                        double dCalB = 0.0;
                        double dCalG = 0.0;
                        double dCalR = 0.0;
                        double dCalA = 0.0;
                        int nIdxWidthMask;
                        int nIdxHightMask;
                        int nFilter = 0;

                        while (nFilter < m_nFilterMax)
                        {
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

                                        dCalB += pPixel2[0] * dMask[nIdxWidthMask, nIdxHightMask];
                                        dCalG += pPixel2[1] * dMask[nIdxWidthMask, nIdxHightMask];
                                        dCalR += pPixel2[2] * dMask[nIdxWidthMask, nIdxHightMask];
                                        dCalA += pPixel2[3] * dMask[nIdxWidthMask, nIdxHightMask];
                                    }
                                }
                            }
                            nFilter++;
                        }
                        pPixel[0] = ComFunc.DoubleToByte(dCalB);
                        pPixel[1] = ComFunc.DoubleToByte(dCalG);
                        pPixel[2] = ComFunc.DoubleToByte(dCalR);
                        pPixel[3] = ComFunc.DoubleToByte(dCalA);
                    }
                }
                m_bitmap.UnlockBits(bitmapData);
            }

            return bRst;
        }
    }
}