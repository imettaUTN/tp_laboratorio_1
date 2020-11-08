#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "Employee.h"

Employee* employee_new()
{
    return (Employee *) malloc(sizeof(Employee));
}

Employee* employee_newParametrosNonString(int id,char* nombre,int horasTrabajadas, int sueldo)
{
    Employee * auxEmployee;
    auxEmployee= employee_new();

    if(auxEmployee != NULL)
    {

        if(!(employee_setId(auxEmployee,id) && employee_setNombre(auxEmployee,nombre) && employee_setSueldo(auxEmployee,sueldo) && employee_setHorasTrabajadas(auxEmployee,horasTrabajadas)))
        {
            // sino pude hacer el set, borro el empleado liberando memoria
            auxEmployee = NULL;
            employee_delete(auxEmployee);
        }
    }
    return auxEmployee;
}


Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char * sueldo)
{
    Employee * auxEmployee;
    auxEmployee= employee_new();

    if(auxEmployee != NULL)
    {

        if(!(employee_setId(auxEmployee,atoi(idStr)) && employee_setNombre(auxEmployee,nombreStr) && employee_setSueldo(auxEmployee,atoi(sueldo)) && employee_setHorasTrabajadas(auxEmployee,atoi(horasTrabajadasStr))))
        {
            // sino pude hacer el set, borro el empleado liberando memoria
            auxEmployee = NULL;
            employee_delete(auxEmployee);
        }
    }
    return auxEmployee;
}
void employee_delete(Employee* pEmployee)
{
    free(pEmployee);
}

int employee_setId(Employee* pEmployee,int id)
{
    int allOk = 0;

    if(pEmployee != NULL )
    {
        if(id >= 0)
        {
            pEmployee ->id = id;
            allOk = 1;

        }
        else
        {
            printf("Id invalido \n");
        }
    }
    return allOk;

}
int employee_getId(Employee* pEmployee,int* id)
{
    int allOk = 0;

    if( pEmployee !=NULL)
    {
        *id = pEmployee ->id;
        allOk = 1;
    }
    return allOk;

}

int employee_setNombre(Employee* pEmployee,char* nombre)
{
    int allOk = 0;
    fflush(stdin);
    if(pEmployee != NULL)
    {
        if(strlen(nombre) > 0)
        {
            strcpy(pEmployee ->nombre,nombre);
            allOk = 1;

        }
        else
        {
            printf("Nombre invalido \n");
        }
    }
    return allOk;
}

int employee_getNombre(Employee* pEmployee,char* nombre)
{
    int allOk = 0;

    if(pEmployee != NULL)
    {
        strcpy(nombre,pEmployee ->nombre);
        allOk = 1;
    }

    return allOk;
}

int employee_setHorasTrabajadas(Employee* pEmployee,int horasTrabajadas)
{
    int allOk = 0;

    if(pEmployee != NULL )
    {
        if(horasTrabajadas >=0)
        {
            pEmployee ->horasTrabajadas = horasTrabajadas;
            allOk = 1;

        }
        else
        {
            printf("Horas trabajadas invalidas \n");
        }
    }
    return allOk;
}
int employee_getHorasTrabajadas(Employee* pEmployee,int* horasTrabajadas)
{
    int allOk = 0;

    if(pEmployee != NULL)
    {
        *horasTrabajadas = pEmployee ->horasTrabajadas ;
        allOk = 1;
    }
    return allOk;
}

int employee_setSueldo(Employee* pEmployee,int sueldo)
{
    int allOk = 0;

    if(pEmployee != NULL)
    {
        if( sueldo >=0)
        {
            pEmployee ->sueldo = sueldo;
            allOk = 1;
        }
        else
        {
            printf("Sueldo invalido \n");
        }
    }
    return allOk;
}
int employee_getSueldo(Employee* pEmployee,int* sueldo)
{
    int allOk = 0;

    if(pEmployee != NULL)
    {
        *sueldo = pEmployee ->sueldo ;
        allOk = 1;
    }
    return allOk;
}

int employee_showEmployee(Employee * emp)
{
    return printf("%d  %s    %d     %d\n",emp->id,emp->nombre,emp->horasTrabajadas,emp->sueldo);
}
