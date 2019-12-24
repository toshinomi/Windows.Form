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
/// エッジ検出のロジック
/// </summary>
public ref class EdgeDetection : public ComImgProc
{
private:
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="_bitmap">ビットマップ</param>
	EdgeDetection(Bitmap^ _bitmap);

	/// <summary>
	/// デスクトラクタ
	/// </summary>
	~EdgeDetection();

	/// <summary>
	/// 初期化
	/// </summary>
	void Init(void) override;

	/// <summary>
	/// エッジ検出の実行
	/// </summary>
	/// <param name="_token">キャンセルトークン</param>
	/// <returns>実行結果 成功/失敗</returns>
	bool GoImgProc(CancellationToken^ _token) override;
};