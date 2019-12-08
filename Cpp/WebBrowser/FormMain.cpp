#include "FormMain.h"
#include "FormWebBrowser.h"

using namespace WebBrowser;
using namespace System;
using namespace System::Windows::Forms;

/// <summary>
/// FormMain�̃��[�h�C�x���g
/// </summary>
/// <param name="sender">�I�u�W�F�N�g</param>
/// <param name="e">�C�x���g�̃f�[�^</param>
void FormMain::OnLoadFormMain(Object^ sender, EventArgs^ e)
{
	SetFormMain();
	SetFormChild();
}

/// <summary>
/// ���j���[�̐V�K�E�B���h�E���J���̃N���b�N�C�x���g
/// </summary>
/// <param name="sender">�I�u�W�F�N�g</param>
/// <param name="e">�C�x���g�̃f�[�^</param>
void FormMain::OnClickMenuFileNewOpen(Object^ sender, EventArgs^ e)
{
	SetFormChild();
}

/// <summary>
/// ���j���[�̏d�˂ĕ\���̃N���b�N�C�x���g
/// </summary>
/// <param name="sender">�I�u�W�F�N�g</param>
/// <param name="e">�C�x���g�̃f�[�^</param>
void FormMain::OnClickMenuWindowCascade(Object^ sender, EventArgs^ e)
{
	this->LayoutMdi(MdiLayout::Cascade);
}

/// <summary>
/// ���j���[�̏㉺�ɕ��ׂĕ\���̃N���b�N�C�x���g
/// </summary>
/// <param name="sender">�I�u�W�F�N�g</param>
/// <param name="e">�C�x���g�̃f�[�^</param>
void FormMain::OnClickMenuWindowTileHorizontal(Object^ sender, EventArgs^ e)
{
	this->LayoutMdi(MdiLayout::TileHorizontal);
}

/// <summary>
/// ���j���[�̍��E�ɕ��ׂĕ\���̃N���b�N�C�x���g
/// </summary>
/// <param name="sender">�I�u�W�F�N�g</param>
/// <param name="e">�C�x���g�̃f�[�^</param>
void FormMain::OnClickMenuWindowTileVertical(Object^ sender, EventArgs^ e)
{
	this->LayoutMdi(MdiLayout::TileVertical);
}

/// <summary>
/// ���j���[�̏I���̃N���b�N�C�x���g
/// </summary>
/// <param name="sender">�I�u�W�F�N�g</param>
/// <param name="e">�C�x���g�̃f�[�^</param>
void FormMain::OnClickMenuFileEnd(Object^ sender, EventArgs^ e)
{
	for each (unsigned int nKey in m_listWebBrowser.Keys)
	{
		FormWebBrowser^ form = m_listWebBrowser[nKey];
		form = nullptr;
	}
	this->Close();

}

/// <summary>
/// Form�̃N���[�Y�C�x���g
/// </summary>
/// <param name="sender">�I�u�W�F�N�g</param>
/// <param name="e">FormClosed�C�x���g�̃f�[�^</param>
void FormMain::OnFormClosedFormMain(Object^ sender, FormClosedEventArgs^ e)
{
	m_listWebBrowser.Clear();
}

/// <summary>
/// FormMain�̐ݒ�
/// </summary>
void FormMain::SetFormMain(void)
{
	this->Size = System::Drawing::Size(1000, 600);
}

/// <summary>
/// FormMain�̎q�E�B���h�E�̐ݒ�
/// </summary>
void FormMain::SetFormChild(void)
{
	FormWebBrowser^ form = gcnew FormWebBrowser();
	form->MdiParent = this;
	form->WindowState = FormWindowState::Minimized;
	form->Show();
	form->Name = m_nCountWebBrowser.ToString();
	form->WindowState = FormWindowState::Maximized;
	m_listWebBrowser.Add(m_nCountWebBrowser, form);
	m_nCountWebBrowser += 1;
}