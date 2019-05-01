#pragma once
#include <string.h>

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Drawing;
using namespace System::Drawing::Imaging;
using namespace System::Text;
using namespace System::Threading;
using namespace System::Threading::Tasks;

namespace ImageProcessing
{
	public ref class EdgeDetection
	{
	private:
		const int m_nMaskSize = 3;
		UInt32 m_nFilterMax;
		Bitmap^ m_bitmap;
	public:
		EdgeDetection(Bitmap^ _bitmap);
		EdgeDetection(Bitmap^ _bitmap, UInt32 _filterMax);
		~EdgeDetection();
		Bitmap^ GetBitmap() { return m_bitmap; }
		void SetBitmap(Bitmap^ _bitmap) { m_bitmap = _bitmap; }
		bool GoEdgeDetection(CancellationToken _token);
	};
}