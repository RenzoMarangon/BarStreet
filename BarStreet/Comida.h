#ifndef COMIDA_H_INCLUDED
#define COMIDA_H_INCLUDED
#include <string>
#include "Articulo.h"

class Comida : public Articulo{
    private:
        char _observacion[100];
        char _guarnicion[100];

    public:
        Comida(std::string observacion, std::string guarnicion);

        std::string getObservacion();
        void setObservacion(std::string observacion);

        std::string getGuarnicion();
        void setGuarnicion(std::string guarnicion);

        void Cargar();
        void Mostrar();

};


#endif // COMIDA_H_INCLUDED
