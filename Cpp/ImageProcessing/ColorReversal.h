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
/// 色反転のロジック
/// </summary>
public ref class ColorReversal
{
private:
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	ColorReversal();

	/// <summary>
	/// デスクトラクタ
	/// </summary>
	~ColorReversal();

	/// <summary>
	/// 色反転の実行
	/// </summary>
	/// <param name="bitmap">ビットマップ</param>
	/// <param name="token">キャンセルトークン</param>
	/// <returns>実行結果 成功/失敗</returns>
	bool ImageProcessing(Bitmap^ bitmap, CancellationToken^ token);
};