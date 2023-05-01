#include "MyForm.h"

bool check_box[7] = { true,true, true, true, true, true, false};
int depth = 0;
using namespace System;
using namespace System::Windows::Forms;
[STAThreadAttribute]

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ PSTR szCmdLine, _In_ int iCmdShow) {

	setup();

	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	Example::MyForm form;
	Application::Run(% form);

	deinit();

	return 0;
}
