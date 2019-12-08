#pragma once
#include "ComImgProc.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Drawing;
using namespace System::Drawing::Imaging;
using namespace System::Text;
using namespace System::Threading;
using namespace System::Threading::Tasks;

/// <summary>
/// グレースケールのロジック
/// </summary>
public ref class GrayScale : public ComImgProc
{
private:
public:
	GrayScale(Bitmap^ _bitmap);
	~GrayScale();
	void Init(void) override;
	bool GoImgProc(CancellationToken^ _token) override;
};