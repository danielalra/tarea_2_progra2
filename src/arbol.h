#ifndef ARBOL_H
#define ARBOL_H
#include "nodo.h"
#include <map>
using namespace std;

class Arbol{

    Nodo *raiz;
    map <int, Nodo *> elementos;

    public:
    Arbol(Empleado jefe);
    ~Arbol();
    void AgregarNodo(Empleado empleado);

};
#endif