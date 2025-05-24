#include "../headers/medicionbase.hpp"

// Implementación de MedicionBase
MedicionBase::MedicionBase(float t) {
    tiempoMedicion = make_unique<float>(t);
};

MedicionBase::MedicionBase(const MedicionBase& other) {
    if (other.tiempoMedicion)
        tiempoMedicion = make_unique<float>(*other.tiempoMedicion);
    else
        tiempoMedicion = nullptr;
};

MedicionBase& MedicionBase::operator=(const MedicionBase& other) {
    if (this != &other) {
        if (other.tiempoMedicion)
            tiempoMedicion = make_unique<float>(*other.tiempoMedicion);
        else
            tiempoMedicion = nullptr;
    }
    return *this;
};