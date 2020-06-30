#pragma once
#include <string.h>
#include "ComImageProcessing.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Drawing;
using namespace System::Drawing::Imaging;
using namespace System::Text;
using namespace System::Threading;
using namespace System::Threading::Tasks;

/// <summary>
/// エッジ検出のロジック
/// </summary>
public ref class EdgeDetection
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	EdgeDetection();

	/// <summary>
	/// デスクトラクタ
	/// </summary>
	~EdgeDetection();

	/// <summary>
	/// エッジ検出の実行
	/// </summary>
	/// <param name="bitmap">ビットマップ</param>
	/// <param name="token">キャンセルトークン</param>
	/// <returns>実行結果 成功/失敗</returns>
	bool ImageProcessing(Bitmap^ bitmap, CancellationToken^ token);
};