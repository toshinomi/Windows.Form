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
	Byte^ m_nThresh;
public:
	/// <summary>
	/// 閾値の設定
	/// </summary>
	/// <param name="_nThresh">閾値</param>
	void SetThresh(Byte^ _nThresh) { m_nThresh = _nThresh; }

	/// <summary>
	/// 閾値の取得
	/// </summary>
	/// <returns>閾値</returns>
	Byte^ GetThresh(void) { return m_nThresh; }

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
	String^ m_strCurImgName;

	/// <summary>
	/// エッジ検出の設定
	/// </summary>
	EdgeDetectionInfo^ m_edgeDetectoinInfo;

	/// <summary>
	/// グレースケールの設定
	/// </summary>
	GrayScaleInfo^ m_grayScaleInfo;

	/// <summary>
	/// 2値化の設定
	/// </summary>
	BinarizationInfo^ m_binarizationInfo;

	/// <summary>
	/// グレースケール2次微分の設定
	/// </summary>
	GrayScale2DiffInfo^ m_grayScale2DiffInfo;

	/// <summary>
	/// 色反転の設定
	/// </summary>
	ColorReversalInfo^ m_colorReversalInfo;
public:
	/// <summary>
	/// 現在の画像処理タイプの名称の設定
	/// </summary>
	/// <param name="_strCurImgName">画像処理タイプの名称</param>
	void SetCurImgName(String^ _strCurImgName) { m_strCurImgName = _strCurImgName; }

	/// <summary>
	/// 現在の画像処理タイプの名称の取得
	/// </summary>
	/// <returns>画像処理タイプの名称</returns>
	String^ GetCurImgName(void) { return m_strCurImgName; }

	/// <summary>
	/// エッジ検出情報の設定
	/// </summary>
	/// <param name="_edgeDetectoinInfo">エッジ検出情報</param>
	void SetEdgeDetectionInfo(EdgeDetectionInfo^ _edgeDetectoinInfo) { m_edgeDetectoinInfo = _edgeDetectoinInfo; }

	/// <summary>
	/// エッジ検出情報の取得
	/// </summary>
	/// <returns>エッジ検出情報</returns>
	EdgeDetectionInfo^ GetEdgeDetectionInfo() { return m_edgeDetectoinInfo; }

	/// <summary>
	/// グレースケール情報の設定
	/// </summary>
	/// <param name="_grayScaleInfo">グレースケール情報</param>
	void SetGrayScaleInfo(GrayScaleInfo^ _grayScaleInfo) { m_grayScaleInfo = _grayScaleInfo; }

	/// <summary>
	/// グレースケール情報の取得
	/// </summary>
	/// <returns>グレースケール情報</returns>
	GrayScaleInfo^ GetGrayScaleInfo(void) { return m_grayScaleInfo; }

	/// <summary>
	/// 2値化情報の設定
	/// </summary>
	/// <param name="_binarizationInfo">2値化情報</param>
	void SetBinarizationInfo(BinarizationInfo^ _binarizationInfo) { m_binarizationInfo = _binarizationInfo; }

	/// <summary>
	/// 2値化情報の取得
	/// </summary>
	/// <returns>2値化情報</returns>
	BinarizationInfo^ GetBinarizationInfo(void) { return m_binarizationInfo; }

	/// <summary>
	/// グレースケール2次微分情報の設定
	/// </summary>
	/// <param name="_grayScale2DiffInfo">グレースケール2次微分情報</param>
	void SetGrayScale2DiffInfo(GrayScale2DiffInfo^ _grayScale2DiffInfo) { m_grayScale2DiffInfo = _grayScale2DiffInfo; }

	/// <summary>
	/// グレースケール2次微分情報の取得
	/// </summary>
	/// <returns>グレースケール2次微分情報</returns>
	GrayScale2DiffInfo^ GetGrayScale2DiffInfo(void) { return m_grayScale2DiffInfo; }

	/// <summary>
	/// 色反転情報の設定
	/// </summary>
	/// <param name="_colorReversalInfo">色反転情報</param>
	void SetColorReversalInfo(ColorReversalInfo^ _colorReversalInfo) { m_colorReversalInfo = _colorReversalInfo; }

	/// <summary>
	/// 色反転情報の取得
	/// </summary>
	/// <returns>色反転情報</returns>
	ColorReversalInfo^ GetColorReversalInfo(void) { return m_colorReversalInfo; }

	/// <summary>
	/// コンストラクタ
	/// </summary>
	ComImgInfo()
	{
		m_edgeDetectoinInfo = gcnew EdgeDetectionInfo();
		m_grayScaleInfo = gcnew GrayScaleInfo();
		m_binarizationInfo = gcnew BinarizationInfo();
		m_grayScale2DiffInfo = gcnew GrayScale2DiffInfo();
		m_colorReversalInfo = gcnew ColorReversalInfo();
	}

	/// <summary>
	/// デスクトラクタ
	/// </summary>
	~ComImgInfo()
	{
		delete m_edgeDetectoinInfo;
		delete m_grayScaleInfo;
		delete m_binarizationInfo;
		delete m_grayScale2DiffInfo;
		delete m_colorReversalInfo;
	}
};