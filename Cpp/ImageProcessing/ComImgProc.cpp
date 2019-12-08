#include "ComImgProc.h"

ComImgProc::ComImgProc(Bitmap^ _bitmap)
{
	m_bitmap = _bitmap;
}

ComImgProc::~ComImgProc()
{
}

void ComImgProc::Init(void)
{
	m_bitmap = nullptr;
	m_bitmapAfter = nullptr;
}
