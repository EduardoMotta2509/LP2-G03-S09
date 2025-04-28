#ifndef PERSONA_H
#define PERSONA_H

#include <iostream>
using namespace std;

class Persona{
private:
    int DNI;
    string direccion;
    string estadoCivil;
public:
    string nombre;
    int edad;
    string sexo;
    Persona(int _DNI, string _direccion, string _estadoCivil, string _nombre, int _edad, string _sexo){
        DNI=_DNI;
        direccion=_direccion;
        estadoCivil=_estadoCivil;
        nombre=_nombre;
        edad=_edad;
        sexo=_sexo;
    }
    
    int getDNI(){
        return DNI;
    }
    string getDireccion(){
        return direccion;
    }
    string getEstadoCivil(){
        return estadoCivil;
    }

    void setDNI(int _DNI){
        DNI=_DNI;
    }
    void setDireccion(string _direccion){
        direccion=_direccion;
    }
    void setEstadoCivil(string _estadoCivil){
        estadoCivil=_estadoCivil;
    }
    
};
#endif