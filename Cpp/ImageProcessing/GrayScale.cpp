#include "GrayScale.h"
#include "ComFunc.h"
#include "ComInfo.h"

/// <summary>
/// コンストラクタ
/// </summary>
/// <param name="_bitmap">ビットマップ</param>
GrayScale::GrayScale(Bitmap^ _bitmap) : ComImgProc(_bitmap)
{
}

/// <summary>
/// デスクトラクタ
/// </summary>
GrayScale::~GrayScale()
{
}

/// <summary>
/// 初期化
/// </summary>
void GrayScale::Init(void)
{
	this->Init();
}

/// <summary>
/// グレースケールの実行
/// </summary>
/// <param name="_token">キャンセルトークン</param>
/// <returns>実行結果 成功/失敗</returns>
bool GrayScale::GoImgProc(CancellationToken^ _token)
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
		if (_token->IsCancellationRequested)
		{
			bRst = false;
			break;
		}

		for (nIdxWidth = 0; nIdxWidth < nWidthSize; nIdxWidth++)
		{
			if (_token->IsCancellationRequested)
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
	bitmapAfter->UnlockBits(bitmapData);
	this->m_bitmapAfter = (Bitmap^)bitmapAfter->Clone();
	delete bitmapAfter;

	return bRst;
}