// Sin Segregacion ISP
#include <iostream>

using namespace std;

// Interfaz que viola ISP 
class Trabajador {
public:
    virtual void programar() = 0;
    virtual void cocinar() = 0;
    virtual ~Trabajador() {}
};

// Programador no debería implementar cocinar()
class Programador : public Trabajador {
public:
    void programar() override {
        cout << "El programador está escribiendo código." << endl;
    }

    void cocinar() override {
        cout << "ERROR: Un programador no cocina en su trabajo." << endl;
    }
};

// Cocinero no debería implementar programar()
class Cocinero : public Trabajador {
public:
    void programar() override {
        cout << "ERROR: Un cocinero no programa en su trabajo." << endl;
    }

    void cocinar() override {
        cout << "El cocinero está preparando una comida deliciosa." << endl;
    }
};

int main() {
    Programador dev;
    Cocinero chef;

    dev.programar();
    dev.cocinar();  // No tiene sentido

    chef.programar(); // No tiene sentido
    chef.cocinar();

    return 0;
}



// Aplicando ISP

#include <iostream>

using namespace std;

// Interfaces específicas
class IProgramador {
public:
    virtual void programar() = 0;
    virtual ~IProgramador() {}
};

class ICocinero {
public:
    virtual void cocinar() = 0;
    virtual ~ICocinero() {}
};

// Programador solo implementa la interfaz de programador
class Programador : public IProgramador {
public:
    void programar() override {
        cout << "El programador está escribiendo código." << endl;
    }
};

// Cocinero solo implementa la interfaz de cocinero
class Cocinero : public ICocinero {
public:
    void cocinar() override {
        cout << "El cocinero está preparando una comida deliciosa." << endl;
    }
};

int main() {
    Programador dev;
    Cocinero chef;

    dev.programar();  // Correcto
    chef.cocinar();   // Correcto

    return 0;
}