#ifndef EMPLEADO_H
#define EMPLEADO_H

#include <string>
using namespace std;

class Empleado {

public:
    Empleado(){};
    virtual ~Empleado() {};
    virtual void SetSalario(int,int)=0;
    virtual void SetNombreSupervisor(string)=0;

    virtual int Getid()=0;
    virtual string GetNombreCompleto()=0;
    virtual string GetNombreSupervisor()=0;
    virtual float GetSalario()=0;

};
#endif
