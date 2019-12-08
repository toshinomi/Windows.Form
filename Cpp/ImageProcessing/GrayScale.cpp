#include "GrayScale.h"
#include "ComFunc.h"
#include "ComInfo.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
/// <param name="_bitmap">�r�b�g�}�b�v</param>
GrayScale::GrayScale(Bitmap^ _bitmap) : ComImgProc(_bitmap)
{
}

/// <summary>
/// �f�X�N�g���N�^
/// </summary>
GrayScale::~GrayScale()
{
}

/// <summary>
/// ������
/// </summary>
void GrayScale::Init(void)
{
	this->Init();
}

/// <summary>
/// �O���[�X�P�[���̎��s
/// </summary>
/// <param name="_token">�L�����Z���g�[�N��</param>
/// <returns>���s���� ����/���s</returns>
bool GrayScale::GoImgProc(CancellationToken^ _token)
{
	bool bRst = true;

	Bitmap^ bitmap = this->GetBitmap();
	int nWidthSize = bitmap->Width;
	int nHeightSize = bitmap->Height;

	Bitmap^ bitmapAfter = gcnew Bitmap(bitmap);

	BitmapData^ bitmapData = bitmapAfter->LockBits(System::Drawing::Rectangle(0, 0, nWidthSize, nHeightSize), ImageLockMode::ReadWrite, PixelFormat::Format32bppArgb);

	int nIdxWidth;
	int nIdxHeight;

	for (nIdxHeight = 0; nIdxHeight < nHeightSize; nIdxHeight++)
	{
		if (_token->IsCancellationRequested)
		{
			bRst = false;
			break;
		}

		for (nIdxWidth = 0; nIdxWidth < nWidthSize; nIdxWidth++)
		{
			if (_token->IsCancellationRequested)
			{
				bRst = false;
				break;
			}

			Byte* pPixel = (Byte*)bitmapData->Scan0.ToPointer() + nIdxHeight * bitmapData->Stride + nIdxWidth * 4;
			Byte nGrayScale = (Byte)((pPixel[ComInfo::Pixel::Type::B] + pPixel[ComInfo::Pixel::Type::G] + pPixel[ComInfo::Pixel::Type::R]) / 3);

			pPixel[ComInfo::Pixel::Type::B] = nGrayScale;
			pPixel[ComInfo::Pixel::Type::G] = nGrayScale;
			pPixel[ComInfo::Pixel::Type::R] = nGrayScale;
		}
	}
	bitmapAfter->UnlockBits(bitmapData);
	this->m_bitmapAfter = (Bitmap^)bitmapAfter->Clone();
	delete bitmapAfter;

	return bRst;
}