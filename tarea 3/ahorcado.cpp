#include <iostream>

using namespace std;

char persona_dibujo[9][7]={
    "_____ ",
    "|   | ",
    "|   | ",
    "|     ",
    "|     ",
    "|     ",
    "|     ",
    "|     ",
    "______",
};
void imprimir_palabra(string palabra, char oculto[])
{
    for(int i=0; i<palabra.size(); i++)
                cout<<oculto[i];
                cout<<endl;
}
void persona(int intentos){
    switch(intentos){
    case 1:
        persona_dibujo[3][4] = '0';
        break;
    case 2:
        persona_dibujo[4][4] = '|';
        break;
    case 3:
        persona_dibujo[4][3] = '/';
        break;
    case 4:
        persona_dibujo[4][5] = '\\';
        break;
    case 5:
        persona_dibujo[5][3] = '/';
        break;
    case 6:
        persona_dibujo[5][5] = '\\';
        break;
    }
}

void imprimir_dibujo(){
    for(int i = 0; i < 9; i++){
        cout << persona_dibujo[i] << endl;
    }
}

bool verificar(char letra, const char *ptr1)
{
    for(; int(*ptr1) != 0; ptr1++){
        if(letra== *ptr1)
            return true;
    }
    return false;
}
void letras_repetidas(char letra, const char *ptr1, int &num_letras)
{
    int cont=0;
    for(; int(*ptr1) != 0; ptr1++){
        if(letra== *ptr1)
            cont++;
    }
    num_letras= num_letras-cont;
}
void ahorcado(string palabra)
{
    char letra;

    char oculto[palabra.size()];
    for(int i = 0; i < palabra.size(); i++)
        oculto[i]='_';

    char *ptr_oculto=oculto;
    const char *ptr1_original = palabra.c_str();

    int num_letras = palabra.size();
    int intentos = 0;

    while(num_letras > 0 && intentos<6){
        cout<<"ingrese una letra: ";
        cin>>letra;

        if(verificar(letra, ptr1_original)==false)
        {
            intentos++;
            persona(intentos);
        }
        else
        {
               letras_repetidas(letra, ptr1_original, num_letras);
        }

        for(; int(*ptr1_original) != 0; ptr1_original++, ptr_oculto++)  //int(*ptr1) != 0 es para que llegue hasta el final del string
        {
            if(letra== *ptr1_original){
                *ptr_oculto=letra;
            }
        }
        imprimir_dibujo();
        imprimir_palabra(palabra, oculto);
        ptr1_original=palabra.c_str();
        ptr_oculto=oculto;
    }

    if(num_letras==0)
        cout<<"GANASTE! "<<endl;
}

int main()
{
    string a="dinosaurio";
    const char *ptr;
    ptr=a.c_str();
    ahorcado(a);
}
