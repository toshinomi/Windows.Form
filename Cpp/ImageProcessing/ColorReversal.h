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
	public ref class ColorReversal : public ComImgProc
	{
	private:
		Byte m_nThresh;
	public:
		ColorReversal(Bitmap^ _bitmap);
		~ColorReversal();
		bool GoImgProc(CancellationToken^ _token) override;
	};
}