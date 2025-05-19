#include <iostream>
using namespace std;

class Persona {
private:
    string nombre;
    int edad;

public:
    Persona() : nombre(""), edad(0) {}

    // Establecer nombre con autoreferencia
    Persona& setNombre(const string& nombre) {
        this->nombre = nombre; // this->nombre se refiere al atributo, nombre es el parámetro
        return *this; // devuelve referencia al objeto actual
    }

    // Establecer edad con autoreferencia
    Persona& setEdad(int edad) {
        this->edad = edad;
        return *this;
    }

    // Mostrar datos
    void mostrar() const {
        cout << "Nombre: " << nombre << ", Edad: " << edad << endl;
    }
};

int main() {
    Persona p;

    // Encadenamiento de llamadas
    p.setNombre("Adriana").setEdad(30).mostrar();

    return 0;
}




class Animal { ... };

class Perro : public Animal { };


class Animal {
protected:
    string nombre;
};

class Perro : public Animal {
public:
    void asignarNombre(string n) {
        nombre = n;  // Acceso permitido
    }
};

