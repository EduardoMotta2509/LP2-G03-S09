#ifndef TRIANGULO_H 
#define TRIANGULO_H 

#include "FiguraGeometrica.h" 

class Triangulo : public FiguraGeometrica { 
    
private: 
    double base; 
    double altura; 
    double lado1; 
    double lado2; 
    double lado3; 
public: 
    Triangulo(double b, double h, double l1, double l2, double l3) 
        : base(b), altura(h), lado1(l1), lado2(l2), lado3(l3) {} 

    double calcularArea() override { 
        return (base * altura) / 2.0; 
    } 

    double calcularPerimetro() override { 
        return lado1 + lado2 + lado3; 
    } 
}; 
#endif 