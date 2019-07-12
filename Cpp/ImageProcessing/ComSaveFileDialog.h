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
		String^ GetFileName(void) { return m_saveFileDialog->FileName; };
		void SetFileName(String^ _fileName) { m_saveFileDialog->FileName = _fileName; };
		String^ GetInitialDirectory(void) { return m_saveFileDialog->InitialDirectory; };
		void SetInitialDirectory(String^ _initDirectory) { m_saveFileDialog->InitialDirectory = _initDirectory; };
		String^ GetFilter(void) { return m_saveFileDialog->Filter; };
		void SetFilter(String^ _filter) { m_saveFileDialog->Filter = _filter; };
		int GetFilterIndex(void) { return m_saveFileDialog->FilterIndex; };
		void SetFilterIndex(int _filterIndex) { m_saveFileDialog->FilterIndex = _filterIndex; };
		String^ GetTitle(void) { return m_saveFileDialog->Title; };
		void SetTitle(String^ _title) { m_saveFileDialog->Title = _title; };
		bool GetCheckFileExists(void) { return m_saveFileDialog->CheckFileExists; };
		void SetCheckFileExists(bool _checkFileExists) { m_saveFileDialog->CheckFileExists = _checkFileExists; };
		bool GetCheckPathExists(void) { return m_saveFileDialog->CheckPathExists; };
		void SetCheckPathExists(bool _checkPathExists) { m_saveFileDialog->CheckPathExists = _checkPathExists; };
		bool ShowDialog(void);
		void StreamWrite(String^ _str);
	};
}