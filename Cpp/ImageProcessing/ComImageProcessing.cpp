#include "ComImageProcessing.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
/// <param name="bitmap">�r�b�g�}�b�v</param>
ComImageProcessing::ComImageProcessing(Bitmap^ bitmap)
{
	mBitmap = bitmap;
}

/// <summary>
/// �f�X�N�g���N�^
/// </summary>
ComImageProcessing::~ComImageProcessing()
{
}

/// <summary>
/// ������
/// </summary>
void ComImageProcessing::Init(void)
{
	mBitmap = nullptr;
}
