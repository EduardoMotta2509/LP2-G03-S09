#ifndef AUTOMOVIL_H
#define AUTOMOVIL_H

#include <iostream>
using namespace std;
#include "Vehiculo.h"

class Automovil : public Vehiculo{
private:
    int nroPuertas;
    string tipoCombustible;
public:
    Automovil(string _marca, string _modelo, int a, float p, int n, string t): Vehiculo(_marca, _modelo, a, p), nroPuertas(n), tipoCombustible(t) {}

    void mostrarAutomovil(){
        mostrarVehiculo();
        cout<<"INFO AUTOMOVIL:"<<endl;
        cout<<"    # Puertas: "<<nroPuertas<<endl;
        cout<<"  Combustible: "<<tipoCombustible<<endl;
        cout<<"\n";
    }
    
};
#endif