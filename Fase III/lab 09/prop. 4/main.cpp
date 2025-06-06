#include <iostream>
using namespace std;

#include "Guerrero.h"
#include "Mago.h"
#include "Arquero.h"

int main(){
    Guerrero g1(200, 300.5);
    Mago m1(170, 300);
    Arquero a1(30, 190);

    g1.atacar();
    g1.defender(300);
    g1.Ultimate();

    m1.atacar();
    m1.defender(301);
    m1.Ultimate();

    a1.atacar();
    a1.defender(190);
    a1.Ultimate();
    return 0;
}
