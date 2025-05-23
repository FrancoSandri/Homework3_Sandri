#include "../headers/circulo.hpp"

//Implementacion de los metodos de la clase Circulo

void Circulo::setCentro(Punto centro){
    this->centro = centro;
}

void Circulo::setRadio(float radio){
    this->radio = radio;
}

Punto Circulo::getCentro() const{
    return centro;
}

float Circulo:: getRadio() const{
    return radio;
}