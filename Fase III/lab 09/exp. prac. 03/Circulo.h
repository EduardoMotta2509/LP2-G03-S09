#include <iostream> 
#ifndef CIRCULO_H 
#define CIRCULO_H 

using namespace std; 

class Circulo : public Figura{ 
private: 
    double radio; 
public: 
    Circulo(double r): radio(r){} 
    double calcularArea() override{ 
        return 3.14*radio*radio; 
    } 
}; 
#endif 