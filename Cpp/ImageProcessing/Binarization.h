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
/// 2値化のロジック
/// </summary>
public ref class Binarization
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	Binarization();

	/// <summary>
	/// デスクトラクタ
	/// </summary>
	~Binarization();

	/// <summary>
	/// 2値化の実行
	/// </summary>
	/// <param name="bitmap">ビットマップ</param>
	/// <param name="token">キャンセルトークン</param>
	/// <param name="thresh">閾値</param>
	/// <returns>実行結果 成功/失敗</returns>
	bool ImageProcessing(Bitmap^ bitmap, CancellationToken^ token, Byte thresh);
};