#pragma once
#include <string.h>
#include "ComImgProc.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Drawing;
using namespace System::Drawing::Imaging;
using namespace System::Text;
using namespace System::Threading;
using namespace System::Threading::Tasks;

/// <summary>
/// �G�b�W���o�̃��W�b�N
/// </summary>
public ref class EdgeDetection : public ComImgProc
{
private:
public:
	EdgeDetection(Bitmap^ _bitmap);
	~EdgeDetection();
	void Init(void) override;
	bool GoImgProc(CancellationToken^ _token) override;
};