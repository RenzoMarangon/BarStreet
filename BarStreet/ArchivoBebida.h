#ifndef ARCHIVOBEBIDA_H_INCLUDED
#define ARCHIVOBEBIDA_H_INCLUDED
#pragma once
# include<iostream>
# include<cstdlib>
# include<cstring>
#include "bebida.h"

class ArchivoComida{

    private:
        char nombre[50];
    public:
        ArchivoComida(const char *n="bebida.dat"){strcpy(nombre,n);}
        bool grabarRegistro(Comida obj);
        Comida leerRegistro(int pos);
        int buscarRegistro(int num);
        int contarRegistros();
        bool modificarRegistro(Comida obj, int pos);
        bool listarRegistros();

};
#endif // ARCHIVOBEBIDA_H_INCLUDED
