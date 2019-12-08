#include "ComImgProc.h"

/// <summary>
/// コンストラクタ
/// </summary>
/// <param name="_bitmap">ビットマップ</param>
ComImgProc::ComImgProc(Bitmap^ _bitmap)
{
	m_bitmap = _bitmap;
}

/// <summary>
/// デスクトラクタ
/// </summary>
ComImgProc::~ComImgProc()
{
}

/// <summary>
/// 初期化
/// </summary>
void ComImgProc::Init(void)
{
	m_bitmap = nullptr;
	m_bitmapAfter = nullptr;
}
