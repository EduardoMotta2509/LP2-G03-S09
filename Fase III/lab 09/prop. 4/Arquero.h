#ifndef ARQUERO_H
#define ARQUERO_H

#include <iostream>
#include "HabilidadesBasicas.h"
using namespace std;

class Arquero: public HabilidadesBasicas{
private:
    float flechaDMG;
    float escudoDMG;
public:
    Arquero(float f, float e): flechaDMG(f), escudoDMG(e) {}

    void atacar() override {
        cout<<"Daño inflingido por segundo por el arquero: "<<flechaDMG*2<<endl;
    }
    void defender(float dmgRecibido) override {
        cout<<"Daño recibido: "<<dmgRecibido<<"...      ";
        if (dmgRecibido>escudoDMG){
            cout<<"Escudo del arquero se rompió..."<<endl;
        }
        else{
            cout<<"vida del escudo del arquero bajo de "<<escudoDMG<<" a "<<escudoDMG-dmgRecibido<<endl;
        }
       
    }
    void Ultimate() override {
        cout<<"     ¡Tirando Ultimate!"<<endl;
        cout<<"     Arquero tiró su Ultimate... ";
        cout<<"     daño de la lluvia de flechas en área "<<flechaDMG*40<<endl;
    }

};
#endif