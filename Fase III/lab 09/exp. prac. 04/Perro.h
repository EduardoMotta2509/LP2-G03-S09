#include <iostream> 
#ifndef PERRO_H 
#define PERRO_H 
#include "Animal.h" 

using namespace std; 

class Perro : public Animal{ 
public: 
    void hacerSonido() override { 
        cout<<"GUAUUU"<<endl; 
    } 
}; 
#endif 