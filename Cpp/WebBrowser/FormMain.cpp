#include "FormMain.h"
#include "FormWebBrowser.h"

using namespace WebBrowser;
using namespace System;
using namespace System::Windows::Forms;

/// <summary>
/// FormMainのロードイベント
/// </summary>
/// <param name="sender">オブジェクト</param>
/// <param name="e">イベントのデータ</param>
void FormMain::OnLoadFormMain(Object^ sender, EventArgs^ e)
{
	SetFormMain();
	SetFormChild();
}

/// <summary>
/// メニューの新規ウィンドウを開くのクリックイベント
/// </summary>
/// <param name="sender">オブジェクト</param>
/// <param name="e">イベントのデータ</param>
void FormMain::OnClickMenuFileNewOpen(Object^ sender, EventArgs^ e)
{
	SetFormChild();
}

/// <summary>
/// メニューの重ねて表示のクリックイベント
/// </summary>
/// <param name="sender">オブジェクト</param>
/// <param name="e">イベントのデータ</param>
void FormMain::OnClickMenuWindowCascade(Object^ sender, EventArgs^ e)
{
	this->LayoutMdi(MdiLayout::Cascade);
}

/// <summary>
/// メニューの上下に並べて表示のクリックイベント
/// </summary>
/// <param name="sender">オブジェクト</param>
/// <param name="e">イベントのデータ</param>
void FormMain::OnClickMenuWindowTileHorizontal(Object^ sender, EventArgs^ e)
{
	this->LayoutMdi(MdiLayout::TileHorizontal);
}

/// <summary>
/// メニューの左右に並べて表示のクリックイベント
/// </summary>
/// <param name="sender">オブジェクト</param>
/// <param name="e">イベントのデータ</param>
void FormMain::OnClickMenuWindowTileVertical(Object^ sender, EventArgs^ e)
{
	this->LayoutMdi(MdiLayout::TileVertical);
}

/// <summary>
/// メニューの終了のクリックイベント
/// </summary>
/// <param name="sender">オブジェクト</param>
/// <param name="e">イベントのデータ</param>
void FormMain::OnClickMenuFileEnd(Object^ sender, EventArgs^ e)
{
	for each (unsigned int key in m_listWebBrowser.Keys)
	{
		FormWebBrowser^ form = m_listWebBrowser[key];
		form = nullptr;
	}
	this->Close();

}

/// <summary>
/// Formのクローズイベント
/// </summary>
/// <param name="sender">オブジェクト</param>
/// <param name="e">FormClosedイベントのデータ</param>
void FormMain::OnFormClosedFormMain(Object^ sender, FormClosedEventArgs^ e)
{
	m_listWebBrowser.Clear();
}

/// <summary>
/// FormMainの設定
/// </summary>
void FormMain::SetFormMain(void)
{
	this->Size = System::Drawing::Size(1000, 600);
}

/// <summary>
/// FormMainの子ウィンドウの設定
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
