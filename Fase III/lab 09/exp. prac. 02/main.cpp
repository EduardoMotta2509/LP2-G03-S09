#include <iostream> 
#include "Calculadora.h" 
using namespace std; 
int main(){ 
    Calculadora calc; 
    cout<<calc.sumar(1,2)<<endl; 
    cout<<calc.sumar(3.3,4.4)<<endl; 
    cout<<calc.sumar(1,2,3)<<endl; 
} 