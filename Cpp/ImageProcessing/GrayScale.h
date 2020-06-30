#pragma once
#include "ComImageProcessing.h"

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
public ref class GrayScale
{
private:
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	GrayScale();

	/// <summary>
	/// デスクトラクタ
	/// </summary>
	~GrayScale();

	/// <summary>
	/// グレースケールの実行
	/// </summary>
	/// <param name="bitmap">ビットマップ</param>
	/// <param name="token">キャンセルトークン</param>
	/// <returns>実行結果 成功/失敗</returns>
	bool ImageProcessing(Bitmap^ bitmap, CancellationToken^ token);
};