#pragma once

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Drawing;
using namespace System::Drawing::Imaging;
using namespace System::Text;
using namespace System::Threading;
using namespace System::Threading::Tasks;

public ref class ComEdgeDetectionInfo
{
public:
	ComEdgeDetectionInfo()
	{
	}

	~ComEdgeDetectionInfo()
	{
	}
};

public ref class ComGrayScaleInfo
{
public:
	ComGrayScaleInfo()
	{
	}

	~ComGrayScaleInfo()
	{
	}
};

public ref class ComBinarizationInfo
{
private:
	Byte^ m_nThresh;
public:
	void SetThresh(Byte^ _nThresh) { m_nThresh = _nThresh; }
	Byte^ GetThresh(void) { return m_nThresh; }
	ComBinarizationInfo()
	{
	}

	~ComBinarizationInfo()
	{
	}
};

public ref class ComGrayScale2DiffInfo
{
public:
	ComGrayScale2DiffInfo()
	{
	}

	~ComGrayScale2DiffInfo()
	{
	}
};

public ref class ComColorReversalInfo
{
public:
	ComColorReversalInfo()
	{
	}

	~ComColorReversalInfo()
	{
	}
};

public ref class ComImgInfo
{
private:
	String^ m_strCurImgName;
	ComEdgeDetectionInfo^ m_edgeDetectoinInfo;
	ComGrayScaleInfo^ m_grayScaleInfo;
	ComBinarizationInfo^ m_binarizationInfo;
	ComGrayScale2DiffInfo^ m_grayScale2DiffInfo;
	ComColorReversalInfo^ m_colorReversalInfo;
public:
	void SetCurImgName(String^ _strCurImgName) { m_strCurImgName = _strCurImgName; }
	String^ GetCurImgName(void) { return m_strCurImgName; }

	void SetEdgeDetectionInfo(ComEdgeDetectionInfo^ _edgeDetectoinInfo) { m_edgeDetectoinInfo = _edgeDetectoinInfo; }
	ComEdgeDetectionInfo^ GetEdgeDetectionInfo() { return m_edgeDetectoinInfo; }

	void SetGrayScaleInfo(ComGrayScaleInfo^ _grayScaleInfo) { m_grayScaleInfo = _grayScaleInfo; }
	ComGrayScaleInfo^ GetGrayScaleInfo(void) { return m_grayScaleInfo; }

	void SetBinarizationInfo(ComBinarizationInfo^ _binarizationInfo) { m_binarizationInfo = _binarizationInfo; }
	ComBinarizationInfo^ GetBinarizationInfo(void) { return m_binarizationInfo; }

	void SetGrayScale2DiffInfo(ComGrayScale2DiffInfo^ _grayScale2DiffInfo) { m_grayScale2DiffInfo = _grayScale2DiffInfo; }
	ComGrayScale2DiffInfo^ GetGrayScale2DiffInfo(void) { return m_grayScale2DiffInfo; }

	void SetColorReversalInfo(ComColorReversalInfo^ _colorReversalInfo) { m_colorReversalInfo = _colorReversalInfo; }
	ComColorReversalInfo^ GetColorReversalInfo(void) { return m_colorReversalInfo; }

	ComImgInfo()
	{
		m_edgeDetectoinInfo = gcnew ComEdgeDetectionInfo();
		m_grayScaleInfo = gcnew ComGrayScaleInfo();
		m_binarizationInfo = gcnew ComBinarizationInfo();
		m_grayScale2DiffInfo = gcnew ComGrayScale2DiffInfo();
		m_colorReversalInfo = gcnew ComColorReversalInfo();
	}

	~ComImgInfo()
	{
		delete m_edgeDetectoinInfo;
		delete m_grayScaleInfo;
		delete m_binarizationInfo;
		delete m_grayScale2DiffInfo;
		delete m_colorReversalInfo;
	}
};