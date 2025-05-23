#include "../headers/rectangulo.hpp"

void Rectangulo::setVerticeIzquierdoInferior(Punto verticeIzquierdoInferior){
    this->verticeIzquierdoInferior = verticeIzquierdoInferior;
}

void Rectangulo::setAncho(float ancho){
    this->ancho = ancho;
}

void Rectangulo::setLargo(float largo){
    this->largo = largo;
}

Punto Rectangulo::getVerticeIzquierdoInferior() const{
    return verticeIzquierdoInferior;
}

float Rectangulo::getAncho() const{
    return ancho;
}

float Rectangulo::getLargo() const{
    return largo;
}