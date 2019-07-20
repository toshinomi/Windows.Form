#pragma once

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Drawing;
using namespace System::Drawing::Imaging;
using namespace System::Text;
using namespace System::Threading;
using namespace System::Threading::Tasks;

namespace ImageProcessing
{
	public  ref class  ComImgProc abstract
	{
	protected:
		Bitmap^ m_bitmap;
		Bitmap^ m_bitmapAfter;
	public:
		ComImgProc(Bitmap^ _bitmap);
		~ComImgProc();
		Bitmap^ GetBitmap() { return m_bitmap; }
		void SetBitmap(Bitmap^ _bitmap) { m_bitmap = _bitmap; }
		Bitmap^ GetBitmapAfter() { return m_bitmapAfter; }
		void SetBitmapAfter(Bitmap^ _bitmap) { m_bitmapAfter = _bitmap; }

		virtual bool GoImgProc(CancellationToken^ _token) = 0;
	};
}