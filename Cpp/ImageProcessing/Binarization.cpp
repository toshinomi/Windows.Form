#include "Binarization.h"
#include "ComFunc.h"
#include "ComInfo.h"

using namespace ImageProcessing;

Binarization::Binarization(Bitmap^ _bitmap)
{
	m_bitmap = _bitmap;
	m_nThresh = 0;
}

ImageProcessing::Binarization::Binarization(Bitmap^ _bitmap, Byte _nThresh)
{
	m_bitmap = _bitmap;
	m_nThresh = _nThresh;
}

Binarization::~Binarization()
{
	m_bitmap = nullptr;
}

bool Binarization::GoEdgeDetection(CancellationToken^ _token)
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
			if (_token->IsCancellationRequested)
			{
				bRst = false;
				break;
			}

			Byte* pPixel = (Byte*)bitmapData->Scan0.ToPointer() + nIdxHeight * bitmapData->Stride + nIdxWidth * 4;
			Byte nGrayScale = (Byte)((pPixel[ComInfo::Pixel::B] + pPixel[ComInfo::Pixel::G] + pPixel[ComInfo::Pixel::R]) / 3);

			Byte nBinarization = nGrayScale >= m_nThresh ? (Byte)255 : (Byte)0;

			pPixel[ComInfo::Pixel::B] = nBinarization;
			pPixel[ComInfo::Pixel::G] = nBinarization;
			pPixel[ComInfo::Pixel::R] = nBinarization;
		}
	}
	m_bitmap->UnlockBits(bitmapData);

	return bRst;
}