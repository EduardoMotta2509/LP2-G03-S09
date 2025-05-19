#include <iostream>
using namespace std;

// 1. Clase Base
class Animal {
protected: // 3. Miembro protected
    string nombre;

public:
    // 4. Constructor de clase base
    Animal(string n) : nombre(n) {
        cout << "Constructor de Animal: " << nombre << endl;
    }

    void comer() {
        cout << nombre << " está comiendo." << endl;
    }

    // 4. Destructor de clase base
    ~Animal() {
        cout << "Destructor de Animal: " << nombre << endl;
    }
};

// 6. Herencia virtual (para evitar duplicación en herencia múltiple)
class Mamifero : virtual public Animal {
public:
    Mamifero(string n) : Animal(n) {
        cout << "Constructor de Mamífero" << endl;
    }
};

// 6. Herencia virtual aplicada también aquí
class Volador : virtual public Animal {
public:
    Volador(string n) : Animal(n) {
        cout << "Constructor de Volador" << endl;
    }
};

// 2. Clase derivada + 5. Herencia Public/Protected/Private (public en este caso)
// 7 y 8 se ven al cambiar `public` por `protected` o `private`
class Murcielago : public Mamifero, public Volador {
public:
    // 4. Constructor de clase derivada
    Murcielago(string n) : Animal(n), Mamifero(n), Volador(n) {
        cout << "Constructor de Murciélago" << endl;
    }

    void volar() {
        cout << nombre << " está volando." << endl; // acceso a miembro protected
    }

    // 4. Destructor de clase derivada
    ~Murcielago() {
        cout << "Destructor de Murciélago" << endl;
    }
};

int main() {
    // Crear objeto de clase derivada
    Murcielago m("Batín");

    m.comer();     // método heredado de Animal
    m.volar();     // método propio de Murciélago

    return 0; // Se ejecutan destructores automáticamente
}


//Shell
Constructor de Animal: Batín
Constructor de Mamífero
Constructor de Volador
Constructor de Murciélago
Batín está comiendo.
Batín está volando.
Destructor de Murciélago
Destructor de Animal: Batín


class MyClass {
public:
    MyClass() {
        // Inicialización por defecto
    }
};

class MyClass {
private:
    int x;
public:
    MyClass(int val) : x(val) {
        // Inicialización con un valor
    }
};


