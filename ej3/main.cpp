#include "headers/clase1.hpp"
#include "headers/clase2.hpp"

int main() {
    
    clase1 datos;

    datos.agregar(1.3);
    datos.agregar(2.1);
    datos.agregar(3.2);

    datos.agregar(string("Hola"));
    datos.agregar(string("Mundo"));

    datos.agregar(vector<int>{1, 2});
    datos.agregar(vector<int>{3, 4});

    clase2 json(datos);
    json.imprimir();

    return 0;
}
