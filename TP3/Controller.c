#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "parser.h"
#include "Employee.h"
#include "string.h"
#include "Controller.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    FILE * f = fopen(path,"r");
    if(f == NULL)
    {
        printf("No se puede abrir el archivo \n");
    }
    todoOk = parser_EmployeeFromText(f,pArrayListEmployee);
    fclose(f);
    return todoOk;
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
    int todoOk = 0;
    FILE * f = fopen(path,"rb");
    if(f == NULL)
    {
        printf("No se puede abrir el archivo \n");
    }
    todoOk = parser_EmployeeFromText(f,pArrayListEmployee);
    fclose(f);
    return todoOk;
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
    Employee * emp ;
    emp = employee_GetCreateAnEmployee();
    ll_add(pArrayListEmployee,emp);
    return 1;
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
    int id = 0 ;
    int allok = 0 ;
    int pos = 0;
    int sueldo = 0;
    int horas = 0;
    char nombre[128];
    int rsta =0;
    printf("Seleccion el id del empleado a editar ");
    controller_ListEmployee(pArrayListEmployee);
    scanf("%d",&id);
    pos = controller_getIndex(pArrayListEmployee,id);
    if(pos >=0)
    {
        Employee * auxEmp = (Employee *) ll_get(pArrayListEmployee,pos);
        printf("Desea modifca el nombre ? si 1, no 0\n");
        scanf("%d",&rsta);
        if(rsta)
        {
            printf("Ingrese el nombre \n");
            fflush(stdin);
            gets(nombre);
            strcpy(auxEmp->nombre,nombre);

        }

        printf("Desea modifica las horas trabajadas ? si 1, no 0\n");
        scanf("%d",&rsta);
        if(rsta)
        {
            printf("Ingrese las horas trabajas \n");
            scanf("%d",&horas);
            if(horas <0)
            {
                printf("horas  invalidas, deben ser mayor a 0 \n");
            }
            else
            {
                auxEmp->horasTrabajadas = horas;
            }
        }

        printf("Desea modifica el sueldo ? si 1, no 0\n");
        scanf("%d",&rsta);
        if(rsta)
        {
            printf("Ingrese el sueldo trabajas \n");
            scanf("%d",&sueldo);
            if(sueldo <0)
            {
                printf("Sueldo invalido, deber ser mayor a 0 \n");
            }
            else
            {
                auxEmp->sueldo = sueldo;
            }
        }

        allok= ll_remove(pArrayListEmployee,pos);
        ll_add(pArrayListEmployee,auxEmp);
    }
    return allok;
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
    int id ;
    int allok = 0 ;
    int pos;
    printf("Seleccion el id del empleado");
    controller_ListEmployee(pArrayListEmployee);
    scanf("%d",&id);
    pos = controller_getIndex(pArrayListEmployee,id);
    if(pos >=0)
    {
        allok= ll_remove(pArrayListEmployee,pos);
    }
    return allok;
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
    int todoOk =1;
    printf("id  nombre  horas   sueldo\n");
    int tam = ll_len(pArrayListEmployee);
    Employee *auxEmp;
    if(pArrayListEmployee != NULL)
    {
        for(int i =0; i< tam ; i++)
        {
            auxEmp = (Employee *) ll_get(pArrayListEmployee,i);
            if(auxEmp != NULL)
            {
                employee_showEmployee(auxEmp);
            }
        }
    }
    return todoOk;
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
    int opc ;
    int order ;
    int allOk = 1;
    do
    {
        printf("Si desea ordenar por: ID ingrese %d,Nombre ingrese %d,horas Trabajadas ingrese %d,Sueldo ingrese %d",1,2,3,4);
        scanf("%d",&opc);
    }
    while(opc < 1 || opc >4);

    do
    {
        printf("Si desea ordenar ascendentemente ingrese 0, sino 1");
        scanf("%d",&order);
    }
    while(order != 0 ||order != 1);

    switch(opc)
    {
    case 1:
        ll_sort(pArrayListEmployee,controller_compararId,order);
        break;
    case 2:
        ll_sort(pArrayListEmployee,controller_compararNombre,order);
        break;
    case 3:
        ll_sort(pArrayListEmployee,controller_compararHorasTrabajadas,order);
        break;
    case 4:
        ll_sort(pArrayListEmployee,controller_compararSueldo,order);
        break;
    }
    return allOk;
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
    int todoOk = 0;
    FILE * f = fopen(path,"a");
    if(f == NULL)
    {
        printf("No se puede abrir el archivo \n");
    }
    int tam = ll_len(pArrayListEmployee);
    Employee *auxEmp;
    for(int i =0; i< tam ; i++)
    {
        auxEmp = (Employee *) ll_get(pArrayListEmployee,i);
        if(auxEmp != NULL)
        {
            fprintf(f,"%d,%s,%d,%d\n",auxEmp->id,auxEmp->nombre,auxEmp->horasTrabajadas,auxEmp->sueldo);
        }
    }
    fclose(f);
    return todoOk;
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
    int todoOk = 0;
    FILE * f = fopen(path,"ab");
    if(f == NULL)
    {
        printf("No se puede abrir el archivo \n");
    }
    int tam = ll_len(pArrayListEmployee);
    Employee *auxEmp;
    for(int i =0; i< tam ; i++)
    {
        auxEmp = (Employee *) ll_get(pArrayListEmployee,i);
        if(auxEmp != NULL)
        {
            fwrite(&auxEmp,sizeof(Employee),1,f);
        }
    }
    fclose(f);
    return todoOk;
}

int controller_getIndex(LinkedList * pArrayListEmployee, int id)
{

    int index = -1;
    int tam = ll_len(pArrayListEmployee);
    Employee *auxEmp;
    for(int i =0; i< tam ; i++)
    {
        auxEmp = (Employee *) ll_get(pArrayListEmployee,i);
        if(auxEmp->id == id)
        {
            return i;
        }
    }
    printf("No se encuentra el id %d, en la lista \n",id);
    return index;
}

int controller_compararId(void * emp1,void * emp2)
{
    return 0;
}
int controller_compararNombre(void * emp1,void * emp2)
{
    return 0;
}
int controller_compararSueldo(void * emp1,void * emp2)
{
    return 0;
}
int controller_compararHorasTrabajadas(void * emp1,void * emp2)
{
    return 0;
}
