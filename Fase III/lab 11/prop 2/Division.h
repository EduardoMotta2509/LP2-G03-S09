#ifndef DIVISION_H
#define DIVISION_H

#include <iostream>
using namespace std;

enum TipoError { ERROR_DIVISION_CERO };

int dividir(int a, int b) {
    if (b == 0) {
        throw ERROR_DIVISION_CERO;
    }
    return a / b;
}

#endif
