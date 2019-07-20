#include "ColorReversal.h"
#include "ComFunc.h"
#include "ComInfo.h"

using namespace ImageProcessing;

ColorReversal::ColorReversal(Bitmap^ _bitmap) : ComImgProc(_bitmap)
{
}

ColorReversal::~ColorReversal()
{
}

bool ColorReversal::GoImgProc(CancellationToken^ _token)
{
	bool bRst = true;

	Bitmap^ bitmap = this->GetBitmap();
	int nWidthSize = bitmap->Width;
	int nHeightSize = bitmap->Height;

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

			pPixel[ComInfo::Pixel::B] = (Byte)(255 - pPixel[ComInfo::Pixel::B]);
			pPixel[ComInfo::Pixel::G] = (Byte)(255 - pPixel[ComInfo::Pixel::G]);
			pPixel[ComInfo::Pixel::R] = (Byte)(255 - pPixel[ComInfo::Pixel::R]);
		}
	}
	bitmapAfter->UnlockBits(bitmapData);
	this->m_bitmapAfter = (Bitmap^)bitmapAfter->Clone();
	delete bitmapAfter;

	return bRst;
}