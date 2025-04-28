#include <iostream>
using namespace std;

#include "ReservaHotel.h"
#include "Habitacion.h"

//version 23:41

int main(){
    ReservaHotel r1(2, "123");
    r1.IngresarHabitaciones();
    r1.calcularTotal();
    return 0;
}