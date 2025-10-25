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
        if (it->getisbn_sn() == Libro.getisbn_sn()) {   //para realizar la 
            libros.erase(it);
            encontrado = true;
            cout << "Libro eliminado.\n";
            break;
        }
    }
    if (!encontrado)
        cout << "Libro no encontrado.\n";
}

int Biblioteca::direccion(const libro& Libro) const {
    for (int i = 0; i < libros.size(); i++) {
        if (libros[i].getTitulo() == Libro.getTitulo() ||
            libros[i].getAutor() == Libro.getAutor()) {
            cout << "Libro encontrado en estante " << i + 1 << endl;
            return i;
        }
    }
    cout << "No se encontró el libro.\n";
    return -1;
}

void Biblioteca::mostrar() const {
    for (int i = 0; i < libros.size(); i++) {
        cout << "Estante " << i + 1 << ": ";
        vector<string> datos = libros[i].glibro();
        for (int j = 0; j < datos.size(); j++) {
            cout << datos[j] << " ";
        }
        cout << endl;
    }
}

vector<libro>& Biblioteca::getLibros() {
    return libros;
}
