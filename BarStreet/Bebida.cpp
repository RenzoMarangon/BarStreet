#include <iostream>
#include <cstring>
#include "Bebida.h"
#include "Funciones.h"


Bebida::Bebida(float volumen, float graduacion_alcohol)
{
    _volumen = volumen;
    _graduacion_acohol = graduacion_acohol;
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
