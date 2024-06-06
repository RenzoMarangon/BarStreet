#include <iostream>
#include <cstring>
#include "Comida.h"
#include "Funciones.h"

Comida::Comida(std::string observacion, std::string guarnicion){

    strcpy(_observacion, observacion);

    strcpy(_guarnicion, guarnicion);
}

std::string Comida::getObservacion()
{
    return _observacion;
}

void Comida::setObservacion( std::string observacion)
{
     if(observacion.size() <= 100){
      strcpy(_observacion, observacion.c_str());
   }
   else{
      strcpy(_observacion, "SIN DATOS");
   }
}


std::string Comida::getGuarnicion()
{
    return _guarnicion;
}

void Comida::setGuarnicion( std::string guarnicion)
{
     if(guarnicion.size() <= 100){
      strcpy(_guarnicion, guarnicion.c_str());
   }
   else{
      strcpy(_guarnicion, "SIN DATOS");
   }
}

void Comida::Cargar()
{
    Articulo::Cargar();
    std::cout << "Guarnicion";
    cargarCadena(_guarnicion,99);

    cout << endl << endl;

    std::cout << "Observacion";
    cargarCadena(_observacion,99);
}

void Bebida::Mostrar()
{

    Articulo::Mostrar();
    std::cout<< "Guarnicion: ";
    std::cin >> _guarnicion;
    std::cout<<endl;

    std::cout<< "Observacion: ";
    std::cin >> _observacion;
    std::cout<<endl;

}
