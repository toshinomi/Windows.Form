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
	ComImgProc(Bitmap^ _bitmap);
	~ComImgProc();
	virtual void Init(void);
	Bitmap^ GetBitmap() { return m_bitmap; }
	void SetBitmap(Bitmap^ _bitmap) { m_bitmap = _bitmap; }
	Bitmap^ GetBitmapAfter() { return m_bitmapAfter; }
	void SetBitmapAfter(Bitmap^ _bitmap) { m_bitmapAfter = _bitmap; }

	/// <summary>
	/// �摜�������s�̒���
	/// </summary>
	/// <param name="_token">�L�����Z���g�[�N��</param>
	/// <returns>���s���� ����/���s</returns>
	virtual bool GoImgProc(CancellationToken^ _token) = 0;
};