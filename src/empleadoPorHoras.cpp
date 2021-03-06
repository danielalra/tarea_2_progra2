#include "empleadoPorHoras.h"



EmpleadoPorHoras::EmpleadoPorHoras(int id, string nombre, string apellido, int idSupervisor){
    this->id=id;
    this->nombre=nombre;
    this->apellido=apellido;
    this->idSupervisor=idSupervisor;
    this->tipoEmpleado=2;
    this->salario=0;
}

void EmpleadoPorHoras::CalcularSalario(float salario, int horas){
    this->salario = salario*horas;
}
void EmpleadoPorHoras::SetNombreSupervisor(string nombreSupervisor){
    this->nombreSupervisor=nombreSupervisor;
}
int EmpleadoPorHoras::Getid(){
    return this-> id;
}

string EmpleadoPorHoras::GetNombreCompleto(){
    return (this->nombre + " " + this->apellido);
}
string EmpleadoPorHoras::GetNombreSupervisor(){
    return this->nombreSupervisor;
}
float EmpleadoPorHoras::GetNeto(){
    return this->salario;
}
float EmpleadoPorHoras::GetBruto(){
    return this->salario;
}