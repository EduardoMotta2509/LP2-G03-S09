#ifndef GUERRERO_H
#define GUERRERO_H

#include <iostream>
#include "HabilidadesBasicas.h"
using namespace std;

class Guerrero: public HabilidadesBasicas{
private:
    float espadaDMG;
    float armaduraDMG;
public:
    Guerrero(float e, float a): espadaDMG(e), armaduraDMG(a) {}

    void atacar() override {
        cout<<"Daño inflingido por la espada del guerrero: "<<espadaDMG<<endl;
    }
    void defender(float dmgRecibido) override {
        cout<<"Daño recibido: "<<dmgRecibido<<"...      ";
        if (dmgRecibido>armaduraDMG){
            cout<<"Armadura del guerrero rota"<<endl;
        }
        else{
            cout<<"resistencia de la armadura del guerrero pasó de "<<armaduraDMG<<" a "<<armaduraDMG-dmgRecibido<<endl;
        }
       
    }
    void Ultimate() override {
        cout<<"     ¡Tirando Ultimate!"<<endl;
        cout<<"     Guerrero tiró su Ultimate... ";
        cout<<"     Daño en área de "<<espadaDMG*5<<endl;
    }

};
#endif