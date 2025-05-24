#pragma once

#include "imediciones.hpp"
#include "posicion.hpp"
#include "presion.hpp"

class SaveFlightData : public IMediciones {
public:
    Posicion posicion;
    Presion presion;

    SaveFlightData(const Posicion& p = Posicion(), const Presion& q = Presion());
    void serializar(ofstream& out) const override;
    void deserializar(ifstream& in) override;
    void imprimir() const;
};
