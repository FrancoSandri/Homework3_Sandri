#include "../headers/clase2.hpp"
#include <iostream>
#include <sstream>

using namespace std;

clase2::clase2(const clase1& c1) : c1(c1) {}

string clase2::vectorDoublesToJson(const vector<double>& v) const {
    ostringstream oss;
    oss << "[";
    for (size_t i = 0; i < v.size(); i++) {
        oss << v[i];
        if (i < v.size() - 1) oss << ",";
    }
    oss << "]";
    return oss.str();
}

string clase2::vectorStringsToJson(const vector<string>& v) const {
    ostringstream oss;
    oss << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        oss << "\"" << v[i] << "\"";
        if (i < v.size() - 1) oss << ", ";
    }
    oss << "]";
    return oss.str();
}

string clase2::matrizToJson(const vector<vector<int>>& m) const {
    ostringstream oss;
    oss << "[\n";
    for (size_t i = 0; i < m.size(); ++i) {
        oss << "  [";
        for (size_t j = 0; j < m[i].size(); ++j) {
            oss << m[i][j];
            if (j < m[i].size() - 1) oss << ", ";
        }
        oss << "]";
        if (i < m.size() - 1) oss << ",";
        oss << "\n";
    }
    oss << "]";
    return oss.str();
}

void clase2::imprimir() const {
    cout << "{\n";
    cout << "  \"vec_doubles\": " << vectorDoublesToJson(c1.getVecDoubles()) << ",\n";
    cout << "  \"palabras\": " << vectorStringsToJson(c1.getPalabras()) << ",\n";
    cout << "  \"listas\": " << matrizToJson(c1.getListas()) << "\n";
    cout << "}" << endl;
}