#pragma once

using namespace System;
using namespace System::Collections::Generic;
using namespace System::IO;
using namespace System::Text;
using namespace System::Threading::Tasks;
using namespace System::Windows::Forms;

namespace ImageProcessing
{
	public ref class ComSaveFileDialog
	{
	protected:
		SaveFileDialog^ m_saveFileDialog;
	public:
		ComSaveFileDialog(void);
		~ComSaveFileDialog(void);
		// FileName
		String^ GetFileName(void) { return m_saveFileDialog->FileName; };
		void SetFileName(String^ _strFileName) { m_saveFileDialog->FileName = _strFileName; };
		// InitialDirectory
		String^ GetInitialDirectory(void) { return m_saveFileDialog->InitialDirectory; };
		void SetInitialDirectory(String^ _strInitDirectory) { m_saveFileDialog->InitialDirectory = _strInitDirectory; };
		// Filter
		String^ GetFilter(void) { return m_saveFileDialog->Filter; };
		void SetFilter(String^ _nFilter) { m_saveFileDialog->Filter = _nFilter; };
		// FilterIndex
		int GetFilterIndex(void) { return m_saveFileDialog->FilterIndex; };
		void SetFilterIndex(int _nFilterIndex) { m_saveFileDialog->FilterIndex = _nFilterIndex; };
		// Title
		String^ GetTitle(void) { return m_saveFileDialog->Title; };
		void SetTitle(String^ _strTitle) { m_saveFileDialog->Title = _strTitle; };
		// CheckFileExists
		bool GetCheckFileExists(void) { return m_saveFileDialog->CheckFileExists; };
		void SetCheckFileExists(bool _bCheckFileExists) { m_saveFileDialog->CheckFileExists = _bCheckFileExists; };
		// CheckPathExists
		bool GetCheckPathExists(void) { return m_saveFileDialog->CheckPathExists; };
		void SetCheckPathExists(bool _bCheckPathExists) { m_saveFileDialog->CheckPathExists = _bCheckPathExists; };
		bool ShowDialog(void);
		bool StreamWrite(String^ _str);
	};
}