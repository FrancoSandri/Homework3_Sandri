#include "../headers/punto.hpp"

// Implementacion de los metodos de la clase Punto

void Punto::setX(float x){
    this->x = x;
}

void Punto::setY(float y){
    this->y = y;
}

float Punto::getX() const{
    return x;
}

float Punto::getY() const{
    return y;
}