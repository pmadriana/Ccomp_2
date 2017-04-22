#include <iostream>
#include "funcionesMatematicas.h"
#include <fstream>
#include <ctype.h>
#include "Afin.h"
using namespace std;


int main()
{
    ifstream file("text.txt");
    ofstream out("out.txt");
    Afin a;
    string cifrado;
    if(file.is_open())
    {
        while(getline(file,cifrado))
        {
            string c= a.descifrar(cifrado);
            out<<c<<endl;
        }
    }

}
