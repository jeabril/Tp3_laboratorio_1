#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "Controller.h"
#include "LinkedList.h"
#define R_OK 1
#define R_ERROR 0

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int r=R_ERROR;

    FILE* pfile = fopen("data.csv", "r");

    if(pfile != NULL)
    {
        r = parser_EmployeeFromText(pfile, pArrayListEmployee);
    }
    else
    {
        printf("Archivo inexistente\n\n");
        system("pause");
    }

    return r;

}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    int r=R_ERROR;

    FILE* pfile = fopen("data.bin", "rb");

    if(pfile != NULL)
    {
        r = parser_EmployeeFromText(pfile, pArrayListEmployee);
    }
    else
    {
        printf("Archivo inexistente\n\n");
        system("pause");
    }

    return r;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int r=R_ERROR;

    Employee* empleado = employee_new();
    int id;
    char nombre[21];
    int horasTrabajadas;
    int sueldo;

    if(pArrayListEmployee != NULL)
    {
        printf("Ingrese ID: ");
        scanf("%d", &id);
        r = employee_setId(empleado, id);

        printf("Ingrese el nombre: ");
        scanf("%s", nombre);
        r = employee_setNombre(empleado, nombre);

        printf("Ingrese la cantidad de horas trabajadas: ");
        scanf("%d", &horasTrabajadas);
        r = employee_setHorasTrabajadas(empleado, horasTrabajadas);

        printf("Ingrese el sueldo: ");
        scanf("%d", &sueldo);
        r = employee_setSueldo(empleado, sueldo);

        r = ll_add(pArrayListEmployee, empleado);
    }
    else
    {
        printf("No hay Datos\n\n");
    }
    return r;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int r=R_ERROR;

    int id;
    int editID;
    char nombreEmployee[21];
    int horasTrabajadas;
    int sueldo;

    Employee* employeeAux = employee_new();

    if(pArrayListEmployee != NULL)
    {
        system("cls");
        printf("\nIngrese ID: ");
        scanf("%d", &editID);

        for(int i = 0; i < ll_len(pArrayListEmployee); i++)
        {
            employeeAux = (Employee*) ll_get(pArrayListEmployee, i);
            r = employee_getId(employeeAux, &id);

            if(r == R_OK)
            {
                if(id == editID)
                {
                    switch(editMenu())
                    {
                    case 1:
                        employee_showOneEmployee(employeeAux);
                        printf("Ingrese nuevo nombre: ");
                        scanf("%s",employeeAux->nombre);
                        strcpy(employeeAux->nombre, nombreEmployee);
                        break;
                    case 2:
                        printf("Ingrese la cantidad de horas trabajadas: ");
                        scanf("%d",employeeAux->horasTrabajadas);
                        employeeAux->horasTrabajadas = horasTrabajadas;
                        break;
                    case 3:
                        printf("Ingrese nuevo sueldo: ");
                        scanf("%d",employeeAux->sueldo);
                        employeeAux->sueldo = sueldo;
                        break;
                    case 4:
                        break;

                    }
                    r = ll_set(pArrayListEmployee, i, employeeAux);
                    break;
                }
            }
        }
    }
    else
    {
        printf("No hay Datos\n\n");
    }




    return r;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int r=R_ERROR;

    char seguir;
    int ind;
    int id = 0;

    if(pArrayListEmployee != NULL)
    {
        printf("Ingrese el ID que desea eliminar: ");
        scanf("%d", &id);

        for(int i = 0; i < ll_len(pArrayListEmployee); i++)
        {
            ind = (Employee*) ll_get(pArrayListEmployee, i);
            r = employee_getId(ind, &id);

            if(r == R_OK)
            {
                employee_ShowOneEmployee(r);

                printf("\nPresione 's' para confirmar o 'n' para anular la operacion: ");
                fflush(stdin);
                scanf("%c", &seguir);

                if(seguir == 'n')
                {
                    printf("Se ha cancelado la operacion\n\n");

                }
                else

                {
                    ll_remove(pArrayListEmployee, ind);
                    printf("Se ha eliminado correctamente\n\n");
                }
                system("pause");
            }
        }
    }

    return r;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int r=R_ERROR;
    int len;
    len = ll_len(pArrayListEmployee);

    if(pArrayListEmployee != NULL)
    {
        if(len != 0)
        {
            printf("Id  Nombre  Horas Trab.  Sueldo\n\n");
            for(int i = 0; i < len; i++)
            {
                employee_showOneEmployee(pArrayListEmployee);
                r= R_OK;
                break;
            }
            system("pause");
        }
        else
        {
            printf("No hay datos\n\n");
            system("pause");
        }
    }
    return r;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int r=R_ERROR;
    if(pArrayListEmployee != NULL)
    {
        switch(ordMenu())
        {
        case 1:
            ll_sort(pArrayListEmployee, employee_ordById,1);
            employee_showAllEmployees(pArrayListEmployee);
            break;
        case 2:
            ll_sort(pArrayListEmployee, employee_ordByName,1);
            employee_showAllEmployees(pArrayListEmployee);
            break;
        case 3:
            ll_sort(pArrayListEmployee, employee_ordByHorasTrabajadas,1);
            employee_showAllEmployees(pArrayListEmployee);
            break;
        case 4:
            ll_sort(pArrayListEmployee, employee_ordBySueldo,1);
            employee_showAllEmployees(pArrayListEmployee);
            break;
        case 5:
            break;
        }
    }
    else
    {
        printf("No hay datos");
    }
    system("pause");

    return r;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    int r=R_ERROR;

    FILE* pfile;
    pfile = fopen("data.csv", "wb");
    Employee* employee;

    if(pArrayListEmployee != NULL)
    {
        for(int i = 0; i<ll_len(pArrayListEmployee); i++)
        {
            employee = (Employee*)ll_get(pArrayListEmployee, i);
            fprintf(pfile, "%d,%s,%d,%d",employee->id,employee->nombre,employee->horasTrabajadas, employee->sueldo);
        }
    }
    else
    {
        printf("No hay datos");
    }
    fclose(pfile);

    return r;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    int r=R_ERROR;

    FILE* pfile;
    pfile = fopen("data.bin", "wb");
    Employee* employee;

    if(pArrayListEmployee != NULL)
    {
        for(int i = 0; i<ll_len(pArrayListEmployee); i++)
        {
            employee = (Employee*)ll_get(pArrayListEmployee, i);
            fwrite(employee, sizeof(Employee*), 1, pfile);
        }
    }
    else
    {
        printf("No hay datos");
    }
    fclose(pfile);


    return r;
}
