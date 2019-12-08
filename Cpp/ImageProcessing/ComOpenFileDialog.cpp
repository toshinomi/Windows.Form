#include "ComOpenFileDialog.h"

/// <summary>
/// コンストラクタ
/// </summary>
ComOpenFileDialog::ComOpenFileDialog()
{
	m_openFileDialog = gcnew OpenFileDialog();
}

/// <summary>
/// デスクトラクタ
/// </summary>
ComOpenFileDialog::~ComOpenFileDialog()
{
	delete m_openFileDialog;
}

/// <summary>
/// ダイアログの表示
/// </summary>
/// <returns>結果 成功/失敗</returns>
bool ComOpenFileDialog::ShowDialog()
{
	bool bRst = false;

	if (m_openFileDialog->ShowDialog() == DialogResult::OK)
	{
		bRst = true;
	}

	return bRst;
}