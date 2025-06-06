#include <iostream> 
#ifndef TRIANGULO_H 
#define TRIANGULO_H 

using namespace std; 

class Triangulo : public Figura{ 
private: 
    double base; 
    double altura; 
public: 
    Triangulo(double b, double a):base(b),altura(a){} 
    double calcularArea() override{ 
        return (base*altura)/2; 
    } 
}; 
#endif 