#pragma once
#include "punto.hpp"

class Elipse {
    private:
        Punto centro;
        float semiejeMayor;
        float semiejeMenor;
    public:
        Elipse(Punto centro, float semiejeMayor, float semiejeMenor) : centro(centro), semiejeMayor(semiejeMayor), semiejeMenor(semiejeMenor){};
        void setCentro(Punto centro);
        void setSemiejeMayor(float semiejeMayor);
        void setSemiejeMenor(float semiejeMenor);
        Punto getCentro () const;
        float getSemiejeMayor() const;
        float getSemiejeMenor() const;
        ~Elipse() = default;
};