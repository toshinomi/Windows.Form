#include "GrayScale2Diff.h"
#include "ComFunc.h"
#include "ComInfo.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
GrayScale2Diff::GrayScale2Diff()
{
}

/// <summary>
/// �f�X�N�g���N�^
/// </summary>
GrayScale2Diff::~GrayScale2Diff()
{
}

/// <summary>
/// �O���[�X�P�[��2�������̎��s
/// </summary>
/// <param name="bitmap">�r�b�g�}�b�v</param>
/// <param name="token">�L�����Z���g�[�N��</param>
/// <returns>���s���� ����/���s</returns>
bool GrayScale2Diff::ImageProcessing(Bitmap^ bitmap, CancellationToken^ token)
{
	bool bRst = true;

	short nMask[3][3] =
	{
		{ 1,  1, 1 },
		{ 1, -8, 1 },
		{ 1,  1, 1 }
	};

	int nWidthSize = bitmap->Width;
	int nHeightSize = bitmap->Height;
	int nMasksize = 3;

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
	bitmap->UnlockBits(bitmapData);

	return bRst;
}