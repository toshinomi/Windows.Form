#include "ComImgProc.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
/// <param name="_bitmap">�r�b�g�}�b�v</param>
ComImgProc::ComImgProc(Bitmap^ _bitmap)
{
	m_bitmap = _bitmap;
}

/// <summary>
/// �f�X�N�g���N�^
/// </summary>
ComImgProc::~ComImgProc()
{
}

/// <summary>
/// ������
/// </summary>
void ComImgProc::Init(void)
{
	m_bitmap = nullptr;
	m_bitmapAfter = nullptr;
}
