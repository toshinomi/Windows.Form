#pragma once

using namespace System;
using namespace System::Collections::Generic;
using namespace System::IO;
using namespace System::Text;
using namespace System::Threading::Tasks;
using namespace System::Windows::Forms;

/// <summary>
/// �t�@�C���Z�[�u�̃��W�b�N
/// </summary>
public ref class ComSaveFileDialog
{
protected:
	/// <summary>
	/// �Z�[�u�t�@�C���_�C�A���O
	/// </summary>
	SaveFileDialog^ mSaveFileDialog;
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	ComSaveFileDialog(void);

	/// <summary>
	/// �f�X�N�g���N�^
	/// </summary>
	~ComSaveFileDialog(void);

	/// <summary>
	/// FileName�̎擾
	/// </summary>
	/// <returns>FileName</returns>
	String^ GetFileName(void) { return mSaveFileDialog->FileName; };

	/// <summary>
	/// FileName�̐ݒ�
	/// </summary>
	/// <param name="fileName">FileName</param>
	void SetFileName(String^ fileName) { mSaveFileDialog->FileName = fileName; };

	/// <summary>
	/// InitialDirectory�̎擾
	/// </summary>
	/// <returns>InitialDirectory</returns>
	String^ GetInitialDirectory(void) { return mSaveFileDialog->InitialDirectory; };

	/// <summary>
	/// InitialDirectory�̐ݒ�
	/// </summary>
	/// <param name="initDirectory">InitialDirectory</param>
	void SetInitialDirectory(String^ initDirectory) { mSaveFileDialog->InitialDirectory = initDirectory; };
	
	/// <summary>
	/// Filter�̎擾
	/// </summary>
	/// <returns>Filter</returns>
	String^ GetFilter(void) { return mSaveFileDialog->Filter; };

	/// <summary>
	/// Filter�̐ݒ�
	/// </summary>
	/// <param name="filter">Filter</param>
	void SetFilter(String^ filter) { mSaveFileDialog->Filter = filter; };

	/// <summary>
	/// FilterIndex�̎擾
	/// </summary>
	/// <returns>FilterIndex</returns>
	int GetFilterIndex(void) { return mSaveFileDialog->FilterIndex; };

	/// <summary>
	/// FilterIndex�̐ݒ�
	/// </summary>
	/// <param name="filterIndex">FilterIndex</param>
	void SetFilterIndex(int filterIndex) { mSaveFileDialog->FilterIndex = filterIndex; };

	/// <summary>
	/// Title�̎擾
	/// </summary>
	/// <returns>Title</returns>
	String^ GetTitle(void) { return mSaveFileDialog->Title; };

	/// <summary>
	/// Title�̐ݒ�
	/// </summary>
	/// <param name="title">Title</param>
	void SetTitle(String^ title) { mSaveFileDialog->Title = title; };

	/// <summary>
	/// CheckFileExists�̎擾
	/// </summary>
	/// <returns>CheckFileExists</returns>
	bool GetCheckFileExists(void) { return mSaveFileDialog->CheckFileExists; };

	/// <summary>
	/// CheckFileExists�̐ݒ�
	/// </summary>
	/// <param name="checkFileExists">CheckFileExists</param>
	void SetCheckFileExists(bool checkFileExists) { mSaveFileDialog->CheckFileExists = checkFileExists; };

	/// <summary>
	/// CheckPathExists�̎擾
	/// </summary>
	/// <returns>CheckPathExists</returns>
	bool GetCheckPathExists(void) { return mSaveFileDialog->CheckPathExists; };

	/// <summary>
	/// CheckPathExists�̐ݒ�
	/// </summary>
	/// <param name="checkPathExists">CheckPathExists</param>
	void SetCheckPathExists(bool checkPathExists) { mSaveFileDialog->CheckPathExists = checkPathExists; };

	/// <summary>
	/// �_�C�A���O�̕\��
	/// </summary>
	/// <returns>���� ����/���s</returns>
	bool ShowDialog(void);

	/// <summary>
	/// �X�g���[���̏�����
	/// </summary>
	/// <param name="_str">�t�@�C������</param>
	/// <returns>���s���� ����/���s</returns>
	bool StreamWrite(String^ _str);
};