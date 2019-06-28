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
	public ref class Binarization
	{
	private:
		Bitmap^ m_bitmap;
		Byte m_nThresh;
	public:
		Binarization(Bitmap^ _bitmap);
		Binarization(Bitmap^ _bitmap, Byte _nThresh);
		~Binarization();
		Bitmap^ GetBitmap() { return m_bitmap; }
		void SetBitmap(Bitmap^ _bitmap) { m_bitmap = _bitmap; }
		bool GoEdgeDetection(CancellationToken _token);
	};
}