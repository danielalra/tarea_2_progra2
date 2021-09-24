#include <map>
#include "arbol.h"
#include "nodo.h"
using namespace std;

Arbol::Arbol(Empleado empleado) {

    Nodo *nodoRaiz = new Nodo(empleado);
    this->raiz = nodoRaiz;

    this->elementos.insert(pair<int,Nodo *>(empleado.getID(), nodoRaiz));
}

Arbol::~Arbol() {

    delete this->raiz;

}


void Arbol::AgregarNodo(Empleado empleado)
{
    Nodo *nodo = new Nodo(empleado);

    // Buscar ese nodo padre
    Nodo *nodoPadre = this->elementos.at(empleado.getIDsupervisor());
    nodoPadre->AgregarHijo(nodo);

    // Agregar nodo al índice
    this->elementos.insert(pair<int,Nodo *>(empleado.getID(), nodo));
}

/*std::ostream& operator << (std::ostream &o, const Arbol &arbol)
{
    Nodo* raiz = arbol.raiz;
    o << *(raiz);

    return o;
}*/