#ifndef MISION_H
#define MISION_H

#include <iostream>


using namespace std;


class Mision{
private:
    string destino;
    float duracion;
    int tripulacion;
public:
    Mision(string _destino, float _duracion, int _tripulacion){
        destino=_destino;
        duracion=_duracion;
        tripulacion=_tripulacion;
    }
    
    string getDestino(){
        return destino;
    }
    float getDuración(){
        return duracion;
    }
    int getTripulacion(){
        return tripulacion;
    }
    
    void mostrarMision(){
        cout<<"·······Caracteristicas de la mision·······"<<endl;
        cout<<"     Destino: "<<destino<<endl;
        cout<<"     Duración: "<<duracion<<endl;
        cout<<"     Tripulación: "<<tripulacion<<endl;
    }
};
#endif