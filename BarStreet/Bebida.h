#pragma once
#ifndef BEBIDA_H_INCLUDED
#define BEBIDA_H_INCLUDED
#include <string>
#include "Articulo.h"


class Bebida : public Articulo{
    private:
        float _volumen;
        float _graduacion_acohol;

    public:
        Bebida(int id, std::string nombre, float precio_inicial, float costo, int stock, float variacion, float volumen, float graduacion_alcohol);


        float getVolumen();
        void setVolumen( float volumen );

        float getGraduacionAlcoholica();
        void setGraduacionAlcoholica( float graduacion_alcohol );

        void Cargar();
        void Mostrar();
};

#endif // BEBIDA_H_INCLUDED
