#ifndef VEHICULO_H
#define VEHICULO_H

#include <iostream>
using namespace std;

class Vehiculo{
private:
    string marca;
    string modelo;
    int anio;
    float precio;
public:
    Vehiculo(string _marca, string _modelo, int a, float p): marca(_marca), modelo(_modelo), anio(a), precio(p) {}

    void mostrarVehiculo(){
        cout<<"\n";
        cout<<"INFO VEHICULO:"<<endl;
        cout<<"     Mara: "<<marca<<endl;
        cout<<"   Modelo: "<<modelo<<endl;
        cout<<"     Anio: "<<anio<<endl;
        cout<<"   Precio: "<<precio<<endl;
        cout<<"\n";
    }

};
#endif