#include "FormMain.h"
#include "FormWebBrowser.h"

using namespace WebBrowser;
using namespace System;
using namespace System::Windows::Forms;


void FormMain::OnLoadFormMain(Object^ sender, EventArgs^ e)
{
	SetFormMain();
	SetFormChild();
}

void FormMain::OnClickMenuFileNewOpen(Object^ sender, EventArgs^ e)
{
	SetFormChild();
}

void FormMain::OnClickMenuWindowCascade(Object^ sender, EventArgs^ e)
{
	this->LayoutMdi(MdiLayout::Cascade);
}

void FormMain::OnClickMenuWindowTileHorizontal(Object^ sender, EventArgs^ e)
{
	this->LayoutMdi(MdiLayout::TileHorizontal);
}

void FormMain::OnClickMenuWindowTileVertical(Object^ sender, EventArgs^ e)
{
	this->LayoutMdi(MdiLayout::TileVertical);
}

void FormMain::OnClickMenuFileEnd(Object^ sender, EventArgs^ e)
{
	for each(unsigned int nKey in m_listWebBrowser.Keys)
	{
		FormWebBrowser^ form = m_listWebBrowser[nKey];
		form = nullptr;
	}
	this->Close();

}

void FormMain::OnFormClosedFormMain(Object^ sender, FormClosedEventArgs^ e)
{
	m_listWebBrowser.Clear();
}

void FormMain::SetFormMain(void)
{
	this->Size = System::Drawing::Size(1000, 600);
}

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
