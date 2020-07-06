#include "ComOpenFileDialog.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
ComOpenFileDialog::ComOpenFileDialog()
{
	mOpenFileDialog = gcnew OpenFileDialog();
}

/// <summary>
/// �f�X�N�g���N�^
/// </summary>
ComOpenFileDialog::~ComOpenFileDialog()
{
	delete mOpenFileDialog;
}

/// <summary>
/// �_�C�A���O�̕\��
/// </summary>
/// <returns>���� ����/���s</returns>
bool ComOpenFileDialog::ShowDialog()
{
	bool bRst = false;

	if (mOpenFileDialog->ShowDialog() == DialogResult::OK)
	{
		bRst = true;
	}

	return bRst;
}