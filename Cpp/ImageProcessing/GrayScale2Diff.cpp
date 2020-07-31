#include "GrayScale2Diff.h"
#include "ComFunc.h"
#include "ComInfo.h"

/// <summary>
/// コンストラクタ
/// </summary>
GrayScale2Diff::GrayScale2Diff()
{
}

/// <summary>
/// デスクトラクタ
/// </summary>
GrayScale2Diff::~GrayScale2Diff()
{
}

/// <summary>
/// グレースケール2次微分の実行
/// </summary>
/// <param name="bitmap">ビットマップ</param>
/// <param name="token">キャンセルトークン</param>
/// <returns>実行結果 成功/失敗</returns>
bool GrayScale2Diff::ImageProcessing(Bitmap^ bitmap, CancellationToken^ token)
{
	bool result = true;

	short mask[3][3] =
	{
		{ 1,  1, 1 },
		{ 1, -8, 1 },
		{ 1,  1, 1 }
	};

	int widthSize = bitmap->Width;
	int heightSize = bitmap->Height;
	int maskSize = 3;

	auto bitmapData = bitmap->LockBits(System::Drawing::Rectangle(0, 0, widthSize, heightSize), ImageLockMode::ReadWrite, PixelFormat::Format32bppArgb);

	int indexWidth;
	int indexHeight;

	for (indexHeight = 0; indexHeight < heightSize; indexHeight++)
	{
		if (token->IsCancellationRequested)
		{
			result = false;
			break;
		}

		for (indexWidth = 0; indexWidth < widthSize; indexWidth++)
		{
			if (token->IsCancellationRequested)
			{
				result = false;
				break;
			}

			Byte* pixel = (Byte*)bitmapData->Scan0.ToPointer() + indexHeight * bitmapData->Stride + indexWidth * 4;

			double averageGrayScale = 0.0;
			int indexWidthMask;
			int indexHightMask;

			for (indexHightMask = 0; indexHightMask < maskSize; indexHightMask++)
			{
				for (indexWidthMask = 0; indexWidthMask < maskSize; indexWidthMask++)
				{
					if (indexWidth + indexWidthMask > 0 &&
						indexWidth + indexWidthMask < widthSize &&
						indexHeight + indexHightMask > 0 &&
						indexHeight + indexHightMask < heightSize)
					{
						Byte* pixelMaskArea = (Byte*)bitmapData->Scan0.ToPointer() + (indexHeight + indexHightMask) * bitmapData->Stride + (indexWidth + indexWidthMask) * 4;

						long blue = pixelMaskArea[ComInfo::Pixel::Type::B] * mask[indexWidthMask][indexHightMask];
						long green = pixelMaskArea[ComInfo::Pixel::Type::G] * mask[indexWidthMask][indexHightMask];
						long red = pixelMaskArea[ComInfo::Pixel::Type::R] * mask[indexWidthMask][indexHightMask];

						double gray = (blue + green + red) / 3;
						averageGrayScale = (averageGrayScale + gray) / 2;
					}
				}
			}
			Byte grayScale = ComFunc::DoubleToByte(averageGrayScale);

			pixel[ComInfo::Pixel::Type::B] = grayScale;
			pixel[ComInfo::Pixel::Type::G] = grayScale;
			pixel[ComInfo::Pixel::Type::R] = grayScale;
		}
	}
	bitmap->UnlockBits(bitmapData);

	return result;
}