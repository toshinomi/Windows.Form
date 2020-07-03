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

			long totalBlue = 0;
			long totalGreen = 0;
			long totalRed = 0;
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

						totalBlue += pixelMaskArea[ComInfo::Pixel::Type::B] * mask[indexWidthMask][indexHightMask];
						totalGreen += pixelMaskArea[ComInfo::Pixel::Type::G] * mask[indexWidthMask][indexHightMask];
						totalRed += pixelMaskArea[ComInfo::Pixel::Type::R] * mask[indexWidthMask][indexHightMask];
					}
				}
			}
			pixel[ComInfo::Pixel::Type::B] = ComFunc::LongToByte(totalBlue);
			pixel[ComInfo::Pixel::Type::G] = ComFunc::LongToByte(totalGreen);
			pixel[ComInfo::Pixel::Type::R] = ComFunc::LongToByte(totalRed);
		}
	}
	bitmap->UnlockBits(bitmapData);

	return result;
}
