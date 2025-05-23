#pragma once
#include "punto.hpp"

class Rectangulo {
    private:
        Punto verticeIzquierdoInferior;
        float ancho;
        float largo;
    public:
        Rectangulo(Punto verticeIzquierdoInferior, float ancho, float largo) : verticeIzquierdoInferior(verticeIzquierdoInferior), ancho(ancho), largo(largo){};
        void setVerticeIzquierdoInferior(Punto verticeIzquierdoInferior);
        void setAncho(float ancho);
        void setLargo(float largo);
        Punto getVerticeIzquierdoInferior() const;
        float getAncho() const;
        float getLargo() const;
        ~Rectangulo() = default;
};