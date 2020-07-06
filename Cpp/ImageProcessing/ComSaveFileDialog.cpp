#include "ComSaveFileDialog.h"

/// <summary>
/// コンストラクタ
/// </summary>
ComSaveFileDialog::ComSaveFileDialog(void)
{
	mSaveFileDialog = gcnew SaveFileDialog();
}

/// <summary>
/// デスクトラクタ
/// </summary>
ComSaveFileDialog::~ComSaveFileDialog(void)
{
}

/// <summary>
/// ダイアログの表示
/// </summary>
/// <returns>結果 成功/失敗</returns>
bool ComSaveFileDialog::ShowDialog(void)
{
	bool bRst = false;

	if (mSaveFileDialog->ShowDialog() == DialogResult::OK)
	{
		bRst = true;
	}

	return bRst;
}

/// <summary>
/// ストリームの書込み
/// </summary>
/// <param name="_str">ファイル名称</param>
/// <returns>実行結果 成功/失敗</returns>
bool ComSaveFileDialog::StreamWrite(String^ _str)
{
	Stream^ stream;
	bool bRst = true;
	try
	{
		stream = mSaveFileDialog->OpenFile();
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

	return bRst;
}