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
/// 色反転のロジック
/// </summary>
public ref class ColorReversal : public ComImgProc
{
private:
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="_bitmap">ビットマップ</param>
	ColorReversal(Bitmap^ _bitmap);

	/// <summary>
	/// デスクトラクタ
	/// </summary>
	~ColorReversal();

	/// <summary>
	/// 初期化
	/// </summary>
	void Init(void) override;

	/// <summary>
	/// 色反転の実行
	/// </summary>
	/// <param name="_token">キャンセルトークン</param>
	/// <returns>実行結果 成功/失敗</returns>
	bool GoImgProc(CancellationToken^ _token) override;
};