#pragma once

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Drawing;
using namespace System::Drawing::Imaging;
using namespace System::Text;
using namespace System::Threading;
using namespace System::Threading::Tasks;

/// <summary>
/// エッジ検出の設定管理のロジック
/// </summary>
public ref class EdgeDetectionInfo
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	EdgeDetectionInfo()
	{
	}

	/// <summary>
	/// デスクトラクタ
	/// </summary>
	~EdgeDetectionInfo()
	{
	}
};

/// <summary>
/// グレースケールの設定管理のロジック
/// </summary>
public ref class GrayScaleInfo
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	GrayScaleInfo()
	{
	}

	/// <summary>
	/// デスクトラクタ
	/// </summary>
	~GrayScaleInfo()
	{
	}
};

/// <summary>
/// 2値化の設定管理のロジック
/// </summary>
public ref class BinarizationInfo
{
private:
	/// <summary>
	/// 閾値
	/// </summary>
	Byte mThresh;
public:
	/// <summary>
	/// 閾値の設定
	/// </summary>
	/// <param name="_nThresh">閾値</param>
	void SetThresh(Byte Thresh) { mThresh = Thresh; }

	/// <summary>
	/// 閾値の取得
	/// </summary>
	/// <returns>閾値</returns>
	Byte GetThresh(void) { return mThresh; }

	/// <summary>
	/// コンストラクタ
	/// </summary>
	BinarizationInfo()
	{
	}

	/// <summary>
	/// デスクトラクタ
	/// </summary>
	~BinarizationInfo()
	{
	}
};

/// <summary>
/// グレースケール2次微分の設定管理のロジック
/// </summary>
public ref class GrayScale2DiffInfo
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	GrayScale2DiffInfo()
	{
	}

	/// <summary>
	/// デスクトラクタ
	/// </summary>
	~GrayScale2DiffInfo()
	{
	}
};

/// <summary>
/// 色反転の設定管理のロジック
/// </summary>
public ref class ColorReversalInfo
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	ColorReversalInfo()
	{
	}

	/// <summary>
	/// デスクトラクタ
	/// </summary>
	~ColorReversalInfo()
	{
	}
};

/// <summary>
/// 画像処理の設定管理のロジック
/// </summary>
public ref class ComImgInfo
{
private:
	/// <summary>
	/// 現在の画像処理の名称
	/// </summary>
	String^ mCurrentImageProcessingName;

	/// <summary>
	/// エッジ検出の設定
	/// </summary>
	EdgeDetectionInfo^ mEdgeDetectoinInfo;

	/// <summary>
	/// グレースケールの設定
	/// </summary>
	GrayScaleInfo^ mGrayScaleInfo;

	/// <summary>
	/// 2値化の設定
	/// </summary>
	BinarizationInfo^ mBinarizationInfo;

	/// <summary>
	/// グレースケール2次微分の設定
	/// </summary>
	GrayScale2DiffInfo^ mGrayScale2DiffInfo;

	/// <summary>
	/// 色反転の設定
	/// </summary>
	ColorReversalInfo^ mColorReversalInfo;
public:
	/// <summary>
	/// 現在の画像処理タイプの名称の設定
	/// </summary>
	/// <param name="currentImageProcessingName">画像処理タイプの名称</param>
	void SetCurrentImageProcessingName(String^ currentImageProcessingName) { mCurrentImageProcessingName = currentImageProcessingName; }

	/// <summary>
	/// 現在の画像処理タイプの名称の取得
	/// </summary>
	/// <returns>画像処理タイプの名称</returns>
	String^ GetCurImgName(void) { return mCurrentImageProcessingName; }

	/// <summary>
	/// エッジ検出情報の設定
	/// </summary>
	/// <param name="edgeDetectoinInfo">エッジ検出情報</param>
	void SetEdgeDetectionInfo(EdgeDetectionInfo^ edgeDetectoinInfo) { mEdgeDetectoinInfo = edgeDetectoinInfo; }

	/// <summary>
	/// エッジ検出情報の取得
	/// </summary>
	/// <returns>エッジ検出情報</returns>
	EdgeDetectionInfo^ GetEdgeDetectionInfo() { return mEdgeDetectoinInfo; }

	/// <summary>
	/// グレースケール情報の設定
	/// </summary>
	/// <param name="grayScaleInfo">グレースケール情報</param>
	void SetGrayScaleInfo(GrayScaleInfo^ grayScaleInfo) { mGrayScaleInfo = grayScaleInfo; }

	/// <summary>
	/// グレースケール情報の取得
	/// </summary>
	/// <returns>グレースケール情報</returns>
	GrayScaleInfo^ GetGrayScaleInfo(void) { return mGrayScaleInfo; }

	/// <summary>
	/// 2値化情報の設定
	/// </summary>
	/// <param name="binarizationInfo">2値化情報</param>
	void SetBinarizationInfo(BinarizationInfo^ binarizationInfo) { mBinarizationInfo = binarizationInfo; }

	/// <summary>
	/// 2値化情報の取得
	/// </summary>
	/// <returns>2値化情報</returns>
	BinarizationInfo^ GetBinarizationInfo(void) { return mBinarizationInfo; }

	/// <summary>
	/// グレースケール2次微分情報の設定
	/// </summary>
	/// <param name="grayScale2DiffInfo">グレースケール2次微分情報</param>
	void SetGrayScale2DiffInfo(GrayScale2DiffInfo^ grayScale2DiffInfo) { mGrayScale2DiffInfo = grayScale2DiffInfo; }

	/// <summary>
	/// グレースケール2次微分情報の取得
	/// </summary>
	/// <returns>グレースケール2次微分情報</returns>
	GrayScale2DiffInfo^ GetGrayScale2DiffInfo(void) { return mGrayScale2DiffInfo; }

	/// <summary>
	/// 色反転情報の設定
	/// </summary>
	/// <param name="colorReversalInfo">色反転情報</param>
	void SetColorReversalInfo(ColorReversalInfo^ colorReversalInfo) { mColorReversalInfo = colorReversalInfo; }

	/// <summary>
	/// 色反転情報の取得
	/// </summary>
	/// <returns>色反転情報</returns>
	ColorReversalInfo^ GetColorReversalInfo(void) { return mColorReversalInfo; }

	/// <summary>
	/// コンストラクタ
	/// </summary>
	ComImgInfo()
	{
		mEdgeDetectoinInfo = gcnew EdgeDetectionInfo();
		mGrayScaleInfo = gcnew GrayScaleInfo();
		mBinarizationInfo = gcnew BinarizationInfo();
		mGrayScale2DiffInfo = gcnew GrayScale2DiffInfo();
		mColorReversalInfo = gcnew ColorReversalInfo();
	}

	/// <summary>
	/// デスクトラクタ
	/// </summary>
	~ComImgInfo()
	{
	}
};