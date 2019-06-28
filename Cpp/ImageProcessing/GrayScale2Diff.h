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
	public ref class GrayScale2Diff
	{
	private:
		const int m_nMaskSize = 3;
		Bitmap^ m_bitmap;
	public:
		GrayScale2Diff(Bitmap^ _bitmap);
		~GrayScale2Diff();
		Bitmap^ GetBitmap() { return m_bitmap; }
		void SetBitmap(Bitmap^ _bitmap) { m_bitmap = _bitmap; }
		bool GoEdgeDetection(CancellationToken _token);
	};
}