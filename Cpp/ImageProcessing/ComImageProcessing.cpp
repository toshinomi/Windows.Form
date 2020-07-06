#include "ComImageProcessing.h"

/// <summary>
/// コンストラクタ
/// </summary>
/// <param name="bitmap">ビットマップ</param>
ComImageProcessing::ComImageProcessing(Bitmap^ bitmap)
{
	mBitmap = bitmap;
}

/// <summary>
/// デスクトラクタ
/// </summary>
ComImageProcessing::~ComImageProcessing()
{
}

/// <summary>
/// 初期化
/// </summary>
void ComImageProcessing::Init(void)
{
	mBitmap = nullptr;
}
