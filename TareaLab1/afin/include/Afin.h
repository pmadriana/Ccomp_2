#ifndef AFIN_H
#define AFIN_H
#include <string>
#include<vector>
#include "funcionesMatematicas.h"
#include <ctype.h>
#include <iostream>

class Afin
{
    int clave_a, clave_privada;
public:
    Afin();
    std::string cifrar(std::string mensaje);
    std::string descifrar(std::string mensaje_cifrado);
};

#endif // AFIN_H
