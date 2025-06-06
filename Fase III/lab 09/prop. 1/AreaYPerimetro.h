#ifndef AREAYPERIMETRO_H
#define AREAYPERIMETRO_H

#include <iostream>
using namespace std;

class AreaYPerimetro{
public:
    AreaYPerimetro() {}
    virtual double calcularArea() = 0;
    virtual double calcularPerimetro() = 0;
    virtual void mostrarInfo() = 0;
    
    ~AreaYPerimetro() {}
};
#endif