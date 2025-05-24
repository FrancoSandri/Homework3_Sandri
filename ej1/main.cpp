#include "headers/medicionbase.hpp"
#include "headers/posicion.hpp"
#include "headers/presion.hpp"
#include "headers/saveflightdata.hpp"
#include <iostream>

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