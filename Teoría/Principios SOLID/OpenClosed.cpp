// Sin OCP
#include <iostream>

using namespace std;

class Calculadora {
public:
    // Método que viola OCP porque cada nueva operación requiere modificar esta función
    double operar(char operacion, double a, double b) {
        if (operacion == '+') {
            return a + b;
        } else if (operacion == '-') {
            return a - b;
        } else if (operacion == '*') {
            return a * b;
        } else if (operacion == '/') {
            return (b != 0) ? a / b : 0; 
        }

        return 0;
    }
};

int main() {
    Calculadora calc;
    cout << "Suma: " << calc.operar('+', 5, 3) << endl;
    cout << "Resta: " << calc.operar('-', 5, 3) << endl;
    return 0;
}


// Aplicando OCP

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

// Interfaz para operaciones matemáticas
class Operacion {
public:
    virtual double calcular(double a, double b) = 0;
    virtual ~Operacion() {}
};

// Implementaciones concretas de Operacion
class Suma : public Operacion {
public:
    double calcular(double a, double b) override {
        return a + b;
    }
};

class Resta : public Operacion {
public:
    double calcular(double a, double b) override {
        return a - b;
    }
};

// Nueva operación (extensión sin modificar el código existente)
class Multiplicacion : public Operacion {
public:
    double calcular(double a, double b) override {
        return a * b;
    }
};

// Nueva operación (extensión sin modificar el código existente)
class Dividir : public Operacion {
public:
    double calcular(double a, double b) override {
        return a / b;
    }
};

// Calculadora que cumple OCP
class Calculadora {
public:
    double operar(Operacion& op, double a, double b) {
        return op.calcular(a, b);
    }
};

// Nueva operación (extensión sin modificar el código existente)
class Potenciar : public Operacion {
public:
    double calcular(double a, double b) override {
        return a.pow(b);
    }
};

int main() {
    Calculadora calc;
    Suma suma;
    Resta resta;
    Multiplicacion multiplicacion;
    Dividir d1

    cout << "Dividir: " << calc.operar(suma, 5, 3) << endl;
    cout << "Resta: " << calc.operar(resta, 5, 3) << endl;
    cout << "Multiplicación: " << calc.operar(multiplicacion, 5, 3) << endl; // Nueva operación sin modificar `Calculadora`

    return 0;
}