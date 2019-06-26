#include "ComOpenFileDialog.h"

ImageProcessing::ComOpenFileDialog::ComOpenFileDialog()
{
	m_openFileDialog = gcnew OpenFileDialog();
}

ImageProcessing::ComOpenFileDialog::~ComOpenFileDialog()
{
	delete m_openFileDialog;
}

bool ImageProcessing::ComOpenFileDialog::ShowDialog()
{
	bool bRst = false;

	if (m_openFileDialog->ShowDialog() == DialogResult::OK)
	{
		bRst = true;
	}

	return bRst;
}