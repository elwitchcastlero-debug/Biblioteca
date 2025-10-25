#ifndef LIBRO_H
#define LIBRO_H
#include<iostream>
#include<vector>
using namespace std;
class libro{                              //se crea la clase libro con el objetivo de definir al libro
    string titulo;
    string autor;
    string isbn_sn;
    bool disponibilidad;
public:
    libro(string x, string y, string z, bool k):titulo(x), autor(y), isbn_sn(z), disponibilidad(k){}
vector<string> glibro() const {
        vector<string> book;         //este metodo es para definir al libro como un vector con los datos almacenados que caracterizan al libro                           
        book.push_back("Título: " + titulo);      //esto se realiza con el unico objetivo de poder definir al libro como un vector para
        book.push_back("Autor: " + autor);        //poderlo retornar y guardarlo en la biblioteca
        book.push_back("ISBN/SN: " + isbn_sn);
        book.push_back(disponibilidad ? "Disponible" : "No disponible");
        return book;                                                           
    }
string getTitulo() const{          //el objetivo de este metodo solo es devolver el valor string del titulo del libro
    return titulo;                 //para con este valor realizar la busqueda del libro en la biblioteca por su nombre
}
string getAutor() const{           //este metodo funciona igual que el anterior pero con la variable de autor
    return autor;                  //esto se hace para poder realizar la busqueda de libros por autor
}
string getisbn_sn()const{
    return isbn_sn;
}
bool estaDisponible() const {      //para retornar el valor booleano de la disponibilidad del libro
    return disponibilidad; }       //se hace para saber si se puede prestar un libro existente en la biblioteca
void setDisponibilidad(bool estado) {     //este es necesario para cuando se presta un libro indicar que ya no está disponible al ya ser prestado
    disponibilidad = estado; }         
};
#endif
