#pragma once

#include "clase1.hpp"

class clase2 {
private:
    const clase1& c1;

    string vectorDoublesToJson(const vector<double>& v) const;
    string vectorStringsToJson(const vector<string>& v) const;
    string matrizToJson(const vector<vector<int>>& m) const;

public:
    explicit clase2(const clase1& c1);
    void imprimir() const;
};

