// SIN APLICAR LSP

#include <iostream>

using namespace std;

// Clase base
class Vehiculo {
public:
    virtual void encender() {
        cout << "El vehículo está encendido." << endl;
    }
};

// Subclase Coche (Correcto)
class Coche : public Vehiculo {
public:
    void encender() override {
        cout << "El coche está encendido." << endl;
    }
};

// Subclase Bicicleta (Incorrecto, ya que una bicicleta no puede encenderse)
class Bicicleta : public Vehiculo {
public:
    void encender() override {
        cout << "ERROR: Una bicicleta no tiene motor, no puede encenderse." << endl;
    }
};

int main() {
    Coche miCoche;
    Bicicleta miBici;

    miCoche.encender();  // Funciona correctamente
    miBici.encender();   // Llamada incorrecta

    return 0;
}

//////////////
//APLICANDO LSP

#include <iostream>

using namespace std;

// Clase base general
class Vehiculo {
public:
    virtual ~Vehiculo() {}  // Destructor virtual para permitir herencia limpia
};

// Clase para vehículos con motor
class VehiculoConMotor : public Vehiculo {
public:
    virtual void encender() = 0;  // Método abstracto
};

// Subclase Coche (Correcto)
class Coche : public VehiculoConMotor {
public:
    void encender() override {
        cout << "El coche está encendido." << endl;
    }
};

// Clase para vehículos sin motor
class VehiculoSinMotor : public Vehiculo {
public:
    void pedalear() {
        cout << "La bicicleta está en movimiento mediante pedaleo." << endl;
    }
};

// Subclase Bicicleta (Correcto, ya no hereda un método innecesario)
class Bicicleta : public VehiculoSinMotor {};

int main() {
    Coche miCoche;
    Bicicleta miBici;

    miCoche.encender();  // Correcto, solo los vehículos con motor pueden encenderse
    miBici.pedalear();   // Correcto, la bicicleta usa pedal en lugar de encenderse

    return 0;
}