#ifndef MOTOCICLETA_H
#define MOTOCICLETA_H

#include <iostream>
using namespace std;
#include "Vehiculo.h"

class Motocicleta : public Vehiculo{
private:
    float cilindrada;
public:
    Motocicleta(string _marca, string _modelo, int a, float p, float c): Vehiculo(_marca, _modelo, a, p), cilindrada(c) {}

    void mostrarMotocicleta(){
        mostrarVehiculo();
        cout<<"INFO MOTOCICLETA:"<<endl;
        cout<<"   Cilindrada: "<<cilindrada<<endl;
        cout<<"\n";
    }

};
#endif