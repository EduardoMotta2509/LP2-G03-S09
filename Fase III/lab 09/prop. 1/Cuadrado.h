#ifndef CUADRADO_H
#define CUADRADO_H

#include <iostream>
#include "AreaYPerimetro.h"
using namespace std;

class Cuadrado: public AreaYPerimetro{
private:
    double lado;
    double area;
    double perimetro;
public:
    Cuadrado(double l): lado(l) {}

    double calcularArea() override {
        return lado*lado;
    }
    double calcularPerimetro() override {
        return 4*lado;
    }
    void mostrarInfo() override {
        area=calcularArea();
        perimetro=calcularPerimetro();
        cout<<"---CUADRADO---"<<endl;
        cout<<"El lado mide: "<<lado<<" u"<<endl;
        cout<<"El área es: "<<area<<" u^2"<<endl;
        cout<<"El perímetro es: "<<perimetro<<" u"<<endl;
    }

};
#endif