#ifndef CIRCULO_H
#define CIRCULO_H

#include <iostream>
#include "AreaYPerimetro.h"
using namespace std;

class Circulo: public AreaYPerimetro{
private:
    double radio;
    double area;
    double perimetro;
public:
    Circulo(double r): radio(r) {}

    double calcularArea() override {
        return 3.14*radio*radio;
    }
    double calcularPerimetro() override {
        return 2*3.14*radio;
    }
    void mostrarInfo() override {
        area=calcularArea();
        perimetro=calcularPerimetro();
        cout<<"---Circulo---"<<endl;
        cout<<"El radio mide: "<<radio<<" u"<<endl;
        cout<<"El área es: "<<area<<" u^2"<<endl;
        cout<<"El perímetro es: "<<perimetro<<" u"<<endl;
    }

};
#endif