#include "../headers/presion.hpp"
#include <iostream>

Presion::Presion(float p, float q, float t) : presionEstatica(p), presionDinamica(q) {
    tiempoMedicion = make_unique<float>(t);
};

float Presion::getTiempo() const {
    return *tiempoMedicion;
};

void Presion::imprimir() const {
    cout << "Presion: Estatica=" << presionEstatica
              << ", Dinamica=" << presionDinamica
              << ", Tiempo=" << getTiempo() << endl;
};

void Presion::serializar(ofstream& out) const {
    out.write(reinterpret_cast<const char*>(&presionEstatica), sizeof(presionEstatica));
    out.write(reinterpret_cast<const char*>(&presionDinamica), sizeof(presionDinamica));
    out.write(reinterpret_cast<const char*>(tiempoMedicion.get()), sizeof(float));
};

void Presion::deserializar(ifstream& in) {
    in.read(reinterpret_cast<char*>(&presionEstatica), sizeof(presionEstatica));
    in.read(reinterpret_cast<char*>(&presionDinamica), sizeof(presionDinamica));
    float t;
    in.read(reinterpret_cast<char*>(&t), sizeof(float));
    tiempoMedicion = make_unique<float>(t);
};

// Implementación de copy constructor y copy assignment para Posicion y Presion
// (necesario por el unique_ptr)

Presion::Presion(const Presion& other)
    : presionEstatica(other.presionEstatica), presionDinamica(other.presionDinamica) {
    if (other.tiempoMedicion)
        tiempoMedicion = std::make_unique<float>(*other.tiempoMedicion);
    else
        tiempoMedicion = nullptr;
};

Presion& Presion::operator=(const Presion& other) {
    if (this != &other) {
        presionEstatica = other.presionEstatica;
        presionDinamica = other.presionDinamica;
        if (other.tiempoMedicion)
            tiempoMedicion = std::make_unique<float>(*other.tiempoMedicion);
        else
            tiempoMedicion = nullptr;
    }
    return *this;
};
