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

    if(auxEmployee != NULL && id>=0 && nombre != NULL && horasTrabajadas >=0 && sueldo >=0)
    {

        if(employee_setId(auxEmployee,id) && employee_setNombre(auxEmployee,nombre) && employee_setSueldo(auxEmployee,sueldo) && employee_setHorasTrabajadas(auxEmployee,horasTrabajadas))
        {
            // sino pude hacer el set, borro el empleado liberando memoria
            auxEmployee = NULL;
            employee_delete(auxEmployee);
        }
        else
        {
            employee_setId(auxEmployee,id);
            employee_setNombre(auxEmployee,nombre) ;
            employee_setSueldo(auxEmployee,sueldo) ;
            employee_setHorasTrabajadas(auxEmployee,horasTrabajadas);
        }
    }
    return auxEmployee;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char * sueldo)
{
    Employee * auxEmployee;
    auxEmployee= employee_new();

    if(auxEmployee != NULL && idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldo != NULL)
    {

        if(employee_setId(auxEmployee,atoi(idStr)) && employee_setNombre(auxEmployee,nombreStr) && employee_setSueldo(auxEmployee,atoi(sueldo)) && employee_setHorasTrabajadas(auxEmployee,atoi(horasTrabajadasStr)))
        {
            // sino pude hacer el set, borro el empleado liberando memoria
            auxEmployee = NULL;
            employee_delete(auxEmployee);
        }
        else
        {
            employee_setId(auxEmployee,atoi(idStr)) ;
            employee_setNombre(auxEmployee,nombreStr);
            employee_setSueldo(auxEmployee,atoi(sueldo)) ;
            employee_setHorasTrabajadas(auxEmployee,atoi(horasTrabajadasStr));
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
    int error = 1;

    if(pEmployee != NULL )
    {
        if(id >= 0)
        {
            pEmployee ->id = id;
            error = 0;

        }
        else
        {
            printf("Id invalido \n");
        }
    }
    return error;

}
int employee_getId(Employee* pEmployee,int* id)
{
    int error = 1;

    if( pEmployee !=NULL)
    {
        *id = pEmployee ->id;
        error = 0;
    }
    return error;

}

int employee_setNombre(Employee* pEmployee,char* nombre)
{
    int error = 1;
    fflush(stdin);
    if(pEmployee != NULL)
    {
        if(strlen(nombre) > 0)
        {
            strcpy(pEmployee ->nombre,nombre);
            error = 0;

        }
        else
        {
            printf("Nombre invalido \n");
        }
    }
    return error;
}

int employee_getNombre(Employee* pEmployee,char* nombre)
{
    int error = 1;

    if(pEmployee != NULL)
    {
        strcpy(nombre,pEmployee ->nombre);
        error = 0;
    }

    return error;
}

int employee_setHorasTrabajadas(Employee* pEmployee,int horasTrabajadas)
{
    int error = 1;

    if(pEmployee != NULL )
    {
        if(horasTrabajadas >=0)
        {
            pEmployee ->horasTrabajadas = horasTrabajadas;
            error = 0;

        }
        else
        {
            printf("Horas trabajadas invalidas \n");
        }
    }
    return error;
}
int employee_getHorasTrabajadas(Employee* pEmployee,int* horasTrabajadas)
{
    int error = 1;

    if(pEmployee != NULL)
    {
        *horasTrabajadas = pEmployee ->horasTrabajadas ;
        error = 0;
    }
    return error;
}

int employee_setSueldo(Employee* pEmployee,int sueldo)
{
    int error = 1;

    if(pEmployee != NULL)
    {
        if( sueldo >=0)
        {
            pEmployee ->sueldo = sueldo;
            error = 0;
        }
        else
        {
            printf("Sueldo invalido \n");
        }
    }
    return error;
}
int employee_getSueldo(Employee* pEmployee,int* sueldo)
{
    int error = 1;

    if(pEmployee != NULL)
    {
        *sueldo = pEmployee ->sueldo ;
        error = 0;
    }
    return error;
}

int employee_showEmployee(Employee * emp)
{
    printf("%d  %s    %d     %d\n",emp->id,emp->nombre,emp->horasTrabajadas,emp->sueldo);
    return 0;
}
