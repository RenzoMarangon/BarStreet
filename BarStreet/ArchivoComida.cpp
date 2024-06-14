#include <iostream>
#include <cstring>
#include "Funciones.h"
#include "ArchivoComida.h"

ArchivoComida::ArchivoComida(const char *n)
{
    strcpy(nombre,n);
}

bool ArchivoComida::grabarRegistro(Comida obj){
    FILE *p;
    p=fopen(nombre, "ab");
    if(p==NULL) return false;
    bool escribio=fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return escribio;
}


bool ArchivoComida::listarRegistros(){
    FILE *p;
    Comida obj(0);
    p=fopen(nombre, "rb");
    if(p==NULL) return false;
    while(fread(&obj, sizeof obj, 1, p)==1){
            obj.Mostrar();
            cout<<endl;
    }
    fclose(p);
    return true;
}

int ArchivoComida::buscarRegistro(int id){
    FILE *p;
    Comida obj(0);
    p=fopen(nombre, "rb");
    int pos=0;
    if(p==NULL) return -1;
    while(fread(&obj, sizeof obj, 1, p)==1){
                if(obj.getID()==id){
                    fclose(p);
                    return pos;
                }
                pos++;
    }
    fclose(p);
    return -2;
}

Comida ArchivoComida::leerRegistro(int pos){
    FILE *p;
    Comida obj(0);
    p=fopen(nombre, "rb");
    obj.setID(-5);
    if(p==NULL) return obj;
    fseek(p, pos*sizeof obj,0);///función que permite ubicarse dentro del archivo
    fread(&obj, sizeof obj, 1, p);
    fclose(p);
    return obj;
}

bool ArchivoComida::modificarRegistro(Comida obj, int pos){
    FILE *p;
    p=fopen(nombre, "rb+"); ///agrega al modo de apertura lo que le falta
    if(p==NULL) return false;
    fseek(p, pos*sizeof obj,0);///función que permite ubicarse dentro del archivo
    bool escribio=fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return escribio;
}

int ArchivoComida::contarRegistros(){
    FILE *p;
    p=fopen(nombre, "rb");
    if(p==NULL) return -1;
    fseek(p, 0,2);///función que permite ubicarse dentro del archivo, en este caso lo ubiqué al final EOF
    int tam=ftell(p);///me devuelve la cantidad de bytes que hay desde el principio del archivo a la posición actual del indicador de pFILE.
    fclose(p);
    return tam/sizeof(Comida);
}
