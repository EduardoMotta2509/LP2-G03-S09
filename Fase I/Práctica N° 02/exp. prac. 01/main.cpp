#include <iostream>
#include "Animales.h"
#include "Coche.h"
#include "Estudiante.h"
#include "Tienda.h"
using namespace std;
   
int main(){
    Animal leon("Leon",10,"Felino","GRRRRRRRRRRRRRRRR");
    Animal perro("Pipo",3,"Canino","GUAUUUUU");
    Animal gato("Clot", 5, "Felino", "MIAUUUUUU");
    Animal caballo("Majestic",12,"Equino","HIIIIIIIiIiIiiii");
    cout<<"El nombre es: "<<leon.getNombre()<<endl;
    leon.setEdad(20);
    leon.mostrarDatos();
    cout<<leon.getSonido()<<endl;
    leon.hacerSonido();
    perro.setEdad(1);
    perro.mostrarDatos();
    cout<<perro.getSonido()<<endl;
    perro.hacerSonido();
    gato.setEdad(7);
    gato.mostrarDatos();
    cout<<gato.getSonido()<<endl;
    gato.hacerSonido();
    caballo.setEdad(15);
    caballo.mostrarDatos();
    cout<<caballo.getSonido()<<endl;
    caballo.hacerSonido();

    //Instanciando objetos de la clase coche
    Coche c1("Bugatti Chiron",2024,220); //vel. máx. 420
    Coche c2("Tesla Model 3", 2020, 61); //vel. máx. 261
    Coche c3("Ferrari LaFerrari", 2015, 152); //vel. máx. 352
    
    c1.acelerar(113.5);
    c2.acelerar(100.4);
    c3.acelerar(150.5);

    c1.frenar();
    c2.frenar();
    c3.frenar();

    //Instanciando objetos de la clase estudiante
    Estudiante e1("Jose", 17, "Segundo año", "LP2");
    e1.tomarExamen(-0.7);
    e1.recibirCalificacion();
    Estudiante e2("Pepe", 17, "Primer año", "Estructuras Descretas");
    e2.tomarExamen(0.4);
    e2.recibirCalificacion();
    Estudiante e3("Juan", 17, "Tercer año", "Redes");
    e3.tomarExamen(2.4);
    e3.recibirCalificacion();

    //Instanciando objetos de la clase Tienda
    Tienda t1("Dtodo","Calle 123", "Bodega", {"Gaseosa","Galleta","Dulce"},50);
    Tienda t2("DtodoUnPoco","Calle 311", "Bodega", {"Queque","Cupcake","Botella de agua"},30);

    t1.agregarProducto("Huevos");
    t1.venderProducto(12,"Galleta");
    t2.agregarProducto("Leche");
    t2.venderProducto(20,"Cupcake");
    return 0;
}