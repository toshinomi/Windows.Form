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
/// 2�l���̃��W�b�N
/// </summary>
public ref class Binarization
{
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	Binarization();

	/// <summary>
	/// �f�X�N�g���N�^
	/// </summary>
	~Binarization();

	/// <summary>
	/// 2�l���̎��s
	/// </summary>
	/// <param name="bitmap">�r�b�g�}�b�v</param>
	/// <param name="token">�L�����Z���g�[�N��</param>
	/// <param name="thresh">臒l</param>
	/// <returns>���s���� ����/���s</returns>
	bool ImageProcessing(Bitmap^ bitmap, CancellationToken^ token, Byte thresh);
};