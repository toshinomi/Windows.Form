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
/// グレースケール2次微分のロジック
/// </summary>
public ref class GrayScale2Diff : ComImgProc
{
private:
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="_bitmap">ビットマップ</param>
	GrayScale2Diff(Bitmap^ _bitmap);

	/// <summary>
	/// デスクトラクタ
	/// </summary>
	~GrayScale2Diff();

	/// <summary>
	/// 初期化
	/// </summary>
	void Init(void) override;

	/// <summary>
	/// グレースケール2次微分の実行
	/// </summary>
	/// <param name="_token">キャンセルトークン</param>
	/// <returns>実行結果 成功/失敗</returns>
	bool GoImgProc(CancellationToken^ _token) override;
};