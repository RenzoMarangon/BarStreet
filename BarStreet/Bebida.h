#ifndef BEBIDA_H_INCLUDED
#define BEBIDA_H_INCLUDED
#include <string>
#include "Articulo.h"


class Bebida : public Articulo{
    private:
        float _volumen;
        float _graduacion_acohol;

    public:
        Bebida( float volumen, float  graduacion_acohol);

        float getVolumen();
        void setVolumen( float volumen );

        float getGraduacionAlcoholica( float graduacion_alcohol);
        void setGraduacionAlcoholica( float graduacion_alcohol );

        void Cargar();
        void Mostrar();
};

#endif // BEBIDA_H_INCLUDED
