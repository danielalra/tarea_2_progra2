#ifndef EMPLEADO_H
#define EMPLEADO_H

#include <string>
using namespace std;

class Empleado {

public:
    Empleado(){};
    virtual ~Empleado() {};
    virtual void CalcularSalario(float,int)=0;
    virtual void SetNombreSupervisor(string)=0;

    virtual int Getid()=0;
    virtual string GetNombreCompleto()=0;
    virtual string GetNombreSupervisor()=0;
    virtual float GetNeto()=0;
    virtual float GetBruto()=0;

};
#endif
