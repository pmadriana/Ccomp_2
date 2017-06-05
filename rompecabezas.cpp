#include <iostream>
#include <stdlib.h>
#include <conio.h>
using namespace std;

int matriz[4][4];
int posX, posY;

void llenar()
{
    int (*mat)[4]= matriz;
    int num = 1;
    while (num != 16){
        int i = rand()%4;
        int j = rand()%4;
        if(*(*(mat+i)+j) == 0){
            *(*(mat+i)+j) = num;
            num++;
        }
    }
}

void imprimir()
{
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            if(*(*(matriz+i)+j) <10)
                cout<<*(*(matriz+i)+j)<<" |";
            else
                cout<<*(*(matriz+i)+j)<<"|";

        }
        cout<<endl;
    }
    cout<<"-----------";
    cout<<endl;
}
bool ordenado()
{
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(*(*(matriz+i)+j) > *(*(matriz+i)+(j+1)));
                return false;
        }
    }
    return true;
}

void posicion()
{
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            if(*(*(matriz+i)+j)==0){
                posX=i;
                posY=j;
            }
        }
    }
}

void tecla(){
char cTecla;

    cout<<"presione una tecla"<<endl;

    while(cTecla != 27 || ordenado()==false)
    {
       cTecla = getch();
       if(cTecla == 0)
           cTecla = getch();
       else
           switch(cTecla)
           {
            case 72: //arriba
            if(posX!= 0){
                *(*(matriz+posX)+posY) = *(*(matriz+(posX-1))+posY) ;
                --posX;
                *(*(matriz+posX)+posY)  = 0;
                imprimir();
			}
            break;
            case 80: //abajo
            if(posX!= 3){

                *(*(matriz+posX)+posY)  = *(*(matriz+(posX+1))+posY) ;
                ++posX;
                *(*(matriz+posX)+posY) = 0;
                imprimir();
			}
            break;

            case 75: //izquierda
            if(posY!= 0){

                *(*(matriz+posX)+posY)  = *(*(matriz+posX)+(posY-1)) ;
                --posY;
                *(*(matriz+posX)+posY) = 0;
                imprimir();
			}
            break;

            case 77: //derecha
            if(posY!= 3){

                *(*(matriz+posX)+posY)  = *(*(matriz+posX)+ (posY+1)) ;
                ++posY;
                *(*(matriz+posX)+posY) = 0;
                imprimir();
			}
            break;
            }
    }

}
int main()
{
    llenar();
    imprimir();
//    cout<<ordenado();
    posicion();
    tecla();

}
