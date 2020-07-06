#include "ComOpenFileDialog.h"

/// <summary>
/// コンストラクタ
/// </summary>
ComOpenFileDialog::ComOpenFileDialog()
{
	mOpenFileDialog = gcnew OpenFileDialog();
}

/// <summary>
/// デスクトラクタ
/// </summary>
ComOpenFileDialog::~ComOpenFileDialog()
{
	delete mOpenFileDialog;
}

/// <summary>
/// ダイアログの表示
/// </summary>
/// <returns>結果 成功/失敗</returns>
bool ComOpenFileDialog::ShowDialog()
{
	bool bRst = false;

	if (mOpenFileDialog->ShowDialog() == DialogResult::OK)
	{
		bRst = true;
	}

	return bRst;
}