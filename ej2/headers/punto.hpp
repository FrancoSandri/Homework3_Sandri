#pragma once
#include <fstream>
#include <iostream>
#include <memory>
#include <type_traits>

using namespace std;

class Punto {
    private:
        float x;
        float y;
    public:
        Punto(float x, float y) : x(x), y(y){};
        void setX(float x);
        void setY(float y);
        float getX() const;
        float getY() const;
        ~Punto() = default;
};
