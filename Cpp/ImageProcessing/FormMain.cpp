#include "FormMain.h"

using namespace ImageProcessing;

/// <summary>
/// �r�b�g�}�b�v���擾����
/// </summary>
/// <returns>�r�b�g�}�b�v</returns>
Bitmap^ FormMain::GetBitmap()
{
	Bitmap^ bitmap = mImageProcessing->GetBitmap();

	return bitmap;
}

/// <summary>
/// �Ώۂ̉摜�����I�u�W�F�N�g�����s����
/// </summary>
/// <param name="comImageProcessingInfo">�摜�����̐ݒ�</param>
/// <param name="token">�L�����Z���g�[�N��</param>
/// <returns>�摜�����̎��s���� ����/���s</returns>
bool FormMain::GoImageProcessing(ComImgInfo^ comImageProcessingInfo, CancellationToken^ token)
{
	mImageProcessing->SetThresh(comImageProcessingInfo->GetBinarizationInfo()->GetThresh());
	bool bRst = mImageProcessing->GoImageProcessing(mCurrentImageProcessingName, token);

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
/// <param name="_lTime">����</param>
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

	mTokenSource = gcnew CancellationTokenSource();
	CancellationToken^ token = mTokenSource->Token;

	ComImgInfo^ imgInfo = gcnew ComImgInfo();
	BinarizationInfo^ binarizationInfo = gcnew BinarizationInfo();
	auto getDelegateSliderThresh = gcnew ComDelegate::DelegateGetByte(this, &FormMain::GetSliderThresh);
	Byte nThresh = (Byte)this->Invoke(getDelegateSliderThresh);
	binarizationInfo->SetThresh(nThresh);
	imgInfo->SetCurrentImageProcessingName(mCurrentImageProcessingName);
	imgInfo->SetBinarizationInfo(binarizationInfo);
	bool bRst = GoImageProcessing(imgInfo, token);
	if (bRst)
	{
		pictureBoxOriginal->ImageLocation = mOpenFileName;
		pictureBoxAfter->Image = GetBitmap();

		stopwatch->Stop();

		auto setDelegateTextTime = gcnew ComDelegate::DelegateSetLongLong(this, &FormMain::SetTextTime);
		this->Invoke(setDelegateTextTime, stopwatch->ElapsedMilliseconds);
		delete setDelegateTextTime;

		Bitmap^ bitmap = gcnew Bitmap(mOpenFileName);
		mHistgram->SetBitmapOrg((Bitmap^)bitmap->Clone());
		if (GetBitmap() != nullptr)
		{
			System::Threading::Thread::Sleep(50);
			mHistgram->SetBitmapAfter((Bitmap^)GetBitmap()->Clone());
		}
		if (mHistgram->GetIsOpen() == true)
		{
			auto actionDrawHistgram = gcnew Action(mHistgram, &FormHistgram::DrawHistgram);
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
	delete mTokenSource;
	delete imgInfo;
	delete binarizationInfo;
	mTokenSource = nullptr;

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
	mBitmap = gcnew Bitmap(mOpenFileName);
	mImageProcessing = gcnew ImageProcessing(mBitmap);

	return;
}

/// <summary>
/// Form�̃N���[�Y�C�x���g
/// </summary>
/// <param name="sender">�I�u�W�F�N�g</param>
/// <param name="e">FormClosing�C�x���g�̃f�[�^</param>
void FormMain::OnFormClosingFormMain(Object^ sender, FormClosingEventArgs^ e)
{
	if (mTokenSource != nullptr)
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
		mOpenFileName = openFileDlg->GetFileName();
		try
		{
			LoadImage();
		}
		catch (Exception^)
		{
			MessageBox::Show(this, "Open File Error", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		pictureBoxOriginal->ImageLocation = mOpenFileName;
		btnStart->Enabled = true;
		textBoxTime->Text = "";

		if (mHistgram == nullptr)
		{
			mHistgram = gcnew FormHistgram();
		}
		else
		{
			mHistgram->Close();
			mHistgram = nullptr;
			mHistgram = gcnew FormHistgram();
		}

		Bitmap^ bitmap = gcnew Bitmap(mOpenFileName);
		mHistgram->SetBitmapOrg((Bitmap^)bitmap->Clone());
		if (GetBitmap() != nullptr)
		{
			mHistgram->SetBitmapAfter((Bitmap^)GetBitmap()->Clone());
		}
		mHistgram->DrawHistgram();
		mHistgram->SetIsOpen(true);
		mHistgram->Show();
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

	mBitmap = nullptr;
	mOpenFileName = "";

	textBoxTime->Text = "";

	btnFileSelect->Enabled = true;
	btnAllClear->Enabled = true;
	btnStart->Enabled = false;
	btnSaveImage->Enabled = false;

	if (mHistgram != nullptr)
	{
		mHistgram->Close();
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
	if (mTokenSource != nullptr)
	{
		mTokenSource->Cancel();
	}

	return;
}

/// <summary>
/// �摜�����̃I�u�W�F�N�g����C���[�W�̎擾
/// </summary>
/// <param name="_strImgName">�摜�����̖���</param>
/// <returns>�r�b�g�}�b�v</returns>
Bitmap^ FormMain::GetImage()
{
	Bitmap^ bitmap = mImageProcessing->GetBitmap();

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
/// �q�X�g�O�����\���{�^���̃N���b�N�C�x���g
/// </summary>
/// <param name="sender">�I�u�W�F�N�g</param>
/// <param name="e">�C�x���g�̃f�[�^</param>
void FormMain::OnClickBtnShowHistgram(Object^ sender, EventArgs^ e)
{
	if (mBitmap == nullptr)
	{
		return;
	}

	if (mHistgram != nullptr)
	{
		mHistgram->Close();
		mHistgram = nullptr;
		delete mHistgram;
		mHistgram = gcnew FormHistgram();
	}

	Bitmap^ bitmap = gcnew Bitmap(mOpenFileName);
	mHistgram->SetBitmapOrg((Bitmap^)bitmap->Clone());
	if (GetBitmap() != nullptr)
	{
		mHistgram->SetBitmapAfter((Bitmap^)GetBitmap()->Clone());
	}

	mHistgram->DrawHistgram();
	mHistgram->SetIsOpen(true);
	mHistgram->Show();

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
		mCurrentImageProcessingName = (String^)win->GetCmbBoxImageProcessingType()->SelectedItem;
		this->Text = "Image Processing ( " + mCurrentImageProcessingName + " )";

		sliderThresh->Enabled = mCurrentImageProcessingName == (String^)ComConstStringInfo::IMG_NAME_BINARIZATION ? true : false;

		pictureBoxAfter->Image = nullptr;
		btnSaveImage->Enabled = false;
		mBitmap = gcnew Bitmap(mOpenFileName);
		mImageProcessing = gcnew ImageProcessing(mBitmap);
		if (mHistgram != nullptr && mHistgram->GetIsOpen() == true)
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
	mTokenSource = gcnew CancellationTokenSource();
	CancellationToken^ token = mTokenSource->Token;

	ComImgInfo^ imgInfo = gcnew ComImgInfo();
	BinarizationInfo^ binarizationInfo = gcnew BinarizationInfo();
	Byte nThresh = (Byte)sliderThresh->Value;
	binarizationInfo->SetThresh(nThresh);
	imgInfo->SetCurrentImageProcessingName(mCurrentImageProcessingName);
	imgInfo->SetBinarizationInfo(binarizationInfo);
	bool bRst = GoImageProcessing(imgInfo, token);
	if (bRst)
	{
		pictureBoxOriginal->ImageLocation = mOpenFileName;
		pictureBoxAfter->Image = GetBitmap();

		Bitmap^ bitmap = gcnew Bitmap(mOpenFileName);
		mHistgram->SetBitmapOrg((Bitmap^)bitmap->Clone());
		if (GetBitmap() != nullptr)
		{
			System::Threading::Thread::Sleep(50);
			mHistgram->SetBitmapAfter((Bitmap^)GetBitmap()->Clone());
		}
		if (mHistgram->GetIsOpen() == true)
		{
			mHistgram->DrawHistgram();
		}
		delete bitmap;
	}
	SetPictureBoxStatusVisible(false);
	SetControlEnable();
	SetSliderThreshEnable(true);

	delete mTokenSource;
	delete imgInfo;
	delete binarizationInfo;
	mTokenSource = nullptr;

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