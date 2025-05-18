#include <iostream>
#include <vector>
#include <string>
#include <type_traits>
#include <sstream>

using namespace std;

class clase1 {
    private:
        vector<double> vec_doubles;
        vector<string> palabras;
        vector<vector<int>> listas;
    
    public:

        template<typename T>
        void agregar(const T& valor){
            if constexpr (is_same_v<T, double>) {
                vec_doubles.push_back(valor); 
            } else if constexpr (is_same_v<T, string>) {
                palabras.push_back(valor);
            } else if constexpr (is_same_v<T, vector<int>>){
                listas.push_back(valor);
            } else {
                static_assert(is_same_v<T, void>, "Tipo no soportado");
            }
        }

        const vector<double>& getVecDoubles() const {return vec_doubles;}
        const vector<string>& getPalabras() const {return palabras;}
        const vector<vector<int>>& getListas() const {return listas;}
};

class clase2 {
    private:
        const clase1& c1;
    
        string vectorDoublesToJson(const vector<double>& v) const {
            ostringstream oss;
            oss << "[";
            for (size_t i = 0; i< v.size(); i++){
                oss << v[i];
                if(i < v.size() - 1) oss << ",";
            } 
            oss << "]";
            return oss.str();
        }
        string vectorStringsToJson(const vector<string>& v) const {
            ostringstream oss;
            oss << "[";
            for (size_t i = 0; i < v.size(); ++i) {
                oss << "\"" << v[i] << "\"";
                if (i < v.size() - 1) oss << ", ";
            }
            oss << "]";
            return oss.str();
        }
        string matrizToJson(const vector<vector<int>>& m) const {
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
    public:
        clase2(const clase1& c1) : c1(c1){};

        void imprimir() const {
        cout << "{\n";
        cout << "  \"vec_doubles\": " << vectorDoublesToJson(c1.getVecDoubles()) << ",\n";
        cout << "  \"palabras\": " << vectorStringsToJson(c1.getPalabras()) << ",\n";
        cout << "  \"listas\": " << matrizToJson(c1.getListas()) << "\n";
        cout << "}" << endl;
    }

};

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
