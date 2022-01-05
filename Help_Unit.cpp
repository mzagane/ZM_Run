/*-----------------------------------------------------------------------------*
*                fichier : Help_Unit.cpp                                       *
*  programmation : ZAAGANE Mohammed                                            *
*  date   : dimanche 23 décembre 2007                                          *
*  modification : vendredi 04 janvier 2008                                     *
*-----------------------------------------------------------------------------*/

//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Help_Unit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
THelp_Form *Help_Form;
//---------------------------------------------------------------------------
__fastcall THelp_Form::THelp_Form(TComponent* Owner)
        : TForm(Owner)
{
}
/*-----------------------------------------------------------------------------*
*    Click sur le label                                                        *
*    pour afficher le site "http://zaagane-mohammed.ifrance.com"               *
*-----------------------------------------------------------------------------*/
void __fastcall THelp_Form::Label4Click(TObject *Sender)
{
          ShellExecute(0, "open","http://zaagane-mohammed.ifrance.com",0,0,SW_SHOWDEFAULT);
}
//---------------------------------------------------------------------------

/*-----------------------------------------------------------------------------*
*                     Click sur le bouton Fermer                               *
*-----------------------------------------------------------------------------*/
void __fastcall THelp_Form::Fermer_ButtonClick(TObject *Sender)
{
          Close();
}
//---------------------------------------------------------------------------

