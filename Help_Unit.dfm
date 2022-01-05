object Help_Form: THelp_Form
  Left = 229
  Top = 100
  BorderStyle = bsDialog
  Caption = 'Aide'
  ClientHeight = 465
  ClientWidth = 470
  Color = clAppWorkSpace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 136
    Top = 340
    Width = 193
    Height = 22
    Caption = 'ZM  Run v1.04.01.2008'
    Font.Charset = ARABIC_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Times New Roman'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label2: TLabel
    Left = 32
    Top = 373
    Width = 188
    Height = 13
    Caption = 'Programmation : ZAAGANE Mohammed'
  end
  object Label3: TLabel
    Left = 280
    Top = 397
    Width = 110
    Height = 13
    Caption = 'zagmoh2005@yahoo.fr'
  end
  object Label4: TLabel
    Left = 264
    Top = 373
    Width = 187
    Height = 13
    Cursor = crHandPoint
    Caption = 'http://zaagane-mohammed.ifrance.com'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlue
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsUnderline]
    ParentFont = False
    OnClick = Label4Click
  end
  object Label5: TLabel
    Left = 232
    Top = 373
    Width = 28
    Height = 13
    Caption = '- site :'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clNavy
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label6: TLabel
    Left = 232
    Top = 397
    Width = 42
    Height = 13
    Caption = '- e-mail : '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clNavy
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Memo1: TMemo
    Left = 28
    Top = 14
    Width = 417
    Height = 315
    Color = clBlack
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clLime
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    Lines.Strings = (
      
        '                        Bien venue dans l'#39'aide de ZM Run v 1.04.' +
        '01.2008'
      ''
      '1) La liste des commandes par defaut'
      
        ' ============================                                   ' +
        '       '
      ' '
      'les commandes externes'
      '--------------------------------------'
      ' - cmd : pour ouvrir l'#39'invite des commandes de windows.       '
      ' - regedit : pour lancer l'#39'editeur de la base de registre.'
      ' - msconfig :pour lancer l'#39'utilitaire de configuration syst'#232'me.'
      ' - pnt : pour lancer MS Paint.'
      ' - notepad : pour lancer bloc-notes de windows'
      ' - shutdown : pour arr'#232'ter l'#39'ordinateur'
      ''
      ''
      'les commandes internes :'
      '----------------------------------------'
      
        '- cnfg : pour afficher la fen'#234'tre de configuration (ajouter des ' +
        'nouvelles '
      '            commandes , changer les options de l'#39'application).'
      '- rd : r'#233'duire l'#39'application dans le system tray.'
      '- exit : pour quitter l'#39'application'
      '- ? : afficher cette fen'#234'tre de l'#39'aide'
      ''
      '2) comment ajouter une commande?'
      '============================'
      ''
      
        #13'1- Tapez la commande : "cnfg"  ou cliquez sur le bouton droit d' +
        'e la souri et '
      
        '     choisissez  "configuration" dans le popup menu pour affiche' +
        'r la fen'#234'tre de '
      '     configuration.'
      
        '2-  Dans la partie "nouvelle commande" de la fen'#234'tre de configur' +
        'ation  '
      '       remplissez les champs et cliquez sur le bouton ajouter.  '
      'exemple '#13':'
      'pour ajouter une commande "restart" qui red'#233'marer l'#39'ordinateur :'
      
        '- dans le champs "commande" on met : restart (le nom de la comma' +
        'nde)'
      
        '- dans le champs "chemin..." on met : x:\windows\system32\shutdo' +
        'wn.exe o'#249' x '
      'le nom de lecteur o'#249' se trouve le repertoir windows.'
      '- dans le champ "param'#232'tres..." on met : -r -f -t 00'
      '- et on clique sur le bouton ajouter.')
    ParentFont = False
    ReadOnly = True
    ScrollBars = ssVertical
    TabOrder = 0
  end
  object Fermer_Button: TButton
    Left = 153
    Top = 432
    Width = 145
    Height = 25
    Caption = '&Fermer'
    TabOrder = 1
    OnClick = Fermer_ButtonClick
  end
end
