#include <iostream> 
#ifndef ANIMAL_H 
#define ANIMAL_H 

using namespace std; 

class Animal{ 
public: 
    virtual void hacerSonido(){ 
        cout<<"Sonido generico de animales"<<endl; 
    } 
}; 
#endif 