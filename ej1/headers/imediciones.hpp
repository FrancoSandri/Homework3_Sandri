#pragma once

#include <fstream>
#include <memory>

using namespace std;

class IMediciones {
public:
    virtual void serializar(ofstream& out) const = 0;
    virtual void deserializar(ifstream& in) = 0;
    virtual ~IMediciones() = default;
};
