object Main_Form: TMain_Form
  Left = 114
  Top = 189
  BorderStyle = bsNone
  Caption = 'My run'
  ClientHeight = 33
  ClientWidth = 169
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsStayOnTop
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 169
    Height = 33
    BevelWidth = 3
    Color = clBlack
    PopupMenu = Tools_PopupMenu
    TabOrder = 0
    OnMouseDown = Panel1MouseDown
    object Agrandir_SpeedButton: TSpeedButton
      Left = 108
      Top = 6
      Width = 34
      Height = 21
      Caption = '<->'
      Flat = True
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      OnClick = Agrandir_SpeedButtonClick
    end
    object Command_Edit: TEdit
      Left = 6
      Top = 6
      Width = 99
      Height = 21
      Color = clBlack
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      OnKeyPress = Command_EditKeyPress
    end
  end
  object Tools_PopupMenu: TPopupMenu
    Left = 48
    object Rduir1: TMenuItem
      Caption = '&R'#233'duire'
      OnClick = Rduir1Click
    end
    object Aide2: TMenuItem
      Caption = 'Ai&de'
      OnClick = Aide2Click
    end
    object Configuration2: TMenuItem
      Caption = '&Configuration'
      OnClick = Configuration2Click
    end
    object Quitter1: TMenuItem
      Caption = '&Quitter'
      OnClick = Quitter1Click
    end
  end
  object SysTry_PopupMenu: TPopupMenu
    Left = 72
    object Agrandir1: TMenuItem
      Caption = '&Agrandir'
      OnClick = Agrandir1Click
    end
    object Aide1: TMenuItem
      Caption = 'Ai&de'
      OnClick = Aide1Click
    end
    object Configuration1: TMenuItem
      Caption = '&Configuration'
      OnClick = Configuration1Click
    end
    object Quitter2: TMenuItem
      Caption = '&Quitter'
      OnClick = Quitter2Click
    end
  end
end
