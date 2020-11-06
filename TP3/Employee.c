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

    if(pEmployee != NULL && id >=0)
    {
        pEmployee ->id = id;
        allOk = 1;
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

    if(pEmployee != NULL && strlen(nombre) > 0)
    {
        strcpy(pEmployee ->nombre,nombre);
        allOk = 1;
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

    if(pEmployee != NULL && horasTrabajadas >=0)
    {
        pEmployee ->horasTrabajadas = horasTrabajadas;
        allOk = 1;
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

    if(pEmployee != NULL && sueldo >=0)
    {
        pEmployee ->sueldo = sueldo;
        allOk = 1;
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
    printf("%s  %s  %s   %s\n",emp->id,emp->nombre,emp->horasTrabajadas,emp->sueldo);
    return 1;
}
Employee* employee_GetCreateAnEmployee()
{
    int id;
    char nombre[128];
    Employee * emp = employee_new();
    int horasTrabajadas;
    int sueldo;

    printf("Ingrese ID");
    scanf("%d",&id);
    emp->id = id;

    printf("Ingrese nombre");
    gets(nombre);
    strcpy(emp->nombre, nombre);

    printf("Ingrese sueldo");
    scanf("%d",&sueldo);
    emp->sueldo = sueldo;

    printf("Ingrese horas");
    scanf("%d",&horasTrabajadas);
    emp->horasTrabajadas = horasTrabajadas;

    return emp;
}
