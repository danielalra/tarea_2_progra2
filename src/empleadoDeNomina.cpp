#include "empleadoDeNomina.h"
#include <iostream>

EmpleadoDeNomina::EmpleadoDeNomina(int id, string nombre, string apellido, int idSupervisor){
    this->id=id;
    this->nombre=nombre;
    this->apellido=apellido;
    this->idSupervisor=idSupervisor;
    this->tipoEmpleado=1;
    this->salario=0; 
}

void EmpleadoDeNomina::SetSalario(int salario, int horas){
    this->salario = salario*0.93;
}
void EmpleadoDeNomina::SetNombreSupervisor(string nombreSupervisor){
    this->nombreSupervisor=nombreSupervisor;
}

int EmpleadoDeNomina::Getid(){
    return this-> id;
}

string EmpleadoDeNomina::GetNombreCompleto(){
    return (this->nombre + " " + this->apellido);
}
string EmpleadoDeNomina::GetNombreSupervisor(){
    return this->nombreSupervisor;
}
float EmpleadoDeNomina::GetNeto(){
    return this->salario;
}
float EmpleadoDeNomina::GetBruto(){
    return this->salario/0.93;
}