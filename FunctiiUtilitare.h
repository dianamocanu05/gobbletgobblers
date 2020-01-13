#pragma once
#include <graphics.h>
#include <winbgim.h>
#include "Dreptunghi.h"
#define lungimeEcran 1000
#define latimeEcran 800


bool Contine(int x, int y, Dreptunghi d)
{
    return(x>=d.stanga && x<=d.dreapta && y>=d.sus && y<=d.jos);
}

void Click(int &x, int &y)
{
    while(!ismouseclick(WM_LBUTTONDOWN)) {}
    getmouseclick(WM_LBUTTONDOWN,x,y);
    clearmouseclick(WM_LBUTTONDOWN);
}
 void AfiseazaNume(int x, int y,char nume[20], char c,int nrJucatori=0,char nume1[20]=NULL)
    {
            setfillstyle(SOLID_FILL,BLACK);
            bar(0,0,lungimeEcran,latimeEcran);

        if(nrJucatori==2)
        {
            outtextxy(50,100,"Introdu numele jucatorilor:");
            outtextxy(50,200,"Player 1:");
            outtextxy(50,300,"Player 2: ");
            if(nume1 !=NULL)
            outtextxy(350,200,nume1);

        }
        else
        {
            outtextxy(50,100,"Introdu numele:");
            outtextxy(50,200,"Player 1:");
            outtextxy(50,300,"Computer: ");
            if(nume1 !=NULL)
            outtextxy(350,200,nume);
            outtextxy(350,300,nume1);
        }
            if(isalnum(c))
            {
                char aux[2];
                aux[0]=c;
                aux[1]='\0';
                strcat(nume, aux);
                outtextxy(x,y,nume);
            }


    }
void CopiazaMatrice(int M1[3][3],int M2[3][3])
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
            M1[i][j]=M2[i][j]
    }

}
void IntroduNume(int x, int y, char nume[20],int nrPlayeri,char nume1[20]=NULL)
{
    while(1)
    {
        char c=getch();
        //std::cout<<std::endl<<c<<std::endl;
        if(c==13) //enter
            break;
        else if(c==8)
        {
            if(strlen(nume))
            {
                nume[strlen(nume)-1]='\0';
                bar(0,0,lungimeEcran,latimeEcran);
                outtextxy(50,100,"Introdu numele:");
                outtextxy(x,y,nume);
            }
        }
        else
            AfiseazaNume(x,y,nume,c,nrPlayeri,nume1);
    }
}


