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
	btnShowHistgram->Enabled = true;
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

void FormMain::ExecTask()
{
	Stopwatch^ stopwatch = gcnew Stopwatch();
	stopwatch->Start();

	m_tokenSource = gcnew CancellationTokenSource();
	CancellationToken^ token = m_tokenSource->Token;

	ComImgInfo^ imgInfo = gcnew ComImgInfo();
	ComBinarizationInfo^ binarizationInfo = gcnew ComBinarizationInfo();
	Byte nThresh = 125;
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
	}
	Invoke(gcnew Action(this, &FormMain::SetPictureBoxStatus));
	Invoke(gcnew Action(this, &FormMain::SetButtonEnable));
	menuMain->Enabled = true;

	delete stopwatch;
	m_tokenSource = nullptr;

	return;
}

bool FormMain::SelectGoImgProc(ComImgInfo^ _comImgInfo, CancellationToken^ _token)
{
	bool bRst = true;

	String^ strCurName = _comImgInfo->GetCurImgName();
	if (strCurName == (String^)ComConstStringInfo::IMG_NAME_EDGE_DETECTION)
	{
		EdgeDetection^ edge = (EdgeDetection^)m_imgProc;
		bRst = edge->GoImgProc(_token);
	}
	else if (strCurName == (String^)ComConstStringInfo::IMG_NAME_GRAY_SCALE)
	{
		GrayScale^ gray = (GrayScale^)m_imgProc;
		bRst = gray->GoImgProc(_token);
	}
	else if (strCurName == (String^)ComConstStringInfo::IMG_NAME_BINARIZATION)
	{
		Binarization^ binarization = (Binarization^)m_imgProc;
		binarization->SetThresh(120);
		bRst = binarization->GoImgProc(_token);
	}
	else if (strCurName == (String^)ComConstStringInfo::IMG_NAME_GRAY_SCALE_2DIFF)
	{
		GrayScale2Diff^ gray2Diff = (GrayScale2Diff^)m_imgProc;
		bRst = gray2Diff->GoImgProc(_token);
	}
	else if (strCurName == (String^)ComConstStringInfo::IMG_NAME_COLOR_REVERSAL)
	{
		ColorReversal^ colorReversal = (ColorReversal^)m_imgProc;
		bRst = colorReversal->GoImgProc(_token);
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

	if (_strImgName == (String^)ComConstStringInfo::IMG_NAME_EDGE_DETECTION)
	{
		m_imgProc = gcnew EdgeDetection(m_bitmap);
	}
	else if (_strImgName == (String^)ComConstStringInfo::IMG_NAME_GRAY_SCALE)
	{
		m_imgProc = gcnew GrayScale(m_bitmap);
	}
	else if (_strImgName == (String^)ComConstStringInfo::IMG_NAME_BINARIZATION)
	{
		m_imgProc = gcnew Binarization(m_bitmap);
	}
	else if (_strImgName == (String^)ComConstStringInfo::IMG_NAME_GRAY_SCALE_2DIFF)
	{
		m_imgProc = gcnew GrayScale2Diff(m_bitmap);
	}
	else if (_strImgName == (String^)ComConstStringInfo::IMG_NAME_COLOR_REVERSAL)
	{
		m_imgProc = gcnew ColorReversal(m_bitmap);
	}

	return bRst;
}

Bitmap^ FormMain::GetImage(String^ _strImgName)
{
	Bitmap^ bitmap = nullptr;

	if (_strImgName == (String^)ComConstStringInfo::IMG_NAME_EDGE_DETECTION)
	{
		EdgeDetection^ edge = (EdgeDetection^)m_imgProc;
		if (edge != nullptr)
		{
			bitmap = edge->GetBitmap();
		}
	}
	else if (_strImgName == (String^)ComConstStringInfo::IMG_NAME_GRAY_SCALE)
	{
		GrayScale^ gray = (GrayScale^)m_imgProc;
		if (gray != nullptr)
		{
			bitmap = gray->GetBitmap();
		}
	}
	else if (_strImgName == (String^)ComConstStringInfo::IMG_NAME_BINARIZATION)
	{
		Binarization^ binarization = (Binarization^)m_imgProc;
		if (binarization != nullptr)
		{
			bitmap = binarization->GetBitmap();
		}
	}
	else if (_strImgName == (String^)ComConstStringInfo::IMG_NAME_GRAY_SCALE_2DIFF)
	{
		GrayScale2Diff^ gray2Diff = (GrayScale2Diff^)m_imgProc;
		if (gray2Diff != nullptr)
		{
			bitmap = gray2Diff->GetBitmap();
		}
	}
	else if (_strImgName == (String^)ComConstStringInfo::IMG_NAME_COLOR_REVERSAL)
	{
		ColorReversal^ colorReversal = (ColorReversal^)m_imgProc;
		if (colorReversal != nullptr)
		{
			bitmap = colorReversal->GetBitmap();
		}
	}

	return bitmap;
}

Bitmap^ FormMain::SelectGetBitmap(String^ _strImgName)
{
	Bitmap^ bitmap = nullptr;

	if (_strImgName == (String^)ComConstStringInfo::IMG_NAME_EDGE_DETECTION)
	{
		EdgeDetection^ edge = (EdgeDetection^)m_imgProc;
		bitmap = edge->GetBitmapAfter();
	}
	else if (_strImgName == (String^)ComConstStringInfo::IMG_NAME_GRAY_SCALE)
	{
		GrayScale^ gray = (GrayScale^)m_imgProc;
		bitmap = gray->GetBitmapAfter();
	}
	else if (_strImgName == (String^)ComConstStringInfo::IMG_NAME_BINARIZATION)
	{
		Binarization^ binarization = (Binarization^)m_imgProc;
		bitmap = binarization->GetBitmapAfter();
	}
	else if (_strImgName == (String^)ComConstStringInfo::IMG_NAME_GRAY_SCALE_2DIFF)
	{
		GrayScale2Diff^ gray2Diff = (GrayScale2Diff^)m_imgProc;
		bitmap = gray2Diff->GetBitmapAfter();
	}
	else if (_strImgName == (String^)ComConstStringInfo::IMG_NAME_COLOR_REVERSAL)
	{
		ColorReversal^ colorReversal = (ColorReversal^)m_imgProc;
		bitmap = colorReversal->GetBitmapAfter();
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

		//sliderThresh.Enabled = m_strCurImgName == ComConstStringInfo::IMG_NAME_BINARIZATION ? true : false;

		pictureBoxAfter->Image = nullptr;
		SelectLoadImage(m_strCurImgName);
		if (m_histgram != nullptr && m_histgram->GetIsOpen() == true)
		{
			OnClickBtnShowHistgram(this, nullptr);
		}
	}
}

void FormMain::TaskWorkImageProcessing()
{
	Task::Run(gcnew Action(this, &FormMain::ExecTask));

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

	return;
}

void FormMain::OnClickBtnStart(Object^ sender, EventArgs^ e)
{
	pictureBoxAfter->Image = nullptr;

	btnFileSelect->Enabled = false;
	btnAllClear->Enabled = false;
	btnStart->Enabled = false;

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
	//m_histgram->SetBitmapAfter((Bitmap^)m_bitmap->Clone());
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