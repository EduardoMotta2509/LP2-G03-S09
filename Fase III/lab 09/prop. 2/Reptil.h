#ifndef REPTIL_H
#define REPTIL_H

#include <iostream>
#include "Comportamiento.h"
using namespace std;

class Reptil: public Comportamiento{
private:
    bool esVenenoso;
    string locomocion;
public:
    Reptil(bool e, string l): esVenenoso(e), locomocion(l) {}
    
    void comer() override {
        cout<<"Comiendo insectos..."<<endl;
    }
    void dormir() override{
        cout<<"Durmiendo en su escondite..."<<endl;
    }
    void desplazarse() override{
        cout<<"El reptil empezó a "<<locomocion<<"..."<<endl;
    }
};
#endif