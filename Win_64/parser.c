#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#define R_OK 1
#define R_ERROR 0

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int r=R_ERROR;



    FILE* pfile;

    char id[5];
    char nombre[21];
    char horasTrabajadas[7];
    char sueldo[7];
    int cant;

    if(pfile != NULL)
    {
        while(!feof(pFile))
        {
            r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,\n]\n", id, nombre, horasTrabajadas, sueldo);
            if(cant != 4)
            {
                printf("Error, no se pudo cargar archivo \n\n");
            }
            else
            {
                Employee* emp = employee_new();
                emp->id = atoi(id);
                strcpy(emp->nombre, nombre);
                emp->horasTrabajadas = atoi(horasTrabajadas);
                emp->sueldo = atoi(sueldo);
                ll_add(pArrayListEmployee, emp);
                system("pause");
            }
        fclose(pfile);
        R_OK;
        }
    }
    else
    {
        printf("Hay datos en el archivo\n\n");
    }

    return r;

}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int r=R_ERROR;

    FILE* pfile;

    if(pfile != NULL)
    {
        while(!feof(pFile))
        {

                Employee* emp = employee_new();
                r = fread(emp, sizeof(Employee),1,pFile);
                ll_add(pArrayListEmployee, emp);
                r = R_OK;

        }
    }
    else
    {
        printf("No hay datos");
    }
    fclose(pfile);

    return r;
}
