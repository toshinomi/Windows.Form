#include "FormMain.h"
#include "FormWebBrowser.h"

using namespace System;
using namespace System::Windows::Forms;

namespace WebBrowser
{
	[STAThread]
	void Main(void)
	{

		Application::EnableVisualStyles();
		Application::SetCompatibleTextRenderingDefault(false);

		Application::Run(gcnew ::WebBrowser::FormMain());

		return;
	}
}