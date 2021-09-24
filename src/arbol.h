#ifndef ARBOL_H
#define ARBOL_H
#include "nodo.h"
#include <map>
using namespace std;

class Arbol{

    //Nodo *raiz;
    map <int, Nodo *> elementos;
    

    public:
    Nodo *raiz;
    Arbol(int, string, string, int);
    ~Arbol();
    void AgregarNodo(int, string, string, int, int);
    void AgregarRaiz(int, string, string, int);
    friend std::ostream& operator << (std::ostream &o, const Arbol &arbol);

};
#endif