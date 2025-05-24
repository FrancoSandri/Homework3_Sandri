#include "../headers/saveflightdata.hpp"
#include <iostream>

// Para permitir la copia, implementamos copy constructor y copy assignment operator
SaveFlightData::SaveFlightData(const Posicion& p, const Presion& q)
    : posicion(p), presion(q) {};

void SaveFlightData::serializar(ofstream& out) const {
    posicion.serializar(out);
    presion.serializar(out);
};

void SaveFlightData::deserializar(ifstream& in) {
    posicion.deserializar(in);
    presion.deserializar(in);
};

void SaveFlightData::imprimir() const {
    cout << "SaveFlightData:" << endl;
    posicion.imprimir();
    presion.imprimir();
};