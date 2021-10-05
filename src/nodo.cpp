#include "nodo.h"
#include "empleadoDeNomina.h"
#include "empleadoPorHoras.h"

#include <iostream>
using namespace std;

Nodo::Nodo(int id, string nombre, string apellido, int tipoEmpleado, int idSupervisor){

    if (tipoEmpleado == 1){
         EmpleadoDeNomina *empleado1 = new EmpleadoDeNomina(id, nombre, apellido, idSupervisor);
        this->empleado = empleado1;
    }
    else { 
        EmpleadoPorHoras *empleado2 = new EmpleadoPorHoras(id, nombre, apellido, idSupervisor);
        this->empleado = empleado2;
    }
}

Nodo::~Nodo(){
    for (Nodo* hijo : this->hijos){
        delete hijo;
    }
}

void Nodo::AgregarHijo(Nodo *hijo) {
    this->hijos.push_back(hijo);
}
void Nodo::SetNombreSupervisorNodo(string nombreSupervisor){

    this->empleado->SetNombreSupervisor(nombreSupervisor);
}
string Nodo::GetNombreNodo(){
    return this->empleado->GetNombreCompleto();
}
void Nodo::SetSalarioNodo(int salario, int horas){
    this->empleado->SetSalario(salario, horas);
}

std::ostream& operator << (std::ostream &o, const Nodo &nodo)
{

    o <<nodo.empleado->Getid();
    o << ", ";
    o << nodo.empleado->GetNombreCompleto();
    o << ", ";
    o << nodo.empleado->GetNombreSupervisor();
    o << ", ";
    o << nodo.empleado->GetSalario();
    o << endl;

    // Imprimir información de cada hijo
    for (Nodo *nodoHijo : nodo.hijos)
    {
        o << *nodoHijo;
    }

    return o;
}

