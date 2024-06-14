#include <iostream>
#include <cstring>
#include "Funciones.h"
#include "ArchivoBebida.h"

bool ArchivoBebida::grabarRegistro(Bebida obj){
    FILE *p;
    p=fopen(nombre, "ab");
    if(p==NULL) return false;
    bool escribio=fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return escribio;
}


bool ArchivoBebida::listarRegistros(){
    FILE *p;
    Bebida obj;
    p=fopen(nombre, "rb");
    if(p==NULL) return false;
    while(fread(&obj, sizeof obj, 1, p)==1){
            obj.Mostrar();
            cout<<endl;
    }
    fclose(p);
    return true;
}

int ArchivoBebida::buscarRegistro(int num){
    FILE *p;
    Bebida obj;
    p=fopen(nombre, "rb");
    int pos=0;
    if(p==NULL) return -1;
    while(fread(&obj, sizeof obj, 1, p)==1){
                if(obj.getNumero()==num){
                    fclose(p);
                    return pos;
                }
                pos++;
    }
    fclose(p);
    return -2;
}

Bebida ArchivoBebida::leerRegistro(int pos){
    FILE *p;
    Bebida obj;
    p=fopen(nombre, "rb");
    obj.setNumero(-5);
    if(p==NULL) return obj;
    fseek(p, pos*sizeof obj,0);///función que permite ubicarse dentro del archivo
    fread(&obj, sizeof obj, 1, p);
    fclose(p);
    return obj;
}

bool ArchivoBebida::modificarRegistro(Bebida obj, int pos){
    FILE *p;
    p=fopen(nombre, "rb+"); ///agrega al modo de apertura lo que le falta
    if(p==NULL) return false;
    fseek(p, pos*sizeof obj,0);///función que permite ubicarse dentro del archivo
    bool escribio=fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return escribio;
}

int ArchivoBebida::contarRegistros(){
    FILE *p;
    p=fopen(nombre, "rb");
    if(p==NULL) return -1;
    fseek(p, 0,2);///función que permite ubicarse dentro del archivo, en este caso lo ubiqué al final EOF
    int tam=ftell(p);///me devuelve la cantidad de bytes que hay desde el principio del archivo a la posición actual del indicador de pFILE.
    fclose(p);
    return tam/sizeof(Comida);
}
