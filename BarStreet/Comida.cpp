#include <iostream>
#include <cstring>
#include "Comida.h"


using namespace std;

Comida::Comida(int id, std::string nombre, float precio_inicial, float costo, int stock, float variacion, float volumen, float graduacion_alcohol, std::string observacion, std::string guarnicion)
    : Articulo( id, nombre, precio_inicial, costo, stock, variacion )
{

    strcpy(_observacion, observacion.c_str());

    strcpy(_guarnicion, guarnicion.c_str());
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

void Comida::Mostrar()
{

    Articulo::Mostrar();
    std::cout<< "Guarnicion: ";
    std::cin >> _guarnicion;
    std::cout<<endl;

    std::cout<< "Observacion: ";
    std::cin >> _observacion;
    std::cout<<endl;

}
