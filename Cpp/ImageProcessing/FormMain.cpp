#include "FormMain.h"
#include "ComOpenFileDialog.h"
#include "ComSaveFileDialog.h"
#include "FormSettingImageProcessing.h"
#include "FormHistgram.h"
#include "ComInfo.h"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;
using namespace System::Threading;
using namespace System::Drawing::Imaging;
using namespace System::Diagnostics;
using namespace System::Threading::Tasks;
using namespace System::Windows::Forms;

using namespace ImageProcessing;

void FormMain::SetToolTip()
{
	toolTipBtnFileSelect->InitialDelay = 1000;
	toolTipBtnFileSelect->ReshowDelay = 1000;
	toolTipBtnFileSelect->AutoPopDelay = 10000;
	toolTipBtnFileSelect->ShowAlways = false;
	toolTipBtnFileSelect->SetToolTip(btnFileSelect, "Please select a file to open.\nDisplay the image on the original image.");

	toolTipBtnAllClear->InitialDelay = 1000;
	toolTipBtnAllClear->ReshowDelay = 1000;
	toolTipBtnAllClear->AutoPopDelay = 10000;
	toolTipBtnAllClear->ShowAlways = false;
	toolTipBtnAllClear->SetToolTip(btnAllClear, "Clear the display.");

	toolTipBtnStart->InitialDelay = 1000;
	toolTipBtnStart->ReshowDelay = 1000;
	toolTipBtnStart->AutoPopDelay = 10000;
	toolTipBtnStart->ShowAlways = false;
	toolTipBtnStart->SetToolTip(btnStart, "Perform unstable filter processing.");

	toolTipBtnStop->InitialDelay = 1000;
	toolTipBtnStop->ReshowDelay = 1000;
	toolTipBtnStop->AutoPopDelay = 10000;
	toolTipBtnStop->ShowAlways = false;
	toolTipBtnStop->SetToolTip(btnStop, "Processing stop.");

	toolTipBtnSaveImage->InitialDelay = 1000;
	toolTipBtnSaveImage->ReshowDelay = 1000;
	toolTipBtnSaveImage->AutoPopDelay = 10000;
	toolTipBtnSaveImage->ShowAlways = false;
	toolTipBtnSaveImage->SetToolTip(btnSaveImage, "Saving image.");

	toolTipBtnShowHistgram->InitialDelay = 1000;
	toolTipBtnShowHistgram->ReshowDelay = 1000;
	toolTipBtnShowHistgram->AutoPopDelay = 10000;
	toolTipBtnShowHistgram->ShowAlways = false;
	toolTipBtnShowHistgram->SetToolTip(btnShowHistgram, "Show Histgram.");

	return;
}

void FormMain::SetButtonEnable()
{
	btnFileSelect->Enabled = true;
	btnAllClear->Enabled = true;
	btnStart->Enabled = true;
	btnStop->Enabled = false;
	btnSaveImage->Enabled = true;
	btnShowHistgram->Enabled = true;
	menuMain->Enabled = true;
}

void FormMain::SetTextTime(long long _lTime)
{
	textBoxTime->Text = _lTime.ToString();

	return;
}

void FormMain::SetPictureBoxStatus()
{
	pictureBoxStatus->Visible = false;

	return;
}

void FormMain::ExecTaskImageProcessing()
{
	Stopwatch^ stopwatch = gcnew Stopwatch();
	stopwatch->Start();

	m_tokenSource = gcnew CancellationTokenSource();
	CancellationToken^ token = m_tokenSource->Token;

	ComImgInfo^ imgInfo = gcnew ComImgInfo();
	ComBinarizationInfo^ binarizationInfo = gcnew ComBinarizationInfo();
	FuncDelegate::GetSliderThreshDelegate^ getSliderThreshDelegate = gcnew FuncDelegate::GetSliderThreshDelegate(this, &FormMain::GetSliderThresh);
	Byte nThresh = (Byte)this->Invoke(getSliderThreshDelegate);
	binarizationInfo->SetThresh(nThresh);
	imgInfo->SetCurImgName(m_strCurImgName);
	imgInfo->SetBinarizationInfo(binarizationInfo);
	bool bRst = SelectGoImgProc(imgInfo, token);
	if (bRst)
	{
		pictureBoxOriginal->ImageLocation = m_strOpenFileName;
		pictureBoxAfter->Image = SelectGetBitmap(m_strCurImgName);

		stopwatch->Stop();

		Invoke(gcnew Action<long long>(this, &FormMain::SetTextTime), stopwatch->ElapsedMilliseconds);

		Bitmap^ bitmap = gcnew Bitmap(m_strOpenFileName);
		m_histgram->SetBitmapOrg((Bitmap^)bitmap->Clone());
		if (SelectGetBitmap(m_strCurImgName) != nullptr)
		{
			System::Threading::Thread::Sleep(50);
			m_histgram->SetBitmapAfter((Bitmap^)SelectGetBitmap(m_strCurImgName)->Clone());
		}
		if (m_histgram->GetIsOpen() == true)
		{
			Invoke(gcnew Action(m_histgram, &FormHistgram::DrawHistgram));
		}
		delete bitmap;
	}
	Invoke(gcnew Action(this, &FormMain::SetPictureBoxStatus));
	Invoke(gcnew Action(this, &FormMain::SetButtonEnable));

	delete stopwatch;
	delete m_tokenSource;
	delete imgInfo;
	delete binarizationInfo;
	m_tokenSource = nullptr;

	return;
}

void FormMain::ExecTaskParamAjust()
{
	m_tokenSource = gcnew CancellationTokenSource();
	CancellationToken^ token = m_tokenSource->Token;

	ComImgInfo^ imgInfo = gcnew ComImgInfo();
	ComBinarizationInfo^ binarizationInfo = gcnew ComBinarizationInfo();
	FuncDelegate::GetSliderThreshDelegate^ getSliderThreshDelegate = gcnew FuncDelegate::GetSliderThreshDelegate(this, &FormMain::GetSliderThresh);
	Byte nThresh = (Byte)this->Invoke(getSliderThreshDelegate);
	binarizationInfo->SetThresh(nThresh);
	imgInfo->SetCurImgName(m_strCurImgName);
	imgInfo->SetBinarizationInfo(binarizationInfo);
	bool bRst = SelectGoImgProc(imgInfo, token);
	if (bRst)
	{
		pictureBoxOriginal->ImageLocation = m_strOpenFileName;
		pictureBoxAfter->Image = SelectGetBitmap(m_strCurImgName);

		Bitmap^ bitmap = gcnew Bitmap(m_strOpenFileName);
		m_histgram->SetBitmapOrg((Bitmap^)bitmap->Clone());
		if (SelectGetBitmap(m_strCurImgName) != nullptr)
		{
			System::Threading::Thread::Sleep(50);
			m_histgram->SetBitmapAfter((Bitmap^)SelectGetBitmap(m_strCurImgName)->Clone());
		}
		if (m_histgram->GetIsOpen() == true)
		{
			Invoke(gcnew Action(m_histgram, &FormHistgram::DrawHistgram));
		}
		delete bitmap;
	}
	Invoke(gcnew Action(this, &FormMain::SetPictureBoxStatus));
	Invoke(gcnew Action(this, &FormMain::SetButtonEnable));

	delete m_tokenSource;
	delete imgInfo;
	delete binarizationInfo;
	m_tokenSource = nullptr;

	return;
}

bool FormMain::SelectGoImgProc(ComImgInfo^ _comImgInfo, CancellationToken^ _token)
{
	bool bRst = true;

	String^ strCurName = _comImgInfo->GetCurImgName();
	int nId = SearchImgTypeId(strCurName);

	switch (nId)
	{
	case ComInfo::ImgProc::Type::EdgeDetection:
	{
		EdgeDetection^ edge = (EdgeDetection^)m_imgProc;
		bRst = edge->GoImgProc(_token);
		break;
	}
	case ComInfo::ImgProc::Type::GrayScale:
	{
		GrayScale^ gray = (GrayScale^)m_imgProc;
		bRst = gray->GoImgProc(_token);
		break;
	}
	case ComInfo::ImgProc::Type::Binarization:
	{
		Binarization^ binarization = (Binarization^)m_imgProc;
		ComBinarizationInfo^ comBinarizationInfo = _comImgInfo->GetBinarizationInfo();
		binarization->SetThresh((Byte)comBinarizationInfo->GetThresh());
		bRst = binarization->GoImgProc(_token);
		break;
	}
	case ComInfo::ImgProc::Type::GrayScale2Diff:
	{
		GrayScale2Diff^ gray2Diff = (GrayScale2Diff^)m_imgProc;
		bRst = gray2Diff->GoImgProc(_token);
		break;
	}
	case ComInfo::ImgProc::Type::ColorReversal:
	{
		ColorReversal^ colorReversal = (ColorReversal^)m_imgProc;
		bRst = colorReversal->GoImgProc(_token);
		break;
	}
	default:
		break;
	}

	return bRst;
}

bool FormMain::SelectLoadImage(String^ _strImgName)
{
	bool bRst = true;

	if (m_imgProc != nullptr)
	{
		m_imgProc = nullptr;
		delete m_imgProc;
	}

	int nId = SearchImgTypeId(_strImgName);

	switch (nId)
	{
	case ComInfo::ImgProc::Type::EdgeDetection:
	{
		m_imgProc = gcnew EdgeDetection(m_bitmap);
		break;
	}
	case ComInfo::ImgProc::Type::GrayScale:
	{
		m_imgProc = gcnew GrayScale(m_bitmap);
		break;
	}
	case ComInfo::ImgProc::Type::Binarization:
	{
		m_imgProc = gcnew Binarization(m_bitmap);
		break;
	}
	case ComInfo::ImgProc::Type::GrayScale2Diff:
	{
		m_imgProc = gcnew GrayScale2Diff(m_bitmap);
		break;
	}
	case ComInfo::ImgProc::Type::ColorReversal:
	{
		m_imgProc = gcnew ColorReversal(m_bitmap);
		break;
	}
	default:
		break;
	}

	return bRst;
}

Bitmap^ FormMain::GetImage(String^ _strImgName)
{
	Bitmap^ bitmap = nullptr;
	int nId = SearchImgTypeId(_strImgName);

	switch (nId)
	{
	case ComInfo::ImgProc::Type::EdgeDetection:
	{
		EdgeDetection^ edge = (EdgeDetection^)m_imgProc;
		if (edge != nullptr)
		{
			bitmap = edge->GetBitmap();
		}
		break;
	}
	case ComInfo::ImgProc::Type::GrayScale:
	{
		GrayScale^ gray = (GrayScale^)m_imgProc;
		if (gray != nullptr)
		{
			bitmap = gray->GetBitmap();
		}
		break;
	}
	case ComInfo::ImgProc::Type::Binarization:
	{
		Binarization^ binarization = (Binarization^)m_imgProc;
		if (binarization != nullptr)
		{
			bitmap = binarization->GetBitmap();
		}
		break;
	}
	case ComInfo::ImgProc::Type::GrayScale2Diff:
	{
		GrayScale2Diff^ gray2Diff = (GrayScale2Diff^)m_imgProc;
		if (gray2Diff != nullptr)
		{
			bitmap = gray2Diff->GetBitmap();
		}
		break;
	}
	case ComInfo::ImgProc::Type::ColorReversal:
	{
		ColorReversal^ colorReversal = (ColorReversal^)m_imgProc;
		if (colorReversal != nullptr)
		{
			bitmap = colorReversal->GetBitmap();
		}
		break;
	}
	default:
		break;
	}

	return bitmap;
}

Bitmap^ FormMain::SelectGetBitmap(String^ _strImgName)
{
	Bitmap^ bitmap = nullptr;
	int nId = SearchImgTypeId(_strImgName);

	switch (nId)
	{
	case ComInfo::ImgProc::Type::EdgeDetection:
	{
		EdgeDetection^ edge = (EdgeDetection^)m_imgProc;
		bitmap = edge->GetBitmapAfter();
		break;
	}
	case ComInfo::ImgProc::Type::GrayScale:
	{
		GrayScale^ gray = (GrayScale^)m_imgProc;
		bitmap = gray->GetBitmapAfter();
		break;
	}
	case ComInfo::ImgProc::Type::Binarization:
	{
		Binarization^ binarization = (Binarization^)m_imgProc;
		bitmap = binarization->GetBitmapAfter();
		break;
	}
	case ComInfo::ImgProc::Type::GrayScale2Diff:
	{
		GrayScale2Diff^ gray2Diff = (GrayScale2Diff^)m_imgProc;
		bitmap = gray2Diff->GetBitmapAfter();
		break;
	}
	case ComInfo::ImgProc::Type::ColorReversal:
	{
		ColorReversal^ colorReversal = (ColorReversal^)m_imgProc;
		bitmap = colorReversal->GetBitmapAfter();
		break;
	}
	default:
		break;
	}

	return bitmap;
}

void ImageProcessing::FormMain::OnClickMenu(System::Object^ sender, System::EventArgs^ e)
{
	ToolStripMenuItem^ menuItem = (ToolStripMenuItem^)sender;
	String^ strText = menuItem->Text;

	if (strText == (String^)ComConstStringInfo::MENU_FILE_END)
	{
		Close();
	}
	else if (strText == (String^)ComConstStringInfo::MENU_SETTING_IMAGE_PROCESSING)
	{
		ShowSettingImageProcessing();
	}
}

void FormMain::ShowSettingImageProcessing(void)
{
	FormSettingImageProcessing^ win = gcnew FormSettingImageProcessing();
	auto dialogResult = win->ShowDialog();

	if (dialogResult == ::DialogResult::OK)
	{
		m_strCurImgName = (String^)win->GetCmbBoxImageProcessingType()->SelectedItem;
		this->Text = "Image Processing ( " + m_strCurImgName + " )";

		sliderThresh->Enabled = m_strCurImgName == (String^)ComConstStringInfo::IMG_NAME_BINARIZATION ? true : false;

		pictureBoxAfter->Image = nullptr;
		SelectLoadImage(m_strCurImgName);
		if (m_histgram != nullptr && m_histgram->GetIsOpen() == true)
		{
			OnClickBtnShowHistgram(this, nullptr);
		}
	}
	delete win;
}

int ImageProcessing::FormMain::SearchImgTypeId(String^ _strImgName)
{
	int nId = -1;

	System::Collections::Generic::Dictionary<int, String^> items;
	System::Configuration::Configuration^ config = ConfigurationManager::OpenExeConfiguration(ConfigurationUserLevel::None);
	items.Add(Convert::ToInt32(config->AppSettings->Settings["ImgTypeEdgeId"]->Value), (String^)config->AppSettings->Settings["ImgTypeEdgeName"]->Value);
	items.Add(Convert::ToInt32(config->AppSettings->Settings["ImgTypeGrayScaleId"]->Value), (String^)config->AppSettings->Settings["ImgTypeGrayScaleName"]->Value);
	items.Add(Convert::ToInt32(config->AppSettings->Settings["ImgTypeBinarizationId"]->Value), (String^)config->AppSettings->Settings["ImgTypeBinarizationName"]->Value);
	items.Add(Convert::ToInt32(config->AppSettings->Settings["ImgTypeGrayScale2DiffId"]->Value), (String^)config->AppSettings->Settings["ImgTypeGrayScale2DiffName"]->Value);
	items.Add(Convert::ToInt32(config->AppSettings->Settings["ImgTypeColorReversalId"]->Value), (String^)config->AppSettings->Settings["ImgTypeColorReversalName"]->Value);

	for each (unsigned int nKey in items.Keys)
	{
		if (items[nKey] == _strImgName)
		{
			nId = nKey - 1;
		}
	}

	return nId;
}

void FormMain::OnSliderPreviewKeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
{
	if (pictureBoxAfter->Image != nullptr)
	{
		ParamAjust();
	}

	return;
}

void FormMain::OnSliderPreviewMouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	if (pictureBoxAfter->Image != nullptr)
	{
		ParamAjust();
	}

	return;
}

void FormMain::ParamAjust()
{
	pictureBoxAfter->Image = nullptr;

	btnFileSelect->Enabled = false;
	btnAllClear->Enabled = false;
	btnStart->Enabled = false;
	menuMain->Enabled = false;

	LoadImage();

	btnStop->Enabled = true;
	btnSaveImage->Enabled = false;
	btnShowHistgram->Enabled = false;

	TaskWorkParamAjust();

	return;
}

void ImageProcessing::FormMain::OnScrollSliderThresh(System::Object^ sender, System::EventArgs^ e)
{
	auto trackBar = (TrackBar^)sender;
	labelValue->Text = trackBar->Value.ToString();
}

void FormMain::TaskWorkImageProcessing()
{
	Task::Run(gcnew Action(this, &FormMain::ExecTaskImageProcessing));

	return;
}

void FormMain::TaskWorkParamAjust()
{
	Task::Run(gcnew Action(this, &FormMain::ExecTaskParamAjust));

	return;
}

void FormMain::LoadImage(void)
{
	m_bitmap = gcnew Bitmap(m_strOpenFileName);
	SelectLoadImage(m_strCurImgName);

	return;
}
void FormMain::OnFormClosingFormMain(Object^ sender, FormClosingEventArgs^ e)
{
	if (m_tokenSource != nullptr)
	{
		e->Cancel = true;
	}
	return;
}

void FormMain::OnClickBtnFileSelect(Object^ sender, EventArgs^ e)
{
	ComOpenFileDialog^ openFileDlg = gcnew ComOpenFileDialog();
	openFileDlg->SetFilter("JPG|*.jpg|PNG|*.png");
	openFileDlg->SetTitle("Open the file");
	if (openFileDlg->ShowDialog() == true)
	{
		pictureBoxOriginal->Image = nullptr;
		pictureBoxAfter->Image = nullptr;
		m_strOpenFileName = openFileDlg->GetFileName();
		try
		{
			LoadImage();
		}
		catch (Exception^)
		{
			MessageBox::Show(this, "Open File Error", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		pictureBoxOriginal->ImageLocation = m_strOpenFileName;
		btnStart->Enabled = true;
		textBoxTime->Text = "";

		if (m_histgram == nullptr)
		{
			m_histgram = gcnew FormHistgram();
		}
		else
		{
			m_histgram->Close();
			m_histgram = nullptr;
			m_histgram = gcnew FormHistgram();
		}

		Bitmap^ bitmap = gcnew Bitmap(m_strOpenFileName);
		m_histgram->SetBitmapOrg((Bitmap^)bitmap->Clone());
		if (SelectGetBitmap(m_strCurImgName) != nullptr)
		{
			m_histgram->SetBitmapAfter((Bitmap^)SelectGetBitmap(m_strCurImgName)->Clone());
		}
		m_histgram->DrawHistgram();
		m_histgram->SetIsOpen(true);
		m_histgram->Show();
		delete bitmap;
	}
	delete openFileDlg;
	return;
}

void FormMain::OnClickBtnAllClear(Object^ sender, EventArgs^ e)
{
	pictureBoxOriginal->ImageLocation = nullptr;
	pictureBoxAfter->Image = nullptr;

	m_bitmap = nullptr;
	m_strOpenFileName = "";

	textBoxTime->Text = "";

	btnFileSelect->Enabled = true;
	btnAllClear->Enabled = true;
	btnStart->Enabled = false;
	btnSaveImage->Enabled = false;

	if (m_histgram != nullptr)
	{
		m_histgram->Close();
	}

	return;
}

void FormMain::OnClickBtnStart(Object^ sender, EventArgs^ e)
{
	pictureBoxAfter->Image = nullptr;

	btnFileSelect->Enabled = false;
	btnAllClear->Enabled = false;
	btnStart->Enabled = false;
	menuMain->Enabled = false;

	textBoxTime->Text = "";

	pictureBoxStatus->Visible = true;

	LoadImage();

	btnStop->Enabled = true;
	btnSaveImage->Enabled = false;
	btnShowHistgram->Enabled = false;

	TaskWorkImageProcessing();

	return;
}

void FormMain::OnClickBtnStop(Object^ sender, EventArgs^ e)
{
	if (m_tokenSource != nullptr)
	{
		m_tokenSource->Cancel();
	}

	return;
}

void FormMain::OnClickBtnSaveImage(Object^ sender, EventArgs^ e)
{
	ComSaveFileDialog^ saveDialog = gcnew ComSaveFileDialog();
	saveDialog->SetFilter("PNG|*.png");
	saveDialog->SetTitle("Save the file");
	if (saveDialog->ShowDialog() == true)
	{
		String^ strFileName = saveDialog->GetFileName();
		auto bitmap = GetImage(m_strCurImgName);
		if (bitmap != nullptr)
		{
			bitmap->Save(strFileName, System::Drawing::Imaging::ImageFormat::Png);
		}
		delete bitmap;
	}
	delete saveDialog;

	return;
}

void FormMain::OnClickBtnShowHistgram(Object^ sender, EventArgs^ e)
{
	if (m_bitmap == nullptr)
	{
		return;
	}

	if (m_histgram != nullptr)
	{
		m_histgram->Close();
		m_histgram = nullptr;
		delete m_histgram;
		m_histgram = gcnew FormHistgram();
	}

	Bitmap^ bitmap = gcnew Bitmap(m_strOpenFileName);
	m_histgram->SetBitmapOrg((Bitmap^)bitmap->Clone());
	if (SelectGetBitmap(m_strCurImgName) != nullptr)
	{
		m_histgram->SetBitmapAfter((Bitmap^)SelectGetBitmap(m_strCurImgName)->Clone());
	}

	m_histgram->DrawHistgram();
	m_histgram->SetIsOpen(true);
	m_histgram->Show();

	delete bitmap;

	return;
}