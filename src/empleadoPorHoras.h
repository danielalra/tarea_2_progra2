#ifndef EMPLEADOPORHORAS_H
#define EMPLEADOPORHORAS_H

#include <string>
using namespace std;

#include "empleado.h"

class EmpleadoPorHoras : public Empleado{
 
    int id;
    string nombre; 
    string apellido;
    int tipoEmpleado;
    int idSupervisor;
    string nombreSupervisor;
    float salario;

    public:

    EmpleadoPorHoras(int, string, string, int);
    ~EmpleadoPorHoras(){}

    virtual void SetSalario(int,int);
    virtual void SetNombreSupervisor(string);

    virtual int Getid();
    virtual string GetNombreCompleto();
    virtual string GetNombreSupervisor();
    virtual float GetSalario();


};

#endif

