#include "FormMain.h"
#include "FormWebBrowser.h"

using namespace WebBrowser;

/// <summary>
/// Form�̃N���[�Y�C�x���g
/// </summary>
/// <param name="sender">�I�u�W�F�N�g</param>
/// <param name="e">FormClosed�C�x���g�̃f�[�^</param>
void FormWebBrowser::OnFormClosedFormWebBrowser(Object^ sender, FormClosedEventArgs^ e)
{
	FormMain^ formMain = (FormMain^)this->MdiParent;
	FormWebBrowser^ form = formMain->GetFormWebBrowser(Convert::ToUInt32(this->Name));
	form = nullptr;
	formMain->RemoveListWebBrowser(Convert::ToUInt32(this->Name));
}

/// <summary>
/// FormWebBrowser�̃��[�h�C�x���g
/// </summary>
/// <param name="sender">�I�u�W�F�N�g</param>
/// <param name="e">�C�x���g�̃f�[�^</param>
void FormWebBrowser::OnLoadFormWebBrowser(Object^ sender, EventArgs^ e)
{
	SetInitToolTip();
	HomeWebBrowser();
}

/// <summary>
/// �O�̃y�[�W�ɖ߂��N���b�N�C�x���g
/// </summary>
/// <param name="sender">�I�u�W�F�N�g</param>
/// <param name="e">�C�x���g�̃f�[�^</param>
void FormWebBrowser::OnClickBack(Object^ sender, EventArgs^ e)
{
	if (webBrowser->CanGoBack == true)
	{
		webBrowser->GoBack();
	}
}

/// <summary>
/// ���̃y�[�W�Ɉړ��N���b�N�C�x���g
/// </summary>
/// <param name="sender">�I�u�W�F�N�g</param>
/// <param name="e">�C�x���g�̃f�[�^</param>
void FormWebBrowser::OnClickForward(Object^ sender, EventArgs^ e)
{
	if (webBrowser->CanGoForward == true)
	{
		webBrowser->GoForward();
	}
}

/// <summary>
/// �X�V�̃N���b�N�C�x���g
/// </summary>
/// <param name="sender">�I�u�W�F�N�g</param>
/// <param name="e">�C�x���g�̃f�[�^</param>
void FormWebBrowser::OnClickRefresh(Object^ sender, EventArgs^ e)
{
	webBrowser->Refresh();
}

/// <summary>
/// URL���͂̃e�L�X�g�{�b�N�X�̃L�[�_�E���C�x���g
/// </summary>
/// <param name="sender">�I�u�W�F�N�g</param>
/// <param name="e">�L�[�C�x���g�̃f�[�^</param>
void FormWebBrowser::OnKeyDownTextUrl(Object^ sender, KeyEventArgs^ e)
{
	if (e->KeyCode == Keys::Enter)
	{
		m_strUrl = textUrl->Text;
		webBrowser->Navigate(m_strUrl);
	}
}

/// <summary>
/// WebBrowser��Navigated�C�x���g
/// </summary>
/// <param name="sender">�I�u�W�F�N�g</param>
/// <param name="e">WebBrowserNavigated�C�x���g�̃f�[�^</param>
void FormWebBrowser::OnNavigatedWebBrowser(Object^ sender, WebBrowserNavigatedEventArgs^ e)
{
	textUrl->Text = webBrowser->Url->AbsoluteUri;
	this->Text = webBrowser->Url->AbsoluteUri;
}

/// <summary>
/// �c�[���`�b�v�̐ݒ�
/// </summary>
void FormWebBrowser::SetInitToolTip(void)
{
	m_toolTip = gcnew ToolTip();
	m_toolTip->SetToolTip(textUrl, "URL���͌�AEnter�L�[�������Ă�������!!!");
}

/// <summary>
/// �z�[���̏���
/// </summary>
void FormWebBrowser::HomeWebBrowser(void)
{
	Uri^ uri = gcnew Uri((String^)HOME_URL);
	webBrowser->Navigate(uri);
	textUrl->Text = m_strUrl;
	this->Text = m_strUrl;
}