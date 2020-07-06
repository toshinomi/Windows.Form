#pragma once
using namespace System;
using namespace System::Collections::Generic;
using namespace System::Drawing;
using namespace System::Drawing::Imaging;
using namespace System::Text;
using namespace System::Threading;
using namespace System::Threading::Tasks;
using namespace System::Windows::Forms;

/// <summary>
/// �t�@�C���I�[�v���̃��W�b�N
/// </summary>
public ref class ComOpenFileDialog
{
protected:
	/// <summary>
	/// �I�[�v���t�@�C���_�C�A���O
	/// </summary>
	OpenFileDialog^ mOpenFileDialog;

public:
	/// <summary>
	/// FileName�̐ݒ�
	/// </summary>
	/// <param name="_strFileName">fileName</param>
	void SetFileName(String^ fileName) { mOpenFileDialog->FileName = fileName; }

	/// <summary>
	/// FileName�̎擾
	/// </summary>
	/// <returns>FileName</returns>
	String^ GetFileName(void) { return mOpenFileDialog->FileName; }

	/// <summary>
	/// InitialDirectory�̐ݒ�
	/// </summary>
	/// <param name="initialDirectory">InitialDirectory</param>
	void SetInitialDirectory(String^ initialDirectory) { mOpenFileDialog->InitialDirectory = initialDirectory; }

	/// <summary>
	/// InitialDirectory�̎擾
	/// </summary>
	/// <returns>InitialDirectory</returns>
	String^ GetInitialDirectory(void) { return mOpenFileDialog->InitialDirectory; }

	/// <summary>
	/// Filter�̐ݒ�
	/// </summary>
	/// <param name="filter">Filter</param>
	void SetFilter(String^ filter) { mOpenFileDialog->Filter = filter; }

	/// <summary>
	/// Filter�̎擾
	/// </summary>
	/// <returns>Filter</returns>
	String^ GetFilter(void) { return mOpenFileDialog->Filter; }

	/// <summary>
	/// FilterIndex�̐ݒ�
	/// </summary>
	/// <param name="filterIndex">FilterIndex</param>
	void SetFilterIndex(int filterIndex) { mOpenFileDialog->FilterIndex = filterIndex; }

	/// <summary>
	/// FilterIndex�̎擾
	/// </summary>
	/// <returns>FilterIndex</returns>
	int GetFilterIndex(void) { return mOpenFileDialog->FilterIndex; }

	/// <summary>
	/// Title�̐ݒ�
	/// </summary>
	/// <param name="title">Title</param>
	void SetTitle(String^ title) { mOpenFileDialog->Title = title; }

	/// <summary>
	/// Title�̎擾
	/// </summary>
	/// <returns>Title</returns>
	String^ GetTitle(void) { return mOpenFileDialog->Title; }

	/// <summary>
	/// CheckFileExists�̐ݒ�
	/// </summary>
	/// <param name="checkFileExists">CheckFileExists</param>
	void SetCheckFileExists(bool checkFileExists) { mOpenFileDialog->CheckFileExists = checkFileExists; }

	/// <summary>
	/// CheckFileExists�̎擾
	/// </summary>
	/// <returns>CheckFileExists</returns>
	bool GetCheckFileExists(void) { return mOpenFileDialog->CheckFileExists; }

	/// <summary>
	/// CheckPathExists�̐ݒ�
	/// </summary>
	/// <param name="checkPathExists">CheckPathExists</param>
	void SetCheckPathExists(bool checkPathExists) { mOpenFileDialog->CheckPathExists = checkPathExists; }

	/// <summary>
	/// CheckPathExists�̎擾
	/// </summary>
	/// <returns>CheckPathExists</returns>
	bool GetCheckPathExists(void) { return mOpenFileDialog->CheckPathExists; }

	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	ComOpenFileDialog();

	/// <summary>
	/// �f�X�N�g���N�^
	/// </summary>
	~ComOpenFileDialog();

	/// <summary>
	/// �_�C�A���O�̕\��
	/// </summary>
	/// <returns>���� ����/���s</returns>
	bool ShowDialog();
};