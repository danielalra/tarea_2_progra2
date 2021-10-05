#include <gtest/gtest.h>
#include "C:/progra2/tarea_2_progra2/src/arbol.h"
#include <string>
using namespace std;

namespace {
    TEST(ArbolTests, Test_Constructor_o_Raiz) {
        Arbol *arbol = new Arbol();
        arbol->AgregarNodo(1, "Daniel", "Alvarez", 1, 3);

        ostringstream streamSalida {};
        streamSalida << *arbol;
        string actual = streamSalida.str();

        string esperado = "1, Daniel Alvarez, , 0\n";

        delete arbol;

        EXPECT_EQ(esperado, actual);
    }

    TEST(ArbolTests, Test_Agregar_Nodo) {
        Arbol *arbol = new Arbol();
        arbol->AgregarNodo(1, "Daniel", "Alvarez", 1, 3);
        arbol->AgregarNodo(2, "Juan", "Perez", 1, 1);       

        ostringstream streamSalida {};
        streamSalida << *arbol;
        string actual = streamSalida.str();

        delete arbol;

        ostringstream streamSalidaEsperada {};
        streamSalidaEsperada << "1, Daniel Alvarez, , 0" << endl;
        streamSalidaEsperada << "2, Juan Perez, Daniel Alvarez, 0" << endl;
        string esperada = streamSalidaEsperada.str();

        EXPECT_EQ(esperada, actual);
    }

    TEST(ArbolTests, Test_Agregar_Nodos_UnNivel) {
        Arbol *arbol = new Arbol();
        arbol->AgregarNodo(1, "Daniel", "Alvarez", 1, 3);
        arbol->AgregarNodo(2, "Juan", "Perez", 1, 1);
        arbol->AgregarNodo(3, "Pedro", "Rodriguez", 1, 1);

        ostringstream streamSalida {};
        streamSalida << *arbol;
        string actual = streamSalida.str();

        delete arbol;

        ostringstream streamSalidaEsperada {};
        streamSalidaEsperada << "1, Daniel Alvarez, , 0" << endl;
        streamSalidaEsperada << "2, Juan Perez, Daniel Alvarez, 0" << endl;
        streamSalidaEsperada << "3, Pedro Rodriguez, Daniel Alvarez, 0" << endl;
        string esperada = streamSalidaEsperada.str();

        EXPECT_EQ(esperada, actual);
    }
    
    TEST(ArbolTests, Test_Agregar_Nodos_DosNiveles) {
        Arbol *arbol = new Arbol();
        arbol->AgregarNodo(1, "Daniel", "Alvarez", 1, 3);
        arbol->AgregarNodo(2, "Juan", "Perez", 1, 1);
        arbol->AgregarNodo(3, "Pedro", "Rodriguez", 1, 1);
        arbol->AgregarNodo(4, "Jose", "Rojas", 2, 2);
        arbol->AgregarNodo(5, "Mario", "Bonilla", 2, 3);

        ostringstream streamSalida {};
        streamSalida << *arbol;
        string actual = streamSalida.str();

        delete arbol;

        ostringstream streamSalidaEsperada {};
        streamSalidaEsperada << "1, Daniel Alvarez, , 0" << std::endl;
        streamSalidaEsperada << "2, Juan Perez, Daniel Alvarez, 0" << std::endl;
        streamSalidaEsperada << "4, Jose Rojas, Juan Perez, 0" << std::endl;
        streamSalidaEsperada << "3, Pedro Rodriguez, Daniel Alvarez, 0" << std::endl;
        streamSalidaEsperada << "5, Mario Bonilla, Pedro Rodriguez, 0" << std::endl;
        string esperada = streamSalidaEsperada.str();

        EXPECT_EQ(esperada, actual);
    }

    TEST(ArbolTests, Test_Lectura_Stream) {
            
        ostringstream streamGeneracionEjemplo {};
        streamGeneracionEjemplo << "1 Daniel Alvarez daniel.alvarez@email.com 1" << std::endl;
        streamGeneracionEjemplo << "2 Juan Perez juan.perez@email.com 1 1" << std::endl;
        string entradaEjemplo = streamGeneracionEjemplo.str();

        istringstream streamEntradaEjemplo {entradaEjemplo};
        Arbol *arbol = new Arbol();
        streamEntradaEjemplo >> *arbol;

        ostringstream streamSalida {};
        streamSalida << *arbol;
        string actual = streamSalida.str();

        delete arbol;

        ostringstream streamSalidaEsperada {};
        streamSalidaEsperada << "1, Daniel Alvarez, , 0" << endl;
        streamSalidaEsperada << "2, Juan Perez, Daniel Alvarez, 0" << endl;
        string esperada = streamSalidaEsperada.str();

        EXPECT_EQ(esperada, actual);
    }

    TEST(ArbolTest, Test_SetSalarioDeNomina){
       Arbol *arbol = new Arbol();
        arbol->AgregarNodo(1, "Daniel", "Alvarez", 1, 3);
        arbol->SetSalario(1, 200, 4); 

        ostringstream streamSalida {};
        streamSalida << *arbol;
        string actual = streamSalida.str();

        string esperada = "1, Daniel Alvarez, , 186\n";

        delete arbol;

        EXPECT_EQ(esperada, actual);
    }

    TEST(ArbolTest, Test_SetSalarioPorHoras){
       Arbol *arbol = new Arbol();
        arbol->AgregarNodo(1, "Daniel", "Alvarez", 2, 3);
        arbol->SetSalario(1, 200, 4); 

        ostringstream streamSalida {};
        streamSalida << *arbol;
        string actual = streamSalida.str();

        string esperada = "1, Daniel Alvarez, , 800\n";

        delete arbol;

        EXPECT_EQ(esperada, actual);
    }
    
    TEST(ArbolTest, Test_GetNeto){
       Arbol *arbol = new Arbol();
        arbol->AgregarNodo(1, "Daniel", "Alvarez", 1, 0);
        arbol->AgregarNodo(2, "Juan", "Perez", 2, 1);

        arbol->SetSalario(1, 2000, 0);
        arbol->SetSalario(2, 200, 4); 

        float actual = arbol->GetNeto();

        float esperado = (800+2000*0.93);

        delete arbol;

        EXPECT_FLOAT_EQ(esperado, actual);
    }
    TEST(ArbolTest, Test_GetBruto){
       Arbol *arbol = new Arbol();
        arbol->AgregarNodo(1, "Daniel", "Alvarez", 1, 0);
        arbol->AgregarNodo(2, "Juan", "Perez", 2, 1);

        arbol->SetSalario(1, 2000, 0);
        arbol->SetSalario(2, 200, 4); 

        float actual = arbol->GetBruto();

        float esperado = (800+2000);

        delete arbol;

        EXPECT_FLOAT_EQ(esperado, actual);
    }
    TEST(ArbolTest, Test_GetRetencion){
       Arbol *arbol = new Arbol();
        arbol->AgregarNodo(1, "Daniel", "Alvarez", 1, 0);
        arbol->AgregarNodo(2, "Juan", "Perez", 2, 1);

        arbol->SetSalario(1, 2000, 0);
        arbol->SetSalario(2, 200, 4); 

        float actual = arbol->GetRetencion();

        float esperado = 140;

        delete arbol;

        EXPECT_FLOAT_EQ(esperado, actual);
    }
}