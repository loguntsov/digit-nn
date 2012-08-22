//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
    : TForm(Owner)
{
Number=0;
}
//---------------------------------------------------------------------------


void __fastcall TForm2::Button3Click(TObject *Sender)
{
    double dx=(Image1->Width)/S;
    double dy=(Image1->Height)/S;
    Image1->Canvas->Brush->Color=clWhite;
    Image1->Canvas->Brush->Style=bsSolid;
    Image1->Canvas->Rectangle(0,0,Image1->Width,Image1->Height);

    int num=0;
    for(int i=0;i<S;i++)
    {
        for(int j=0;j<S;j++)
        {
            double n=Form1->InList->Items[Number]->Data[num];
            if (n>0)
            {
                n=1-n;
                Image1->Canvas->Brush->Color=RGB(255*n,255*n,255*n);
                Image1->Canvas->Rectangle(i*dx,j*dy,i*dx+dx,j*dy+dy);
            }
        num++;
        }
    }
    Label1->Caption="";
    for(int i=0;i<10;i++)
        if (Form1->OutList->Items[Number]->Data[i]>0.5) Label1->Caption=Label1->Caption+IntToStr(i);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button2Click(TObject *Sender)
{
    if (Number<Form1->InList->Count-1)
    {
        Number++;
        Button3Click(Sender);
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button1Click(TObject *Sender)
{
    if (Number>0)
    {
        Number--;
        Button3Click(Sender);
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button4Click(TObject *Sender)
{
if (OpenDialog1->Execute()) {
    TFileStream *a=new TFileStream(OpenDialog1->FileName,fmOpenRead);
    Form1->InList->LoadFromStream(a);
    Form1->OutList->LoadFromStream(a);
    delete a;
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button6Click(TObject *Sender)
{
Form1->InList->Clear();
Form1->OutList->Clear();
Number=0;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button5Click(TObject *Sender)
{
if (SaveDialog1->Execute())
    {
        TFileStream *a=new TFileStream(SaveDialog1->FileName,fmCreate|fmOpenWrite);
        Form1->InList->SaveToStream(a);
        Form1->OutList->SaveToStream(a);
        delete a;
        }
}
//---------------------------------------------------------------------------
