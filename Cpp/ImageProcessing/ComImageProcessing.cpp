#include "ComImageProcessing.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
/// <param name="_bitmap">�r�b�g�}�b�v</param>
ComImageProcessing::ComImageProcessing(Bitmap^ bitmap)
{
	m_bitmap = bitmap;
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
	m_bitmap = nullptr;
}
