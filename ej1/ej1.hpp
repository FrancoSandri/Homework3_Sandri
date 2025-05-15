#pragma once
#include <fstream>
#include <memory>

using namespace std;

// Interfaz IMediciones
class IMediciones {
public:
    virtual void serializar(ofstream& out) const = 0;
    virtual void deserializar(ifstream& in) = 0;
    virtual ~IMediciones() = default;
};

// Clase abstracta MedicionBase
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

// Clase Presion
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

// Clase Posicion
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

// Clase SaveFlightData
class SaveFlightData : public IMediciones {
public:
    Posicion posicion;
    Presion presion;

    SaveFlightData(const Posicion& p = Posicion(), const Presion& q = Presion());
    void serializar(ofstream& out) const override;
    void deserializar(ifstream& in) override;
    void imprimir() const;
};
