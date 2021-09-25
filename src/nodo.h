#ifndef NODO_H
#define NODO_H
#include <vector>
#include <string>
using namespace std;

class Nodo{
    int ID;
    string nombre;
    string apellido;
    int tipoEmpleado;
    int IDsupervisor;
    string nombreSupervisor;
    float pago;
    vector <Nodo *> hijos;

    public:
    Nodo(int, string, string, int, int);
    ~Nodo();

    void AgregarHijo(Nodo *hijo);
    string GetNombreCompleto();
    void SetNombreSupervisor(string nombreSupervisor);
    void SetPago(float pago);
    friend std::ostream& operator << (std::ostream &o, const Nodo &nodo);
};

#endif