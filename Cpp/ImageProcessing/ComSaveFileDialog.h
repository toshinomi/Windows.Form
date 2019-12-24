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
	SaveFileDialog^ m_saveFileDialog;
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
	String^ GetFileName(void) { return m_saveFileDialog->FileName; };

	/// <summary>
	/// FileName�̐ݒ�
	/// </summary>
	/// <param name="_strFileName">FileName</param>
	void SetFileName(String^ _strFileName) { m_saveFileDialog->FileName = _strFileName; };

	/// <summary>
	/// InitialDirectory�̎擾
	/// </summary>
	/// <returns>InitialDirectory</returns>
	String^ GetInitialDirectory(void) { return m_saveFileDialog->InitialDirectory; };

	/// <summary>
	/// InitialDirectory�̐ݒ�
	/// </summary>
	/// <param name="_strInitialDirectory">InitialDirectory</param>
	void SetInitialDirectory(String^ _strInitDirectory) { m_saveFileDialog->InitialDirectory = _strInitDirectory; };
	
	/// <summary>
	/// Filter�̎擾
	/// </summary>
	/// <returns>Filter</returns>
	String^ GetFilter(void) { return m_saveFileDialog->Filter; };

	/// <summary>
	/// Filter�̐ݒ�
	/// </summary>
	/// <param name="_strFilter">Filter</param>
	void SetFilter(String^ _nFilter) { m_saveFileDialog->Filter = _nFilter; };

	/// <summary>
	/// FilterIndex�̎擾
	/// </summary>
	/// <returns>FilterIndex</returns>
	int GetFilterIndex(void) { return m_saveFileDialog->FilterIndex; };

	/// <summary>
	/// FilterIndex�̐ݒ�
	/// </summary>
	/// <param name="_nFilterIndex">FilterIndex</param>
	void SetFilterIndex(int _nFilterIndex) { m_saveFileDialog->FilterIndex = _nFilterIndex; };

	/// <summary>
	/// Title�̎擾
	/// </summary>
	/// <returns>Title</returns>
	String^ GetTitle(void) { return m_saveFileDialog->Title; };

	/// <summary>
	/// Title�̐ݒ�
	/// </summary>
	/// <param name="_strTitle">Title</param>
	void SetTitle(String^ _strTitle) { m_saveFileDialog->Title = _strTitle; };

	/// <summary>
	/// CheckFileExists�̎擾
	/// </summary>
	/// <returns>CheckFileExists</returns>
	bool GetCheckFileExists(void) { return m_saveFileDialog->CheckFileExists; };

	/// <summary>
	/// CheckFileExists�̐ݒ�
	/// </summary>
	/// <param name="_bCheckFileExists">CheckFileExists</param>
	void SetCheckFileExists(bool _bCheckFileExists) { m_saveFileDialog->CheckFileExists = _bCheckFileExists; };

	/// <summary>
	/// CheckPathExists�̎擾
	/// </summary>
	/// <returns>CheckPathExists</returns>
	bool GetCheckPathExists(void) { return m_saveFileDialog->CheckPathExists; };

	/// <summary>
	/// CheckPathExists�̐ݒ�
	/// </summary>
	/// <param name="_bCheckPathExists">CheckPathExists</param>
	void SetCheckPathExists(bool _bCheckPathExists) { m_saveFileDialog->CheckPathExists = _bCheckPathExists; };

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