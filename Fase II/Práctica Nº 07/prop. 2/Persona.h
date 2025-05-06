#ifndef PERSONA_H
#define PERSONA_H

#include <iostream>
using namespace std;

class Persona{
private:
    string nombre;
    int edad;
    float salario;
protected:
    string email;
public:
    Persona(string n, int e, float s, string mail): nombre(n), edad(e), salario(s), email(mail) {}
    
    void mostrarPersona(){
        cout<<"\n";
        cout<<"Atributos Persona: "<<endl;
        cout<<"     Nombre: "<<nombre<<endl;
        cout<<"       Edad: "<<edad<<endl;
        cout<<"    Salario: "<<salario<<endl;
        cout<<"      Email: "<<email<<endl;
        cout<<"\n";
    }
    
    void setEmail(string nuevo){
        email=nuevo;
        cout<<"     --> Nuevo email para PERSONA: "<<email<<" <--     "<<endl;
    }
};
#endif