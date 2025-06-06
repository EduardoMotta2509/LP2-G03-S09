#include <iostream> 
#ifndef GATO_H 
#define GATO_H 
#include "Animal.h" 

using namespace std; 

class Gato : public Animal{ 
public: 
    void hacerSonido() override { 
        cout<<"MIAU"<<endl; 
    } 
}; 
#endif 