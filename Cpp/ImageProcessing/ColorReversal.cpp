#include "ColorReversal.h"
#include "ComFunc.h"
#include "ComInfo.h"

/// <summary>
/// コンストラクタ
/// </summary>
ColorReversal::ColorReversal()
{
}

/// <summary>
/// デスクトラクタ
/// </summary>
ColorReversal::~ColorReversal()
{
}

/// <summary>
/// 色反転の実行
/// </summary>
/// <param name="bitmap">ビットマップ</param>
/// <param name="token">キャンセルトークン</param>
/// <returns>実行結果 成功/失敗</returns>
bool ColorReversal::ImageProcessing(Bitmap^ bitmap, CancellationToken^ token)
{
	bool result = true;

	int widthSize = bitmap->Width;
	int heightSize = bitmap->Height;

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

			pixel[ComInfo::Pixel::Type::B] = (Byte)(255 - pixel[ComInfo::Pixel::Type::B]);
			pixel[ComInfo::Pixel::Type::G] = (Byte)(255 - pixel[ComInfo::Pixel::Type::G]);
			pixel[ComInfo::Pixel::Type::R] = (Byte)(255 - pixel[ComInfo::Pixel::Type::R]);
		}
	}
	bitmap->UnlockBits(bitmapData);

	return result;
}
