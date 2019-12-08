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
public  ref class  ComImgProc abstract
{
protected:
	/// <summary>
	/// ビットマップ
	/// </summary>
	Bitmap^ m_bitmap;

	/// <summary>
	/// 画像処理後のビットマップ
	/// </summary>
	Bitmap^ m_bitmapAfter;
public:
	ComImgProc(Bitmap^ _bitmap);
	~ComImgProc();
	virtual void Init(void);
	Bitmap^ GetBitmap() { return m_bitmap; }
	void SetBitmap(Bitmap^ _bitmap) { m_bitmap = _bitmap; }
	Bitmap^ GetBitmapAfter() { return m_bitmapAfter; }
	void SetBitmapAfter(Bitmap^ _bitmap) { m_bitmapAfter = _bitmap; }

	/// <summary>
	/// 画像処理実行の抽象
	/// </summary>
	/// <param name="_token">キャンセルトークン</param>
	/// <returns>実行結果 成功/失敗</returns>
	virtual bool GoImgProc(CancellationToken^ _token) = 0;
};