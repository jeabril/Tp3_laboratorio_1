#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "Controller.h"
#include "LinkedList.h"
#define R_OK 1
#define R_ERROR 0




/*/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*******************************************************/


int main()
{
    int opcion = 0;

    LinkedList* listaEmpleados = ll_newLinkedList();

    do
    {
        opcion= menu();


        switch(opcion)
        {
        case 1:
            controller_loadFromText("data.csv",listaEmpleados);
            break;
        case 2:
            controller_loadFromBinary("data.csv",listaEmpleados);
            break;
        case 3:
            controller_addEmployee(listaEmpleados);
            break;
        case 4:
            controller_editEmployee(listaEmpleados);
            break;
        case 5:
            controller_removeEmployee(listaEmpleados);
            break;
        case 6:
            controller_ListEmployee(listaEmpleados);
            break;
        case 7:
            controller_sortEmployee(listaEmpleados);
            break;
        case 8:
            controller_saveAsText("data.csv", listaEmpleados);
            break;
        case 9:
            controller_saveAsBinary("data.bin", listaEmpleados);
            break;

        }

    }while(opcion != 10);






    return 0;
}

int menu()
{
    int op;
    system("color F5");
    system("cls");

    do{
        printf("************************************************************************************\n");
        printf("*     Menu:                                                                         *\n");
        printf("*     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)   *\n");
        printf("*     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario) *\n");
        printf("*     3. Alta de empleado                                                           *\n");
        printf("*     4. Modificar datos de empleado                                                *\n");
        printf("*     5. Baja de empleado                                                           *\n");
        printf("*     6. Listar empleados                                                           *\n");
        printf("*     7. Ordenar empleados                                                          *\n");
        printf("*     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).    *\n");
        printf("*     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).  *\n");
        printf("*    10. Salir                                                                      *\n");
        printf("************************************************************************************\n");

    printf("Elija una opcion: ");
        scanf("%d",&op);
    }while(op < 1 || op > 10);


    return op;


}

int editMenu()
{
    int r;

    do
    {
        system("cls");
        printf("    ***Elija el campo que desea modificar***\n\n");
        printf("      *****************************\n");
        printf("      *   1. Nombre.              *\n");
        printf("      *   2. Horas trabajadas.    *\n");
        printf("      *   3. Sueldo.              *\n");
        printf("      *   4. Salir.               *\n");
        printf("      *****************************\n");
        scanf("%d", &r);
    }
    while(r < 1 || r > 4);

    return r;
}

int ordMenu()
{
    int r;

    do
    {
        system("cls");
        printf("    *** Elija mediante que campo desea ordenar:***\n\n");
        printf("                ***************************\n");
        printf("                *   1. Id.                *\n");
        printf("                *   2. Nombre.            *\n");
        printf("                *   3. Horas Trabajadas.  *\n");
        printf("                *   4. Sueldo             *\n");
        printf("                *   5. Salir              *\n");
        printf("                ***************************\n");
        scanf("%d", &r);
    }
    while(r < 1 || r > 5);

    return r;
}
