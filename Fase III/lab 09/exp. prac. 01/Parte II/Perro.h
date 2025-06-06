#ifndef PERRO_H 
#define PERRO_H 

#include <iostream> 
using namespace std; 

class Perro : public Animal{ 
public: 
    void hacerSonido(){ 
        cout<<"El perro hace guau"<<endl; 
    } 
}; 
#endif 