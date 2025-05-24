#pragma once

#include "medicionbase.hpp"

class Posicion : public MedicionBase {
public:
    float latitud;
    float longitud;
    float altitud;

    Posicion(float lat = 0.0f, float lon = 0.0f, float alt = 0.0f, float t = 0.0f);
    Posicion(const Posicion& other);
    Posicion& operator=(const Posicion& other);

    float getTiempo() const override;
    void imprimir() const override;
    void serializar(ofstream& out) const override;
    void deserializar(ifstream& in) override;
};