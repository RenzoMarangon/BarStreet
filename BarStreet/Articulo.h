#pragma once
#ifndef ARTICULO_H_INCLUDED
#define ARTICULO_H_INCLUDED

#include <string>

#include "Funciones.h"

class Articulo
{
    public:
        Articulo(int id, std::string nombre, float precio_inicial, float costo, int stock, float variacion);

        int getID();
        void setID(int id);

        std::string getNombre();
        void setNombre(std::string nombre);

        float getPrecioInicial();
        void setPrecioInicial(float precio_inicial);

        int getStock();
        void setStock(int stock);

        float getCosto();
        void setCosto( float costo );

        float getVariacion();
        void setVariacion( float variacion );

        bool getEstado();
        void setEstado(bool estado);

        void Cargar();
        void Mostrar();

    private:
        int _id;
        char _nombre[50];
        int _stock;
        float _costo;
        float _precio_inicial;
        float _variacion;
        bool _estado;
};

#endif // ARTICULO_H_INCLUDED
