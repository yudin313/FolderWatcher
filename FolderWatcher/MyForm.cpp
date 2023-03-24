#include "MyForm.h"
#include <Windows.h>
#include <fileapi.h>
#include <iostream>

using namespace System;
using namespace System::Windows::Forms;
[STAThreadAttribute]
//[STAThread]

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ PSTR szCmdLine, _In_ int iCmdShow) {
	
	//backend_main();

	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	Example::MyForm form;
	Application::Run(% form);

	return 0;
}
