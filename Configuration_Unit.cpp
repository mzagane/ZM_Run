
/*-----------------------------------------------------------------------------*
                fichier : Configuration_Unit.cpp                               *
  programmation : ZAAGANE Mohammed                                             *
  date   : dimanche 23 décembre 2007                                           *
  modification : vendredi 04 janvier 2008                                      *
*-----------------------------------------------------------------------------*/

//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Configuration_Unit.h"
#include "Main_Unit.h"
#include "Help_Unit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TConfiguration_Form *Configuration_Form;
//---------------------------------------------------------------------------
__fastcall TConfiguration_Form::TConfiguration_Form(TComponent* Owner)
        : TForm(Owner)
{
}
/*-----------------------------------------------------------------------------*
*        Click sur le Bouton "Parcourir"                                       *
*        pour selectioner le fichier                                           *
*-----------------------------------------------------------------------------*/
void __fastcall TConfiguration_Form::Parcourir_ButtonClick(TObject *Sender)
{
          if(OpenDialog1->Execute())
          {
                  Chemin_Edit->Text=OpenDialog1->FileName;
          }
}
//------------------------------------------------------------------------------

/*-----------------------------------------------------------------------------*
*        Click sur le Bouton "Ajouter"                                         *
*                                                                              *
*-----------------------------------------------------------------------------*/
void __fastcall TConfiguration_Form::Ajouter_ButtonClick(TObject *Sender)
{
          AnsiString temp,command;
          bool trouve=false;


          if(Command_Edit->Text!="" && Chemin_Edit->Text!="")// si les champs
          //non vide
          {
                  SetCurrentDirectory(Main_Form->Current_Directory);// le reprtoire
                  //courant = le repertoire où setrouve notre application
                  if(FileExists("command.cmnd"))// si le fichier de commande existe
                  {
                          TStringList *Commands_List = new TStringList();
                          Commands_List->LoadFromFile("command.cmnd");//chargement
                          // de la liste des commandes.

                          //chercher si la commande existe déja ou non----------
                          for(int i=0;i<Commands_List->Count;i++)// boucle pour
                          //parcourir tout la liste des commandes
                          {
                                  temp=Commands_List->Strings[i];
                                  command="";
                                  if(!temp.IsEmpty())
                                  {
                                           for(int j=1;j<temp.Length()+1;j++)
                                           {
                                                      if(temp[j]!='#')
                                                      {
                                                               command.Insert(temp[j],j);
                                                      }
                                                      else
                                                      {
                                                               break;
                                                      }
                                           }

                                           if(StrComp(Command_Edit->Text.c_str(),command.c_str())==0 || Command_Edit->Text=="rd" ||Command_Edit->Text=="cnfg" ||Command_Edit->Text=="?")// si la commande entrée existe dans la liste.
                                           {
                                                      trouve=true;
                                                      break;
                                           }
                                  }
                          }
                          //----------------------------------------------------

                          if(!trouve)// la commande n'existe pas déja.
                          {
                                  AnsiString entrie="";
                                  entrie=entrie+Command_Edit->Text+"#"+Chemin_Edit->Text+"#"+Prametres_Edit->Text+"#";
                                  Commands_List->Add(entrie);
                                  Commands_List->SaveToFile("command.cmnd");
                                  ShowMessage("commande ajoutée.");
                          }
                          else
                          {
                                  ShowMessage("Cette commande existe déja !");
                          }
                          delete Commands_List;
                  }
                  else
                  {
                          MessageDlg("Le fichier des commande est introuvable",mtError, TMsgDlgButtons() << mbOK, 0);
                  }
          }
          else
          {
                  ShowMessage("Les champs : 'commande' et 'chemin...' sont obligatoires, veuillez les remplir.");
          }
}
//------------------------------------------------------------------------------

/*-----------------------------------------------------------------------------*
*             Click sur le Bouton "Ok"                                         *
*                                                                              *
*-----------------------------------------------------------------------------*/
void __fastcall TConfiguration_Form::Ok_ButtonClick(TObject *Sender)
{
          if(AutoStar_CheckBox->Checked)
          {
                    AutoStart(Application->ExeName.c_str(),"ZM Run");// démarrage
                    //avec l'ordinateur
          }
          else
          {
                    Desactive_AutoStart("ZM Run");// désactiver le démarrage avec
                    //l'ordinateur.
          }
          Close();// fermer la fenêtre
}
//------------------------------------------------------------------------------

/*-----------------------------------------------------------------------------*
*             Click sur le Bouton "Aide"                                       *
*             Pour afficher la fenêtre de l'aide                               *
*-----------------------------------------------------------------------------*/
void __fastcall TConfiguration_Form::Help_ButtonClick(TObject *Sender)
{
          Help_Form->ShowModal();
}
//---------------------------------------------------------------------------

/*-----------------------------------------------------------------------------*
*             permet de démarrer notre application avec le démarrage           *
*             de l'ordinateur (créer une valeur dans la clé "Run" de registre) *
*-----------------------------------------------------------------------------*/
bool __fastcall TConfiguration_Form::AutoStart(char *filename,char *valeur)
{
       TRegistry *Reg = new TRegistry();
       Reg->RootKey = HKEY_LOCAL_MACHINE;

       if(Reg->OpenKey("Software\\Microsoft\\Windows\\CurrentVersion\\Run", false))
       {
               Reg->WriteString(valeur,filename);
               delete Reg;
               return true;
       }
       else
       {
               delete Reg;
               return false;
       }
}

/*-----------------------------------------------------------------------------*
*             Click sur le Bouton "Appliquer"                                  *
*                                                                              *
*-----------------------------------------------------------------------------*/
void __fastcall TConfiguration_Form::Appliquer_ButtonClick(TObject *Sender)
{
          if(AutoStar_CheckBox->Checked)
          {
                    AutoStart(Application->ExeName.c_str(),"ZM Run");
          }
          else
          {
                    Desactive_AutoStart("ZM Run");
          }
}
//------------------------------------------------------------------------------

/*-----------------------------------------------------------------------------*
*     permet de désactiver le démarrage de notre application avec le démarrage *
*     de l'ordinateur (supprimer une valeur dans la clé "Run" de registre)     *
*-----------------------------------------------------------------------------*/
bool __fastcall TConfiguration_Form::Desactive_AutoStart(char *valeur)
{
       TRegistry *Reg = new TRegistry();
       Reg->RootKey = HKEY_LOCAL_MACHINE;

       if(Reg->OpenKey("Software\\Microsoft\\Windows\\CurrentVersion\\Run", false))
       {
               if (Reg->DeleteValue(valeur))
               {
                       delete Reg;
                       return true;
               }
               else
               {
                       delete Reg;
                       return false;
               }

       }
       else
       {
               delete Reg;
               return false;
       }
}
//------------------------------------------------------------------------------

/*-----------------------------------------------------------------------------*
*      l'evenement OnFormActivate de la Form : Configuration_Form              *
*-----------------------------------------------------------------------------*/
void __fastcall TConfiguration_Form::FormActivate(TObject *Sender)
{
       TRegistry *Reg = new TRegistry();
       Reg->RootKey = HKEY_LOCAL_MACHINE;

       if(Reg->OpenKey("Software\\Microsoft\\Windows\\CurrentVersion\\Run", false))
       {
               if(Reg->ValueExists("ZM Run"))
               {
                       AutoStar_CheckBox->Checked=true;
               }
               else
               {
                       AutoStar_CheckBox->Checked=false;
               }
       }
}
//------------------------------------------------------------------------------

