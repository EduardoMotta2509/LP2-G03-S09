#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include <iostream>
using namespace std;
class Estudiante{
private:
    string nombre;
    int edad;
    string grado;
    float nota=0;
    string curso;
    bool val=false;
    float desempeño=0; //Un valor entre 0 y 1 que indica el rendimiento del estudiante (0 = bajo rendimiento, 1 = rendimiento máximo).
public:
    Estudiante(string _nombre, int _edad, string _grado, string _curso){
        nombre=_nombre;
        edad=_edad;
        grado=_grado;
        curso=_curso;
    }
    void tomarExamen(float _desempeño){
        if(_desempeño<0||_desempeño>1){
            val=false;
            cout<<"Desempeño ingresado ("<<_desempeño<<") fuera de rango: (0-1)"<<endl;
        }
        else{
            val=true;
            cout<<"Tomando examen del curso "<<curso<<" al estudiante: "<<nombre<<endl;
            nota=_desempeño*20;
        }
    }
    void recibirCalificacion(){
        if(val==true){
            cout<<"Nota del curso: "<<curso<<" del estudiante: "<<nombre<<" --> "<<nota<<endl;
        }
        else{
            cout<<"-"<<endl;
        }
    }
};
#endif