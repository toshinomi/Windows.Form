#pragma once

namespace ImageProcessing
{
	public class ComInfo
	{
	public:
		enum Pixel
		{
			B = 0,
			G,
			R,
			A,
		};

		enum ImgType
		{
			EdgeDetection = 0,
		};

		enum ImgDataType
		{
			Jpg = 0,
			Png,
		};
	};

	public ref class ComConstStringInfo
	{
	public:
		static const String^ MENU_SETTING_IMAGE_PROCESSING = "Image Processing";
		static const String^ MENU_FILE_END = "End(_X)";
		static const String^ MENU_SAVE_CSV = "Save Csv...";
		static const String^ BTN_OK = "btnOk";
		static const String^ BTN_CANCEL = "btnCancel";
		static const String^ IMG_NAME_EDGE_DETECTION = "EdgeDetection";
		static const String^ IMG_NAME_GRAY_SCALE = "GrayScale";
		static const String^ IMG_NAME_BINARIZATION = "Binarization";
		static const String^ IMG_NAME_GRAY_SCALE_2DIFF = "GrayScale 2Diff";
		static const String^ IMG_NAME_COLOR_REVERSAL = "ColorReversal";
	};
}