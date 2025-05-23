#pragma once
#include "punto.hpp"


class Circulo {
    private:
        Punto centro;
        float radio;
    public:
        Circulo(Punto centro, float radio) : centro(centro), radio(radio){};
        void setCentro(Punto centro);
        void setRadio(float radio);
        Punto getCentro() const;
        float getRadio() const;
        ~Circulo() = default;
};