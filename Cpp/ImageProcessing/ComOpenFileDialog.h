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
	OpenFileDialog^ m_openFileDialog;

public:
	/// <summary>
	/// FileName�̐ݒ�
	/// </summary>
	/// <param name="_strFileName">FileName</param>
	void SetFileName(String^ _strFileName) { m_openFileDialog->FileName = _strFileName; }

	/// <summary>
	/// FileName�̎擾
	/// </summary>
	/// <returns>FileName</returns>
	String^ GetFileName(void) { return m_openFileDialog->FileName; }

	/// <summary>
	/// InitialDirectory�̐ݒ�
	/// </summary>
	/// <param name="_strInitialDirectory">InitialDirectory</param>
	void SetInitialDirectory(String^ _strInitialDirectory) { m_openFileDialog->InitialDirectory = _strInitialDirectory; }

	/// <summary>
	/// InitialDirectory�̎擾
	/// </summary>
	/// <returns>InitialDirectory</returns>
	String^ GetInitialDirectory(void) { return m_openFileDialog->InitialDirectory; }

	/// <summary>
	/// Filter�̐ݒ�
	/// </summary>
	/// <param name="_strFilter">Filter</param>
	void SetFilter(String^ _strFilter) { m_openFileDialog->Filter = _strFilter; }

	/// <summary>
	/// Filter�̎擾
	/// </summary>
	/// <returns>Filter</returns>
	String^ GetFilter(void) { return m_openFileDialog->Filter; }

	/// <summary>
	/// FilterIndex�̐ݒ�
	/// </summary>
	/// <param name="_nFilterIndex">FilterIndex</param>
	void SetFilterIndex(int _nFilterIndex) { m_openFileDialog->FilterIndex = _nFilterIndex; }

	/// <summary>
	/// FilterIndex�̎擾
	/// </summary>
	/// <returns>FilterIndex</returns>
	int GetFilterIndex(void) { return m_openFileDialog->FilterIndex; }

	/// <summary>
	/// Title�̐ݒ�
	/// </summary>
	/// <param name="_strTitle">Title</param>
	void SetTitle(String^ _strTitle) { m_openFileDialog->Title = _strTitle; }

	/// <summary>
	/// Title�̎擾
	/// </summary>
	/// <returns>Title</returns>
	String^ GetTitle(void) { return m_openFileDialog->Title; }

	/// <summary>
	/// CheckFileExists�̐ݒ�
	/// </summary>
	/// <param name="_bCheckFileExists">CheckFileExists</param>
	void SetCheckFileExists(bool _bCheckFileExists) { m_openFileDialog->CheckFileExists = _bCheckFileExists; }

	/// <summary>
	/// CheckFileExists�̎擾
	/// </summary>
	/// <returns>CheckFileExists</returns>
	bool GetCheckFileExists(void) { return m_openFileDialog->CheckFileExists; }

	/// <summary>
	/// CheckPathExists�̐ݒ�
	/// </summary>
	/// <param name="_bCheckPathExists">CheckPathExists</param>
	void SetCheckPathExists(bool _bCheckPathExists) { m_openFileDialog->CheckPathExists = _bCheckPathExists; }

	/// <summary>
	/// CheckPathExists�̎擾
	/// </summary>
	/// <returns>CheckPathExists</returns>
	bool GetCheckPathExists(void) { return m_openFileDialog->CheckPathExists; }

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