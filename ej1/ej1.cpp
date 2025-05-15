#include <iostream>
#include <fstream>
#include <memory>
#include "ej1.hpp"

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

// Implementación de Presion
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

// Implementación de Posicion
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

// Implementación de SaveFlightData
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

void test_posicion() {
    Posicion pos(10.0f, 20.0f, 100.0f, 1.5f);
    pos.imprimir();
    ofstream out("posicion.bin", ios::binary);
    pos.serializar(out);
    out.close();
    Posicion pos2;
    ifstream in("posicion.bin", ios::binary);
    pos2.deserializar(in);
    in.close();
    cout << "Deserializada: ";
    pos2.imprimir();
};

void test_presion() {
    Presion pres(101.3f, 5.8f, 2.2f);
    pres.imprimir();
    ofstream out("presion.bin", ios::binary);
    pres.serializar(out);
    out.close();
    Presion pres2;
    ifstream in("presion.bin", ios::binary);
    pres2.deserializar(in);
    in.close();
    cout << "Deserializada: ";
    pres2.imprimir();
};

void test_save_flight_data() {
    Posicion pos(-34.6f, -58.4f, 950.0f, 5.3f);
    Presion pres(101.3f, 5.8f, 6.1f);
    SaveFlightData flightData(pos, pres);
    flightData.imprimir();
    ofstream out("flightdata.bin", ios::binary);
    flightData.serializar(out);
    out.close();
    SaveFlightData flightData2;
    ifstream in("flightdata.bin", ios::binary);
    flightData2.deserializar(in);
    in.close();
    cout << "Deserializada: " << endl;
    flightData2.imprimir();
};

int main() {
    cout << "--- Test Posicion ---" << endl;
    test_posicion();
    cout << "\n--- Test Presion ---" << endl;
    test_presion();
    cout << "\n--- Test SaveFlightData ---" << endl;
    test_save_flight_data();
    return 0;
};