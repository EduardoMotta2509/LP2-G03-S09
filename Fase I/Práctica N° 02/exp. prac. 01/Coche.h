#ifndef COCHE_H
#define COCHE_H

#include <iostream>
using namespace std;
class Coche{
private:
    string modelo;
    int anio;
    float velocidad;
public:
    Coche(string _modelo, int _anio, float _velocidad){
        modelo=_modelo;
        anio=_anio;
        velocidad=_velocidad;
    }
    void acelerar(float _velocidad){
        cout<<"\nAumentando: "<<_velocidad<<"Km/h"<<" al vehiculo "<<modelo<<endl;
        cout<<"     se incrementó la velocidad de "<<velocidad<<"Km/h"<<" --> "<<velocidad+_velocidad<<"Km/h"<<"\n"<<endl;
        velocidad=velocidad+_velocidad;
    }
    void frenar(){
        velocidad = 0;
        cout<<"\nEl vehiculo "<<modelo<<" se detuvo"<<endl;
        cout<<" velocidad actual: "<<velocidad<<"Km/h"<<"\n"<<endl;
    }
};
#endif