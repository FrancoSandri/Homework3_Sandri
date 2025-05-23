#pragma once
#include "circulo.hpp"
#include "elipse.hpp"
#include "rectangulo.hpp"
#include <iostream>

template <typename T>
class ProcesadorFigura{
    public:
        void calcular_area(T&){
            cout << "Tipo no soportado" << endl;
        };
};

template <>
class ProcesadorFigura<Circulo>{
    public:
        float calcular_area(Circulo& circulo){
            float area = 3.14159 * circulo.getRadio() * circulo.getRadio();
            return area;
        };
};

template <>
class ProcesadorFigura<Elipse>{
    public:
        float calcular_area(Elipse& elipse){
            float area = 3.14159 * elipse.getSemiejeMayor() * elipse.getSemiejeMenor();
            return area;
        };
};

template <>
class ProcesadorFigura<Rectangulo>{
    public:
        float calcular_area(Rectangulo& rectangulo){
            float area = rectangulo.getAncho() * rectangulo.getLargo();
            return area;
        };
};