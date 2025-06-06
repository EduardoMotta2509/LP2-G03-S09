#ifndef MAMIFERO_H
#define MAMIFERO_H

#include <iostream>
#include "Comportamiento.h"
using namespace std;

class Mamifero: public Comportamiento{
private:
    string alimentacion;
    string ecosistema;
public:
    Mamifero(string a, string e): alimentacion(a), ecosistema(e) {}
    
    void comer() override {
        cout<<"Comiendo "<<alimentacion<<"..."<<endl;
    }
    void dormir() override{
        cout<<"Durmiendo en "<<ecosistema<<"..."<<endl;
    }
    void desplazarse() override{
        cout<<"Caminando..."<<endl;
    }
};
#endif