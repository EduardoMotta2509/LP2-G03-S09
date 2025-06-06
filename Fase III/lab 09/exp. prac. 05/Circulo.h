#ifndef CIRCULO_H 
#define CIRCULO_H 

#include "FiguraGeometrica.h" 

class Circulo : public FiguraGeometrica { 
private: 
    double radio; 
public: 
    Circulo(double r) : radio(r) {} 
    double calcularArea() override { 
        return 3.14 * radio * radio; 
    } 

    double calcularPerimetro() override { 
        return 2 * 3.14 * radio; 
    } 
}; 
#endif 