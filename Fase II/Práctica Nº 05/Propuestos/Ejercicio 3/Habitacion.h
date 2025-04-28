#ifndef HABITACION_H
#define HABITACION_H

#include <iostream>
using namespace std;

class Habitacion{
private:
    int numero;
    string tipo;
    float precioPorNoche;
public:
    Habitacion() : numero(0), tipo(""), precioPorNoche(0.0) {}
    Habitacion(int n, string t, float p):numero(n), tipo(t), precioPorNoche(p){}

    void mostrarHabitacion(){
        cout<<"     Nro: "<<numero<<" Tipo: "<<tipo<<" Precio x noche: "<<precioPorNoche<<endl;
    }

    float getPrecioXNoche(){ return precioPorNoche; }

};
#endif