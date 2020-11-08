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
        return todoOk;
    }
    todoOk = parser_EmployeeFromText(f,pArrayListEmployee);
    fclose(f);
    printf("Carga de datos exitosa \n");
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
        return todoOk;
    }
    todoOk = parser_EmployeeFromBinary(f,pArrayListEmployee);
    fclose(f);
    printf("Carga de datos exitosa \n");
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
    char nombre[128];
    Employee * emp = employee_new();
    int horasTrabajadas;
    int sueldo;

    employee_setId(emp,controller_getLastId(pArrayListEmployee) +1);

    do
    {
        printf("Ingrese nombre \n");
        fflush(stdin);
        gets(nombre);
    }
    while(!employee_setNombre(emp, nombre));

    do
    {
        printf("Ingrese sueldo \n");
        scanf("%d",&sueldo);
    }
    while(!employee_setSueldo(emp,sueldo));

    do
    {
        printf("Ingrese horas \n");
        scanf("%d",&horasTrabajadas);
    }
    while(!employee_setHorasTrabajadas(emp,horasTrabajadas));

    ll_add(pArrayListEmployee,emp);
    free(emp);
    printf("Alta exitosa\n");
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


    if(pArrayListEmployee == NULL || ll_isEmpty(pArrayListEmployee))
    {
        printf("Lista vacia. No hay empleado para editar \n");
        return allok;
    }

    printf("Seleccion el id del empleado a editar \n");
    controller_ListEmployee(pArrayListEmployee);
    scanf("%d",&id);
    //obtengo posicion en la lista para recuperar la estructura
    pos = controller_getIndex(pArrayListEmployee,id);
    // recupero la esctrura del empleado
    Employee * auxEmp = (Employee *) ll_get(pArrayListEmployee,pos);

    printf("Empleado a editar :\n");
    employee_showEmployee(auxEmp);
    printf("Esta seguro que desea editar el empleado Si 1 , No 0: \n");
    scanf("%d",&rsta);
    // si ingreso que no lo quiere modificar pongo el negado de 0 para que devuelva ok porque no hay error
    allok = !rsta;
    if(rsta)
    {

        if(pos >=0)
        {
            Employee * emp = (Employee *) ll_get(pArrayListEmployee,pos);
            printf("Desea modifca el nombre ? si 1, no 0\n");
            scanf("%d",&rsta);
            if(rsta)
            {
                do
                {
                    printf("Ingrese nombre \n");
                    gets(nombre);
                }
                while(!employee_setNombre(emp, nombre));
            }

            printf("Desea modifica las horas trabajadas ? si 1, no 0\n");
            scanf("%d",&rsta);
            if(rsta)
            {
                do
                {
                    printf("Ingrese horas \n");
                    scanf("%d",&horas);
                }
                while(!employee_setHorasTrabajadas(emp,horas));
            }

            printf("Desea modifica el sueldo ? si 1, no 0\n");
            scanf("%d",&rsta);
            if(rsta)
            {
                do
                {
                    printf("Ingrese sueldo \n");
                    scanf("%d",&sueldo);
                }
                while(!employee_setSueldo(emp,sueldo));
            }

            allok= ll_remove(pArrayListEmployee,pos);
            allok = ll_add(pArrayListEmployee,emp);

        }
        else
        {
            printf("No se encuentra el id %d, en la lista \n",id);
        }
    }
    if(allok)
    {
        printf("Edicion del empleado correcta \n");
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
    int rsta ;
    int allok = 0 ;
    int pos;
    if(pArrayListEmployee == NULL || ll_isEmpty(pArrayListEmployee))
    {

        printf("Lista vacia \n");
        return !allok;
    }

    printf("Seleccion el id del empleado a eliminar \n");
    controller_ListEmployee(pArrayListEmployee);
    scanf("%d",&id);
    pos = controller_getIndex(pArrayListEmployee,id);
    Employee * auxEmp = (Employee *) ll_get(pArrayListEmployee,pos);
    printf("Empleado a eliminar :\n");
    employee_showEmployee(auxEmp);
    printf("Esta seguro que desea eliminar el empleado Si 1 , No 0: \n");
    scanf("%d",&rsta);
    // si ingreso que no lo quiere modificar pongo el negado de 0 para que devuelva ok porque no hay error
    allok = !rsta;
    if(rsta)
    {
        if(pos >=0)
    {
        allok= ll_remove(pArrayListEmployee,pos);
    }
    if(allok)
    {
        printf("Remocion correcta \n");
    }
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
    Employee *auxEmp ;
    if(pArrayListEmployee != NULL || !ll_isEmpty(pArrayListEmployee))
    {
        for(int i =0; i< tam ; i++)
        {
            auxEmp = (Employee *)ll_get(pArrayListEmployee,i);

            if(auxEmp != NULL)
            {
                employee_showEmployee(auxEmp);
            }
        }
    }
    else
    {
        printf("Lista vacia \n");
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
    int allOk = 0;
    if(pArrayListEmployee == NULL || ll_isEmpty(pArrayListEmployee))
    {
        printf("La lista se encuentra vacia");
        return !allOk;
    }

    do
    {
        printf("Si desea ordenar por ID ingrese %d\nSi desea ordenar por Nombre ingrese %d\nSi desea ordenar por horas Trabajadas ingrese %d\n Si desea ordenar por Sueldo ingrese %d\n",1,2,3,4);
        scanf("%d",&opc);
    }
    while(opc < 1 || opc >4);

    do
    {
        printf("Si desea ordenar ascendentemente ingrese 0, sino 1\n");
        scanf("%d",&order);
    }
    while(order < 0 ||order > 1);

    switch(opc)
    {
    case 1:
        allOk =ll_sort(pArrayListEmployee,controller_compararId,order);
        break;
    case 2:
       allOk= ll_sort(pArrayListEmployee,controller_compararNombre,order);
        break;
    case 3:
        allOk =ll_sort(pArrayListEmployee,controller_compararHorasTrabajadas,order);
        break;
    case 4:
        allOk = ll_sort(pArrayListEmployee,controller_compararSueldo,order);
        break;
    }
    if(allOk)
    {
        printf("Ordenamiento correcto \n");
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
    if(pArrayListEmployee == NULL || ll_isEmpty(pArrayListEmployee))
    {
        printf("La lista esta vacia, no se grabara nada \n");
        return !todoOk;
    }
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
   int allok=0;
    FILE* pFile=fopen(path, "wb");
    Employee* auxEmployee;
    int tam= ll_len(pArrayListEmployee);
    if(pArrayListEmployee != NULL || !ll_isEmpty(pArrayListEmployee))
    {
        for(int i=0; i<tam; i++)
        {
            auxEmployee= (Employee*)ll_get(pArrayListEmployee, i);
            if(auxEmployee!=NULL)
            {
               allok =fwrite(&auxEmployee, sizeof(Employee), 1, pFile);
            }
        }
        fclose(pFile);
        printf("El archivo se grabo correctamente \n");
    }
    else
    {
        printf("La lista esta vacia. No se grabara nada \n");
    }

    return allok;
}

int controller_getIndex(LinkedList * pArrayListEmployee, int id)
{
    int index = -1;
    if(pArrayListEmployee == NULL || ll_isEmpty(pArrayListEmployee))    {
        return index;
    }
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
    return index;
}

int controller_getLastId(LinkedList * pArrayListEmployee)
{
    if(pArrayListEmployee == NULL || ll_isEmpty(pArrayListEmployee))
    {
        return -1;
    }
    int tam = ll_len(pArrayListEmployee);
    Employee *auxEmp;
    auxEmp = (Employee *) ll_get(pArrayListEmployee,tam - 1);
    return auxEmp ->id;
}

int controller_compararId(void * emp1,void * emp2)
{
    Employee * empa = (Employee *) emp1;
    Employee * empb = (Employee *) emp2;
    return empa->id - empb->id;
}
int controller_compararNombre(void * emp1,void * emp2)
{
    Employee * empa = (Employee *) emp1;
    Employee * empb = (Employee *) emp2;

    return strcmp( empa->nombre,empb->nombre);
}
int controller_compararSueldo(void * emp1,void * emp2)
{
    Employee * empa = (Employee *) emp1;
    Employee * empb = (Employee *) emp2;

    return empa->sueldo - empb->sueldo;
}
int controller_compararHorasTrabajadas(void * emp1,void * emp2)
{
    Employee * empa = (Employee *) emp1;
    Employee * empb = (Employee *) emp2;

    return empa->horasTrabajadas - empb->horasTrabajadas;
}
