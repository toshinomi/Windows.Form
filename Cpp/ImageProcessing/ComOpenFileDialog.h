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
/// ファイルオープンのロジック
/// </summary>
public ref class ComOpenFileDialog
{
protected:
	OpenFileDialog^ m_openFileDialog;

public:
	// FileName
	void SetFileName(String^ _strFileName) { m_openFileDialog->FileName = _strFileName; }
	String^ GetFileName(void) { return m_openFileDialog->FileName; }
	// InitialDirectory
	void SetInitialDirectory(String^ _strInitialDirectory) { m_openFileDialog->InitialDirectory = _strInitialDirectory; }
	String^ GetInitialDirectory(void) { return m_openFileDialog->InitialDirectory; }
	// Filter
	void SetFilter(String^ _strFilter) { m_openFileDialog->Filter = _strFilter; }
	String^ GetFilter(void) { return m_openFileDialog->Filter; }
	// FilterIndex
	void SetFilterIndex(int _nFilterIndex) { m_openFileDialog->FilterIndex = _nFilterIndex; }
	int GetFilterIndex(void) { return m_openFileDialog->FilterIndex; }
	// Title
	void SetTitle(String^ _strTitle) { m_openFileDialog->Title = _strTitle; }
	String^ GetTitle(void) { return m_openFileDialog->Title; }
	// CheckFileExists
	void SetCheckFileExists(bool _bCheckFileExists) { m_openFileDialog->CheckFileExists = _bCheckFileExists; }
	bool GetCheckFileExists(void) { return m_openFileDialog->CheckFileExists; }
	// CheckPathExists
	void SetCheckPathExists(bool _bCheckPathExists) { m_openFileDialog->CheckPathExists = _bCheckPathExists; }
	bool GetCheckPathExists(void) { return m_openFileDialog->CheckPathExists; }

	ComOpenFileDialog();
	~ComOpenFileDialog();

	bool ShowDialog();
};