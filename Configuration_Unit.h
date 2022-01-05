//---------------------------------------------------------------------------

#ifndef Configuration_UnitH
#define Configuration_UnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include <Dialogs.hpp>
#include <Registry.hpp>
//---------------------------------------------------------------------------
class TConfiguration_Form : public TForm
{
__published:	// IDE-managed Components
        TGroupBox *GroupBox1;
        TEdit *Command_Edit;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TEdit *Prametres_Edit;
        TButton *Ok_Button;
        TButton *Help_Button;
        TButton *Appliquer_Button;
        TGroupBox *GroupBox2;
        TBevel *Bevel1;
        TButton *Ajouter_Button;
        TEdit *Chemin_Edit;
        TButton *Parcourir_Button;
        TOpenDialog *OpenDialog1;
        TCheckBox *AutoStar_CheckBox;
        void __fastcall Parcourir_ButtonClick(TObject *Sender);
        void __fastcall Ajouter_ButtonClick(TObject *Sender);
        void __fastcall Ok_ButtonClick(TObject *Sender);
        void __fastcall Help_ButtonClick(TObject *Sender);
        void __fastcall Appliquer_ButtonClick(TObject *Sender);
        void __fastcall FormActivate(TObject *Sender);
private:	// User declarations
public:		// User declarations

        bool __fastcall AutoStart(char *filename,char *cle);//créer une valeur dans Run du registre
        bool __fastcall Desactive_AutoStart(char *valeur);// supprimer une valeur dans Run du registre
        __fastcall TConfiguration_Form(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TConfiguration_Form *Configuration_Form;
//---------------------------------------------------------------------------
#endif
