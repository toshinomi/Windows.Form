#pragma once

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Drawing;
using namespace System::Drawing::Imaging;
using namespace System::Text;
using namespace System::Threading;
using namespace System::Threading::Tasks;

/// <summary>
/// 画像処理の共通のロジック
/// </summary>
public  ref class ComImageProcessing abstract
{
protected:
	/// <summary>
	/// ビットマップ
	/// </summary>
	Bitmap^ m_bitmap;

public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="_bitmap">ビットマップ</param>
	ComImageProcessing(Bitmap^ bitmap);

	/// <summary>
	/// デスクトラクタ
	/// </summary>
	~ComImageProcessing();

	/// <summary>
	/// 初期化
	/// </summary>
	virtual void Init(void);

	/// <summary>
	/// オリジナルのビットマップの取得
	/// </summary>
	/// <returns>ビットマップ</returns>
	Bitmap^ GetBitmap() { return m_bitmap; }

	/// <summary>
	/// オリジナルのビットマップの設定
	/// </summary>
	/// <param name="bitmap">ビットマップ</param>
	void SetBitmap(Bitmap^ bitmap) { m_bitmap = bitmap; }

	/// <summary>
	/// 画像処理実行の抽象
	/// </summary>
	/// <param name="imageProcessingName">画像処理オブジェクトの名称</param>
	/// <param name="token">キャンセルトークン</param>
	/// <returns>実行結果 成功/失敗</returns>
	virtual bool GoImageProcessing(String^ imageProcessingName, CancellationToken^ token) = 0;
};