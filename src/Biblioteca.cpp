#include "Biblioteca.h"
#include <iostream>
#include <vector>
using namespace std;
//la clase solo fue definida en Biblioteca.h para facilidad de compilación al no ser tan extenso al darme problemas
//la unica variable a manejar es (vector<libro> libros) al este ser la biblioteca donde se guardan los libros, tambien fue definida solo en Biblioteca.h
//por facilidad de uso
void Biblioteca::agregar(const libro& Libro) { //pide por su propia cuenta el libro y se encarga de añadirlo a la biblioteca
    libros.push_back(Libro);
}

void Biblioteca::quitar(const libro& Libro) {      //metodo para quitar libros de la biblioteca
    bool encontrado = false;                       //definimos una variable para determinar si es encontrado o no
    for (auto it = libros.begin(); it != libros.end(); ++it) {  //usamos un puntero para tener acceso a la memoria del vector y poderlo cambiar de manera facil
        if (it->getisbn_sn() == Libro.getisbn_sn()) {   //la busqueda la realizaremos recorriendo el vector de biblioteca, y para hacer esta busqueda 
            libros.erase(it);                           //haremos una comparación para encontrar el valor isbn_sn al ser este un valor unico de cada libro
            encontrado = true;                          //una vez encontrado se procede a eliminar y a declarar a encontrado como true
            cout << "Libro eliminado.\n";
            break;
        }
    }
    if (!encontrado)                                     //eso para poder definir que pasará si no lo encontramos
        cout << "Libro no encontrado.\n";
}

int Biblioteca::direccion(const libro& Libro) const {
    for (int i = 0; i < libros.size(); i++) {
        if (libros[i].getTitulo() == Libro.getTitulo() ||        //comparación de los valores titulo y autor de nuestro libro con cada libro de la biblioteca
            libros[i].getAutor() == Libro.getAutor()) {         //mediante el titulo o el autor donde si el titulo o autor del libro que buscamos coincide con
            cout << "Libro encontrado en estante " << i + 1 << endl;  //el de algun libro de la biblioteca, devuelve i para indicar en que posición del vector
            return i;                                                 //biblioteca está para el proceso de prestamo que realizaremos en el usuario, este es el
        }                                                            //metodo buscar que nos pedian pero lo renombramos así y definimos esa salida así al resultarnos
    }                                                         //mas util para el proceso de prestamos
    cout << "No se encontró el libro.\n";                      //si no se encuentra se devuelve -1
    return -1;
}

void Biblioteca::mostrar() const {                                           //para imprimir los datos de la biblioteca para mostrar
    for (int i = 0; i < libros.size(); i++) {
        cout << "Estante " << i + 1 << ": ";
        vector<string> datos = libros[i].glibro();
        for (int j = 0; j < datos.size(); j++) {
            cout << datos[j] << " ";
        }
        cout << endl;
    }
}

vector<libro>& Biblioteca::getLibros() {                                  //para poder recojer la biblioteca como vector y por & poderle hacer cambios al original
    return libros;                                                        //para el proceso de prestamos
}
