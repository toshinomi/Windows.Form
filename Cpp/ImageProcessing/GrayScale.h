#pragma once
#include "ComImageProcessing.h"

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
public ref class GrayScale
{
private:
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	GrayScale();

	/// <summary>
	/// �f�X�N�g���N�^
	/// </summary>
	~GrayScale();

	/// <summary>
	/// �O���[�X�P�[���̎��s
	/// </summary>
	/// <param name="bitmap">�r�b�g�}�b�v</param>
	/// <param name="token">�L�����Z���g�[�N��</param>
	/// <returns>���s���� ����/���s</returns>
	bool ImageProcessing(Bitmap^ bitmap, CancellationToken^ token);
};