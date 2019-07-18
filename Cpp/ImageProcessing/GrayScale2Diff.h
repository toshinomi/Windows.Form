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
	public ref class GrayScale2Diff : ComImgProc
	{
	private:
	public:
		GrayScale2Diff(Bitmap^ _bitmap);
		~GrayScale2Diff();
		bool GoImgProc(CancellationToken^ _token) override;
	};
}