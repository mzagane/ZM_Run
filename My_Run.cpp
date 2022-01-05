//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("Main_Unit.cpp", Main_Form);
USEFORM("Configuration_Unit.cpp", Configuration_Form);
USEFORM("Help_Unit.cpp", Help_Form);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 SetWindowLong(Application->Handle, GWL_EXSTYLE, WS_EX_TOOLWINDOW);// pour cacher l'application de la barre des taches.
                 Application->Initialize();
                 Application->CreateForm(__classid(TMain_Form), &Main_Form);
                 Application->CreateForm(__classid(TConfiguration_Form), &Configuration_Form);
                 Application->CreateForm(__classid(THelp_Form), &Help_Form);
                 Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        catch (...)
        {
                 try
                 {
                         throw Exception("");
                 }
                 catch (Exception &exception)
                 {
                         Application->ShowException(&exception);
                 }
        }
        return 0;
}
//---------------------------------------------------------------------------
