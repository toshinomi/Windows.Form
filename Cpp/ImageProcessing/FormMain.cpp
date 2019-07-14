#include "FormMain.h"
#include "ComOpenFileDialog.h"
#include "ComSaveFileDialog.h"
#include "FormSettingImageProcessing.h"

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
	CancellationToken token = m_tokenSource->Token;
	bool bRst = m_edgeDetection->GoEdgeDetection(token);
	if (bRst)
	{
		pictureBoxOriginal->ImageLocation = m_strOpenFileName;
		pictureBoxAfter->Image = m_edgeDetection->GetBitmap();

		stopwatch->Stop();

		Invoke(gcnew Action<long long>(this, &FormMain::SetTextTime), stopwatch->ElapsedMilliseconds);
	}
	Invoke(gcnew Action(this, &FormMain::SetPictureBoxStatus));
	Invoke(gcnew Action(this, &FormMain::SetButtonEnable));

	delete stopwatch;
	m_tokenSource = nullptr;
	m_bitmap = nullptr;

	return;
}

void FormMain::TaskWorkImageProcessing()
{
	Task::Run(gcnew Action(this, &FormMain::ExecTask));

	return;
}

void FormMain::LoadImage(void)
{
	m_bitmap = gcnew Bitmap(m_strOpenFileName);
	m_edgeDetection = gcnew EdgeDetection(m_bitmap);

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
		auto bitmap = gcnew Bitmap(m_edgeDetection->GetBitmap());
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
	return;
}
