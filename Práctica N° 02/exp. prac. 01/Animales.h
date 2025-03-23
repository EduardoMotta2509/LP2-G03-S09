#ifndef ANIMALES_H
#define ANIMALES_H

#include <iostream>
using namespace std;

class Animal {
private:
	string nombre;
	int edad;
	string tipoDeAnimal;
	string sonido;
public:
	Animal(string _nombre, int _edad, string _tipoDeAnimal, string _sonido) {
		nombre=_nombre;
		edad=_edad;
		tipoDeAnimal=_tipoDeAnimal;
		sonido=_sonido;
	}

	string getNombre() {
		return nombre; //Devuelve el nombre del objeto
	}
	int getEdad() {
		return edad; //Devuelve la edad del objeto
	}
	string getTipoDeAnimal() {
		return tipoDeAnimal; //Devuelve el tipo de animal del objeto
	}
	string getSonido() {
		return sonido;
	}

	void setNombre(string _nombre) {
		nombre = _nombre;
	}
	void setEdad(int _edad) {
		edad = _edad;
	}
	void setTipoDeAnimal(string _tipoDeAnimal) {
		tipoDeAnimal = _tipoDeAnimal;
	}
	void setSonido(string _sonido) {
		sonido = _sonido;
	}

	void mostrarDatos() {
		cout<<"\n-------"<<endl;
		cout<<"     Nombre: "<<nombre<<endl;
		cout<<"     Edad: "<<edad<<endl;
		cout<<"     Tipo de animal: "<<tipoDeAnimal<<endl;
		cout<<"     Sonido: "<<sonido<<endl;
		cout<<"-------"<<endl;
	}

	void alimentar() {
		cout<<"Se ha alimentado a "<<nombre<<endl;
	}
	void hacerSonido() {
		cout<<nombre<<" hace "<< sonido<<endl;
	}
};
#endif