#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
int modulo(int a, int n)
{
    int q=a/n;
    int r= a-(q*n);
    if(r<0)
        return n-r;
    return r;

}
void billetes(int mont, int billete)
     {
         int b;
         if(mont <1)
            return;
        else if(billete==500){

             b=mont/billete; 
             mont=modulo(mont, billete); 
             if(b!=0){
                cout<<b<<" billete de "<< billete<<endl;
             }
             billetes(mont, 400);

         }
         else if(billete==50){
             b=mont/billete;
             mont=modulo(mont, billete); 
             if(b!=0)
                cout<<b<<" billete de "<< billete<<endl;
            billetes(mont, 20);

         }

         else{
             b=mont/billete; 
             mont=modulo(mont, billete); 
             if(b!=0){
                cout<<b<<" billetes de "<< billete<<endl;
             }
            else if(mont<5){
                b=mont/1;
                mont=modulo(mont, 1);
                cout<<b<<" monedas de 1 sol "<<endl;
            }
            billetes(mont, billete/2);

         }
     }

void monedas(int mont, int mon)
{
    int b;
    if(mon<10)
        return;
    else if(mon == 50){
        b=mont/mon;
        mont=mont%mon;
        if(b==0)
                cout<<"";
        else{cout<<b<<" moneda de "<< mon<<" centimos" << endl;}
        monedas(mont, 20);
    }
    else{
        b=mont/mon;
        mont=mont%mon;
        if(b==0)
                cout<<"";
        else{cout<<b<<" monedas de "<< mon<<" centimos" <<endl;}
        monedas(mont, mon/2);
    }
}
void cambio_moneda(int billetess,int m) {
   billetes(billetess, 500);
   monedas(m,50);
}


main()
{
   cambio_moneda(100000000000,0);

}
