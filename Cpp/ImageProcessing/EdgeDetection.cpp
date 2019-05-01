#include "EdgeDetection.h"
#include "ComFunc.h"
#include "ComInfo.h"

using namespace ImageProcessing;

EdgeDetection::EdgeDetection(Bitmap^ _bitmap)
{
	m_nFilterMax = 1;
	m_bitmap = _bitmap;
}

EdgeDetection::EdgeDetection(Bitmap^ _bitmap, UInt32 _filterMax)
{
	m_nFilterMax = _filterMax;
	m_bitmap = _bitmap;
}

EdgeDetection::~EdgeDetection()
{
	m_bitmap = nullptr;
}

bool EdgeDetection::GoEdgeDetection(CancellationToken _token)
{
	bool bRst = true;

	double dMask[3][3] =
	{
		{ 1.0,  1.0, 1.0 },
		{ 1.0, -8.0, 1.0 },
		{ 1.0,  1.0, 1.0 }
	};

	int nWidthSize = m_bitmap->Width;
	int nHeightSize = m_bitmap->Height;
	int nMasksize = m_nMaskSize;

	BitmapData^ bitmapData = m_bitmap->LockBits(System::Drawing::Rectangle(0, 0, nWidthSize, nHeightSize), ImageLockMode::ReadWrite, PixelFormat::Format32bppArgb);

	int nIdxWidth;
	int nIdxHeight;

	for (nIdxHeight = 0; nIdxHeight < nHeightSize; nIdxHeight++)
	{
		for (nIdxWidth = 0; nIdxWidth < nWidthSize; nIdxWidth++)
		{
			if (_token.IsCancellationRequested)
			{
				bRst = false;
				break;
			}

			Byte* pPixel = (Byte*)bitmapData->Scan0.ToPointer() + nIdxHeight * bitmapData->Stride + nIdxWidth * 4;

			double dCalB = 0.0;
			double dCalG = 0.0;
			double dCalR = 0.0;
			double dCalA = 0.0;
			int nIdxWidthMask;
			int nIdxHightMask;
			UInt32 nFilter = 0;

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
							Byte* pPixel2 = (Byte*)bitmapData->Scan0.ToPointer() + (nIdxHeight + nIdxHightMask) * bitmapData->Stride + (nIdxWidth + nIdxWidthMask) * 4;

							dCalB += pPixel2[ComInfo::Pixel::B] * dMask[nIdxWidthMask][nIdxHightMask];
							dCalG += pPixel2[ComInfo::Pixel::G] * dMask[nIdxWidthMask][nIdxHightMask];
							dCalR += pPixel2[ComInfo::Pixel::R] * dMask[nIdxWidthMask][nIdxHightMask];
							dCalA += pPixel2[ComInfo::Pixel::A] * dMask[nIdxWidthMask][nIdxHightMask];
						}
					}
				}
				nFilter++;
			}
			pPixel[ComInfo::Pixel::B] = ComFunc::DoubleToByte(dCalB);
			pPixel[ComInfo::Pixel::G] = ComFunc::DoubleToByte(dCalG);
			pPixel[ComInfo::Pixel::R] = ComFunc::DoubleToByte(dCalR);
			pPixel[ComInfo::Pixel::A] = ComFunc::DoubleToByte(dCalA);
		}
	}
	m_bitmap->UnlockBits(bitmapData);

	return bRst;
}