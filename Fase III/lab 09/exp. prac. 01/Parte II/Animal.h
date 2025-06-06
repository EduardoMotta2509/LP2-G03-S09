#ifndef ANIMAL_H 
#define ANIMAL_H 

#include <iostream> 
using namespace std; 

class Animal{ 
    public: 
    virtual void hacerSonido(){ 
        cout<<"Sonido de un animal"<<endl; 
    }
    ~Animal() {}
}; 
#endif 