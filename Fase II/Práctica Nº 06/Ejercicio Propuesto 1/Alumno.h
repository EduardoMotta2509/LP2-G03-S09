#ifndef ALUMNO_H
#define ALUMNO_H

#include <iostream>
using namespace std;

class Alumno{
private:
    string nombre;
    int edad;
    float promedio;
public:
    Alumno() : nombre(""), edad(0), promedio(0.0) {} 
    Alumno(string n, int e, float p): nombre(n), edad(e), promedio(p) {}

    string representarAlumno(){
        return nombre;
    }
    
    float getPromedio() const { return promedio; }
    string getNombre() const { return nombre; }
    
    bool compararPromedio(const Alumno otro){
        if (promedio<otro.promedio){
            return true;
        }
        else{
            return false;
        }
    }
    
};
#endif
