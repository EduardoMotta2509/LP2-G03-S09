#ifndef AVION_H
#define AVION_H

#include <iostream>
#include "Mision.h"

using namespace std;


class Avion{
private:
    float capacidadCombustible;
    float combustibleDisponible;
    int aforo;
    float consumo;
    bool viable=false;
public:
    Avion(float _capacidadCombustible,float _combustibleDisponible, int _aforo, float _consumo){
        capacidadCombustible=_capacidadCombustible;
        combustibleDisponible=_combustibleDisponible;
        aforo=_aforo;
        consumo=_consumo;
    }
    void mostrarInfo(){
        cout<<"········Caracteristicas del avion········"<<endl;
        cout<<"     Capacidad de combustible: "<<capacidadCombustible<<endl;
        cout<<"     Combustible disponible: "<<combustibleDisponible<<endl;
        cout<<"     Aforo: "<<aforo<<endl;
        cout<<"     Consumo por hora: "<<consumo<<endl;
        if (viable==true){
            cout<<"     Estado para la mision: VIABLE"<<endl;
        }
        else{
            cout<<"     Estado para la mision: NO VIABLE"<<endl;
        }
        
        
        
    }
    void simularMision(Mision _mision){
        float horasVuelo = combustibleDisponible/consumo;
        if(_mision.getDuración()<horasVuelo&&aforo>_mision.getTripulacion()){
            cout<<"---------------------------------------"<<endl;
            cout<<"         Avion aprobado"<<endl;
            cout<<"Duracion de la mision: "<<_mision.getDuración()<<endl;
            cout<<"     Horas de vuelo del avion: "<<horasVuelo<<endl;
            cout<<"Tripulacion de la mision: "<<_mision.getTripulacion()<<endl;
            cout<<"     Aforo del avion: "<<aforo<<endl;
            cout<<"---------------------------------------"<<endl;
            viable=true;
        }
        else{
            cout<<"         Avion NO aprobado"<<endl;
            cout<<"---------------------------------------"<<endl;
            cout<<"Duracion de la mision: "<<_mision.getDuración()<<endl;
            cout<<"     Horas de vuelo del avion: "<<horasVuelo<<endl;
            cout<<"Tripulacion de la mision: "<<_mision.getTripulacion()<<endl;
            cout<<"     Aforo del avion: "<<aforo<<endl;
            cout<<"---------------------------------------"<<endl;
            viable=false;
        }
    }
};
#endif