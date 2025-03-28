#include <iostream>
using namespace std;

class Libro{
    private:
        string titulo;
        bool prestado;
    public:
        Libro(string _titulo){
            titulo= _titulo;
            prestado= false;
        }

        string getTitulo(){
            return titulo;
        }
        bool getEstaPrestado(){
            return prestado;
        }

        void setTitulo(string _titulo){
            titulo= _titulo;
        }

        void setEstaPrestado(bool _prestado){
            prestado= _prestado;
        }

        void setPrestar(){
            if (getEstaPrestado()){
                cout<<"El libro "<<titulo<<" ya está prestado"<<endl;
            }
            else{
                setEstaPrestado(true);
                cout<<"El libro "<<titulo<<" ha sido prestado"<<endl;
            }
        }

        void setDevolver(){
            if(getEstaPrestado()){
                setEstaPrestado(false);
                cout<<"El libro "<<titulo<<" se ha devuelto"<<endl;
            }
            else{
                cout<<"El libro"<<titulo<<" no estaba prestado"<<endl;
            }
        }
};

class Biblioteca {
    public:
        void setPrestarLibro(Libro &blibro){
            blibro.setPrestar();
        }

        void setDevolverLibro(Libro &blibro){
            blibro.setDevolver();
        }
};

int main() {
    Biblioteca biblioteca;
    Libro libro1("Mago de Oz");
    Libro libro2("Chumpitasi");
    Libro libro3("Lingo");

    int opc=0;
    while (opc!=3){
        cout<<"\nEliga la opción que desee realizar"<<endl;
        cout<<"1.- Prestar un libro"<<endl;
        cout<<"2.- Devolver un libro"<<endl;
        cout<<"3.- Salir del programa"<<endl;
        cout<<"Opción: "<<endl;
        cin>>opc;

        if (opc==1 || opc==2){
            int seleclibro;
            cout<<"Seleccione el libro: "<<endl;
            cout<<"1.-"<<libro1.getTitulo()<<endl;
            cout<<"2.-"<<libro2.getTitulo()<<endl;
            cout<<"3.-"<<libro3.getTitulo()<<endl;
            cout<<"Opción: "<<endl;
            cin>>seleclibro;
            if (seleclibro==1){
                if(opc==1) biblioteca.setPrestarLibro(libro1);
                else biblioteca.setDevolverLibro(libro1);
            }

            else if (seleclibro==2){
                if(opc==1) biblioteca.setPrestarLibro(libro2);
                else biblioteca.setDevolverLibro(libro2);
            }

            else if (seleclibro==3){
                if(opc==1) biblioteca.setPrestarLibro(libro3);
                else biblioteca.setDevolverLibro(libro3);
            }
            else {
                cout<<"Opción no válida"<<endl;
            }

        }
    }
    cout<<"Finalización del programa"<<endl;
    return 0;
}
    