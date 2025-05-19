#include "Circulo.h"
#include "Rectangulo.h"
#include "Triangulo.h"

int main() {
    Circulo c(5);
    Rectangulo r(4, 6);
    Triangulo t(3, 7);

    c.dibujar();
    cout << "Area del circulo: " << c.calcularArea() << endl << endl;

    r.dibujar();
    cout << "Area del rectangulo: " << r.calcularArea() << endl << endl;

    t.dibujar();
    cout << "Area del triangulo: " << t.calcularArea() << endl;

    return 0;
}
