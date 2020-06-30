#pragma once
#include <string.h>
#include "ComImageProcessing.h"
#include "ComFunc.h"
#include "ComInfo.h"
#include "EdgeDetection.h"
#include "GrayScale.h"
#include "Binarization.h"
#include "GrayScale2Diff.h"
#include "ColorReversal.h"

namespace ImageProcessing {

	using namespace System;
	using namespace System::Collections::Generic;
	using namespace System::Drawing;
	using namespace System::Drawing::Imaging;
	using namespace System::Text;
	using namespace System::Threading;
	using namespace System::Threading::Tasks;

	/// <summary>
	/// �摜�����̃��W�b�N
	/// </summary>
	public ref class ImageProcessing : public ComImageProcessing
	{
	private:
		array<Object^>^ arrayImageProcessing = gcnew array<Object^>(ComInfo::ImgProc::Type::MAX);

		/// <summary>
		/// 臒l
		/// </summary>
		Byte thresh;
	public:
		/// <summary>
		/// �R���X�g���N�^
		/// </summary>
		/// <param name="_bitmap">�r�b�g�}�b�v</param>
		ImageProcessing(Bitmap^ bitmap);

		/// <summary>
		/// �f�X�N�g���N�^
		/// </summary>
		~ImageProcessing();

		/// <summary>
		/// ������
		/// </summary>
		void Init(void) override;

		/// <summary>
		/// 臒l�̎擾
		/// </summary>
		/// <returns>臒l</returns>
		Byte GetThresh() { return thresh; }

		/// <summary>
		/// 臒l�̐ݒ�
		/// </summary>
		/// <param name="thresh">臒l</param>
		void SetThresh(Byte thresh) { this->thresh = thresh; }

		/// <summary>
		/// �摜�����̎��s
		/// </summary>
		/// <param name="imageProcessingName">�摜�����I�u�W�F�N�g�̖���</param>
		/// <param name="token">�L�����Z���g�[�N��</param>
		/// <returns>���s���� ����/���s</returns>
		bool GoImageProcessing(String^ imageProcessingName, CancellationToken^ _token) override;
	};
};