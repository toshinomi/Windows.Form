#include "ColorReversal.h"
#include "ComFunc.h"
#include "ComInfo.h"

using namespace ImageProcessing;

ColorReversal::ColorReversal(Bitmap^ _bitmap)
{
	m_bitmap = _bitmap;
}

ColorReversal::~ColorReversal()
{
	m_bitmap = nullptr;
}

bool ColorReversal::GoEdgeDetection(CancellationToken _token)
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

			pPixel[ComInfo::Pixel::B] = (Byte)(255 - pPixel[ComInfo::Pixel::B]);
			pPixel[ComInfo::Pixel::G] = (Byte)(255 - pPixel[ComInfo::Pixel::G]);
			pPixel[ComInfo::Pixel::R] = (Byte)(255 - pPixel[ComInfo::Pixel::R]);
		}
	}
	m_bitmap->UnlockBits(bitmapData);

	return bRst;
}