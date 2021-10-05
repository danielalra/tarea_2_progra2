#ifndef NODO_H
#define NODO_H

#include <vector>
#include <string>
using namespace std;

#include "empleado.h"

class Nodo{
   
    Empleado *empleado;
    vector <Nodo *> hijos;

    public:
    Nodo(int, string, string, int, int);
    ~Nodo();

    void AgregarHijo(Nodo *hijo);
    void SetNombreSupervisorNodo(string nombreSupervisor);
    string GetNombreNodo();
    void SetSalarioNodo(float, int);
    float GetBrutoNodo();
    float GetNetoNodo();
    friend std::ostream& operator << (std::ostream &o, const Nodo &nodo);
};

#endif