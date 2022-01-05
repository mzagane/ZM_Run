//---------------------------------------------------------------------------

#ifndef Help_UnitH
#define Help_UnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class THelp_Form : public TForm
{
__published:	// IDE-managed Components
        TMemo *Memo1;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label5;
        TLabel *Label6;
        TButton *Fermer_Button;
        void __fastcall Label4Click(TObject *Sender);
        void __fastcall Fermer_ButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall THelp_Form(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE THelp_Form *Help_Form;
//---------------------------------------------------------------------------
#endif
