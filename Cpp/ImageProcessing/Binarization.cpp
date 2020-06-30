#include "Binarization.h"
#include "ComFunc.h"
#include "ComInfo.h"

/// <summary>
/// コンストラクタ
/// </summary>
Binarization::Binarization()
{
}

/// <summary>
/// デスクトラクタ
/// </summary>
Binarization::~Binarization()
{
}

/// <summary>
/// 2値化の実行
/// </summary>
/// <param name="bitmap">ビットマップ</param>
/// <param name="token">キャンセルトークン</param>
/// <param name="thresh">閾値</param>
/// <returns>実行結果 成功/失敗</returns>
bool Binarization::ImageProcessing(Bitmap^ bitmap, CancellationToken^ token, Byte thresh)
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

			Byte nBinarization = nGrayScale >= thresh ? (Byte)255 : (Byte)0;

			pPixel[ComInfo::Pixel::Type::B] = nBinarization;
			pPixel[ComInfo::Pixel::Type::G] = nBinarization;
			pPixel[ComInfo::Pixel::Type::R] = nBinarization;
		}
	}
	bitmap->UnlockBits(bitmapData);

	return bRst;
}