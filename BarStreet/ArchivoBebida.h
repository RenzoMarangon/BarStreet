#ifndef ARCHIVOBEBIDA_H_INCLUDED
#define ARCHIVOBEBIDA_H_INCLUDED
#pragma once
# include<iostream>
# include<cstdlib>
# include<cstring>
#include "bebida.h"

class ArchivoBebida{

    private:
        char nombre[50];
    public:
        ArchivoBebida(const char *n="bebida.dat");
        bool grabarRegistro(Bebida obj);
        Bebida leerRegistro(int pos);
        int buscarRegistro(int num);
        int contarRegistros();
        bool modificarRegistro(Bebida obj, int pos);
        bool listarRegistros();

};
#endif // ARCHIVOBEBIDA_H_INCLUDED
