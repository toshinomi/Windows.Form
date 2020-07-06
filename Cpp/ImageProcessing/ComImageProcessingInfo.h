#pragma once

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Drawing;
using namespace System::Drawing::Imaging;
using namespace System::Text;
using namespace System::Threading;
using namespace System::Threading::Tasks;

/// <summary>
/// �G�b�W���o�̐ݒ�Ǘ��̃��W�b�N
/// </summary>
public ref class EdgeDetectionInfo
{
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	EdgeDetectionInfo()
	{
	}

	/// <summary>
	/// �f�X�N�g���N�^
	/// </summary>
	~EdgeDetectionInfo()
	{
	}
};

/// <summary>
/// �O���[�X�P�[���̐ݒ�Ǘ��̃��W�b�N
/// </summary>
public ref class GrayScaleInfo
{
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	GrayScaleInfo()
	{
	}

	/// <summary>
	/// �f�X�N�g���N�^
	/// </summary>
	~GrayScaleInfo()
	{
	}
};

/// <summary>
/// 2�l���̐ݒ�Ǘ��̃��W�b�N
/// </summary>
public ref class BinarizationInfo
{
private:
	/// <summary>
	/// 臒l
	/// </summary>
	Byte mThresh;
public:
	/// <summary>
	/// 臒l�̐ݒ�
	/// </summary>
	/// <param name="_nThresh">臒l</param>
	void SetThresh(Byte Thresh) { mThresh = Thresh; }

	/// <summary>
	/// 臒l�̎擾
	/// </summary>
	/// <returns>臒l</returns>
	Byte GetThresh(void) { return mThresh; }

	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	BinarizationInfo()
	{
	}

	/// <summary>
	/// �f�X�N�g���N�^
	/// </summary>
	~BinarizationInfo()
	{
	}
};

/// <summary>
/// �O���[�X�P�[��2�������̐ݒ�Ǘ��̃��W�b�N
/// </summary>
public ref class GrayScale2DiffInfo
{
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	GrayScale2DiffInfo()
	{
	}

	/// <summary>
	/// �f�X�N�g���N�^
	/// </summary>
	~GrayScale2DiffInfo()
	{
	}
};

/// <summary>
/// �F���]�̐ݒ�Ǘ��̃��W�b�N
/// </summary>
public ref class ColorReversalInfo
{
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	ColorReversalInfo()
	{
	}

	/// <summary>
	/// �f�X�N�g���N�^
	/// </summary>
	~ColorReversalInfo()
	{
	}
};

/// <summary>
/// �摜�����̐ݒ�Ǘ��̃��W�b�N
/// </summary>
public ref class ComImgInfo
{
private:
	/// <summary>
	/// ���݂̉摜�����̖���
	/// </summary>
	String^ mCurrentImageProcessingName;

	/// <summary>
	/// �G�b�W���o�̐ݒ�
	/// </summary>
	EdgeDetectionInfo^ mEdgeDetectoinInfo;

	/// <summary>
	/// �O���[�X�P�[���̐ݒ�
	/// </summary>
	GrayScaleInfo^ mGrayScaleInfo;

	/// <summary>
	/// 2�l���̐ݒ�
	/// </summary>
	BinarizationInfo^ mBinarizationInfo;

	/// <summary>
	/// �O���[�X�P�[��2�������̐ݒ�
	/// </summary>
	GrayScale2DiffInfo^ mGrayScale2DiffInfo;

	/// <summary>
	/// �F���]�̐ݒ�
	/// </summary>
	ColorReversalInfo^ mColorReversalInfo;
public:
	/// <summary>
	/// ���݂̉摜�����^�C�v�̖��̂̐ݒ�
	/// </summary>
	/// <param name="currentImageProcessingName">�摜�����^�C�v�̖���</param>
	void SetCurrentImageProcessingName(String^ currentImageProcessingName) { mCurrentImageProcessingName = currentImageProcessingName; }

	/// <summary>
	/// ���݂̉摜�����^�C�v�̖��̂̎擾
	/// </summary>
	/// <returns>�摜�����^�C�v�̖���</returns>
	String^ GetCurImgName(void) { return mCurrentImageProcessingName; }

	/// <summary>
	/// �G�b�W���o���̐ݒ�
	/// </summary>
	/// <param name="edgeDetectoinInfo">�G�b�W���o���</param>
	void SetEdgeDetectionInfo(EdgeDetectionInfo^ edgeDetectoinInfo) { mEdgeDetectoinInfo = edgeDetectoinInfo; }

	/// <summary>
	/// �G�b�W���o���̎擾
	/// </summary>
	/// <returns>�G�b�W���o���</returns>
	EdgeDetectionInfo^ GetEdgeDetectionInfo() { return mEdgeDetectoinInfo; }

	/// <summary>
	/// �O���[�X�P�[�����̐ݒ�
	/// </summary>
	/// <param name="grayScaleInfo">�O���[�X�P�[�����</param>
	void SetGrayScaleInfo(GrayScaleInfo^ grayScaleInfo) { mGrayScaleInfo = grayScaleInfo; }

	/// <summary>
	/// �O���[�X�P�[�����̎擾
	/// </summary>
	/// <returns>�O���[�X�P�[�����</returns>
	GrayScaleInfo^ GetGrayScaleInfo(void) { return mGrayScaleInfo; }

	/// <summary>
	/// 2�l�����̐ݒ�
	/// </summary>
	/// <param name="binarizationInfo">2�l�����</param>
	void SetBinarizationInfo(BinarizationInfo^ binarizationInfo) { mBinarizationInfo = binarizationInfo; }

	/// <summary>
	/// 2�l�����̎擾
	/// </summary>
	/// <returns>2�l�����</returns>
	BinarizationInfo^ GetBinarizationInfo(void) { return mBinarizationInfo; }

	/// <summary>
	/// �O���[�X�P�[��2���������̐ݒ�
	/// </summary>
	/// <param name="grayScale2DiffInfo">�O���[�X�P�[��2���������</param>
	void SetGrayScale2DiffInfo(GrayScale2DiffInfo^ grayScale2DiffInfo) { mGrayScale2DiffInfo = grayScale2DiffInfo; }

	/// <summary>
	/// �O���[�X�P�[��2���������̎擾
	/// </summary>
	/// <returns>�O���[�X�P�[��2���������</returns>
	GrayScale2DiffInfo^ GetGrayScale2DiffInfo(void) { return mGrayScale2DiffInfo; }

	/// <summary>
	/// �F���]���̐ݒ�
	/// </summary>
	/// <param name="colorReversalInfo">�F���]���</param>
	void SetColorReversalInfo(ColorReversalInfo^ colorReversalInfo) { mColorReversalInfo = colorReversalInfo; }

	/// <summary>
	/// �F���]���̎擾
	/// </summary>
	/// <returns>�F���]���</returns>
	ColorReversalInfo^ GetColorReversalInfo(void) { return mColorReversalInfo; }

	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	ComImgInfo()
	{
		mEdgeDetectoinInfo = gcnew EdgeDetectionInfo();
		mGrayScaleInfo = gcnew GrayScaleInfo();
		mBinarizationInfo = gcnew BinarizationInfo();
		mGrayScale2DiffInfo = gcnew GrayScale2DiffInfo();
		mColorReversalInfo = gcnew ColorReversalInfo();
	}

	/// <summary>
	/// �f�X�N�g���N�^
	/// </summary>
	~ComImgInfo()
	{
	}
};