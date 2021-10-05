#include <gtest/gtest.h>
#include "C:/progra2/tarea_2_progra2/src/nodo.h"
#include <string>
using namespace std;

namespace {
    TEST(NodolTests, Test_Constructor) {
        Nodo *nodo = new Nodo(2, "Daniel", "Alvarez", 1, 1);

        ostringstream streamSalida {};
        streamSalida << *nodo;
        string actual = streamSalida.str();

        string esperada = "2, Daniel Alvarez, , 0\n";

        delete nodo;

        EXPECT_EQ(esperada, actual);
    }
    TEST(NodoTest, Test_SetNombreSupervisor){
        Nodo *nodoHijo = new Nodo(2, "Juan", "Perez", 1, 1);
        nodoHijo->SetNombreSupervisorNodo("Daniel Alvarez");

        ostringstream streamSalida {};
        streamSalida << *nodoHijo;
        string actual = streamSalida.str();

        string esperada = "2, Juan Perez, Daniel Alvarez, 0\n";

        EXPECT_EQ(esperada, actual);

    }
    TEST(NodoTest, Test_GetNombreNodo){
        Nodo *nodo = new Nodo(2, "Daniel", "Alvarez", 1, 1);
        string nombre = nodo->GetNombreNodo();

        EXPECT_EQ("Daniel Alvarez", nombre);
    }
    
    //no deberia aparecer el nombre ya que el SetNombreSupervisor se ejecuta en el arbol
    TEST(NodoTests, Test_Agregar_Hijo) {
        Nodo *nodo = new Nodo(1, "Daniel", "Alvarez", 1, 0);
        Nodo * nodoHijo = new Nodo(2, "Juan", "Perez", 1, 1);
        nodo->AgregarHijo(nodoHijo);       

        ostringstream streamSalida {};
        streamSalida << *nodo;
        string actual = streamSalida.str();

        delete nodo;

        ostringstream streamSalidaEsperada {};
        streamSalidaEsperada << "1, Daniel Alvarez, , 0" << endl;
        streamSalidaEsperada << "2, Juan Perez, , 0" << endl;
        string esperada = streamSalidaEsperada.str();

        EXPECT_EQ(esperada, actual);
    }

    
    TEST(NodoTest, Test_SetSalarioDeNomina){
       Nodo *nodo = new Nodo(1, "Daniel", "Alvarez", 1, 0);
        nodo->SetSalarioNodo(200,4); 

        ostringstream streamSalida {};
        streamSalida << *nodo;
        string actual = streamSalida.str();

        string esperada = "1, Daniel Alvarez, , 200\n";

        delete nodo;

        EXPECT_EQ(esperada, actual);
    }

    TEST(ArbolTest, Test_SetSalarioPorHoras){
        Nodo *nodo = new Nodo(1, "Daniel", "Alvarez", 2, 0);
        nodo->SetSalarioNodo(200,4); 

        ostringstream streamSalida {};
        streamSalida << *nodo;
        string actual = streamSalida.str();

        string esperada = "1, Daniel Alvarez, , 800\n";

        delete nodo;

        EXPECT_EQ(esperada, actual);
    }
}