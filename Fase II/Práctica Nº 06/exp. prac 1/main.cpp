#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class Estudiante{
private:
    string nombre;
    int codigo;
    float nota;
public:
Estudiante(): nombre(""), codigo(0), nota(0.0){}
    Estudiante(string n, int c, float _nota): nombre(n), codigo(c), nota(_nota){}

    float getNota() const { return nota;}

    void mostrarEst(){
        cout<<"     Nombre: "<<nombre<<" código: "<<codigo<<" nota: "<<nota<<endl;
    }
};

int main(){
    vector<Estudiante> estudiantes;

    estudiantes.emplace_back("Joel", 100, 19.8);
    estudiantes.emplace_back("Maria", 101, 15.7);
    estudiantes.emplace_back("Pablo", 102, 14.3);
    estudiantes.emplace_back("Pedro", 103, 18.2);
    
    cout<<"\nEstudiantes matriculados SIN ORDENAR:"<<endl;
    
    for(int i=0; i<estudiantes.size(); i++){
        estudiantes[i].mostrarEst();
    }
    
    //Ordenamos el vector 
    sort(estudiantes.begin(), estudiantes.end(), [](const Estudiante& a, const Estudiante& b) {
        return a.getNota() < b.getNota();
    });
    
    cout<<"\nEstudiantes matriculados ORDENADOS:"<<endl;
    
    for(int i=0; i<estudiantes.size(); i++){
        estudiantes[i].mostrarEst();
    }
    
    cout<<"\nEstudiantes con promedio mayor a 11.5: "<<endl;
    
    for(int i=0; i<estudiantes.size(); i++){
        if(estudiantes[i].getNota() >= 11.5){
            estudiantes[i].mostrarEst();
        }
    }
    return 0;
}

    