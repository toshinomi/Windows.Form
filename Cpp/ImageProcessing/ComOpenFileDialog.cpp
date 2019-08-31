#include "ComOpenFileDialog.h"

ComOpenFileDialog::ComOpenFileDialog()
{
	m_openFileDialog = gcnew OpenFileDialog();
}

ComOpenFileDialog::~ComOpenFileDialog()
{
	delete m_openFileDialog;
}

bool ComOpenFileDialog::ShowDialog()
{
	bool bRst = false;

	if (m_openFileDialog->ShowDialog() == DialogResult::OK)
	{
		bRst = true;
	}

	return bRst;
}