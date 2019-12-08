#include "FormMain.h"

using namespace ImageProcessing;

/// <summary>
/// �Ώۂ̉摜�����I�u�W�F�N�g�ɃC���[�W�����[�h����
/// </summary>
/// <param name="_strImgName">�摜�����I�u�W�F�N�g�̖���</param>
void FormMain::SelectLoadImage(String^ _strImgName)
{
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

	return;
}

/// <summary>
/// �Ώۂ̉摜�����I�u�W�F�N�g����WriteableBitmap���擾����
/// </summary>
/// <param name="_strImgName">�摜�����I�u�W�F�N�g�̖���</param>
/// <returns>Writeable�ȃr�b�g�}�b�v</returns>
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

/// <summary>
/// �Ώۂ̉摜�����I�u�W�F�N�g�����s����
/// </summary>
/// <param name="_comImgInfo">�摜�����̐ݒ�</param>
/// <param name="_token">�L�����Z���g�[�N��</param>
/// <returns>�摜�����̎��s���� ����/���s</returns>
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
		BinarizationInfo^ binarizationInfo = _comImgInfo->GetBinarizationInfo();
		binarization->SetThresh((Byte)binarizationInfo->GetThresh());
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

/// <summary>
/// �c�[���`�b�v�̐ݒ�
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
/// �{�^����Enable�𐧌䂷��
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
/// ���Ԃ�\������e�L�X�g�{�b�N�X�Ɏ��Ԃ�ݒ肷��
/// </summary>
void FormMain::SetTextTime(long long _lTime)
{
	textBoxTime->Text = _lTime.ToString();

	return;
}

/// <summary>
/// �R���g���[����Enable�𐧌䂷��
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
/// �摜�������s�p�̃^�X�N
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
	bool bRst = SelectGoImgProc(imgInfo, token);
	if (bRst)
	{
		pictureBoxOriginal->ImageLocation = m_strOpenFileName;
		pictureBoxAfter->Image = SelectGetBitmap(m_strCurImgName);

		stopwatch->Stop();

		auto setDelegateTextTime = gcnew ComDelegate::DelegateSetLongLong(this, &FormMain::SetTextTime);
		this->Invoke(setDelegateTextTime, stopwatch->ElapsedMilliseconds);
		delete setDelegateTextTime;

		Bitmap^ bitmap = gcnew Bitmap(m_strOpenFileName);
		m_histgram->SetBitmapOrg((Bitmap^)bitmap->Clone());
		if (SelectGetBitmap(m_strCurImgName) != nullptr)
		{
			System::Threading::Thread::Sleep(50);
			m_histgram->SetBitmapAfter((Bitmap^)SelectGetBitmap(m_strCurImgName)->Clone());
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
/// �摜�����̃^�X�N���s
/// </summary>
void FormMain::TaskWorkImageProcessing()
{
	auto actionTask = gcnew Action(this, &FormMain::ExecTaskImageProcessing);
	Task::Run(actionTask);
	delete actionTask;

	return;
}

/// <summary>
/// �C���[�W�̃��[�h����
/// </summary>
void FormMain::LoadImage(void)
{
	m_bitmap = gcnew Bitmap(m_strOpenFileName);
	SelectLoadImage(m_strCurImgName);

	return;
}

/// <summary>
/// Form�̃N���[�Y�C�x���g
/// </summary>
/// <param name="sender">�I�u�W�F�N�g</param>
/// <param name="e">FormClosing�C�x���g�̃f�[�^</param>
void FormMain::OnFormClosingFormMain(Object^ sender, FormClosingEventArgs^ e)
{
	if (m_tokenSource != nullptr)
	{
		e->Cancel = true;
	}
	return;
}

/// <summary>
/// �t�@�C���I���{�^���̃N���b�N�C�x���g
/// </summary>
/// <param name="sender">�I�u�W�F�N�g</param>
/// <param name="e">�C�x���g�̃f�[�^</param>
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

/// <summary>
/// �I�[���N���A�{�^���̃N���b�N�C�x���g
/// </summary>
/// <param name="sender">�I�u�W�F�N�g</param>
/// <param name="e">�C�x���g�̃f�[�^</param>
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
/// �X�^�[�g�{�^���̃N���b�N�C�x���g
/// </summary>
/// <param name="sender">�I�u�W�F�N�g</param>
/// <param name="e">�C�x���g�̃f�[�^</param>
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
/// �X�g�b�v�{�^���̃N���b�N�C�x���g
/// </summary>
/// <param name="sender">�I�u�W�F�N�g</param>
/// <param name="e">�C�x���g�̃f�[�^</param>
void FormMain::OnClickBtnStop(Object^ sender, EventArgs^ e)
{
	if (m_tokenSource != nullptr)
	{
		m_tokenSource->Cancel();
	}

	return;
}

/// <summary>
/// �摜�����̃I�u�W�F�N�g����C���[�W�̎擾
/// </summary>
/// <param name="_strImgName">�摜�����̖���</param>
/// <returns>�r�b�g�}�b�v</returns>
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
			bitmap = edge->GetBitmapAfter();
		}
		break;
	}
	case ComInfo::ImgProc::Type::GrayScale:
	{
		GrayScale^ gray = (GrayScale^)m_imgProc;
		if (gray != nullptr)
		{
			bitmap = gray->GetBitmapAfter();
		}
		break;
	}
	case ComInfo::ImgProc::Type::Binarization:
	{
		Binarization^ binarization = (Binarization^)m_imgProc;
		if (binarization != nullptr)
		{
			bitmap = binarization->GetBitmapAfter();
		}
		break;
	}
	case ComInfo::ImgProc::Type::GrayScale2Diff:
	{
		GrayScale2Diff^ gray2Diff = (GrayScale2Diff^)m_imgProc;
		if (gray2Diff != nullptr)
		{
			bitmap = gray2Diff->GetBitmapAfter();
		}
		break;
	}
	case ComInfo::ImgProc::Type::ColorReversal:
	{
		ColorReversal^ colorReversal = (ColorReversal^)m_imgProc;
		if (colorReversal != nullptr)
		{
			bitmap = colorReversal->GetBitmapAfter();
		}
		break;
	}
	default:
		break;
	}

	return bitmap == nullptr ? bitmap : (Bitmap^)bitmap->Clone();
}

/// <summary>
/// �C���[�W�̕ۑ��{�^���̃N���b�N�C�x���g
/// </summary>
/// <param name="sender">�I�u�W�F�N�g</param>
/// <param name="e">�C�x���g�̃f�[�^</param>
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
/// �q�X�g�O�����\���{�^���̃N���b�N�C�x���g
/// </summary>
/// <param name="sender">�I�u�W�F�N�g</param>
/// <param name="e">�C�x���g�̃f�[�^</param>
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

/// <summary>
/// ���j���[�̃N���b�N�C�x���g
/// </summary>
/// <param name="sender">�I�u�W�F�N�g</param>
/// <param name="e">�C�x���g�̃f�[�^</param>
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
/// �ݒ��ʂ̏���
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
		SelectLoadImage(m_strCurImgName);
		if (m_histgram != nullptr && m_histgram->GetIsOpen() == true)
		{
			OnClickBtnShowHistgram(this, nullptr);
		}
	}
	delete win;
}

/// <summary>
/// 2�l����臒l�̃X���C�_�̃X�N���[���C�x���g
/// </summary>
/// <param name="sender">�I�u�W�F�N�g</param>
/// <param name="e">�C�x���g�̃f�[�^</param>
void FormMain::OnScrollSliderThresh(System::Object^ sender, System::EventArgs^ e)
{
	auto trackBar = (TrackBar^)sender;
	labelValue->Text = trackBar->Value.ToString();
}

/// <summary>
/// 2�l����臒l�̃X���C�_�̃L�[�A�b�v�C�x���g
/// </summary>
/// <param name="sender">�I�u�W�F�N�g</param>
/// <param name="e">�L�[�C�x���g�̃f�[�^</param>
void FormMain::OnSliderPreviewKeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
{
	if (pictureBoxAfter->Image != nullptr)
	{
		ParamAjust();
	}

	return;
}

/// <summary>
/// 2�l����臒l�̃X���C�_�̃}�E�X�A�b�v�C�x���g
/// </summary>
/// <param name="sender">�I�u�W�F�N�g</param>
/// <param name="e">�}�E�X�{�^���C�x���g�̃f�[�^</param>
void FormMain::OnSliderMouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	if (pictureBoxAfter->Image != nullptr)
	{
		ParamAjust();
	}

	return;
}

/// <summary>
/// 2�l���̃X���C�_�𒲐������Ƃ��̏���
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
/// 2�l���̃X���C�_�𒲐������Ƃ��̏���
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
/// 2�l���̃X���C�_�𒲐������Ƃ��̏���
/// </summary>
/// <param name="_strImgName">�摜�����̖���</param>
/// <returns>�摜������ID</returns>
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