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
/// �O���[�X�P�[���̃��W�b�N
/// </summary>
public ref class GrayScale : public ComImgProc
{
private:
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="_bitmap">�r�b�g�}�b�v</param>
	GrayScale(Bitmap^ _bitmap);

	/// <summary>
	/// �f�X�N�g���N�^
	/// </summary>
	~GrayScale();

	/// <summary>
	/// ������
	/// </summary>
	void Init(void) override;

	/// <summary>
	/// �O���[�X�P�[���̎��s
	/// </summary>
	/// <param name="_token">�L�����Z���g�[�N��</param>
	/// <returns>���s���� ����/���s</returns>
	bool GoImgProc(CancellationToken^ _token) override;
};