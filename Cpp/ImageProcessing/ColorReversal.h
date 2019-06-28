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
	public ref class ColorReversal
	{
	private:
		Bitmap^ m_bitmap;
		Byte m_nThresh;
	public:
		ColorReversal(Bitmap^ _bitmap);
		~ColorReversal();
		Bitmap^ GetBitmap() { return m_bitmap; }
		void SetBitmap(Bitmap^ _bitmap) { m_bitmap = _bitmap; }
		bool GoEdgeDetection(CancellationToken _token);
	};
}