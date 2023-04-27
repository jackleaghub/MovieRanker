#include "MyForm1.h"
using namespace System;
using namespace System::Windows::Forms;

void main(array<String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    DSAFinalUI::MyForm1 form;
    Application::Run(% form);
}

