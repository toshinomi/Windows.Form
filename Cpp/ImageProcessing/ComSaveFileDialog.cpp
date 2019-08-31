#include "ComSaveFileDialog.h"

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

bool ComSaveFileDialog::StreamWrite(String^ _str)
{
	Stream^ stream;
	bool bRst = true;
	try
	{
		stream = m_saveFileDialog->OpenFile();
	}
	catch (Exception^)
	{
		bRst = false;
		return bRst;
	}
	StreamWriter^ streamWriter = gcnew StreamWriter(stream, Encoding::GetEncoding("UTF-8"));
	streamWriter->Write(_str);
	streamWriter->Close();
	stream->Close();
	delete streamWriter;

	return bRst;
}