#ifndef CALCULADORA_H 
#define CALCULADORA_H 
#include <iostream> 
using namespace std; 
 
class Calculadora{ 
    public: 
    int sumar (int a, int b){ 
        return a+b; 
    } 
    double sumar(double a, double b){ 
        return a+b; 
    } 
    int sumar (int a, int b, int c){ 
        return a+b+c; 
    } 
}; 
#endif 