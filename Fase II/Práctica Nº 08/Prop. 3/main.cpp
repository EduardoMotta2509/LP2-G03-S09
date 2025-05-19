#include "EmpleadoTiempoCompleto.h"
#include "EmpleadoMedioTiempo.h"

int main() {
    EmpleadoTiempoCompleto emp1(3000);  // salario mensual fijo
    EmpleadoMedioTiempo emp2(20, 80);   // 20so por hora, 80h al mes

    cout << "Salario del empleado a tiempo completo: " << emp1.calcularSalario() << endl;
    cout << "Salario del empleado a medio tiempo: " << emp2.calcularSalario() << endl;

    return 0;
}
