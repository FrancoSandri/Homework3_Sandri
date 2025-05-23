#include "../headers/elipse.hpp"

//Implementacion de los metodos de la clase Elipse

void Elipse::setCentro(Punto centro){
    this->centro = centro;
}

void Elipse::setSemiejeMayor(float semiejeMayor){
    this->semiejeMayor = semiejeMayor;
}

void Elipse::setSemiejeMenor(float semiejeMenor){
    this->semiejeMenor = semiejeMenor;
}

Punto Elipse::getCentro() const{
    return centro;
}

float Elipse::getSemiejeMayor() const{
    return semiejeMayor;
}

float Elipse::getSemiejeMenor() const{
    return semiejeMenor;
}