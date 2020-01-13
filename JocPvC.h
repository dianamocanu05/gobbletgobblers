#pragma once
#include "Dreptunghi.h"
#include <time.h>
int nrJuc=1;
char numeComputer[10];
char numePlayer[10];
char GenereazaNumeComputer(char nume[10])
{

char caractere[] =
"0123456789"
"!@#$%^&*"
"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
"abcdefghijklmnopqrstuvwxyz";

int lungime = strlen(caractere) - 1;


    srand(time(0));
    for(int z=0; z < 5; z++)
    {
         char aux[2];
         aux[0]=caractere[rand() % lungime];
         aux[1]='\0';
         strcat(nume, aux);

    }

}
bool AmAlesPvC(int x, int y)
{
    Dreptunghi buton;
    InitDreptunghi(501,0,lungimeEcran,latimeEcran,buton);
    return (Contine(x,y,buton));
}

void NumePVC()
{
    cleardevice();
    settextstyle(0,0,4);
    setcolor(WHITE);
    outtextxy(50,100,"Introdu numele:");
    outtextxy(50,200,"Player 1:");
    outtextxy(50,300,"Computer: ");
    GenereazaNumeComputer(numeComputer);
    outtextxy(350,300,numeComputer);
    IntroduNume(350,200,nume1,nrJuc,numeComputer);

}

void JocPvC()
{
    ;
}
