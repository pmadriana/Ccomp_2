#include "Afin.h"

using namespace std;
Afin::Afin()
{
    cout << "Clave publica: ";
    cin >> clave_a;
    while(euclides(clave_a,95)!=1)
    {
        int nueva;
        cout<<"Ingrese otra: ";
        cin>>nueva;
        clave_a=nueva;
    }
    this->clave_a=modulo(clave_a,95);
    clave_privada = modinv(clave_a,95);
}
string Afin::cifrar(string mensaje)
{
    string mensaje_cifrado;
    char nueva_letra;
    for(int i=0;i<mensaje.size();i++)
    {
        if(isprint(mensaje[i]))
            {
                nueva_letra = mensaje[i];
                nueva_letra = modulo((nueva_letra*clave_a)+8-' ',95)+32;
                mensaje_cifrado += nueva_letra;
            }
    }
    return mensaje_cifrado;
}

string Afin::descifrar(string mensaje_cifrado )
{
     string mensaje_descifrado;
    char letra;
    for(int i=0;i<mensaje_cifrado.size();i++)
    {
        if(isprint(mensaje_cifrado[i]))
        {
            letra = mensaje_cifrado[i];
            letra = modulo((clave_privada*(letra-8)-' '),95)+32;
            mensaje_descifrado += letra;
        }
    }
    return mensaje_descifrado;
}
