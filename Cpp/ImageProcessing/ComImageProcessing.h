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
public  ref class ComImageProcessing abstract
{
protected:
	/// <summary>
	/// �r�b�g�}�b�v
	/// </summary>
	Bitmap^ m_bitmap;

public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="_bitmap">�r�b�g�}�b�v</param>
	ComImageProcessing(Bitmap^ bitmap);

	/// <summary>
	/// �f�X�N�g���N�^
	/// </summary>
	~ComImageProcessing();

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
	/// <param name="bitmap">�r�b�g�}�b�v</param>
	void SetBitmap(Bitmap^ bitmap) { m_bitmap = bitmap; }

	/// <summary>
	/// �摜�������s�̒���
	/// </summary>
	/// <param name="imageProcessingName">�摜�����I�u�W�F�N�g�̖���</param>
	/// <param name="token">�L�����Z���g�[�N��</param>
	/// <returns>���s���� ����/���s</returns>
	virtual bool GoImageProcessing(String^ imageProcessingName, CancellationToken^ token) = 0;
};