#include <iostream> 
#ifndef VACA_H 
#define VACA_H 
#include "Animal.h" 

using namespace std; 

class Vaca : public Animal { 
public: 
    void hacerSonido() override { 
        cout<<"MUUUUUU"<<endl; 
    } 
}; 
#endif 