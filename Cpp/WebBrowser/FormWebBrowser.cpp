#include "FormMain.h"
#include "FormWebBrowser.h"

using namespace WebBrowser;

void FormWebBrowser::OnFormClosedFormWebBrowser(Object^ sender, FormClosedEventArgs^ e)
{
	FormMain^ formMain = (FormMain^)this->MdiParent;
	FormWebBrowser^ form = formMain->GetFormWebBrowser(Convert::ToUInt32(this->Name));
	form = nullptr;
	formMain->RemoveListWebBrowser(Convert::ToUInt32(this->Name));
}

void FormWebBrowser::OnLoadFormWebBrowser(Object^ sender, EventArgs^ e)
{
	SetInitToolTip();
	HomeWebBrowser();
}

void FormWebBrowser::OnClickBack(Object^ sender, EventArgs^ e)
{
	if (webBrowser->CanGoBack == true)
	{
		webBrowser->GoBack();
	}
}

void FormWebBrowser::OnClickForward(Object^ sender, EventArgs^ e)
{
	if (webBrowser->CanGoForward == true)
	{
		webBrowser->GoForward();
	}
}

void FormWebBrowser::OnClickRefresh(Object^ sender, EventArgs^ e)
{
	webBrowser->Refresh();
}

void FormWebBrowser::OnKeyDownTextUrl(Object^ sender, KeyEventArgs^ e)
{
	if (e->KeyCode == Keys::Enter)
	{
		m_strUrl = textUrl->Text;
		webBrowser->Navigate(m_strUrl);
	}
}

void FormWebBrowser::OnNavigatedWebBrowser(Object^ sender, WebBrowserNavigatedEventArgs^ e)
{
	textUrl->Text = webBrowser->Url->AbsoluteUri;
	this->Text = webBrowser->Url->AbsoluteUri;
}

void FormWebBrowser::SetInitToolTip(void)
{
	m_toolTip = gcnew ToolTip();
	m_toolTip->SetToolTip(textUrl, "URL“ü—ÍŒãAEnterƒL[‚ð‰Ÿ‚µ‚Ä‚­‚¾‚³‚¢!!!");
}

void FormWebBrowser::HomeWebBrowser(void)
{
	Uri^ uri = gcnew Uri((String^)HOME_URL);
	webBrowser->Navigate(uri);
	textUrl->Text = m_strUrl;
	this->Text = m_strUrl;
}