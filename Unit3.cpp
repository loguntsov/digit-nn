//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit3.h"
#include "Unit1.h"
#include <math.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cspin"
#pragma link "CSPIN"
#pragma resource "*.dfm"
TForm3 *Form3;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Button1Click(TObject *Sender)
{
if (OpenDialog1->Execute())
    {
    Form1->Net->LoadFromFile(OpenDialog1->FileName);
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Button2Click(TObject *Sender)
{
if (SaveDialog1->Execute())
    {
    Form1->Net->SaveToFile(SaveDialog1->FileName);
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm3::FormActivate(TObject *Sender)
{
CSpinEdit1->MaxValue=Form1->Net->NLayer-1;
CSpinEdit1Change(this);
Timer1->Enabled=true;
}
//---------------------------------------------------------------------------
void __fastcall TForm3::CSpinEdit1Change(TObject *Sender)
{
int n=CSpinEdit1->Value;
Series1->Clear();
for(int i=0;i<Form1->Net->Layer[n]->Count;i++)
{
    double sum=0;
    for(int j=0;j<Form1->Net->Layer[n]->Items[i]->LOut->Count;j++)
    {
    sum=sum+Form1->Net->Layer[n]->Items[i]->LOut->Items[j]->Link;
    }
    Series1->AddXY(i,sum,"",clTeeColor);
}
}
//---------------------------------------------------------------------------
void __fastcall TForm3::FormDeactivate(TObject *Sender)
{
Timer1->Enabled=false;    
}
//---------------------------------------------------------------------------

