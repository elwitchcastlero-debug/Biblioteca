#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H
#include <iostream>
#include <vector>
#include "libro.h"
using namespace std;

class Biblioteca {
    vector<libro> libros;

public:                                                   //solo aqui se define la clase Biblioteca junto a su variable libros  y su constructor y metodos
    Biblioteca(vector<libro> ls = {}) : libros(ls) {}

    void agregar(const libro& Libro);
    void quitar(const libro& Libro);
    int direccion(const libro& Libro) const;
    void mostrar() const;
    vector<libro>& getLibros();
};

#endif
