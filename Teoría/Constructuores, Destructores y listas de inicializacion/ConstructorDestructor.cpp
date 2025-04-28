#include <iostream>
using namespace std;

class Persona {
private:
    string nombre;
    int edad;
public:
    // Constructor por defecto
    Persona() {
        nombre = "Sin nombre";
        edad = 0;
        cout << "Constructor por defecto llamado." << endl;
    }

    // Constructor con un parámetro
    Persona(string n) {
        nombre = n;
        edad = 0;
        cout << "Constructor con un parámetro llamado." << endl;
    }

    // Constructor con dos parámetros
    Persona(string n, int e) {
        nombre = n;
        edad = e;
        cout << "Constructor con dos parámetros llamado." << endl;
    }

    void mostrar() {
        cout << "Nombre: " << nombre << ", Edad: " << edad << endl;
    }

    // Destructor
    ~Persona() {
        cout << "Destructor invocado para: " << nombre << endl;
    }
};

int main() {
    Persona p1;
    Persona p2("Adriana");
    Persona p3("Carlos", 35);

    p1.mostrar();
    p2.mostrar();
    p3.mostrar();

    return 0;
}
