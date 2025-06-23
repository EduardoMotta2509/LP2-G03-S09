#include "Division.h"

int main() {
    int x, y;
    cout << "Ingrese dos números enteros: ";
    cin >> x >> y;

    try {
        int resultado = dividir(x, y);
        cout << "Resultado: " << resultado << endl;
    } catch (TipoError e) {
        switch (e) {
            case ERROR_DIVISION_CERO:
                cout << "Error: No se puede dividir por cero." << endl;
                break;
        }
    }

    return 0;
}
