//---------------------------------------------------------------------------

#ifndef Main_UnitH
#define Main_UnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <dir.h>//
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>
#include <Buttons.hpp>

#define AM_CALLBACK_MESSAGE   WM_APP + 408// systray

//---------------------------------------------------------------------------
class TMain_Form : public TForm
{
__published:	// IDE-managed Components
        TPopupMenu *Tools_PopupMenu;
        TMenuItem *Quitter1;
        TMenuItem *Rduir1;
        TPopupMenu *SysTry_PopupMenu;
        TMenuItem *Agrandir1;
        TMenuItem *Quitter2;
        TPanel *Panel1;
        TEdit *Command_Edit;
        TMenuItem *Configuration1;
        TMenuItem *Configuration2;
        TMenuItem *Aide1;
        TMenuItem *Aide2;
        TSpeedButton *Agrandir_SpeedButton;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall Rduir1Click(TObject *Sender);
        void __fastcall Quitter1Click(TObject *Sender);
        void __fastcall Quitter2Click(TObject *Sender);
        void __fastcall Agrandir1Click(TObject *Sender);
        void __fastcall Panel1MouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall Command_EditKeyPress(TObject *Sender, char &Key);
        void __fastcall Configuration1Click(TObject *Sender);
        void __fastcall Configuration2Click(TObject *Sender);
        void __fastcall Aide1Click(TObject *Sender);
        void __fastcall Aide2Click(TObject *Sender);
        void __fastcall Agrandir_SpeedButtonClick(TObject *Sender);

        //------------------ pour la réduction dans le systray -----------------
        protected:
        void __fastcall NotifyCallback ( TMessage &message );

        BEGIN_MESSAGE_MAP
        VCL_MESSAGE_HANDLER( AM_CALLBACK_MESSAGE, TMessage, NotifyCallback);
        END_MESSAGE_MAP(TForm);
        //----------------------------------------------------------------------


private:	// User declarations
public:		// User declarations

        // variables
        NOTIFYICONDATA    NI_Data;// pour la réduction dans le systry
        char Windows_Directory[MAXPATH];//le chemin complet du repertoire windows
        char System_Directory[MAXPATH];//le chemin complet du repertoire systèm "system32"
        char Current_Directory[MAXPATH];//le chemin du repertoire courant
        TStringList *Commands_List;

        // méthodes
        __fastcall TMain_Form(TComponent* Owner);
        void __fastcall Set_Default_Commands();// créer les commandes par defaut
        void __fastcall My_GetCurrentDirectory(char Current_Dir[MAXPATH]); // trouver le repertoire courant
};
//---------------------------------------------------------------------------
extern PACKAGE TMain_Form *Main_Form;
//---------------------------------------------------------------------------
#endif
