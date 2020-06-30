#include "EdgeDetection.h"
#include "ComFunc.h"
#include "ComInfo.h"

/// <summary>
/// コンストラクタ
/// </summary>
EdgeDetection::EdgeDetection()
{
}

/// <summary>
/// デスクトラクタ
/// </summary>
EdgeDetection::~EdgeDetection()
{
}

/// <summary>
/// エッジ検出の実行
/// </summary>
/// <param name="bitmap">ビットマップ</param>
/// <param name="token">キャンセルトークン</param>
/// <returns>実行結果 成功/失敗</returns>
bool EdgeDetection::ImageProcessing(Bitmap^ bitmap, CancellationToken^ token)
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

						lCalB += pPixel2[ComInfo::Pixel::Type::B] * nMask[nIdxWidthMask][nIdxHightMask];
						lCalG += pPixel2[ComInfo::Pixel::Type::G] * nMask[nIdxWidthMask][nIdxHightMask];
						lCalR += pPixel2[ComInfo::Pixel::Type::R] * nMask[nIdxWidthMask][nIdxHightMask];
					}
				}
			}
			pPixel[ComInfo::Pixel::Type::B] = ComFunc::LongToByte(lCalB);
			pPixel[ComInfo::Pixel::Type::G] = ComFunc::LongToByte(lCalG);
			pPixel[ComInfo::Pixel::Type::R] = ComFunc::LongToByte(lCalR);
		}
	}
	bitmap->UnlockBits(bitmapData);

	return bRst;
}