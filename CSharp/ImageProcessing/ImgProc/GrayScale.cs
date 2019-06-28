﻿using System;
using System.Collections.Generic;
using System.Drawing;
using System.Drawing.Imaging;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace ImageProcessing
{
    class GrayScale : ComImgProc
    {
        public GrayScale(Bitmap _bitmap) : base(_bitmap)
        {
        }

        ~GrayScale()
        {
        }

        public override bool GoImgProc(CancellationToken _token)
        {
            bool bRst = true;

            int nWidthSize = base.m_bitmap.Width;
            int nHeightSize = base.m_bitmap.Height;

            BitmapData bitmapData = base.m_bitmap.LockBits(new Rectangle(0, 0, nWidthSize, nHeightSize), ImageLockMode.ReadWrite, PixelFormat.Format32bppArgb);

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
                        byte nGrayScale = (byte)((pPixel[(int)ComInfo.Pixel.B] + pPixel[(int)ComInfo.Pixel.G] + pPixel[(int)ComInfo.Pixel.R]) / 3);

                        pPixel[(int)ComInfo.Pixel.B] = nGrayScale;
                        pPixel[(int)ComInfo.Pixel.G] = nGrayScale;
                        pPixel[(int)ComInfo.Pixel.R] = nGrayScale;
                    }
                }
                base.m_bitmap.UnlockBits(bitmapData);
            }
            
            return bRst;
        }
    }
}