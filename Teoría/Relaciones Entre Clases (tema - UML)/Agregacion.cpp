#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Clase Empleado (puede existir por sí solo)
class Empleado {
private:
    string nombre;
public:
    Empleado(string nombre) : nombre(nombre) {}

    void mostrar() const {
        cout << "Empleado: " << nombre << endl;
    }
};

// Clase Departamento (agrega Empleados)
class Departamento {
private:
    string nombre;
    vector<Empleado*> empleados;  // Agregación: no es dueño de los objetos
public:
    Departamento(string nombre) : nombre(nombre) {}

    void agregarEmpleado(Empleado* emp) {
        empleados.push_back(emp);  // Agrega sin asumir propiedad
    }

    void mostrarEmpleados() const {
        cout << "Departamento: " << nombre << endl;
        for (Empleado* emp : empleados) {
            emp->mostrar();
        }
    }
};

int main() {
    // Crear empleados
    Empleado e1("Ana Torres");
    Empleado e2("Luis García");

    // Crear un departamento
    Departamento dep("Recursos Humanos");

    // Asociar empleados al departamento
    dep.agregarEmpleado(&e1);
    dep.agregarEmpleado(&e2);

    // Mostrar información
    dep.mostrarEmpleados();

    return 0;
}
