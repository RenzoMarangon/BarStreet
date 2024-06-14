#include <iostream>
#include <cstring>
#include "Bebida.h"

using namespace std;

Bebida::Bebida(int id, std::string nombre, float precio_inicial, float costo, int stock, float variacion, float volumen, float graduacion_alcohol)
    : Articulo(id, nombre, precio_inicial, costo, stock, variacion)
{
    _volumen = volumen;
    _graduacion_acohol = graduacion_alcohol;
}

float Bebida::getVolumen()
{
    return _volumen;
}

void Bebida::setVolumen( float volumen )
{
    _volumen = volumen;
}

float Bebida::getGraduacionAlcoholica()
{
    return _graduacion_acohol;
}

void Bebida::setGraduacionAlcoholica( float graduacion_acohol )
{
    _graduacion_acohol = graduacion_acohol;
}

void Bebida::Cargar()
{
    Articulo::Cargar();


    std::cout << "Volumen";
    cin >> _volumen;

    cout << endl << endl;

    std::cout << "Graduacion alcoholica";
    cin >> _graduacion_acohol;

}

void Bebida::Mostrar()
{

    Articulo::Mostrar();
    std::cout<< "Volumen: ";
    std::cin >> _volumen;
    std::cout<<endl;

    std::cout<< "Graduacion acoholica: ";
    std::cin >> _graduacion_acohol;
    std::cout<<endl;

}
