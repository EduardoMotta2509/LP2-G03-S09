#include <iostream>
using namespace std;

class Fecha {
private:
    int dia, mes, anio;
public:
    Fecha(int d, int m, int a) : dia(d), mes(m), anio(a) {
        cout << "Fecha creada: ";
        mostrar();
        cout << endl;
    }

    void mostrar() const {
        cout << dia << "/" << mes << "/" << anio;
    }
};

class Persona {
private:
    string nombre;
    Fecha fechaNacimiento;

public:
    Persona(string n, int d, int m, int a)
        : nombre(n), fechaNacimiento(d, m, a) // lista de inicialización
    {
        cout << "Persona creada: " << nombre << endl;
    }

    void mostrar() const {
        cout << "Nombre: " << nombre << ", Fecha de nacimiento: ";
        fechaNacimiento.mostrar();
        cout << endl;
    }
};

int main() {
    Persona p("Adriana", 25, 4, 1990);
    p.mostrar();

    return 0;
}
