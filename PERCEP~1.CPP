//---------------------------------------------------------------------------
//#include <vcl.h>
//#pragma hdrstop

#include <stdlib.h>
#include <time.h>
#include "Perceptron.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)

Perceptron::Perceptron(int Width,int Height,int NumAction)
{
randomize();
X0=Width;
Y0=Height;
NumbElement=Width*Height;
NumActions=NumAction;
Actions=new Action[NumActions];
for (unsigned int i=0;i<NumActions;i++)
{
for (int j=0;j<2;j++) {Actions[i].Link[j]=random(NumbElement);}
Actions[i].Ball=0;
Actions[i].NotS=false;
if (random(10)>5) { Actions[i].NotS=true; } else
                { Actions[i].NotS=false; }
}
}
Perceptron::~Perceptron()
{
delete Actions;
}
bool Perceptron::Rechenie(bool Data[])
{
long sum=0;
for(unsigned int i=1;i<NumActions;i++)
{
bool zn=Data[Actions[i].Link[0]] && Data[Actions[i].Link[1]];
if (Actions[i].NotS) zn=!zn;
if (zn) {
    sum=sum+Actions[i].Ball;
    }
}
return (sum>0);
}
void Perceptron::Lern(bool Data[],bool Ideal)
{
long sum=0;
bool *Check=new bool [NumActions];
for(unsigned int i=1;i<NumActions;i++)
{
bool zn=Data[Actions[i].Link[0]] && Data[Actions[i].Link[1]];
if (Actions[i].NotS) zn=!zn;
if (zn) {
    sum=sum+Actions[i].Ball;
    Check[i]=true;
    } else Check[i]=false;
}
if ((sum>0)&&(!Ideal))   {
                        for(unsigned int i=0;i<NumActions;i++)
                        {
                            if (Check[i]) {
                                            Actions[i].Ball--; }
                        }
                        }
if ((sum<=0)&&(Ideal))   {
                        for(unsigned int i=0;i<NumActions;i++)
                        {
                            if (Check[i]) {
                                            Actions[i].Ball++; }
                        }
                        }
}
bool Perceptron::KW(TCanvas *Canva,int x,int y,int dx,int dy) const
{
register bool rez=false;
for(int i=x;i<x+dx;i++)
for(int j=y;j<y+dy;j++) {
register TColor zn=Canva->Pixels[i][j];
rez=rez || (zn==clBlack); }
return rez;
}
void Perceptron::Kadr(TCanvas *Canva,  int X, int Y, int *Xmin,int *Ymin,int *Xmax,int *Ymax)
{
*Xmin=X;*Ymin=Y;*Xmax=0;*Ymax=0;
for(int i=1;i<X;i++)
for(register j=1;j<Y;j++)
{
if (Canva->Pixels[i][j]==0) {
                            if (*Xmin>i) *Xmin=i;
                            if (*Ymin>j) *Ymin=j;
                            if (*Xmax<i) *Xmax=i;
                            if (*Ymax<j) *Ymax=j;
                            }
}
}
bool * Perceptron::Preobr(TCanvas *Canva, int X,int Y)
{
int xmin,ymin,xmax,ymax;
Kadr(Canva,X,Y,&xmin,&ymin,&xmax,&ymax);
int dx,dy;
dx=(xmax-xmin)/X0;
dy=(ymax-ymin)/Y0;
bool *Data=new bool [X0*Y0];
register z=0;
for(unsigned int i=0;i<X0;i++)
{
    for(unsigned int j=0;j<Y0;j++)
    {
        Data[z]=KW(Canva,xmin+i*dx,ymin+j*dy,dx,dy);z++;
    }
}
return Data;
}

