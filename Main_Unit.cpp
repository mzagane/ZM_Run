/*-----------------------------------------------------------------------------*
                fichier : Main_Unit.cpp
  programmation : ZAAGANE Mohammed
  date   : dimanche 23 décembre 2007
  modification :vendredi 04 janvier 2008
         - ajouter des commands par default
         - régler des problèmes
         - ajouter des commentaires au source
         
  remarque:
  - la partie de systray appartir: -http://www.cppfrance.com/codes/CREEZ-VOTRE-PREMIERE-TRAY-ICON-CODE-TRES-SIMPLE_36629.aspx
                         -par : kalvados

*-----------------------------------------------------------------------------*/



//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Main_Unit.h"
#include "Configuration_Unit.h"
#include "Help_Unit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMain_Form *Main_Form;
//---------------------------------------------------------------------------

__fastcall TMain_Form::TMain_Form(TComponent* Owner)
        : TForm(Owner)
{
}


/*-----------------------------------------------------------------------------*
*                créer les commande (externes) par defaut                      *
*-----------------------------------------------------------------------------*/
void __fastcall TMain_Form::Set_Default_Commands()
{
         GetWindowsDirectory(Windows_Directory,MAXPATH);// obtenir le chemin
         //complet du repertoire de windows (exemple : d:\windows)
         GetSystemDirectory(System_Directory,MAXPATH);// obtenir le chemin
         //complet du repetoire sytem de windows (exemple : d:\windows\system32)

         //GetCurrentDirectory(MAXPATH,Current_Directory);
         My_GetCurrentDirectory(Current_Directory);// obtenir le chemin
         //complet du repertoire courant
         //AnsiString temp=Application->ExeName;

         Commands_List = new TStringList();// la liste des commandes

         if(!FileExists("command.cmnd"))//si le fichier des command est introuvable
         {
                  //------------------- l'invite de commandes ------------------
                  char temp[MAXPATH];
                  strcpy(temp,"cmd#");           // la commande

                  strcat(temp,System_Directory);//  le chemein et le
                  strcat(temp,"\\cmd.exe#");    //  nom du fichier

                  strcat(temp,"#");             // prametre a passer (dans ce cas
                                                //  pas de paramètres a passer).

                  Commands_List->Add(temp);

                  // le caractère # pour séparer entre la commande et le chemin
                  // complet de fichiet et les paramètres à passer.
                  // dans ce cas l'entrée à ajouter est: cmd#d:\windows\cmd.exe##

                  //------------------------------------------------------------

                  //------------------ l'éditeur de la base de registre---------
                  strcpy(temp,"regedit#");
                  strcat(temp,Windows_Directory);
                  strcat(temp,"\\regedit.exe#");
                  strcat(temp,"#");
                  Commands_List->Add(temp);
                  //------------------------------------------------------------

                  //------------------ configuration système--------------------
                  strcpy(temp,"msconfig#");
                  strcat(temp,Windows_Directory);
                  strcat(temp,"\\pchealth\\helpctr\\binaries\\msconfig.exe#");
                  strcat(temp,"#");
                  Commands_List->Add(temp);
                  //------------------------------------------------------------

                  //----------------- arrèter l'ordinateur----------------------
                  strcpy(temp,"shutdown#");
                  strcat(temp,System_Directory);
                  strcat(temp,"\\shutdown.exe#");
                  strcat(temp," -s -f -t 00#");
                  Commands_List->Add(temp);
                  //------------------------------------------------------------

                  //----------------- note pade --------------------------------
                  strcpy(temp,"notepad#");
                  strcat(temp,Windows_Directory);
                  strcat(temp,"\\notepad.exe#");
                  strcat(temp,"#");
                  Commands_List->Add(temp);
                  //------------------------------------------------------------

                  //------------------ MS Paint --------------------------------
                  strcpy(temp,"pnt#");
                  strcat(temp,System_Directory);
                  strcat(temp,"\\mspaint.exe#");
                  strcat(temp,"#");
                  Commands_List->Add(temp);
                  //------------------------------------------------------------

                  Commands_List->SaveToFile("command.cmnd");// enregister la liste
                  // des commandes dans un fichier (texte)
         }
         delete Commands_List;
}
//------------------------------------------------------------------------------

void __fastcall TMain_Form::My_GetCurrentDirectory(char Current_Dir[MAXPATH])
{
          char drive[MAXDRIVE];
          char dir[MAXDIR];
          char file[MAXFILE];
          char ext[MAXEXT];

          fnsplit(Application->ExeName.c_str(),drive,dir,file,ext);
          strcpy(Current_Dir,drive);
          strcat(Current_Dir,dir);
}
//------------------------------------------------------------------------------

/*-----------------------------------------------------------------------------*
*          l'evenement OnCreate de La Form : Main_Form                         *
*-----------------------------------------------------------------------------*/
void __fastcall TMain_Form::FormCreate(TObject *Sender)
{
         Main_Form->Left=0;//
         Main_Form->Top=0;// pour positionner notre fenêtre principale au coin
         //superieur de gauche

         Command_Edit->Parent=Main_Form;//pour régler un problème lie au popupmenu
         Set_Default_Commands();//créer les commande (externes) par defaut :
         //regedit,cmd,msconfig,shutdown,...

}
//------------------------------------------------------------------------------


/*-----------------------------------------------------------------------------*
*        click sur l'item "réduire" dans le popupmenu de la fenêtre principale *
*        (panel1)                                                              *
*-----------------------------------------------------------------------------*/
void __fastcall TMain_Form::Rduir1Click(TObject *Sender)
{

         Main_Form->Hide();//cacher la fenêtre principale

         NI_Data.cbSize = sizeof( NOTIFYICONDATA );
         // Cela permet à Windows de savoir avec quelle version de la structure
         // on souhaite travailler
         NI_Data.hWnd = this->Handle;
         // C'est à ce handle que windows va envoyer les messages provenant de
         // l'icône : permet de gérer les cliks, etc.
         NI_Data.uID = 0;
         // C'est l'identifiant de l'icône dans l'application. Cela permet à
         // Windows de faire la distinction entre différents icônes de notification
         // que l'application a crée.
         NI_Data.hIcon = Application->Icon->Handle;
         // Par défaut notre icone de notification aura le même icone que
         // l'application.
         NI_Data.uCallbackMessage = AM_CALLBACK_MESSAGE;
         //Permet d'intercepter les messages venant du systray (cliks...)
         NI_Data.uFlags = NIF_ICON | NIF_MESSAGE | NIF_TIP;
         strcpy(NI_Data.szTip, "ZM Run version 1.04.01.2008");
         //Permet de définir le texte de l'infobulle...
         Shell_NotifyIcon(NIM_ADD,&NI_Data);


}
//------------------------------------------------------------------------------

void __fastcall TMain_Form::NotifyCallback(TMessage &message)
{
          if ( message.WParam == 0 )
          // WParam contient l'indice de l'icone de l'appication.
          // En effet une application peut avoir plusieurs icones de notification
          // c'est l'indice que nous avison mis dans uID de la structure de type
          // NOTIFYICONDATA
          {
                 //------------------- double click ----------------------------
                  if ( message.LParam == WM_LBUTTONDBLCLK ) //WM_RBUTTONUP, WM_LBUTTONDOWN...
                  {
                            Main_Form->Show();
                            //Sleep(100); //pas indispensable mais si vous avez
                                          //comme moi l'icône de MSN
		                          //juste à côté de "la votre" vous comp
                                          //rendrez l'utilité :)
                            NI_Data.uFlags = 0;
                            Shell_NotifyIcon(NIM_DELETE,&NI_Data);
                  }
                  //------------------------------------------------------------

                  //-------------------  click boutton droit de la sourri-------
                  if ( message.LParam == WM_RBUTTONUP ) //réagit quand on relâche le clik droit
                  {
                            SysTry_PopupMenu->Popup( Mouse->CursorPos.x, Mouse->CursorPos.y );
                            //ouvre un menu popup là où se trouve la souris ;)
                  }
                  //------------------------------------------------------------
          }
}

//------------------------------------------------------------------------------

/*-----------------------------------------------------------------------------*
*        click sur l'item "Quitter" dans le popupmenu de la fenêtre principale *
*       (panel1)                                                               *
*-----------------------------------------------------------------------------*/
void __fastcall TMain_Form::Quitter1Click(TObject *Sender)
{
          if(MessageDlg("Voulez - vous vraiment quittez l'application ?",mtConfirmation,TMsgDlgButtons() << mbYes <<mbNo,0)==mrYes)
          {
                  Application->Terminate();//quitter l'application
          }
}
//------------------------------------------------------------------------------

/*-----------------------------------------------------------------------------*
*        click sur l'item "Quitter" dans le popupmenu de systray               *
*-----------------------------------------------------------------------------*/
void __fastcall TMain_Form::Quitter2Click(TObject *Sender)
{
          if(MessageDlg("Voulez - vous vraiment quittez l'application ?",mtConfirmation,TMsgDlgButtons() << mbYes <<mbNo,0)==mrYes)
          {
                  Application->Terminate();//quitter l'application
          }
}
//------------------------------------------------------------------------------

/*-----------------------------------------------------------------------------*
*        click sur l'item "Agrandir" dans le popupmenu de systray              *
*-----------------------------------------------------------------------------*/
void __fastcall TMain_Form::Agrandir1Click(TObject *Sender)
{
          Main_Form->Show();
}
//------------------------------------------------------------------------------

/*-----------------------------------------------------------------------------*
*        l'evenement OnMouseDown de Panel1                                     *
*        pour déplacer notre fenêtre principale                                *
*-----------------------------------------------------------------------------*/
void __fastcall TMain_Form::Panel1MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
          ReleaseCapture();
          Panel1->Cursor=crSizeAll;//changer le curseur de la souri
          SendMessage(Handle, WM_SYSCOMMAND, 0xF012, 0);
          Panel1->Cursor=crDefault;// restaurer le curseur par defaut de la souri
}
//---------------------------------------------------------------------------

/*-----------------------------------------------------------------------------*
*        l'evenement OnKeyPress de l'edit : Command_Edit                       *
*                                                                              *
*-----------------------------------------------------------------------------*/
void __fastcall TMain_Form::Command_EditKeyPress(TObject *Sender,
      char &Key)
{

         //char *command="";// la commande
         AnsiString  chemin;//le chemin du fichier exécutable.
         AnsiString parametres;//les paramètres à passer vers l'application.
         AnsiString temp,command;
         bool execute=false;//si egale true la commande est executée.


         Commands_List = new TStringList();

         if(FileExists("command.cmnd"))// si le fichier des commande est trouvable
         {
                  Commands_List->LoadFromFile("command.cmnd");// chargement de
                  //la liste des commandes.
         }
         else // si le fichier des commande est introuvable
         {
                  int hndl=FileCreate("command.cmnd",0);
                  FileClose(hndl);
                  Commands_List->LoadFromFile("command.cmnd");// chargement de
                  //la liste des commandes.
         }

         if(Key==VK_RETURN && Command_Edit->Text!="" )// si la touche pressée est
         //"entrée" et le Edit non vide
         {
                  execute=false;
                  for(int i=0;i<Commands_List->Count;i++)// boucle pour parcourir
                  // tout la liste des commandes
                  {
                            temp=Commands_List->Strings[i];
                            command="";
                            if(!temp.IsEmpty())// si l'entrée est non vide
                            {
                                     //---extraction de la commande de l'entrée
                                     int index=0;
                                     for(int j=1;j<temp.Length()+1;j++)
                                     {
                                              if(temp[j]!='#')
                                              {
                                                      command.Insert(temp[j],j);
                                              }
                                              else
                                              {
                                                      index=j;
                                                      break;
                                              }
                                     }
                                     //-----------------------------------------

                                     if(StrComp(Command_Edit->Text.c_str(),command.c_str())==0)// si la commande entrée existe dans la liste.
                                     {
                                              //extraction du chemin de fichier-
                                              int k=1;
                                              for(int j=index+1;j<temp.Length()+1;j++)
                                              {
                                                      if(temp[j]!='#')
                                                      {
                                                               chemin.Insert(temp[j],k);
                                                               k++;
                                                      }
                                                      else
                                                      {
                                                               index=j;
                                                               break;
                                                      }
                                              }
                                              //--------------------------------

                                              //extraction des paramètres-------
                                              k=1;
                                              for(int j=index+1;j<temp.Length()+1;j++)
                                              {
                                                      if(temp[j]!='#')
                                                      {
                                                               parametres.Insert(temp[j],k);
                                                               k++;
                                                      }
                                                      else
                                                      {
                                                               break;
                                                      }
                                              }
                                              //--------------------------------

                                              /*if(parametres=="")
                                              {
                                                      //parametres=NULL;
                                              }*/
                                              execute=true;
                                              ShellExecute(0, "open",chemin.c_str(),parametres.c_str(),0,SW_SHOWNORMAL);
                                              break;
                                     }
                            }
                   }
                   if(!execute)// si la commande introuvable dans la liste des commandes
                   {
                            if(Command_Edit->Text=="exit" || Command_Edit->Text=="rd" ||Command_Edit->Text=="cnfg" ||Command_Edit->Text=="?")// si la commande entrée parmi les commande interne
                            {
                                     if(Command_Edit->Text=="exit")// la commande interne pour fermer l'application
                                     {
                                             Application->Terminate();
                                     }

                                     if(Command_Edit->Text=="rd")// la commande interne pour la réduction dans le system tray
                                     {
                                             Rduir1Click(Main_Form);// la réduction dans le system tray
                                     }

                                     if(Command_Edit->Text=="cnfg")// la commande interne pour afficher la fenêtre de configuration
                                     {
                                             Configuration_Form->Show(); //afficher la fenêtre de configuration
                                     }

                                     if(Command_Edit->Text=="?")// la commande interne pour afficher la fenêtre de l'aide
                                     {
                                             Help_Form->ShowModal(); //afficher la fenêtre de l'aide
                                     }
                             }
                             else // nouvelle commande
                             {

                                     if(MessageDlg("La Commande \"" +Command_Edit->Text+"\" est introuvable. Voulez - vous ajoutez cette commande à la lite des commandes ?",mtInformation, TMsgDlgButtons() << mbYes << mbNo, 0)==mrYes)
                                     {
                                             Configuration_Form->Command_Edit->Text=Command_Edit->Text;
                                             Configuration_Form->ShowModal();
                                     }
                             }
                   }
          }
          delete Commands_List;
}
//------------------------------------------------------------------------------

/*-----------------------------------------------------------------------------*
*  click sur l'item "Configuration" dans le popupmenu de la fenêtre principale *
*   (panel1)                                                                   *
*        pour afficher la fenêtre de configuration                             *
*-----------------------------------------------------------------------------*/
void __fastcall TMain_Form::Configuration1Click(TObject *Sender)
{
          Configuration_Form->Show();
}
//------------------------------------------------------------------------------

/*-----------------------------------------------------------------------------*
*        click sur l'item "Configuration" dans le popupmenu de systray         *
*        pour afficher la fenêtre de configuration                             *
*-----------------------------------------------------------------------------*/
void __fastcall TMain_Form::Configuration2Click(TObject *Sender)
{
          Configuration_Form->Show();
}
//------------------------------------------------------------------------------

/*-----------------------------------------------------------------------------*
*        click sur l'item "Aide" dans le popupmenu de la fenêtre principale    *
*       (panel1)
*       pour afficher la fenêtre de l'aide                                     *
*-----------------------------------------------------------------------------*/
void __fastcall TMain_Form::Aide1Click(TObject *Sender)
{
          Help_Form->ShowModal();
}
//------------------------------------------------------------------------------

/*-----------------------------------------------------------------------------*
*        click sur l'item "Aide" dans le popupmenu de systray                  *
*       pour afficher la fenêtre de l'aide                                     *
*-----------------------------------------------------------------------------*/
void __fastcall TMain_Form::Aide2Click(TObject *Sender)
{
          Help_Form->ShowModal();
}
//------------------------------------------------------------------------------

/*-----------------------------------------------------------------------------*
*        click sur le bouton "<->" ">-<"                                       *
*-----------------------------------------------------------------------------*/
void __fastcall TMain_Form::Agrandir_SpeedButtonClick(TObject *Sender)
{
          if(Agrandir_SpeedButton->Caption=="<->")
          {
                   Main_Form->Width=Screen->Width;
                   Panel1->Width=Screen->Width;
                   Agrandir_SpeedButton->Caption=">-<";

          }

          else if(Agrandir_SpeedButton->Caption==">-<")
          {
                   Main_Form->Width=164;
                   Panel1->Width=164;
                   Agrandir_SpeedButton->Caption="<->";

          }
}
//---------------------------------------------------------------------------



