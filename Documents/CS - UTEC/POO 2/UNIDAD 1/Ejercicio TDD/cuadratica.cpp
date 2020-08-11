//
// Created by Macarena Oyague on 2019-09-07.
//

#include <stdio.h>
#include <math.h>

class Cuadratica{
private:
    float a, b, c;
public:
    Cuadratica(float a, float b, float c) : a(a), b(b), c(c) {}

    float getA() const {
        return a;
    }

    void setA(float a) {
        Cuadratica::a = a;
    }

    float getB() const {
        return b;
    }

    void setB(float b) {
        Cuadratica::b = b;
    }

    float getC() const {
        return c;
    }

    void setC(float c) {
        Cuadratica::c = c;
    }

    float calcularX1() {
        float x1=(-b+sqrt(b*b-4*a*c))/(2*a);
        return x1;
    }

    float calcularX2() {
        float x2=(-b-sqrt(b*b-4*a*c))/(2*a);
        return x2;
    }

    bool calcularDiscriminante() {
        float discriminante=b*b-4*a*c;
        if (discriminante>=0)
            return true;
        else
            return false;
    }
};