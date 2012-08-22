//---------------------------------------------------------------------------
#ifndef PerceptronH

#include <vcl\graphics.hpp>

#define PerceptronH
//---------------------------------------------------------------------------
struct Action{
    unsigned int Link[2];
    int Ball;
    bool NotS;
    };
class Perceptron
{
private:
Action *Actions;
unsigned int NumbElement,NumActions,X0,Y0;
public:
    Perceptron(int Width,int Height,int NumAction);
    ~Perceptron();
    bool Rechenie(bool Data[]); // Мнение перцептрона о данной картинке
    void Lern(bool Data[],bool Ideal); // Обучение перцептрона
    bool KW(TCanvas *Canva,int x,int y,int dx,int dy) const; // Уменьшение расширения
    void Kadr(TCanvas *Canva,  int X,int Y,int *Xmin,
                int *Ymin,int *Xmax,int *Ymax);
    bool * Preobr(TCanvas *Canva, int X,int Y);
};
#endif
