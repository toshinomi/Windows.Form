#include "FormMain.h"
#include "FormWebBrowser.h"

using namespace WebBrowser;

/// <summary>
/// Formのクローズイベント
/// </summary>
/// <param name="sender">オブジェクト</param>
/// <param name="e">FormClosedイベントのデータ</param>
void FormWebBrowser::OnFormClosedFormWebBrowser(Object^ sender, FormClosedEventArgs^ e)
{
	FormMain^ formMain = (FormMain^)this->MdiParent;
	FormWebBrowser^ form = formMain->GetFormWebBrowser(Convert::ToUInt32(this->Name));
	form = nullptr;
	formMain->RemoveListWebBrowser(Convert::ToUInt32(this->Name));
}

/// <summary>
/// FormWebBrowserのロードイベント
/// </summary>
/// <param name="sender">オブジェクト</param>
/// <param name="e">イベントのデータ</param>
void FormWebBrowser::OnLoadFormWebBrowser(Object^ sender, EventArgs^ e)
{
	SetInitToolTip();
	HomeWebBrowser();
}

/// <summary>
/// 前のページに戻すクリックイベント
/// </summary>
/// <param name="sender">オブジェクト</param>
/// <param name="e">イベントのデータ</param>
void FormWebBrowser::OnClickBack(Object^ sender, EventArgs^ e)
{
	if (webBrowser->CanGoBack == true)
	{
		webBrowser->GoBack();
	}
}

/// <summary>
/// 次のページに移動クリックイベント
/// </summary>
/// <param name="sender">オブジェクト</param>
/// <param name="e">イベントのデータ</param>
void FormWebBrowser::OnClickForward(Object^ sender, EventArgs^ e)
{
	if (webBrowser->CanGoForward == true)
	{
		webBrowser->GoForward();
	}
}

/// <summary>
/// 更新のクリックイベント
/// </summary>
/// <param name="sender">オブジェクト</param>
/// <param name="e">イベントのデータ</param>
void FormWebBrowser::OnClickRefresh(Object^ sender, EventArgs^ e)
{
	webBrowser->Refresh();
}

/// <summary>
/// URL入力のテキストボックスのキーダウンイベント
/// </summary>
/// <param name="sender">オブジェクト</param>
/// <param name="e">キーイベントのデータ</param>
void FormWebBrowser::OnKeyDownTextUrl(Object^ sender, KeyEventArgs^ e)
{
	if (e->KeyCode == Keys::Enter)
	{
		mUrl = textUrl->Text;
		webBrowser->Navigate(mUrl);
	}
}

/// <summary>
/// WebBrowserのNavigatedイベント
/// </summary>
/// <param name="sender">オブジェクト</param>
/// <param name="e">WebBrowserNavigatedイベントのデータ</param>
void FormWebBrowser::OnNavigatedWebBrowser(Object^ sender, WebBrowserNavigatedEventArgs^ e)
{
	textUrl->Text = webBrowser->Url->AbsoluteUri;
	this->Text = webBrowser->Url->AbsoluteUri;
}

/// <summary>
/// ツールチップの設定
/// </summary>
void FormWebBrowser::SetInitToolTip(void)
{
	mToolTip = gcnew ToolTip();
	mToolTip->SetToolTip(textUrl, "URL入力後、Enterキーを押してください!!!");
}

/// <summary>
/// ホームの処理
/// </summary>
void FormWebBrowser::HomeWebBrowser(void)
{
	Uri^ uri = gcnew Uri((String^)HOME_URL);
	webBrowser->Navigate(uri);
	textUrl->Text = mUrl;
	this->Text = mUrl;
}
