#include <iostream>

#include "Comida.h"
#include "Bebida.h"
#include "ArchivoBebida.h"
#include "ArchivoComida.h"


using namespace std;

int main()
{
    cout << "Bienvenido al BarStreet" << endl;
    Comida comidita(10);
    Bebida bebidita(15);
    ArchivoBebida archBebida("bebida.dat");
    ArchivoComida archComida("comida.dat");



    archBebida.grabarRegistro(bebidita);

    archComida.grabarRegistro(comidita);

    bebidita = archBebida.leerRegistro(0);



    comidita = archComida.leerRegistro(0);

    comidita.Mostrar();

      cout << endl << endl;

    bebidita.Mostrar();




    return 0;
}
