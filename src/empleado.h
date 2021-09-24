#ifndef EMPLEADO_H
#define EMPLEADO_H
#include <string>
using namespace std;

class Empleado{
    int ID;
    string nombre;
    string apellido;
    string correo;
    int tipoEmpleado;
    int ID_supervisor;

    public:
    Empleado(int, string, string, string, int, int);
    
    int getID();
    string getNombre();
    string getApellido();
};
#endif