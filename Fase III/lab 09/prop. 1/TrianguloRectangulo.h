#ifndef TRIANGULORECTANGULO_H
#define TRIANGULORECTANGULO_H

#include <iostream>
#include "AreaYPerimetro.h"
#include <cmath>
using namespace std;

class TrianguloRectangulo: public AreaYPerimetro{
private:
    double base;
    double altura;
    double area;
    double perimetro;
public:
    TrianguloRectangulo(double b, double h): base(b), altura(h) {}

    double calcularArea() override {
        return base*altura/2;
    }
    double calcularPerimetro() override {
        double hipotenusa=sqrt(base*base+altura*altura);
        return base+altura+hipotenusa;
    }
    void mostrarInfo() override {
        area=calcularArea();
        perimetro=calcularPerimetro();
        cout<<"---Triangulo Rectángulo---"<<endl;
        cout<<"La base mide: "<<base<<" u"<<endl;
        cout<<"La altura mide: "<<altura<<" u"<<endl;
        cout<<"El área es: "<<area<<" u^2"<<endl;
        cout<<"El perímetro es: "<<perimetro<<" u"<<endl;
    }

};
#endif