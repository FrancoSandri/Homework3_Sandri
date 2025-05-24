#include <iostream>
#include <vector>
#include <string>
#include <type_traits>
#include <sstream>
#include "../headers/clase1.hpp"

using namespace std;


// Implementación de los getters

const std::vector<double>& clase1::getVecDoubles() const {
    return vec_doubles;
}

const std::vector<std::string>& clase1::getPalabras() const {
    return palabras;
}

const std::vector<std::vector<int>>& clase1::getListas() const {
    return listas;
}