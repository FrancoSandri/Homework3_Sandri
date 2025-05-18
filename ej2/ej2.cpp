#include "ej2.hpp"
#include <iostream>
#include <type_traits>

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

//Implementacion de los metodos de la clase Rectangulo

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

int main() {
    // Crear puntos
    Punto p1(1.0f, 2.0f);
    cout << "Punto inicial: (" << p1.getX() << ", " << p1.getY() << ")\n";
    p1.setX(3.0f);
    p1.setY(4.0f);
    cout << "Punto modificado: (" << p1.getX() << ", " << p1.getY() << ")\n";

    // Probar Circulo
    Circulo c(p1, 5.0f);
    cout << "\nCentro del círculo: (" << c.getCentro().getX() << ", " << c.getCentro().getY() << ")\n";
    cout << "Radio del círculo: " << c.getRadio() << "\n";
    c.setRadio(10.0f);
    cout << "Nuevo radio del círculo: " << c.getRadio() << "\n";
    cout << "Área del círculo: " << ProcesadorFigura::calcularArea(c) << "\n";

    // Probar Elipse
    Elipse e(p1, 4.0f, 2.0f);
    cout << "\nCentro de la elipse: (" << e.getCentro().getX() << ", " << e.getCentro().getY() << ")\n";
    cout << "Semieje mayor: " << e.getSemiejeMayor() << "\n";
    cout << "Semieje menor: " << e.getSemiejeMenor() << "\n";
    e.setSemiejeMayor(6.0f);
    e.setSemiejeMenor(3.0f);
    cout << "Área de la elipse: " << ProcesadorFigura::calcularArea(e) << "\n";

    // Probar Rectángulo
    Rectangulo r(p1, 8.0f, 5.0f);
    cout << "\nVértice inferior izquierdo del rectángulo: (" << r.getVerticeIzquierdoInferior().getX() << ", " << r.getVerticeIzquierdoInferior().getY() << ")\n";
    cout << "Ancho: " << r.getAncho() << "\n";
    cout << "Largo: " << r.getLargo() << "\n";
    r.setAncho(10.0f);
    r.setLargo(6.0f);
    cout << "Área del rectángulo: " << ProcesadorFigura::calcularArea(r) << "\n";

    return 0;
}
