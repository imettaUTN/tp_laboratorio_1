#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int error = 1;
    char buffer[4][128];
    int cant ;
    if(pFile == NULL && pArrayListEmployee == NULL  )
    {
        printf("No se puede abrir el archivo \n");
        return error;
    }
    fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);
    while(!feof(pFile))
    {
        Employee * aux;
        cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);
        if(cant == 4)
        {
            aux = employee_newParametros(buffer[0],buffer[1],buffer[2],buffer[3]);
            if(aux != NULL)
            {
               error= ll_add(pArrayListEmployee,aux);
            }

        }
        else
        {
            break;
        }
    }

    return error;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int error = 1;
    int count ;
    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        while(!feof(pFile))
        {
            Employee* auxEmployee = employee_new();
            count= fread(auxEmployee, sizeof(Employee), 1, pFile);
            if(count >0)
            {
             error= ll_add(pArrayListEmployee, auxEmployee);

            }
        }
    }
    return error;

}
