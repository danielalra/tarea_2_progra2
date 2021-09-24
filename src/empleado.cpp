#include "empleado.h"
#include <string>
using namespace std;

Empleado::Empleado(int ID, string nombre, string apellido, string correo, int tipoEmpleado, int ID_supervisor){
    this->ID=ID;
    this->nombre=nombre;
    this->apellido=apellido;
    this->correo=correo;
    this->tipoEmpleado=tipoEmpleado;
    this->ID_supervisor=ID_supervisor;
}

int Empleado::getID (){
    return this->ID;
}
string Empleado::getNombre (){
    return this->nombre;
}
string Empleado::getApellido (){
    return this->apellido;
}
int Empleado:: getIDsupervisor(){
    return ID_supervisor;
}