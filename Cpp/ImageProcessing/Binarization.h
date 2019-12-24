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
/// 2値化のロジック
/// </summary>
public ref class Binarization : public ComImgProc
{
private:
	/// <summary>
	/// 閾値
	/// </summary>
	Byte m_nThresh;
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="_bitmap">ビットマップ</param>
	Binarization(Bitmap^ _bitmap);

	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="_bitmap">ビットマップ</param>
	/// <param name="_nThresh">閾値</param>
	Binarization(Bitmap^ _bitmap, Byte _nThresh);

	/// <summary>
	/// デスクトラクタ
	/// </summary>
	~Binarization();

	/// <summary>
	/// 初期化
	/// </summary>
	void Init(void) override;

	/// <summary>
	/// 閾値の取得
	/// </summary>
	/// <returns>閾値</returns>
	Byte GetThresh() { return m_nThresh; }

	/// <summary>
	/// 閾値の設定
	/// </summary>
	/// <param name="_nThresh">閾値</param>
	void SetThresh(Byte _nThresh) { m_nThresh = _nThresh; }

	/// <summary>
	/// 2値化の実行
	/// </summary>
	/// <param name="_token">キャンセルトークン</param>
	/// <returns>実行結果 成功/失敗</returns>
	bool GoImgProc(CancellationToken^ _token) override;
};