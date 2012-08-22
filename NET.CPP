//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
USERES("Net.res");
USEFORM("Unit1.cpp", Form1);
USEUNIT("..\Neuro.cpp");
USEFORM("..\..\..\..\Мои программы\C++\НейроСеть\Распознавание символов\Unit2.cpp", Form2);
USEFORM("..\..\..\..\Мои программы\C++\НейроСеть\Распознавание символов\Unit3.cpp", Form3);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    try
    {
        Application->Initialize();
        Application->Title = "Распознавание символов";
        Application->CreateForm(__classid(TForm1), &Form1);
        Application->CreateForm(__classid(TForm2), &Form2);
        Application->CreateForm(__classid(TForm3), &Form3);
        Application->Run();
    }
    catch (Exception &exception)
    {
        Application->ShowException(&exception);
    }
    return 0;
}
//---------------------------------------------------------------------------
