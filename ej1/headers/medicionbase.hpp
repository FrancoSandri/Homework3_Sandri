#pragma once
#include "imediciones.hpp"

class MedicionBase : public IMediciones {
protected:
    unique_ptr<float> tiempoMedicion;
public:
    MedicionBase(float t = 0.0f);
    MedicionBase(const MedicionBase& other);
    MedicionBase& operator=(const MedicionBase& other);
    virtual float getTiempo() const = 0;
    virtual void imprimir() const = 0;
    virtual ~MedicionBase() = default;
};