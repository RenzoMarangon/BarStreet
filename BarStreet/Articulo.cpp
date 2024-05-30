#include <iostream>
#include <cstring>
#include "Articulo.h"
#include "Funciones.h"

Articulo::Articulo(int id, std::string nombre, float precio_inicial, float costo, int stock, float variacion = 0)
{
    setID( id );
    setNombre( nombre );
    setPrecioInicial( precio_inicial );
    setCosto( costo );
    setStock( stock );
    setVariacion( variacion );
    setEstado( true );

}

int Articulo::getID()
{
    return _id;
}
void Articulo::setID( int id)
{
    _id = id;
}

std::string Articulo::getNombre(){
    return _nombre;
}
void Articulo::setNombre(std::string nombre){
   if(nombre.size() <= 50){
      strcpy(_nombre, nombre.c_str());
   }
   else{
      strcpy(_nombre, "SIN DATOS");
   }
}

float Articulo::getPrecioInicial(){
    return _precio_inicial;
}
void Articulo::setPrecioInicial( float precio_inicial )
{
    _precio_inicial = precio_inicial;
}


float Articulo::getCosto(){
    return _costo;
}
void Articulo::setCosto( float costo )
{
    _costo = costo;
}

int Articulo::getStock(){
    return _stock;
}
void Articulo::setStock( int stock ){
    _stock = stock;
}

float Articulo::getVariacion(){
    return _variacion;
}
void Articulo::setVariacion( float variacion )
{
    _variacion = variacion;
}

bool Articulo::getEstado(){
    return _estado;
}
void Articulo::setEstado( bool estado )
{
    _estado = estado;
}

void Articulo::Cargar()
{

    std::cout<<"ID: ";
    std::cin >> _id;

    std::cout << "Nombre";
    cargarCadena(_nombre,49);

    std::cout<< "Stock: ";
    std::cin >> _stock;

    std::cout<< "Precio inicial: ";
    std::cin >> _precio_inicial;

    std::cout<< "Costo: ";
    std::cin >> _costo;

    std::cout<< "Variacion: ";
    std::cin >> _variacion;
}

void Articulo::Mostrar()
{
    std::cout<<"ID: " << _id;


    std::cout << "Nombre: " << _nombre;

    std::cout<< "Stock: " << _stock;

    std::cout<< "Precio inicial: " << _precio_inicial;

    std::cout<< "Costo: " << _costo;

    std::cout<< "Variacion: " << _variacion;
}




