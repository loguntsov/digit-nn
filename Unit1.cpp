//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
#include "Neuro.h"
#include <math.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
}
__fastcall TForm1::~TForm1()
{
}
//---------------------------------------------------------------------------
bool state=false;
void __fastcall TForm1::Image1MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
if (Button==mbLeft) {
                    state=true;
                    Image1->Canvas->MoveTo(X,Y);
                    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image1MouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
if (state) {
            Image1->Canvas->LineTo(X,Y);
            if (xmax<X) xmax=X;
            if (ymax<Y) ymax=Y;
            if (xmin>X) xmin=X;
            if (ymin>Y) ymin=Y;
            }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Image1MouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
state=false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N2Click(TObject *Sender)
{
Image1->Canvas->Brush->Color=clWhite;
Image1->Canvas->Pen->Color=clWhite;
Image1->Canvas->Rectangle(0,0,Image1->Width,Image1->Height);
Image1->Canvas->Pen->Color=clBlack;
xmax=ymax=0;
xmin=ymin=10000;
}
//---------------------------------------------------------------------------

NData * TForm1::Kadr(void)
{
    int num=0;
    NData *Data=new NData(S*S);
    double dx=double(xmax-xmin)/(S);
    double dy=double(ymax-ymin)/(S);
    double max=0;
    for(int i=0;i<S;i++)
    {
        for(int j=0;j<S;j++)
        {
            int fl=0;
            for(int k=0;k<=dx;k++)
            {
                for(int l=0;l<=dy;l++)
                {
                    if (Image1->Canvas->Pixels[double(dx*i+xmin+k)+0.9999][double(dy*j+ymin+l)+0.9999]==clBlack) fl++;
                    //Image1->Canvas->Pixels[xmin+dx*i+k][ymin+dy*j+l]=clWhite;
                    //Application->ProcessMessages ();
                }
            }
            Data->Data[num]=fl;
            if (max<fl) max=fl;
            num++;
        }
    }
    for(int i=0;i<S*S;i++) Data->Data[i]=Data->Data[i]/max;
    return Data;
}


void __fastcall TForm1::Button1Click(TObject *Sender)
{
    NData *D=Kadr();
    NData *data=Net->TestNData(D);
    delete D;
    Label1->Caption="";
    for(int i=0;i<10;i++)
        if (data->Data[i]>Edit3->Text.ToDouble()) Label1->Caption=Label1->Caption+IntToStr(i);
    delete data;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
    Button2->Enabled=false;
    if (Edit2->Text!="") Net->kpr=Edit2->Text.ToDouble();
    double e0=10000000000;
    Label1->Caption="";
    int j0=0,n0=0;
    ProgressBar1->Max=InList->Count;
    while (e0>0.5)
    {
        j0=0;
        for (int i=0;i<InList->Count;i++)
        {
            Net->LearnNData(InList->Items[i],OutList->Items[i]);
            if (i%30==0) Application->ProcessMessages ();
        }
    double e=0,e1=0;
    for(int i=0;i<InList->Count;i++)
    {
        NData *Dat=Net->TestNData(InList->Items[i]);
        e1=0;
        for (int j=0;j<10;j++)
        {
            double x=fabs(Dat->Data[j]-OutList->Items[i]->Data[j]);
            e1=e1+x;
        }
        e=e+e1;
        delete Dat;
        if (e1<=0.05) j0++;

    }
    ProgressBar1->Position=j0;
    if (e0>=e ) {
       n0++;
       if (n0%2==0) { Net->kpr=Net->kpr*1.3;n0=1; }
       } else

        {
            if (Net->kpr>1) {Net->kpr=0.5;} else 
            if (Net->kpr>1e-7) { Net->kpr=Net->kpr*0.5;n0=0;} else
            {
                Net->Randomize();
            }
        }
    e0=e;
    Label2->Caption=FloatToStr(e);
    //if (Net->kpr>3) Net->kpr=3;
    Edit2->Text=FloatToStr(Net->kpr);
    Application->ProcessMessages ();
    }
    Label1->Caption="Все";
    ProgressBar1->Position=0;
    Beep();
    Edit2->Text="0.1";
    Button2->Enabled=true;    
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
    NData *Data=Kadr();
    NData *out=new NData(10);
    for(int i=0;i<10;i++) out->Data[i]=0;
    int n=Edit1->Text[1]-48;
    if (n>=0 && n<=9) out->Data[n]=1;
    InList->Add(Data);
    OutList->Add(out);
    //delete Data,out;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button5Click(TObject *Sender)
{
Form2->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
xmax=ymax=0;
xmin=ymin=10000;
InList=new NDataList;
OutList=new NDataList;
int D[]={S*S,40,20,10,10};
Net=new NeuroNet(4,D);

Edit2->Text=FloatToStr(Net->kpr);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
{
Form3->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormDestroy(TObject *Sender)
{
delete Net;
delete InList;
delete OutList;
    
}
//---------------------------------------------------------------------------

