#include "GrayScale.h"
#include "ComFunc.h"
#include "ComInfo.h"

/// <summary>
/// コンストラクタ
/// </summary>
GrayScale::GrayScale()
{
}

/// <summary>
/// デスクトラクタ
/// </summary>
GrayScale::~GrayScale()
{
}

/// <summary>
/// グレースケールの実行
/// </summary>
/// <param name="bitmap">ビットマップ</param>
/// <param name="token">キャンセルトークン</param>
/// <returns>実行結果 成功/失敗</returns>
bool GrayScale::ImageProcessing(Bitmap^ bitmap, CancellationToken^ token)
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
			Byte nGrayScale = (Byte)((pPixel[ComInfo::Pixel::Type::B] + pPixel[ComInfo::Pixel::Type::G] + pPixel[ComInfo::Pixel::Type::R]) / 3);

			pPixel[ComInfo::Pixel::Type::B] = nGrayScale;
			pPixel[ComInfo::Pixel::Type::G] = nGrayScale;
			pPixel[ComInfo::Pixel::Type::R] = nGrayScale;
		}
	}
	bitmap->UnlockBits(bitmapData);

	return bRst;
}