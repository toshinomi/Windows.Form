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
	Byte^ m_nThresh;
public:
	/// <summary>
	/// 臒l�̐ݒ�
	/// </summary>
	/// <param name="_nThresh">臒l</param>
	void SetThresh(Byte^ _nThresh) { m_nThresh = _nThresh; }

	/// <summary>
	/// 臒l�̎擾
	/// </summary>
	/// <returns>臒l</returns>
	Byte^ GetThresh(void) { return m_nThresh; }

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
	String^ m_strCurImgName;

	/// <summary>
	/// �G�b�W���o�̐ݒ�
	/// </summary>
	EdgeDetectionInfo^ m_edgeDetectoinInfo;

	/// <summary>
	/// �O���[�X�P�[���̐ݒ�
	/// </summary>
	GrayScaleInfo^ m_grayScaleInfo;

	/// <summary>
	/// 2�l���̐ݒ�
	/// </summary>
	BinarizationInfo^ m_binarizationInfo;

	/// <summary>
	/// �O���[�X�P�[��2�������̐ݒ�
	/// </summary>
	GrayScale2DiffInfo^ m_grayScale2DiffInfo;

	/// <summary>
	/// �F���]�̐ݒ�
	/// </summary>
	ColorReversalInfo^ m_colorReversalInfo;
public:
	/// <summary>
	/// ���݂̉摜�����^�C�v�̖��̂̐ݒ�
	/// </summary>
	/// <param name="_strCurImgName">�摜�����^�C�v�̖���</param>
	void SetCurImgName(String^ _strCurImgName) { m_strCurImgName = _strCurImgName; }

	/// <summary>
	/// ���݂̉摜�����^�C�v�̖��̂̎擾
	/// </summary>
	/// <returns>�摜�����^�C�v�̖���</returns>
	String^ GetCurImgName(void) { return m_strCurImgName; }

	/// <summary>
	/// �G�b�W���o���̐ݒ�
	/// </summary>
	/// <param name="_edgeDetectoinInfo">�G�b�W���o���</param>
	void SetEdgeDetectionInfo(EdgeDetectionInfo^ _edgeDetectoinInfo) { m_edgeDetectoinInfo = _edgeDetectoinInfo; }

	/// <summary>
	/// �G�b�W���o���̎擾
	/// </summary>
	/// <returns>�G�b�W���o���</returns>
	EdgeDetectionInfo^ GetEdgeDetectionInfo() { return m_edgeDetectoinInfo; }

	/// <summary>
	/// �O���[�X�P�[�����̐ݒ�
	/// </summary>
	/// <param name="_grayScaleInfo">�O���[�X�P�[�����</param>
	void SetGrayScaleInfo(GrayScaleInfo^ _grayScaleInfo) { m_grayScaleInfo = _grayScaleInfo; }

	/// <summary>
	/// �O���[�X�P�[�����̎擾
	/// </summary>
	/// <returns>�O���[�X�P�[�����</returns>
	GrayScaleInfo^ GetGrayScaleInfo(void) { return m_grayScaleInfo; }

	/// <summary>
	/// 2�l�����̐ݒ�
	/// </summary>
	/// <param name="_binarizationInfo">2�l�����</param>
	void SetBinarizationInfo(BinarizationInfo^ _binarizationInfo) { m_binarizationInfo = _binarizationInfo; }

	/// <summary>
	/// 2�l�����̎擾
	/// </summary>
	/// <returns>2�l�����</returns>
	BinarizationInfo^ GetBinarizationInfo(void) { return m_binarizationInfo; }

	/// <summary>
	/// �O���[�X�P�[��2���������̐ݒ�
	/// </summary>
	/// <param name="_grayScale2DiffInfo">�O���[�X�P�[��2���������</param>
	void SetGrayScale2DiffInfo(GrayScale2DiffInfo^ _grayScale2DiffInfo) { m_grayScale2DiffInfo = _grayScale2DiffInfo; }

	/// <summary>
	/// �O���[�X�P�[��2���������̎擾
	/// </summary>
	/// <returns>�O���[�X�P�[��2���������</returns>
	GrayScale2DiffInfo^ GetGrayScale2DiffInfo(void) { return m_grayScale2DiffInfo; }

	/// <summary>
	/// �F���]���̐ݒ�
	/// </summary>
	/// <param name="_colorReversalInfo">�F���]���</param>
	void SetColorReversalInfo(ColorReversalInfo^ _colorReversalInfo) { m_colorReversalInfo = _colorReversalInfo; }

	/// <summary>
	/// �F���]���̎擾
	/// </summary>
	/// <returns>�F���]���</returns>
	ColorReversalInfo^ GetColorReversalInfo(void) { return m_colorReversalInfo; }

	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	ComImgInfo()
	{
		m_edgeDetectoinInfo = gcnew EdgeDetectionInfo();
		m_grayScaleInfo = gcnew GrayScaleInfo();
		m_binarizationInfo = gcnew BinarizationInfo();
		m_grayScale2DiffInfo = gcnew GrayScale2DiffInfo();
		m_colorReversalInfo = gcnew ColorReversalInfo();
	}

	/// <summary>
	/// �f�X�N�g���N�^
	/// </summary>
	~ComImgInfo()
	{
		delete m_edgeDetectoinInfo;
		delete m_grayScaleInfo;
		delete m_binarizationInfo;
		delete m_grayScale2DiffInfo;
		delete m_colorReversalInfo;
	}
};