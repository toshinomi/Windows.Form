#include "FormMain.h"

using namespace ImageProcessing;

/// <summary>
/// ビットマップを取得する
/// </summary>
/// <returns>ビットマップ</returns>
Bitmap^ FormMain::GetBitmap()
{
	Bitmap^ bitmap = m_imageProcessing->GetBitmap();

	return bitmap;
}

/// <summary>
/// 対象の画像処理オブジェクトを実行する
/// </summary>
/// <param name="_comImgInfo">画像処理の設定</param>
/// <param name="_token">キャンセルトークン</param>
/// <returns>画像処理の実行結果 成功/失敗</returns>
bool FormMain::GoImageProcessing(ComImgInfo^ _comImgInfo, CancellationToken^ _token)
{
	m_imageProcessing->SetThresh(_comImgInfo->GetBinarizationInfo()->GetThresh());
	bool bRst = m_imageProcessing->GoImageProcessing(m_strCurImgName, _token);

	return bRst;
}

/// <summary>
/// ツールチップの設定
/// </summary>
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

/// <summary>
/// ボタンのEnableを制御する
/// </summary>
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

/// <summary>
/// 時間を表示するテキストボックスに時間を設定する
/// </summary>
/// <param name="_lTime">時間</param>
void FormMain::SetTextTime(long long _lTime)
{
	textBoxTime->Text = _lTime.ToString();

	return;
}

/// <summary>
/// コントロールのEnableを制御する
/// </summary>
void FormMain::SetControlEnable(void)
{
	btnFileSelect->Enabled = true;
	btnAllClear->Enabled = true;
	btnStart->Enabled = true;
	btnStop->Enabled = false;
	btnSaveImage->Enabled = true;
	btnShowHistgram->Enabled = true;
	menuMain->Enabled = true;
}

/// <summary>
/// 画像処理実行用のタスク
/// </summary>
void FormMain::ExecTaskImageProcessing()
{
	Stopwatch^ stopwatch = gcnew Stopwatch();
	stopwatch->Start();

	m_tokenSource = gcnew CancellationTokenSource();
	CancellationToken^ token = m_tokenSource->Token;

	ComImgInfo^ imgInfo = gcnew ComImgInfo();
	BinarizationInfo^ binarizationInfo = gcnew BinarizationInfo();
	auto getDelegateSliderThresh = gcnew ComDelegate::DelegateGetByte(this, &FormMain::GetSliderThresh);
	Byte nThresh = (Byte)this->Invoke(getDelegateSliderThresh);
	binarizationInfo->SetThresh(nThresh);
	imgInfo->SetCurImgName(m_strCurImgName);
	imgInfo->SetBinarizationInfo(binarizationInfo);
	bool bRst = GoImageProcessing(imgInfo, token);
	if (bRst)
	{
		pictureBoxOriginal->ImageLocation = m_strOpenFileName;
		pictureBoxAfter->Image = GetBitmap();

		stopwatch->Stop();

		auto setDelegateTextTime = gcnew ComDelegate::DelegateSetLongLong(this, &FormMain::SetTextTime);
		this->Invoke(setDelegateTextTime, stopwatch->ElapsedMilliseconds);
		delete setDelegateTextTime;

		Bitmap^ bitmap = gcnew Bitmap(m_strOpenFileName);
		m_histgram->SetBitmapOrg((Bitmap^)bitmap->Clone());
		if (GetBitmap() != nullptr)
		{
			System::Threading::Thread::Sleep(50);
			m_histgram->SetBitmapAfter((Bitmap^)GetBitmap()->Clone());
		}
		if (m_histgram->GetIsOpen() == true)
		{
			auto actionDrawHistgram = gcnew Action(m_histgram, &FormHistgram::DrawHistgram);
			this->Invoke(actionDrawHistgram);
			delete actionDrawHistgram;
		}
		delete bitmap;
	}
	auto setDelegatePictureBoxStatusVisible = gcnew ComDelegate::DelegateSetBool(this, &FormMain::SetPictureBoxStatusVisible);
	this->Invoke(setDelegatePictureBoxStatusVisible, false);
	auto setDelegateControlEnable = gcnew ComDelegate::DelegateSetControlEnable(this, &FormMain::SetControlEnable);
	this->Invoke(setDelegateControlEnable);
	delete setDelegatePictureBoxStatusVisible;
	delete setDelegateControlEnable;

	delete stopwatch;
	delete m_tokenSource;
	delete imgInfo;
	delete binarizationInfo;
	m_tokenSource = nullptr;

	return;
}

/// <summary>
/// 画像処理のタスク実行
/// </summary>
void FormMain::TaskWorkImageProcessing()
{
	auto actionTask = gcnew Action(this, &FormMain::ExecTaskImageProcessing);
	Task::Run(actionTask);
	delete actionTask;

	return;
}

/// <summary>
/// イメージのロード処理
/// </summary>
void FormMain::LoadImage(void)
{
	m_bitmap = gcnew Bitmap(m_strOpenFileName);
	m_imageProcessing = gcnew ImageProcessing(m_bitmap);

	return;
}

/// <summary>
/// Formのクローズイベント
/// </summary>
/// <param name="sender">オブジェクト</param>
/// <param name="e">FormClosingイベントのデータ</param>
void FormMain::OnFormClosingFormMain(Object^ sender, FormClosingEventArgs^ e)
{
	if (m_tokenSource != nullptr)
	{
		e->Cancel = true;
	}
	return;
}

/// <summary>
/// ファイル選択ボタンのクリックイベント
/// </summary>
/// <param name="sender">オブジェクト</param>
/// <param name="e">イベントのデータ</param>
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
		if (GetBitmap() != nullptr)
		{
			m_histgram->SetBitmapAfter((Bitmap^)GetBitmap()->Clone());
		}
		m_histgram->DrawHistgram();
		m_histgram->SetIsOpen(true);
		m_histgram->Show();
		delete bitmap;
	}
	delete openFileDlg;
	return;
}

/// <summary>
/// オールクリアボタンのクリックイベント
/// </summary>
/// <param name="sender">オブジェクト</param>
/// <param name="e">イベントのデータ</param>
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

/// <summary>
/// スタートボタンのクリックイベント
/// </summary>
/// <param name="sender">オブジェクト</param>
/// <param name="e">イベントのデータ</param>
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

/// <summary>
/// ストップボタンのクリックイベント
/// </summary>
/// <param name="sender">オブジェクト</param>
/// <param name="e">イベントのデータ</param>
void FormMain::OnClickBtnStop(Object^ sender, EventArgs^ e)
{
	if (m_tokenSource != nullptr)
	{
		m_tokenSource->Cancel();
	}

	return;
}

/// <summary>
/// 画像処理のオブジェクトからイメージの取得
/// </summary>
/// <param name="_strImgName">画像処理の名称</param>
/// <returns>ビットマップ</returns>
Bitmap^ FormMain::GetImage()
{
	Bitmap^ bitmap = m_imageProcessing->GetBitmap();

	return bitmap == nullptr ? bitmap : (Bitmap^)bitmap->Clone();
}

/// <summary>
/// イメージの保存ボタンのクリックイベント
/// </summary>
/// <param name="sender">オブジェクト</param>
/// <param name="e">イベントのデータ</param>
void FormMain::OnClickBtnSaveImage(Object^ sender, EventArgs^ e)
{
	ComSaveFileDialog^ saveDialog = gcnew ComSaveFileDialog();
	saveDialog->SetFilter("PNG|*.png");
	saveDialog->SetTitle("Save the file");
	if (saveDialog->ShowDialog() == true)
	{
		String^ strFileName = saveDialog->GetFileName();
		auto bitmap = GetImage();
		if (bitmap != nullptr)
		{
			try
			{
				bitmap->Save(strFileName, System::Drawing::Imaging::ImageFormat::Png);
			}
			catch (Exception^)
			{
				MessageBox::Show(this, "Save Image File Error", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
		delete bitmap;
	}
	delete saveDialog;

	return;
}

/// <summary>
/// ヒストグラム表示ボタンのクリックイベント
/// </summary>
/// <param name="sender">オブジェクト</param>
/// <param name="e">イベントのデータ</param>
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
	if (GetBitmap() != nullptr)
	{
		m_histgram->SetBitmapAfter((Bitmap^)GetBitmap()->Clone());
	}

	m_histgram->DrawHistgram();
	m_histgram->SetIsOpen(true);
	m_histgram->Show();

	delete bitmap;

	return;
}

/// <summary>
/// メニューのクリックイベント
/// </summary>
/// <param name="sender">オブジェクト</param>
/// <param name="e">イベントのデータ</param>
void FormMain::OnClickMenu(System::Object^ sender, System::EventArgs^ e)
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

/// <summary>
/// 設定画面の処理
/// </summary>
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
		btnSaveImage->Enabled = false;
		m_bitmap = gcnew Bitmap(m_strOpenFileName);
		m_imageProcessing = gcnew ImageProcessing(m_bitmap);
		if (m_histgram != nullptr && m_histgram->GetIsOpen() == true)
		{
			OnClickBtnShowHistgram(this, nullptr);
		}
	}
	delete win;
}

/// <summary>
/// 2値化の閾値のスライダのスクロールイベント
/// </summary>
/// <param name="sender">オブジェクト</param>
/// <param name="e">イベントのデータ</param>
void FormMain::OnScrollSliderThresh(System::Object^ sender, System::EventArgs^ e)
{
	auto trackBar = (TrackBar^)sender;
	labelValue->Text = trackBar->Value.ToString();
}

/// <summary>
/// 2値化の閾値のスライダのキーアップイベント
/// </summary>
/// <param name="sender">オブジェクト</param>
/// <param name="e">キーイベントのデータ</param>
void FormMain::OnSliderPreviewKeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
{
	if (pictureBoxAfter->Image != nullptr)
	{
		ParamAjust();
	}

	return;
}

/// <summary>
/// 2値化の閾値のスライダのマウスアップイベント
/// </summary>
/// <param name="sender">オブジェクト</param>
/// <param name="e">マウスボタンイベントのデータ</param>
void FormMain::OnSliderMouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	if (pictureBoxAfter->Image != nullptr)
	{
		ParamAjust();
	}

	return;
}

/// <summary>
/// 2値化のスライダを調整したときの処理
/// </summary>
void FormMain::ExecParamAjust()
{
	m_tokenSource = gcnew CancellationTokenSource();
	CancellationToken^ token = m_tokenSource->Token;

	ComImgInfo^ imgInfo = gcnew ComImgInfo();
	BinarizationInfo^ binarizationInfo = gcnew BinarizationInfo();
	Byte nThresh = (Byte)sliderThresh->Value;
	binarizationInfo->SetThresh(nThresh);
	imgInfo->SetCurImgName(m_strCurImgName);
	imgInfo->SetBinarizationInfo(binarizationInfo);
	bool bRst = GoImageProcessing(imgInfo, token);
	if (bRst)
	{
		pictureBoxOriginal->ImageLocation = m_strOpenFileName;
		pictureBoxAfter->Image = GetBitmap();

		Bitmap^ bitmap = gcnew Bitmap(m_strOpenFileName);
		m_histgram->SetBitmapOrg((Bitmap^)bitmap->Clone());
		if (GetBitmap() != nullptr)
		{
			System::Threading::Thread::Sleep(50);
			m_histgram->SetBitmapAfter((Bitmap^)GetBitmap()->Clone());
		}
		if (m_histgram->GetIsOpen() == true)
		{
			m_histgram->DrawHistgram();
		}
		delete bitmap;
	}
	SetPictureBoxStatusVisible(false);
	SetControlEnable();
	SetSliderThreshEnable(true);

	delete m_tokenSource;
	delete imgInfo;
	delete binarizationInfo;
	m_tokenSource = nullptr;

	return;
}

/// <summary>
/// 2値化のスライダを調整したときの処理
/// </summary>
void FormMain::ParamAjust()
{
	sliderThresh->Enabled = false;

	pictureBoxAfter->Image = nullptr;

	btnFileSelect->Enabled = false;
	btnAllClear->Enabled = false;
	btnStart->Enabled = false;
	menuMain->Enabled = false;

	LoadImage();

	btnStop->Enabled = true;
	btnSaveImage->Enabled = false;
	btnShowHistgram->Enabled = false;

	ExecParamAjust();

	return;
}

/// <summary>
/// 2値化のスライダを調整したときの処理
/// </summary>
/// <param name="_strImgName">画像処理の名称</param>
/// <returns>画像処理のID</returns>
int FormMain::SearchImgTypeId(String^ _strImgName)
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