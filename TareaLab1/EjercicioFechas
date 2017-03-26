#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;
int clave_mes_bisiesto[12] = {0,3,4,0,2,5,0,3,6,1,4,6};
int clave_mes_normal[12] = {0,3,3,6,1,4,6,2,5,0,3,5};
int clave_siglo[24] = {4,3,2,1,0,6,5,4,3,2,1,0,6,5,4,6,4,2,0,6,4,2,0,6};
string nombre_dia[7] = {"Lunes","Martes","Miercoles","Jueves","Viernes","Sabado","Domingo"};
bool ano_bisiesto(int ano)
{
    if(((ano%4==0)&&(ano%100!=0))||((ano%100==0)&&(ano%400==0)))
    {
        return true;
    }
    else
        return false;
}
int cortar_ano(string anio_completo)
{
    string anio_corto = anio_completo.substr(2,3);
    int anio_final = atoi(anio_corto.c_str());
    return anio_final;
}
int clave_siglo_funcion(string anio)
{
    int anio_int = atoi(anio.c_str());
    if(anio_int>999)
    {
        string siglo = anio.substr(0,2);
        int siglo_int = atoi(siglo.c_str());
        return siglo_int;
    }
    if((anio_int>99)&&(anio_int<1000))
    {
        string siglo = anio.substr(0,1);
        int siglo_int = atoi(siglo.c_str());
        return siglo_int;
    }
    else
        return 0;
}
string give_name_day(int dia, int mes, int anio)
{
    int anios_bisiestos = 0, anios_normales = 0;
    int cpy_anio = anio;
    while(cpy_anio>0)
    {
        if(ano_bisiesto(cpy_anio)==true)
        {
            anios_bisiestos++;
        }
        else
            anios_normales++;
        cpy_anio--;
    }
    int total_dias = anios_bisiestos*366 + anios_normales*365;
    switch(mes)
    {
    case 1:
        total_dias += 0;
        break;
    case 2:
        total_dias += 31;
        break;
    case 3:
        total_dias += 28+31;
        break;
    case 4:
        total_dias += 31+28+31;
        break;
    case 5:
        total_dias += 30+31+28+31;
        break;
    case 6:
        total_dias += 31+30+31+28+31;
        break;
    case 7:
        total_dias += 30+31+30+31+28+31;
        break;
    case 8:
        total_dias += 31+30+31+30+31+28+31;
        break;
    case 9:
        total_dias += 31+31+30+31+30+31+28+31;
        break;
    case 10:
        total_dias += 30+31+31+30+31+30+31+28+31;
        break;
    case 11:
        total_dias += 31+30+31+31+30+31+30+31+28+31;
        break;
    case 12:
        total_dias += 30+31+30+31+31+30+31+30+31+28+31;
        break;
    }
    total_dias += dia;
    return nombre_dia[total_dias%7];
}
string nombre_dia_fecha(int dia, int mes, string ano)
{
    int anio_int_corto = cortar_ano(ano);
    if(ano_bisiesto(atoi(ano.c_str()))==true)
    {
        return nombre_dia[(dia + clave_mes_bisiesto[mes-1] + anio_int_corto + (int)(anio_int_corto/4) + clave_siglo[clave_siglo_funcion(ano)])%7];

    }
    else
        return nombre_dia[(dia + clave_mes_normal[mes-1] + anio_int_corto + (int)(anio_int_corto/4)+1 + clave_siglo[clave_siglo_funcion(ano)])%7];


}
int imprimir_mes(int mes, int ano)
{
    int dias_mes=0;
    int pos_dia;
    switch (mes)
    {

    case 2: //febrero
        if(ano_bisiesto(ano)==true)
            dias_mes=dias_mes+29;
        dias_mes=dias_mes+28;
        break;
    case 1: //enero
    case 3: //marzo
    case 5: //mayo
    case 7: //julio
    case 8: //agosto
    case 10: //octubre
    case 12: //diciembre
        dias_mes=dias_mes +31;
        break;
    case 4: //abril
    case 6: //junio
    case 9: //septiembre
    case 11: //nov
        dias_mes=dias_mes+30;
        break;
    }
    cout << "|DO|LU|MA|MI|JU|VI|SA|"<<endl;
    cout << "----------------------"<<endl;
    int calendario[6][7];

    if(give_name_day(1, mes, ano)== "Domingo"){
        calendario[0][0]=1;
        cout<<"| "<<calendario[0][0];
        pos_dia=1;
    }
    if(give_name_day(1, mes, ano)== "Lunes"){
        calendario[0][1]=1;
        cout<<"   | "<<calendario[0][1];
        pos_dia=2;
    }
    if(give_name_day(1, mes, ano)== "Martes"){
        calendario[0][2]=1;
        cout<<"      | "<<calendario[0][2];
        pos_dia=3;
    }
    if(give_name_day(1, mes, ano)== "Miercoles"){
        calendario[0][3]=1;
        cout<<"         | "<<calendario[0][3];
        pos_dia=4;
    }
    if(give_name_day(1, mes, ano)== "Jueves"){
        calendario[0][4]=1;
        cout<<"            | "<<calendario[0][4];
        pos_dia=5;
    }
    if(give_name_day(1, mes, ano)== "Viernes"){
        calendario[0][5]=1;
        cout<<"               | "<<calendario[0][5];
        pos_dia=6;
    }
    if(give_name_day(1, mes, ano)== "Sabado"){
        calendario[0][6]=1;
        cout<<"                  | "<<calendario[0][6];
        pos_dia=7;
    }
    int i,j,pos=2;
    for (i=0; i<6; i++)
    {
        for (j=pos_dia; j<7; j++)
        {
            if(pos<=dias_mes){
            calendario[i][j] = pos ;
            pos++;
            if(pos<11 ){
            cout<<"| "<<calendario[i][j];
            }else
            cout<<"|"<<calendario[i][j];
            }

        }
        pos_dia=0;
        cout<<"\n";
    }

}
int main()
{

    int dia, mes,ano;
    cout<<"dia: ";
    cin>>dia;
    cout<<"Mes: ";
    cin>>mes;
    cout<<"Ano: ";
    cin>>ano;
    cout<< give_name_day(dia, mes, ano);
    cout<<ano_bisiesto(ano);
    cout<<"\n";
    imprimir_mes(mes,ano);

}
