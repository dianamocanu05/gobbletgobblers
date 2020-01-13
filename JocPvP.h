#pragma once
#include "Tabla.h"
#include "Player.h"
#include <cstdio>
char nume1[20],nume2[20];
int nrPlayeri=2;
int playerCurent=1;
Player player1,player2;
Dreptunghi tablaAct[3][3];
int matrice[3][3];

bool AmAlesPvP(int x, int y)
{
    Dreptunghi buton;
    InitDreptunghi(0,0,lungimeEcran/2,latimeEcran,buton);
    return (Contine(x,y,buton));
}

int win()
{
    int neg=0,poz=0,i,j;
    for(i=0; i<3; i++)
    {
        neg=0;
        poz=0;
        for(j=0; j<3; j++)
            if(matrice[i][j]!=0)
            {
                if(matrice[i][j]<0)
                    neg++;
                else
                    poz++;
            }
        if(neg==3)
            return 2;
        if(poz==3)
            return 1;
    }
    for(j=0; j<3; j++)
    {
        neg=0;
        poz=0;
        for(i=0; i<3; i++)
            if(matrice[i][j]!=0)
            {
                if(matrice[i][j]<0)
                    neg++;
                else
                    poz++;
                if(neg==3)
                    return 2;
                if(poz==3)
                    return 1;
            }
    }

    return 0;
}


void NumePVP()
{
    cleardevice();
    settextstyle(0,0,4);
    setcolor(WHITE);
    outtextxy(50,100,"Introdu numele jucatorilor:");
    outtextxy(50,200,"Player 1:");
    outtextxy(50,300,"Player 2: ");
    outtextxy(50,200,"Player 1:");
    outtextxy(50,300,"Player 2: ");
    //outtextxy(350,200,nume1);

    IntroduNume(350,200,nume1,nrPlayeri);
    outtextxy(350,200,nume1);
    IntroduNume(350,300,nume2,nrPlayeri,nume1);

}

void Update()
{
    setfillstyle(SOLID_FILL,BLACK);
    bar(0,0,lungimeEcran,latimeEcran);
    if(playerCurent==1)
    {
        setcolor(4);
        outtextxy(50,50,nume1);
    }
    else
    {

        setcolor(1);
        outtextxy(latimeEcran-100,50,nume2);
    }
    int x,y,linie,coloana;
    int i;
    DeseneazaTabla(tablaAct);
    DeseneazaPiese(player1);
    DeseneazaPiese(player2);
    Click(x,y);
    if(playerCurent==1)
    {
        for( i=0; i<6; i++)
        {

            if(Contine(x,y,player1.piese[i].d))
            {
                player1.piese[i].aFostSelectata=true;
                std::cout<<player1.piese[i].aFostSelectata;
                break;
            }
        }

    }
    else
    {
        for( i=0; i<6; i++)
        {

            if(Contine(x,y,player2.piese[i].d))
            {
                player2.piese[i].aFostSelectata=true;
                break;
            }
        }

    }
    Click(x,y);
    int l=DeterminaLinie(y);
    int c=DeterminaColoana(x);
    if(playerCurent==1)
    {

        if(PotPunePiesa(player1.piese[i].dimensiune,l,c,matrice))
        {
            PlaseazaPiesa(tablaAct,l,c,player1.piese[i]);
        }

    }
    if(playerCurent==2)
    {
        if(PotPunePiesa(player2.piese[i].dimensiune,l,c,matrice))
        {

            PlaseazaPiesa(tablaAct,l,c,player2.piese[i]);

        }

    }


for(int i=0; i<3; i++)
{
    for(int j=0; j<3; j++)
        std::cout<<matrice[i][j]<<' ';
    std::cout<<std::endl;
}
playerCurent=(playerCurent++)%2+1;
}
void InitPiese(Piesa piesePl1[6],Piesa piesePl2[6])
{
    for(int i=0; i<2; i++)
    {
        piesePl1[i].d.stanga=150;
        piesePl1[i].d.sus=200;
        piesePl1[i].d.dreapta=210;
        piesePl1[i].d.jos=260;
        piesePl1[i].d.culoare=4;
        piesePl1[i].dimensiune=3;
        piesePl1[i].contor=2;
    }
    for(int i=2; i<4; i++)
    {
        piesePl1[i].d.stanga=150;
        piesePl1[i].d.sus=375;
        piesePl1[i].d.dreapta=200;
        piesePl1[i].d.jos=425;
        piesePl1[i].d.culoare=4;
        piesePl1[i].dimensiune=2;
        piesePl1[i].contor=2;
    }
    for(int i=4; i<6; i++)
    {
        piesePl1[i].d.stanga=150;
        piesePl1[i].d.sus=500;
        piesePl1[i].d.dreapta=190;
        piesePl1[i].d.jos=540;
        piesePl1[i].d.culoare=4;
        piesePl1[i].dimensiune=1;
        piesePl1[i].contor=2;
    }
    for(int i=0; i<2; i++)
    {
        piesePl2[i].d.stanga=720;
        piesePl2[i].d.sus=200;
        piesePl2[i].d.dreapta=780;
        piesePl2[i].d.jos=260;
        piesePl2[i].d.culoare=1;
        piesePl2[i].dimensiune=-3;
        piesePl2[i].contor=2;
    }
    for(int i=2; i<4; i++)
    {
        piesePl2[i].d.stanga=730;
        piesePl2[i].d.sus=375;
        piesePl2[i].d.dreapta=780;
        piesePl2[i].d.jos=425;
        piesePl2[i].d.culoare=1;
        piesePl2[i].dimensiune=-2;
        piesePl2[i].contor=2;
    }
    for(int i=4; i<6; i++)
    {
        piesePl2[i].d.stanga=740;
        piesePl2[i].d.sus=500;
        piesePl2[i].d.dreapta=780;
        piesePl2[i].d.jos=540;
        piesePl2[i].d.culoare=1;
        piesePl2[i].dimensiune=-1;
        piesePl2[i].contor=2;
    }
}

void JocPvP()
{
    int playerCastigator;
    playerCurent=1;
    InitTabla(tablaAct);
    Piesa piesePl1[6];
    Piesa piesePl2[6];
    InitPiese(piesePl1,piesePl2);
    InitPlayer(player1,nume1,piesePl1);
    InitPlayer(player2,nume2,piesePl2);
    while(1)
        {
        Update();
        playerCastigator=win();
        if(playerCastigator!=0)
            break;
    }
    char buffer[40];
    sprintf(buffer,"%d",playerCastigator);
    bar(0,0,lungimeEcran,latimeEcran);
    outtextxy(250,250,buffer);
    getch();
}


