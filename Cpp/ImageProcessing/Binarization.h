#pragma once
#include "ComImgProc.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Drawing;
using namespace System::Drawing::Imaging;
using namespace System::Text;
using namespace System::Threading;
using namespace System::Threading::Tasks;

namespace ImageProcessing
{
	public ref class Binarization : public ComImgProc
	{
	private:
		Byte m_nThresh;
	public:
		Binarization(Bitmap^ _bitmap);
		Binarization(Bitmap^ _bitmap, Byte _nThresh);
		~Binarization();
		Byte GetThresh() { return m_nThresh; }
		void SetThresh(Byte _nThresh) { m_nThresh = _nThresh; }
		bool GoImgProc(CancellationToken^ _token);
	};
}