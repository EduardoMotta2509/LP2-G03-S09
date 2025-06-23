#include "ArchivoTexto.h"

int main() {
    string nombre;
    cout << "Ingrese el nombre del archivo de texto: ";
    cin >> nombre;

    mostrarContenidoArchivo(nombre);

    return 0;
}
