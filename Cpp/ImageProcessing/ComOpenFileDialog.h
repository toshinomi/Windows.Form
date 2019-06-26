#pragma once
using namespace System;
using namespace System::Collections::Generic;
using namespace System::Drawing;
using namespace System::Drawing::Imaging;
using namespace System::Text;
using namespace System::Threading;
using namespace System::Threading::Tasks;
using namespace System::Windows::Forms;

namespace ImageProcessing
{
	public ref class ComOpenFileDialog
	{
	protected:
		OpenFileDialog^ m_openFileDialog;

	public:
		// FileName
		void SetFileName(String^ value) { m_openFileDialog->FileName = value; }
		String^ GetFileName(void) { return m_openFileDialog->FileName; }

		// InitialDirectory
		void SetInitialDirectory(String^ value) { m_openFileDialog->InitialDirectory = value; }
		String^ GetInitialDirectory(void) { return m_openFileDialog->InitialDirectory; }

		// Filter
		void SetFilter(String^ value) { m_openFileDialog->Filter = value; }
		String^ GetFilter(void) { return m_openFileDialog->Filter; }

		// FilterIndex
		void SetFilterIndex(int value) { m_openFileDialog->FilterIndex = value; }
		int GetFilterIndex(void) { return m_openFileDialog->FilterIndex; }

		// Title
		void SetTitle(String^ value) { m_openFileDialog->Title = value; }
		String^ GetTitle(void) { return m_openFileDialog->Title; }

		// CheckFileExists
		void SetCheckFileExists(bool value) { m_openFileDialog->CheckFileExists = value; }
		bool GetCheckFileExists(void) { return m_openFileDialog->CheckFileExists; }

		// CheckPathExists
		void SetCheckPathExists(bool value) { m_openFileDialog->CheckPathExists = value; }
		bool GetCheckPathExists(void) { return m_openFileDialog->CheckPathExists; }

		ComOpenFileDialog();
		~ComOpenFileDialog();

		bool ShowDialog();
	};
}