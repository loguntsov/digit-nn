//---------------------------------------------------------------------------
#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
#include "Neuro.h"
#include <ComCtrls.hpp>

const S=10;
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TMainMenu *MainMenu1;
    TPopupMenu *PopupMenu1;
    TMenuItem *N1;
    TMenuItem *N2;
    TMenuItem *N3;
    TMenuItem *N4;
    TMenuItem *N5;
    TMenuItem *N6;
    TMenuItem *N7;
    TMenuItem *N8;
    TMenuItem *N9;
    TMenuItem *N10;
    TButton *Button1;
    TButton *Button2;
    TEdit *Edit1;
    TLabel *Label1;
    TButton *Button3;
    TImage *Image1;
    TButton *Button4;
    TLabel *Label2;
    TEdit *Edit2;
    TButton *Button5;
    TProgressBar *ProgressBar1;
    TButton *Button6;
    TEdit *Edit3;
    void __fastcall Image1MouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void __fastcall Image1MouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
    void __fastcall Image1MouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void __fastcall N2Click(TObject *Sender);
    
    void __fastcall Button1Click(TObject *Sender);
    void __fastcall Button2Click(TObject *Sender);
    void __fastcall Button4Click(TObject *Sender);
    void __fastcall Button5Click(TObject *Sender);
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall Button6Click(TObject *Sender);
    void __fastcall FormDestroy(TObject *Sender);
private:	// User declarations
    int xmax,xmin,ymax,ymin;
public:		// User declarations
    __fastcall TForm1(TComponent* Owner);
    __fastcall ~TForm1();
    NeuroNet *Net;
    NData * Kadr(void);
    NDataList *InList,*OutList;
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
