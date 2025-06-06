#ifndef MAGO_H
#define MAGO_H

#include <iostream>
#include "HabilidadesBasicas.h"
using namespace std;

class Mago: public HabilidadesBasicas{
private:
    float hechizoDMG;
    float vida;
public:
    Mago(float h, float v): hechizoDMG(h), vida(v) {}

    void atacar() override {
        cout<<"Daño inflingido a distancia por el mago: "<<hechizoDMG<<endl;
    }
    void defender(float dmgRecibido) override {
        cout<<"Daño recibido: "<<dmgRecibido<<"...      ";
        if (dmgRecibido>vida){
            cout<<"Mago murió..."<<endl;
        }
        else{
            cout<<"vida del mago pasó de "<<vida<<" a "<<vida-dmgRecibido<<endl;
        }
        vida=vida-dmgRecibido;
       
    }
    void Ultimate() override {
        cout<<"     ¡Tirando Ultimate!"<<endl;
        if(vida>0.01){
            cout<<"     Mago tiró su Ultimate... ";
            cout<<"     Daño concentrado de "<<hechizoDMG*10<<endl;
        }
        else{
            cout<<"     El mago está muerto..."<<endl;
        }
    }

};
#endif