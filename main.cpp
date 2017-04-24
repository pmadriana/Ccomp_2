#include <iostream>
#include <afin.h>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    cout << " " << endl;
    cout << "||||||||||CIFRADO||||||||||" << endl;
    cout << " " << endl;
    string texto_cifrado, texto_descifrado;
    ifstream file;
    Afin encriptador;
    int clave_privada, b;
    string texto;
    //encriptador.claves();
    cout << "Ingrese su clave privada para descifrar: ";
    cin >> clave_privada;
    cout << "Ingrese b: ";
    cin >> b;
    file.open("texto.txt");
    if(file.is_open())
    {
        while(getline(file, texto))
        {
            string line = encriptador.cifrar(texto);
            cout<<encriptador.descifrar(clave_privada, b, line);

        }
    }
    cout << " " << endl;

    //Cifrado

    /*cout << " " << endl;
    cout << " " << endl;
    cout << " " << endl;
    //Descifrado
    encriptador.claves();
    cout << "||||||||||DESCIFRADO||||||||||" << endl;
    cout << " " << endl;
    cout << " " << endl;
    cout << " " << endl;
    texto_descifrado = encriptador.descifrar(clave_privada, b, texto_cifrado);
    cout << texto_descifrado;*/
}
