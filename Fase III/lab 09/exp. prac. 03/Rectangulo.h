#include <iostream> 
#ifndef RECTANGULO_H 
#define RECTANGULO_H 

using namespace std; 

class Rectangulo : public Figura{ 
private: 
    double largo; 
    double ancho; 
public: 
    Rectangulo(double l, double a): largo(l), ancho(a){} 

    double calcularArea() override{ 
        return largo*ancho; 
    } 
}; 
#endif 