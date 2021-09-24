#ifndef NODO_H
#define NODO_H
#include "empleado.h"
#include <vector>
using namespace std;

class Nodo{
    int ID;
    Empleado empleado;
    vector <Nodo *> hijos;

    public:
    Nodo(Empleado empleado);
    ~Nodo();

    void AgregarHijo(Nodo *hijo);

    //friend std::ostream& operator << (std::ostream &o, const Nodo &nodo);
};

#endif