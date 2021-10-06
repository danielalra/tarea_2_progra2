#ifndef EMPLEADODENOMINA_H
#define EMPLEADODENOMINA_H

#include <string>
using namespace std;

#include "empleado.h"

class EmpleadoDeNomina : public Empleado{
 
    int id;
    string nombre; 
    string apellido;
    int tipoEmpleado;
    int idSupervisor;
    string nombreSupervisor;
    float salario;

    public:
    EmpleadoDeNomina(int, string, string, int);
    ~EmpleadoDeNomina(){}

    virtual void CalcularSalario(float,int);
    virtual void SetNombreSupervisor(string);

    virtual int Getid();
    virtual string GetNombreCompleto();
    virtual string GetNombreSupervisor();
    virtual float GetNeto();
    virtual float GetBruto();


};

#endif