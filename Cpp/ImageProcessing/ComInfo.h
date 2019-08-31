#pragma once
using namespace System;

namespace ComInfo
{
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

	namespace ImgData
	{
		enum Type
		{
			Jpg = 0,
			Png,
			MAX,
		};
	}

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
};