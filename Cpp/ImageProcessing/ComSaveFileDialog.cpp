#include "ComSaveFileDialog.h"

using namespace ImageProcessing;

ComSaveFileDialog::ComSaveFileDialog(void)
{
	m_saveFileDialog = gcnew SaveFileDialog();
}

ComSaveFileDialog::~ComSaveFileDialog(void)
{
	delete m_saveFileDialog;
}

bool ComSaveFileDialog::ShowDialog(void)
{
	bool bRst = false;

	if (m_saveFileDialog->ShowDialog() == DialogResult::OK)
	{
		bRst = true;
	}

	return bRst;
}

void ComSaveFileDialog::StreamWrite(String^ _str)
{
	Stream^ stream = m_saveFileDialog->OpenFile();
	StreamWriter^ streamWriter = gcnew StreamWriter(stream, Encoding::GetEncoding("UTF-8"));
	streamWriter->Write(_str);
	streamWriter->Close();
	stream->Close();
	delete streamWriter;

	return;
}
