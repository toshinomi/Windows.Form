#pragma once
#include <string.h>
#include "ComImageProcessing.h"
#include "ComFunc.h"
#include "ComInfo.h"
#include "EdgeDetection.h"
#include "GrayScale.h"
#include "Binarization.h"
#include "GrayScale2Diff.h"
#include "ColorReversal.h"

namespace ImageProcessing {

	using namespace System;
	using namespace System::Collections::Generic;
	using namespace System::Drawing;
	using namespace System::Drawing::Imaging;
	using namespace System::Text;
	using namespace System::Threading;
	using namespace System::Threading::Tasks;

	/// <summary>
	/// 画像処理のロジック
	/// </summary>
	public ref class ImageProcessing : public ComImageProcessing
	{
	private:
		array<Object^>^ arrayImageProcessing = gcnew array<Object^>(ComInfo::ImgProc::Type::MAX);

		/// <summary>
		/// 閾値
		/// </summary>
		Byte thresh;
	public:
		/// <summary>
		/// コンストラクタ
		/// </summary>
		/// <param name="_bitmap">ビットマップ</param>
		ImageProcessing(Bitmap^ bitmap);

		/// <summary>
		/// デスクトラクタ
		/// </summary>
		~ImageProcessing();

		/// <summary>
		/// 初期化
		/// </summary>
		void Init(void) override;

		/// <summary>
		/// 閾値の取得
		/// </summary>
		/// <returns>閾値</returns>
		Byte GetThresh() { return thresh; }

		/// <summary>
		/// 閾値の設定
		/// </summary>
		/// <param name="thresh">閾値</param>
		void SetThresh(Byte thresh) { this->thresh = thresh; }

		/// <summary>
		/// 画像処理の実行
		/// </summary>
		/// <param name="imageProcessingName">画像処理オブジェクトの名称</param>
		/// <param name="token">キャンセルトークン</param>
		/// <returns>実行結果 成功/失敗</returns>
		bool GoImageProcessing(String^ imageProcessingName, CancellationToken^ _token) override;
	};
};