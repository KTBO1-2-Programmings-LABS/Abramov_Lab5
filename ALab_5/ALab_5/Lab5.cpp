#include "Lab5.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace ALab5;
[STAThread]
int main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew Lab5());

	return 0;
}
