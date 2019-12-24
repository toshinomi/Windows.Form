#pragma once
using namespace System;

namespace ComInfo
{
	/// <summary>
	/// Pixelの列挙
	/// </summary>
	namespace Pixel
	{
		enum Type
		{
			B = 0,
			G,
			R,
			A,
			MAX,
		};
	}

	/// <summary>
	/// 画像処理のタイプの列挙
	/// </summary>
	namespace ImgProc
	{
		enum Type
		{
			EdgeDetection = 0,
			GrayScale,
			Binarization,
			GrayScale2Diff,
			ColorReversal,
			MAX,
		};
	}

	/// <summary>
	/// 画像のタイプの列挙
	/// </summary>
	namespace ImgData
	{
		enum Type
		{
			Jpg = 0,
			Png,
			MAX,
		};
	}

	/// <summary>
	/// 画像の状態の列挙
	/// </summary>
	namespace Picture
	{
		enum Type
		{
			Original = 0,
			After,
			MAX,
		};
	}
	static const short RGB_MAX = 256;
}

/// <summary>
/// 共通の文字列
/// </summary>
public ref class ComConstStringInfo
{
public:
	static const String^ MENU_SETTING_IMAGE_PROCESSING = "Image Processing";
	static const String^ MENU_FILE_END = "End(&X)";
	static const String^ MENU_SAVE_CSV = "Save Csv...";
	static const String^ BTN_OK = "btnOk";
	static const String^ BTN_CANCEL = "btnCancel";
	static const String^ IMG_NAME_EDGE_DETECTION = "EdgeDetection";
	static const String^ IMG_NAME_GRAY_SCALE = "GrayScale";
	static const String^ IMG_NAME_BINARIZATION = "Binarization";
	static const String^ IMG_NAME_GRAY_SCALE_2DIFF = "GrayScale 2Diff";
	static const String^ IMG_NAME_COLOR_REVERSAL = "ColorReversal";

	static const String^ IMG_TYPE_SELECT_NAME = "ImgTypeSelectName";
	static const String^ IMG_TYPE_EDGE_ID = "ImgTypeEdgeId";
	static const String^ IMG_TYPE_EDGE_NAME = "ImgTypeEdgeName";
	static const String^ IMG_TYPE_GRAY_SCALE_ID = "ImgTypeGrayScaleId";
	static const String^ IMG_TYPE_GRAY_SCALE_NAME = "ImgTypeGrayScaleName";
	static const String^ IMG_TYPE_BINARIZATION_ID = "ImgTypeBinarizationId";
	static const String^ IMG_TYPE_BINARIZATION_NAME = "ImgTypeBinarizationName";
	static const String^ IMG_TYPE_GRAY_SCALE_2DIFF_ID = "ImgTypeGrayScale2DiffId";
	static const String^ IMG_TYPE_GRAY_SCALE_2DIFF_NAME = "ImgTypeGrayScale2DiffName";
	static const String^ IMG_TYPE_COLOR_REVERSAL_ID = "ImgTypeColorReversalId";
	static const String^ IMG_TYPE_COLOR_REVERSAL_NAME = "ImgTypeColorReversalName";
};