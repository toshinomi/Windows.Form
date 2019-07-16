#include "GrayScale.h"
#include "ComFunc.h"
#include "ComInfo.h"

using namespace ImageProcessing;

GrayScale::GrayScale(Bitmap^ _bitmap)
{
	m_bitmap = _bitmap;
}

GrayScale::~GrayScale()
{
	m_bitmap = nullptr;
}

bool GrayScale::GoEdgeDetection(CancellationToken^ _token)
{
	bool bRst = true;

	int nWidthSize = m_bitmap->Width;
	int nHeightSize = m_bitmap->Height;

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
			Byte nGrayScale = (Byte)((pPixel[ComInfo::Pixel::B] + pPixel[ComInfo::Pixel::G] + pPixel[ComInfo::Pixel::R]) / 3);

			pPixel[ComInfo::Pixel::B] = nGrayScale;
			pPixel[ComInfo::Pixel::G] = nGrayScale;
			pPixel[ComInfo::Pixel::R] = nGrayScale;
		}
	}
	m_bitmap->UnlockBits(bitmapData);

	return bRst;
}