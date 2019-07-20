#include "EdgeDetection.h"
#include "ComFunc.h"
#include "ComInfo.h"

using namespace ImageProcessing;

EdgeDetection::EdgeDetection(Bitmap^ _bitmap) : ComImgProc(_bitmap)
{
}

EdgeDetection::~EdgeDetection()
{
}

bool EdgeDetection::GoImgProc(CancellationToken^ _token)
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

						lCalB += pPixel2[ComInfo::Pixel::B] * nMask[nIdxWidthMask][nIdxHightMask];
						lCalG += pPixel2[ComInfo::Pixel::G] * nMask[nIdxWidthMask][nIdxHightMask];
						lCalR += pPixel2[ComInfo::Pixel::R] * nMask[nIdxWidthMask][nIdxHightMask];
					}
				}
			}
			pPixel[ComInfo::Pixel::B] = ComFunc::LongToByte(lCalB);
			pPixel[ComInfo::Pixel::G] = ComFunc::LongToByte(lCalG);
			pPixel[ComInfo::Pixel::R] = ComFunc::LongToByte(lCalR);
		}
	}
	bitmapAfter->UnlockBits(bitmapData);
	this->m_bitmapAfter = (Bitmap^)bitmapAfter->Clone();
	delete bitmapAfter;

	return bRst;
}
