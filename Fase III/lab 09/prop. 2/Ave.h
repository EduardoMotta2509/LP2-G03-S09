#ifndef AVE_H
#define AVE_H

#include <iostream>
#include "Comportamiento.h"
using namespace std;

class Ave: public Comportamiento{
private:
    string plumaje;
    string tipoPico;
public:
    Ave(string p, string t): plumaje(p), tipoPico(t) {}
    
    void comer() override {
        cout<<"Comiendo alpiste..."<<endl;
    }
    void dormir() override{
        cout<<"Durmiendo en su nido..."<<endl;
    }
    void desplazarse() override{
        cout<<"Volando..."<<endl;
    }
};
#endif