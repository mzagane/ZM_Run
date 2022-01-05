object Configuration_Form: TConfiguration_Form
  Left = 695
  Top = 243
  BorderStyle = bsDialog
  Caption = 'Configuration'
  ClientHeight = 377
  ClientWidth = 321
  Color = clAppWorkSpace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnActivate = FormActivate
  PixelsPerInch = 96
  TextHeight = 13
  object Bevel1: TBevel
    Left = 8
    Top = 96
    Width = 309
    Height = 5
    Shape = bsTopLine
  end
  object GroupBox1: TGroupBox
    Left = 8
    Top = 112
    Width = 313
    Height = 217
    Caption = 'Nouvelle commande : '
    Color = clBlack
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clLime
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentColor = False
    ParentFont = False
    TabOrder = 0
    object Label1: TLabel
      Left = 8
      Top = 32
      Width = 62
      Height = 13
      Caption = 'Commande : '
    end
    object Label2: TLabel
      Left = 8
      Top = 88
      Width = 237
      Height = 13
      Caption = 'Chemin complet du programme  ou du  document :'
    end
    object Label3: TLabel
      Left = 8
      Top = 152
      Width = 105
      Height = 13
      Caption = 'Param'#232'tres '#224' passer : '
    end
    object Command_Edit: TEdit
      Left = 8
      Top = 52
      Width = 121
      Height = 21
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
    end
    object Chemin_Edit: TEdit
      Left = 8
      Top = 112
      Width = 298
      Height = 21
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
    end
    object Prametres_Edit: TEdit
      Left = 8
      Top = 168
      Width = 121
      Height = 21
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 2
    end
    object Ajouter_Button: TButton
      Left = 208
      Top = 168
      Width = 89
      Height = 25
      Caption = 'Ajo&uter'
      TabOrder = 3
      OnClick = Ajouter_ButtonClick
    end
    object Parcourir_Button: TButton
      Left = 247
      Top = 84
      Width = 61
      Height = 24
      Caption = '&Parcourir...'
      TabOrder = 4
      OnClick = Parcourir_ButtonClick
    end
  end
  object Ok_Button: TButton
    Left = 8
    Top = 344
    Width = 89
    Height = 25
    Caption = '&Ok'
    TabOrder = 1
    OnClick = Ok_ButtonClick
  end
  object Help_Button: TButton
    Left = 112
    Top = 344
    Width = 97
    Height = 25
    Caption = '&Aide'
    TabOrder = 2
    OnClick = Help_ButtonClick
  end
  object Appliquer_Button: TButton
    Left = 216
    Top = 344
    Width = 89
    Height = 25
    Caption = 'Appli&quer'
    TabOrder = 3
    OnClick = Appliquer_ButtonClick
  end
  object GroupBox2: TGroupBox
    Left = 8
    Top = 16
    Width = 311
    Height = 65
    Caption = 'Options : '
    Color = clDefault
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clLime
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentColor = False
    ParentFont = False
    TabOrder = 4
    object AutoStar_CheckBox: TCheckBox
      Left = 11
      Top = 30
      Width = 185
      Height = 17
      Caption = 'D'#233'marrage avec l'#39'ordinateur'
      Color = clLime
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentColor = False
      ParentFont = False
      TabOrder = 0
    end
  end
  object OpenDialog1: TOpenDialog
    Left = 256
    Top = 32
  end
end
