#include "MyForm.h"
#include <Windows.h>
using namespace Chess; 

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	srand(2);
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MyForm);
	return 0;
}