#include "../headers/posicion.hpp"
#include <iostream>

Posicion::Posicion(float lat, float lon, float alt, float t)
    : latitud(lat), longitud(lon), altitud(alt) {
    tiempoMedicion = make_unique<float>(t);
};

float Posicion::getTiempo() const {
    return *tiempoMedicion;
};

void Posicion::imprimir() const {
    cout << "Posicion: Latitud=" << latitud
              << ", Longitud=" << longitud
              << ", Altitud=" << altitud
              << ", Tiempo=" << getTiempo() << endl;
};

void Posicion::serializar(ofstream& out) const {
    out.write(reinterpret_cast<const char*>(&latitud), sizeof(latitud));
    out.write(reinterpret_cast<const char*>(&longitud), sizeof(longitud));
    out.write(reinterpret_cast<const char*>(&altitud), sizeof(altitud));
    out.write(reinterpret_cast<const char*>(tiempoMedicion.get()), sizeof(float));
};

void Posicion::deserializar(ifstream& in) {
    in.read(reinterpret_cast<char*>(&latitud), sizeof(latitud));
    in.read(reinterpret_cast<char*>(&longitud), sizeof(longitud));
    in.read(reinterpret_cast<char*>(&altitud), sizeof(altitud));
    float t;
    in.read(reinterpret_cast<char*>(&t), sizeof(float));
    tiempoMedicion = make_unique<float>(t);
};

// Implementación de copy constructor y copy assignment para Posicion y Presion
// (necesario por el unique_ptr)
Posicion::Posicion(const Posicion& other)
    : latitud(other.latitud), longitud(other.longitud), altitud(other.altitud) {
    if (other.tiempoMedicion)
        tiempoMedicion = make_unique<float>(*other.tiempoMedicion);
    else
        tiempoMedicion = nullptr;
};

Posicion& Posicion::operator=(const Posicion& other) {
    if (this != &other) {
        latitud = other.latitud;
        longitud = other.longitud;
        altitud = other.altitud;
        if (other.tiempoMedicion)
            tiempoMedicion = make_unique<float>(*other.tiempoMedicion);
        else
            tiempoMedicion = nullptr;
    }
    return *this;
};