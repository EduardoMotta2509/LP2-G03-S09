#ifndef VALIDAR_FECHA_EXCEPCION_H
#define VALIDAR_FECHA_EXCEPCION_H

#include <stdexcept>
#include <string>
using namespace std;

class ValidarFechaExcepcion : public exception {
private:
    string mensaje;
public:
    ValidarFechaExcepcion(const string& msg) : mensaje(msg) {}
    const char* what() const noexcept override { return mensaje.c_str(); }
};

#endif
