#include <iostream>
using namespace std;

#include "Asignatura.h"
#include "Asistencia.h"
#include "Estudiante.h"
#include "Notas.h"
#include "Profesor.h"
#include "RendimientoEstudiante.h"
#include "RegistroEstudiantes.h"

//version 22:27
int main() {
    // Crear profesores
    Profesor prof1("Ana Gómez", "Calle Luna 123", "987654321", {});
    Profesor prof2("Carlos Pérez", "Calle Sol 456", "123456789", {});

    // Crear asignaturas
    Asignatura mat("MAT101", "Matemáticas", "Álgebra y cálculo", &prof1);
    Asignatura bio("BIO202", "Biología", "Estructura celular", &prof2);
    Asignatura quimi("QUI202", "Química", "Enlaces", &prof2);

    // Agregar asignaturas a los profesores
    prof1.asignarNuevoCurso(mat);
    prof2.asignarNuevoCurso(bio);
    prof2.asignarNuevoCurso(quimi);

    // Crear estudiante
    vector<Asignatura> asignaturasEst1 = {mat, bio};
    Estudiante est1("Lucía Martínez", "Av. Siempre Viva 742", "20230001", asignaturasEst1);
    
    vector<Asignatura> asignaturasEst2 = {mat, quimi};
    Estudiante est2("Mirkala Banda", "Av. Locurita 666", "20240002", asignaturasEst2);

    // Crear notas
    vector<float> notasEst1 = {18.5, 15.0};
    Notas notas1(&est1, notasEst1);
    
    vector<float> notasEst2 = {20.0, 17.0};
    Notas notas2(&est2, notasEst2);

    // Crear asistencia
        //Estudiante 1 Lucía
    vector<string> asistMat = {"Presete", "Presete", "Ausente", "Presete"}; 
    vector<string> asistBio = {"Presete", "Ausente", "Presete", "Presete"};
    vector<vector<string>> asistenciaGeneral1 = {asistMat, asistBio};
    Asistencia asistencia1(&est1, asistenciaGeneral1);
    
        //Estudiante 1 Mirkala
    vector<string> asistMat1 = {"Presete", "Presete", "Presente", "Presete"}; 
    vector<string> asistQuim = {"Presete", "Presente", "Presete", "Presete"};
    vector<vector<string>> asistenciaGeneral2 = {asistMat1, asistQuim};
    Asistencia asistencia2(&est1, asistenciaGeneral2);
    asistencia2.imprimirReporteGeneral();
    

    // Registrar asistencia para verificar método
    asistencia1.registrarAsistenciaCurso("MAT101", asistMat);
    asistencia1.registrarAsistenciaCurso("BIO202", asistBio);

    // Consolidar rendimiento
    RendimientoEstudiante rendimiento1(&est1, &notas1, &asistencia1);
    RendimientoEstudiante rendimiento2(&est2, &notas2, &asistencia2);

    // Registro de estudiantes
    vector<RendimientoEstudiante> rendimientos = {rendimiento1, rendimiento2};
    RegistroEstudiantes registro(rendimientos);

    // Imprimir toda la info
    registro.imprimirRegistro();

    return 0;
}

