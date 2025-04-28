#include "Estudiante.h"
#include "Docente.h"
#include "Curso.h"
#include "Asociacion.h"

int main() {
    Estudiante* est1 = new Estudiante("Francisco Filinich", 2024001337);
    Estudiante* est2 = new Estudiante("André Lazo", 2024001887);

    Docente* doc1 = new Docente("Mg. Adrian Solano", "Programación I");
    Docente* doc2 = new Docente("Mg. Mary Dueñas", "Cálculo I");

    Curso* curso1 = new Curso("Cálculo I", 2003441556);
    Curso* curso2 = new Curso("Programación I", 2005114998);

    Asociacion* asoc1 = new Asociacion(est1, doc1, curso2);
    Asociacion* asoc2 = new Asociacion(est2, doc2, curso1);

    asoc1->mostrarRelacion();
    asoc2->mostrarRelacion();

    delete est1;
    delete est2;
    delete doc1;
    delete doc2;
    delete curso1;
    delete curso2;
    delete asoc1;
    delete asoc2;

    return 0;
}