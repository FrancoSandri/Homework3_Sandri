#pragma once

#include <vector>
#include <string>
#include <type_traits>

using namespace std;

class clase1 {
private:
    vector<double> vec_doubles;
    vector<string> palabras;
    vector<vector<int>> listas;

public:
    template<typename T>
    void agregar(const T& valor) {
        if constexpr (is_same_v<T, double>) {
            vec_doubles.push_back(valor);
        } else if constexpr (is_same_v<T, string>) {
            palabras.push_back(valor);
        } else if constexpr (is_same_v<T, vector<int>>) {
            listas.push_back(valor);
        } else {
            static_assert(is_same_v<T, void>, "Tipo no soportado");
        }
    }

    const vector<double>& getVecDoubles() const;

    const vector<string>& getPalabras() const;

    const vector<vector<int>>& getListas() const;
};

