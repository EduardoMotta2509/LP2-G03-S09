// Structura Basica

#include <iostream>
#include <string>
using namespace std;
 
int main()
{
    struct datosPersona
    {
        string nombre;
        char  inicial;
        int   edad;
        float nota;
    };
 
    datosPersona persona;
 
    persona.nombre = "Juan";
    persona.inicial = 'J';
    persona.edad = 20;
    persona.nota = 7.5;
    cout << "La edad es " << persona.edad;
 
    return 0;
}



///Arreglo de estructuras

#include <iostream>
#include <string>
using namespace std;
 
int main()
{
    struct datosPersona
    {
        string nombre;
        char  inicial;
        int   edad;
        float nota;
    };
 
    datosPersona *persona = new datosPersona[50];
 
    for (int i=0; i<5; i++)
    {
        cout << "Dime el nombre de la persona " << i << endl;
        cin >> persona[i].nombre;
    }
 
    cout << "La persona 3 es " << persona[2].nombre << endl;
 
    return 0;
}



//// Estructuras Anidadas

#include <iostream>
#include <string>
using namespace std;
 
struct fechaNacimiento
{
    int  dia;
    int  mes;
    int anyo;
};
 
struct datosPersona
{
    string nombre;
    char  inicial;
    struct fechaNacimiento diaDeNacimiento;
    float nota;
};
 
int main()
{
    datosPersona persona;
 
    persona.nombre = "Ignacio";
    persona.inicial = 'I';
    persona.diaDeNacimiento.mes = 8;
    persona.nota = 7.5;
    cout << "La nota es " << persona.nota;
 
    return 0;
}