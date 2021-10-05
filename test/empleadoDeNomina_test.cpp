#include <gtest/gtest.h>
#include "C:/progra2/tarea_2_progra2/src/empleadoDeNomina.h"
#include <string>
using namespace std;

namespace{

    TEST(EmpleadoDeNomina, SetSalario_GetSalario_test){
        EmpleadoDeNomina *empleado1 = new EmpleadoDeNomina(4,"Daniel", "Alvarez",3);
        empleado1->SetSalario(200,4);
        float salario = empleado1->GetSalario();
        EXPECT_FLOAT_EQ(200, salario);
    }

    TEST(EmpleadoDeNomina_Test, SetNombreSupervisor_GetNombreSupervisor_Test){
       EmpleadoDeNomina *empleado1 = new EmpleadoDeNomina(4,"Daniel", "Alvarez",3);
       empleado1->SetNombreSupervisor("Juan Perez");
       string nombreSupervisor = empleado1->GetNombreSupervisor();
       EXPECT_EQ("Juan Perez", nombreSupervisor); 
    } 
    TEST(EmpleadoDeNomina_Test, Getid_Test){
       EmpleadoDeNomina *empleado1 = new EmpleadoDeNomina(4,"Daniel", "Alvarez",3);
       int id = empleado1->Getid();
       EXPECT_EQ(4, id); 
    }  
    TEST(EmpleadoDeNomina_Test, GetNombreCompleto_Test){
       EmpleadoDeNomina *empleado1 = new EmpleadoDeNomina(4,"Daniel", "Alvarez",3);
       string nombreSupervisor = empleado1->GetNombreCompleto();
       EXPECT_EQ("Daniel Alvarez", nombreSupervisor);
    }

}