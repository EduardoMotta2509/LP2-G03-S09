#include<iostream>
#include "Padre.h"
#include "Hijo.h"
using namespace std;
Padre::Padre(){
    numHijos = 0;
}
Padre::Padre(string nom){
    nombre = nom;
    numHijos= 0;
}

void Padre::setNombre(string nom){
    nombre = nom;
}

string Padre::getNombre(){
    return nombre;
}

void Padre::agregarHijo(Hijo* h){
    if (numHijos<max_hijos){
        hijos[numHijos] = h;
        numHijos++;
    }
    else{
        cout<<"No se pueden añadir mas hijos ya que llegó al límite."<<endl;
    }
}

void Padre::imprimirInfo(){
    cout<<"El papá es: "<<nombre<<endl;
    cout<<"La cantidad de hijos que tiene es: "<<numHijos<<endl;
    for(int i=0; i<numHijos;i++){
        cout<<"Hijo "<< i + 1<< ": "<<hijos[i]->getNombre()<<endl;
    }
}

Hijo::Hijo(){}
Hijo::Hijo(string nom){
    nombre = nom;
}

void Hijo::setNombre(string nom){
    nombre = nom;
}

string Hijo::getNombre(){
    return nombre;
}

int main() {
    Padre padre("Eduardo");

    Hijo hijo1("Leandro");
    Hijo hijo2("Nicolas");
    Hijo hijo3("André");

    padre.agregarHijo(&hijo1);
    padre.agregarHijo(&hijo2);
    padre.agregarHijo(&hijo3);

    padre.imprimirInfo();

    return 0;
}