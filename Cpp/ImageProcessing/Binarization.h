#pragma once
#include "ComImgProc.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Drawing;
using namespace System::Drawing::Imaging;
using namespace System::Text;
using namespace System::Threading;
using namespace System::Threading::Tasks;

/// <summary>
/// 2�l���̃��W�b�N
/// </summary>
public ref class Binarization : public ComImgProc
{
private:
	/// <summary>
	/// 臒l
	/// </summary>
	Byte m_nThresh;
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="_bitmap">�r�b�g�}�b�v</param>
	Binarization(Bitmap^ _bitmap);

	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="_bitmap">�r�b�g�}�b�v</param>
	/// <param name="_nThresh">臒l</param>
	Binarization(Bitmap^ _bitmap, Byte _nThresh);

	/// <summary>
	/// �f�X�N�g���N�^
	/// </summary>
	~Binarization();

	/// <summary>
	/// ������
	/// </summary>
	void Init(void) override;

	/// <summary>
	/// 臒l�̎擾
	/// </summary>
	/// <returns>臒l</returns>
	Byte GetThresh() { return m_nThresh; }

	/// <summary>
	/// 臒l�̐ݒ�
	/// </summary>
	/// <param name="_nThresh">臒l</param>
	void SetThresh(Byte _nThresh) { m_nThresh = _nThresh; }

	/// <summary>
	/// 2�l���̎��s
	/// </summary>
	/// <param name="_token">�L�����Z���g�[�N��</param>
	/// <returns>���s���� ����/���s</returns>
	bool GoImgProc(CancellationToken^ _token) override;
};