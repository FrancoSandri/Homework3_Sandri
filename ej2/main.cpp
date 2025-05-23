#include <iostream>
#include "headers/procesadorfigura.hpp"



int main() {

    // Crear punto
    Punto p1(1.0f, 2.0f);
    cout << "Punto inicial: (" << p1.getX() << ", " << p1.getY() << ")\n";
    cout << "--Cambio las coordenadas del punto--" << endl;
    p1.setX(3.0f);
    p1.setY(4.0f);
    cout << "Punto modificado: (" << p1.getX() << ", " << p1.getY() << ")\n";

    ProcesadorFigura<Circulo> c1;
    ProcesadorFigura<Elipse> e1;
    ProcesadorFigura<Rectangulo> r1;

    // Probar Circulo
    Circulo c(p1, 5.0f);
    cout << "\nCentro del círculo: (" << c.getCentro().getX() << ", " << c.getCentro().getY() << ")\n";
    cout << "Radio del círculo: " << c.getRadio() << endl;
    cout << "--Cambio el radio del circulo--" << endl;
    c.setRadio(10.0f);
    cout << "Nuevo radio del círculo: " << c.getRadio() << endl;
    cout << "Área del círculo: " << c1.calcular_area(c) << endl;

    // Probar Elipse
    Elipse e(p1, 4.0f, 2.0f);
    cout << "\nCentro de la elipse: (" << e.getCentro().getX() << ", " << e.getCentro().getY() << ")\n";
    cout << "Semieje mayor: " << e.getSemiejeMayor() << endl;
    cout << "Semieje menor: " << e.getSemiejeMenor() << endl;
    cout << "--Cambios los semiejes de la elipse--" << endl;
    e.setSemiejeMayor(6.0f);
    e.setSemiejeMenor(3.0f);
    cout << "Nuevo semieje mayor: " << e.getSemiejeMayor() << endl;
    cout << "Nuevo semieje menor: " << e.getSemiejeMenor() << endl;
    cout << "Área de la elipse: " << e1.calcular_area(e) << endl;

    // Probar Rectángulo
    Rectangulo r(p1, 8.0f, 5.0f);
    cout << "\nVértice inferior izquierdo del rectángulo: (" << r.getVerticeIzquierdoInferior().getX() << ", " << r.getVerticeIzquierdoInferior().getY() << ")\n";
    cout << "Ancho: " << r.getAncho() << endl;
    cout << "Largo: " << r.getLargo() << endl;
    cout << "--Cambio el ancho y el largo del rectangulo--" << endl;
    r.setAncho(10.0f);
    r.setLargo(6.0f);
    cout << "Nuevo ancho: " << r.getAncho() << endl;
    cout << "Nuevo largo: " << r.getLargo() << endl;
    cout << "Área del rectángulo: " << r1.calcular_area(r) << endl;

    return 0;
}
