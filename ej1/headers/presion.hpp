#pragma once

#include "medicionbase.hpp"

class Presion : public MedicionBase {
public:
    float presionEstatica;
    float presionDinamica;

    Presion(float p = 0.0f, float q = 0.0f, float t = 0.0f);
    Presion(const Presion& other);
    Presion& operator=(const Presion& other);

    float getTiempo() const override;
    void imprimir() const override;
    void serializar(ofstream& out) const override;
    void deserializar(ifstream& in) override;
};