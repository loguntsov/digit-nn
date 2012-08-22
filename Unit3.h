//---------------------------------------------------------------------------
#ifndef Unit3H
#define Unit3H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "cspin.h"
#include <Chart.hpp>
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
#include <Series.hpp>
#include <TeEngine.hpp>
#include <TeeProcs.hpp>
#include "CSPIN.h"
//---------------------------------------------------------------------------
class TForm3 : public TForm
{
__published:	// IDE-managed Components
    TPanel *Panel1;
    TButton *Button1;
    TButton *Button2;
    TOpenDialog *OpenDialog1;
    TSaveDialog *SaveDialog1;
    TChart *Chart1;
    TBarSeries *Series1;
    TLabel *Label1;
    TCSpinEdit *CSpinEdit1;
    TTimer *Timer1;
    void __fastcall Button1Click(TObject *Sender);
    void __fastcall Button2Click(TObject *Sender);
    void __fastcall FormActivate(TObject *Sender);
    void __fastcall CSpinEdit1Change(TObject *Sender);
    void __fastcall FormDeactivate(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TForm3(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm3 *Form3;
//---------------------------------------------------------------------------
#endif
