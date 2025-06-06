#ifndef RECTANGULO_H 
#define RECTANGULO_H 
#include "FiguraGeometrica.h" 

class Rectangulo : public FiguraGeometrica { 
private: 
    double largo; 
    double ancho; 
public: 
    Rectangulo(double l, double a) : largo(l), ancho(a) {} 

    double calcularArea() override { 
        return largo * ancho; 
    } 

    double calcularPerimetro() override { 
        return 2 * (largo + ancho); 
    } 
}; 
#endif 