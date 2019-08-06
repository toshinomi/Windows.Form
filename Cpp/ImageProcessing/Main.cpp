#include "FormMain.h"

using namespace System;
using namespace System::Windows::Forms;

namespace ImageProcessing
{
	[STAThread]
	void Main(void)
	{
		Application::EnableVisualStyles();
		Application::SetCompatibleTextRenderingDefault(false);

		Application::Run(gcnew FormMain());

		return;
	}
}