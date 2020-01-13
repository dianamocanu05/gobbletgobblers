#pragma once
#include <graphics.h>
#include <winbgim.h>
#include "Piesa.h"
#include <cmath>
#define latura 130

void InitTabla(Dreptunghi tabla[3][3])
{
    for(size_t i=0; i<3; i++)
        for(size_t j=0; j<3; j++)
            {
             tabla[i][j].stanga=270+ j*latura;
             tabla[i][j].sus=175+ i*latura;
             tabla[i][j].jos=tabla[i][j].sus+latura;
             tabla[i][j].dreapta=tabla[i][j].stanga+latura;
             tabla[i][j].culoare=BLACK;
            }
}

void DeseneazaTabla(Dreptunghi tabla[3][3])
{

    setcolor(WHITE);
    for(size_t i=0; i<3; i++)
        for(size_t j=0; j<3; j++)
           rectangle(tabla[i][j].stanga,tabla[i][j].sus,tabla[i][j].dreapta,tabla[i][j].jos);
}

void PlaseazaPiesa(Dreptunghi tabla[3][3],int linie,int coloana,Piesa &p)
{
    setfillstyle(SOLID_FILL,p.d.culoare);
    int marime=p.d.dreapta-p.d.stanga;
    int undex=tabla[linie][coloana].stanga+(latura-marime)/2;
    int undey=tabla[linie][coloana].sus+(latura-marime)/2;
    p.d.stanga=undex;
    p.d.sus=undey;
    p.d.dreapta=undex+marime;
    p.d.jos=undey+marime;
    Deseneaza(p.d);

}

bool PotPunePiesa(int dimensiune,int linie,int coloana,int Matrice[3][3])
{
 if(Matrice[linie][coloana]==0)
 {
    Matrice[linie][coloana]=dimensiune;
    return true;
 }
 if(std::abs(Matrice[linie][coloana])<std::abs(dimensiune))
 {
    Matrice[linie][coloana]=dimensiune;
    return true;
 }
 return false;
}
int DeterminaColoana(int xx)  //pe ce coloana
{

    if(xx>=270 && xx<400)
        return 0;
    if(xx>=400 && xx<530)
        return 1;
    if(xx>=530 && xx<=660)
        return 2;
}

int DeterminaLinie(int yy)  //pe ce linie
{

   if(yy>=175 && yy<305)
        return 0;
    if(yy>=305 && yy<435)
        return 1;
    if(yy>=435 && yy<=565)
        return 2;


}
