#include "ColorReversal.h"
#include "ComFunc.h"
#include "ComInfo.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
ColorReversal::ColorReversal()
{
}

/// <summary>
/// �f�X�N�g���N�^
/// </summary>
ColorReversal::~ColorReversal()
{
}

/// <summary>
/// �F���]�̎��s
/// </summary>
/// <param name="bitmap">�r�b�g�}�b�v</param>
/// <param name="token">�L�����Z���g�[�N��</param>
/// <returns>���s���� ����/���s</returns>
bool ColorReversal::ImageProcessing(Bitmap^ bitmap, CancellationToken^ token)
{
	bool bRst = true;

	int nWidthSize = bitmap->Width;
	int nHeightSize = bitmap->Height;

	auto bitmapData = bitmap->LockBits(System::Drawing::Rectangle(0, 0, nWidthSize, nHeightSize), ImageLockMode::ReadWrite, PixelFormat::Format32bppArgb);

	int nIdxWidth;
	int nIdxHeight;

	for (nIdxHeight = 0; nIdxHeight < nHeightSize; nIdxHeight++)
	{
		if (token->IsCancellationRequested)
		{
			bRst = false;
			break;
		}

		for (nIdxWidth = 0; nIdxWidth < nWidthSize; nIdxWidth++)
		{
			if (token->IsCancellationRequested)
			{
				bRst = false;
				break;
			}

			Byte* pPixel = (Byte*)bitmapData->Scan0.ToPointer() + nIdxHeight * bitmapData->Stride + nIdxWidth * 4;

			pPixel[ComInfo::Pixel::Type::B] = (Byte)(255 - pPixel[ComInfo::Pixel::Type::B]);
			pPixel[ComInfo::Pixel::Type::G] = (Byte)(255 - pPixel[ComInfo::Pixel::Type::G]);
			pPixel[ComInfo::Pixel::Type::R] = (Byte)(255 - pPixel[ComInfo::Pixel::Type::R]);
		}
	}
	bitmap->UnlockBits(bitmapData);

	return bRst;
}