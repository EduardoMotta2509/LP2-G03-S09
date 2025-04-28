#include <iostream>
#include <vector>

#include "Autor.h"
#include "Libro.h"
#include "Prestamo.h"
#include "RepositorioLibros.h"
#include "RepositorioUsuarios.h"
#include "Usuario.h"

//versión 23:47

using namespace std;
int main() {
    // === AUTORES Y LIBROS ===
    Autor autor1("J.K. Rowling", "Británica", {});
    Autor autor2("George Orwell", "Británico", {});

    Libro* libro1 = new Libro("HP1", "Harry Potter y la piedra filosofal", 1997, 5, &autor1);
    Libro* libro2 = new Libro("HP2", "Harry Potter y la cámara secreta", 1998, 3, &autor1);
    Libro* libro3 = new Libro("1984", "1984", 1949, 4, &autor2);
    Libro* libro4 = new Libro("RF1", "Rebelión en la granja", 1945, 2, &autor2);

    // Asignar libros a autores
    autor1.librosEscritos = { *libro1, *libro2 };
    autor2.librosEscritos = { *libro3, *libro4 };

    // === USUARIOS ===
    Usuario* usuario1 = new Usuario("Ana Gómez", "Calle Falsa 123", "111-111", {});
    Usuario* usuario2 = new Usuario("Luis Torres", "Av. Libertador 456", "222-222", {});
    Usuario* usuario3 = new Usuario("María Ruiz", "Callejón del libro 789", "333-333", {});

    // === REPOSITORIOS ===
    vector<Libro*> libros = { libro1, libro2, libro3, libro4 };
    RepositorioLibros repoLibros(libros);

    vector<Usuario*> usuarios = { usuario1, usuario2, usuario3 };
    RepositorioUsuarios repoUsuarios(usuarios);

    // === PRÉSTAMOS ===
    Prestamo prestamo1("2025-04-05", "2025-04-20", libro1, usuario1, &repoLibros, &repoUsuarios);
    prestamo1.realizarPrestamo(1);

    Prestamo prestamo2("2025-04-05", "2025-04-25", libro3, usuario2, &repoLibros, &repoUsuarios);
    prestamo2.realizarPrestamo(2);

    Prestamo prestamo3("2025-04-05", "2025-04-22", libro4, usuario3, &repoLibros, &repoUsuarios);
    prestamo3.realizarPrestamo(1);

    // === LIMPIEZA DE MEMORIA ===
    delete libro1;
    delete libro2;
    delete libro3;
    delete libro4;

    delete usuario1;
    delete usuario2;
    delete usuario3;

    return 0;
}