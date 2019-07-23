#include "GrayScale2Diff.h"
#include "ComFunc.h"
#include "ComInfo.h"

using namespace ImageProcessing;

GrayScale2Diff::GrayScale2Diff(Bitmap^ _bitmap) : ComImgProc(_bitmap)
{
}

GrayScale2Diff::~GrayScale2Diff()
{
}

bool GrayScale2Diff::GoImgProc(CancellationToken^ _token)
{
	bool bRst = true;

	short nMask[3][3] =
	{
		{ 1,  1, 1 },
		{ 1, -8, 1 },
		{ 1,  1, 1 }
	};

	Bitmap^ bitmap = this->GetBitmap();
	int nWidthSize = bitmap->Width;
	int nHeightSize = bitmap->Height;
	int nMasksize = 3;

	Bitmap^ bitmapAfter = gcnew Bitmap(bitmap);

	BitmapData^ bitmapData = bitmapAfter->LockBits(System::Drawing::Rectangle(0, 0, nWidthSize, nHeightSize), ImageLockMode::ReadWrite, PixelFormat::Format32bppArgb);

	int nIdxWidth;
	int nIdxHeight;

	for (nIdxHeight = 0; nIdxHeight < nHeightSize; nIdxHeight++)
	{
		for (nIdxWidth = 0; nIdxWidth < nWidthSize; nIdxWidth++)
		{
			if (_token->IsCancellationRequested)
			{
				bRst = false;
				break;
			}

			Byte* pPixel = (Byte*)bitmapData->Scan0.ToPointer() + nIdxHeight * bitmapData->Stride + nIdxWidth * 4;

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
						Byte* pPixel2 = (Byte*)bitmapData->Scan0.ToPointer() + (nIdxHeight + nIdxHightMask) * bitmapData->Stride + (nIdxWidth + nIdxWidthMask) * 4;

						lCalB = pPixel2[ComInfo::Pixel::Type::B] * nMask[nIdxWidthMask][nIdxHightMask];
						lCalG = pPixel2[ComInfo::Pixel::Type::G] * nMask[nIdxWidthMask][nIdxHightMask];
						lCalR = pPixel2[ComInfo::Pixel::Type::R] * nMask[nIdxWidthMask][nIdxHightMask];

						double dcalGray = (lCalB + lCalG + lCalR) / 3;
						dCalAve = (dCalAve + dcalGray) / 2;
					}
				}
			}
			Byte nGrayScale = ComFunc::DoubleToByte(dCalAve);

			pPixel[ComInfo::Pixel::Type::B] = nGrayScale;
			pPixel[ComInfo::Pixel::Type::G] = nGrayScale;
			pPixel[ComInfo::Pixel::Type::R] = nGrayScale;
		}
	}
	bitmapAfter->UnlockBits(bitmapData);
	this->m_bitmapAfter = (Bitmap^)bitmapAfter->Clone();
	delete bitmapAfter;

	return bRst;
}