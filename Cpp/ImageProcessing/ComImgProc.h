#pragma once

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Drawing;
using namespace System::Drawing::Imaging;
using namespace System::Text;
using namespace System::Threading;
using namespace System::Threading::Tasks;

/// <summary>
/// �摜�����̋��ʂ̃��W�b�N
/// </summary>
public  ref class  ComImgProc abstract
{
protected:
	/// <summary>
	/// �r�b�g�}�b�v
	/// </summary>
	Bitmap^ m_bitmap;

	/// <summary>
	/// �摜������̃r�b�g�}�b�v
	/// </summary>
	Bitmap^ m_bitmapAfter;
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="_bitmap">�r�b�g�}�b�v</param>
	ComImgProc(Bitmap^ _bitmap);

	/// <summary>
	/// �f�X�N�g���N�^
	/// </summary>
	~ComImgProc();

	/// <summary>
	/// ������
	/// </summary>
	virtual void Init(void);

	/// <summary>
	/// �I���W�i���̃r�b�g�}�b�v�̎擾
	/// </summary>
	/// <returns>�r�b�g�}�b�v</returns>
	Bitmap^ GetBitmap() { return m_bitmap; }

	/// <summary>
	/// �I���W�i���̃r�b�g�}�b�v�̐ݒ�
	/// </summary>
	/// <param name="_bitmap">�r�b�g�}�b�v</param>
	void SetBitmap(Bitmap^ _bitmap) { m_bitmap = _bitmap; }

	/// <summary>
	/// �摜������̃r�b�g�}�b�v�̎擾
	/// </summary>
	/// <returns>�r�b�g�}�b�v</returns>
	Bitmap^ GetBitmapAfter() { return m_bitmapAfter; }

	/// <summary>
	/// �摜������̃r�b�g�}�b�v�̐ݒ�
	/// </summary>
	/// <returns>�r�b�g�}�b�v</returns>
	void SetBitmapAfter(Bitmap^ _bitmap) { m_bitmapAfter = _bitmap; }

	/// <summary>
	/// �摜�������s�̒���
	/// </summary>
	/// <param name="_token">�L�����Z���g�[�N��</param>
	/// <returns>���s���� ����/���s</returns>
	virtual bool GoImgProc(CancellationToken^ _token) = 0;
};