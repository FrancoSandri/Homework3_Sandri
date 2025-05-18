#pragma once

#include <fstream>
#include <iostream>
#include <memory>
#include <type_traits>

using namespace std;

class Punto {
    private:
        float x;
        float y;
    public:
        Punto(float x, float y) : x(x), y(y){};
        void setX(float x);
        void setY(float y);
        float getX() const;
        float getY() const;
        ~Punto() = default;
};

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

class Elipse {
    private:
        Punto centro;
        float semiejeMayor;
        float semiejeMenor;
    public:
        Elipse(Punto centro, float semiejeMayor, float semiejeMenor) : centro(centro), semiejeMayor(semiejeMayor), semiejeMenor(semiejeMenor){};
        void setCentro(Punto centro);
        void setSemiejeMayor(float semiejeMayor);
        void setSemiejeMenor(float semiejeMenor);
        Punto getCentro () const;
        float getSemiejeMayor() const;
        float getSemiejeMenor() const;
        ~Elipse() = default;
};

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

class ProcesadorFigura{
    public:
        template <typename T>
            static float calcularArea(const T& figura) {
                if constexpr (is_same_v<T, Circulo>) {
                    return 3.14159f * figura.getRadio() * figura.getRadio();
                } else if constexpr (is_same_v<T, Elipse>) {
                    return 3.14159f * figura.getSemiejeMayor() * figura.getSemiejeMenor();
                } else if constexpr (is_same_v<T, Rectangulo>) {
                    return figura.getAncho() * figura.getLargo();
                } else {
                    static_assert(is_same_v<T, void>, "Tipo de figura no soportado");
                }
            }
};