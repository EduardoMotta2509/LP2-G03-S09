#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "Alumno.h"
#include "Grupo.h"
using namespace std;

int main(){
    Grupo g1(5);
    g1.agregarAlumno("Juan", 18, 18.6);
    g1.agregarAlumno("Maria", 18, 19.2);
    g1.agregarAlumno("Pedro", 18, 15.0);
    g1.agregarAlumno("Pablo", 19, 12.9);
    g1.agregarAlumno("Samira", 20, 10.5);

    g1.representarGrupo();
    g1.calcularPromedioGeneral();
    g1.mejorPromedio();

    return 0;
}