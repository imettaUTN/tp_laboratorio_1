#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "Common.h"
#define TRUE 1
#define FALSE 0


/****************************************************
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
*****************************************************/


int main()
{
    int option = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    option =common_getMenu("1 CARGA EMPLEADOS ARH TXT\n2 CARGA EMPLEADOS ARH BIN:\n3 ALTA EMPLEADO\n4 MODIFICA EMPLADO\n5 BAJA EMPLEADO\n6 LISTAR EMPLEADOS\n7 ORDENAR EMPLEADOS\n8 GRABAR EMPLEADOS ARH TXT\n9 GRABAR EMPLEADOS ARH BIN \n10SALIR","Opcion invalida. Reingrese",1,10,3);
    char * pathTxt = "C:\\Programacion1\\Archivos\\data.csv";
    char * pathBin = "C:\\Programacion1\\Archivos\\dataB.bin";
    int exit = FALSE;
    int cargueDatosPrimero = FALSE;
    do
    {
        switch(option)
        {
        case 1:
            if(controller_loadFromText(pathTxt,listaEmpleados))
            {
                printf("CARGA DE DATOS INVALIDA \n");
            }
            else {cargueDatosPrimero = TRUE;}
            break;
        case 2:
            if(controller_loadFromBinary(pathBin,listaEmpleados))
            {
                printf("CARGA DE DATOS INVALIDA \n");
            }
            else {cargueDatosPrimero = TRUE;}
            break;
        case 3:
            if(!controller_addEmployee(listaEmpleados))
            {
                printf("ERROR EN EL ALTA DEL EMPLEADO \n");
            }
            else {cargueDatosPrimero = TRUE;}
            break;
        case 4:
            if(!cargueDatosPrimero)
            {
                printf("Primero deber cargar datos para poder editar un empleado \n");
                break;
            }
            if(!controller_editEmployee(listaEmpleados))
            {
                printf("ERROR EDITANDO EMPLEADO \n");
            }
            break;
        case 5:
            if(!cargueDatosPrimero)
            {
                printf("Primero deber cargar datos para poder remover un empleado \n");
                break;
            }
            if(!controller_removeEmployee(listaEmpleados))
            {
                printf("ERROR REMOVIENDO EMPLEAOD \n");
            }
            break;
        case 6:
            if(!cargueDatosPrimero)
            {
                printf("Primero deber cargar datos para poder listar empleados \n");
                break;
            }
            if(!controller_ListEmployee(listaEmpleados))
            {
                printf("ERROR LISTANDO EMPLEADOS \n");
            }
            break;
        case 7:
            if(!cargueDatosPrimero)
            {
                printf("Primero deber cargar datos para poder ordenar la lista de empleados \n");
                break;
            }
            if(!controller_sortEmployee(listaEmpleados))
            {
                printf("ERROR ORDENANDO LISTA DE EMPLEADOS\n");
            }
            break;
        case 8:
            if(!cargueDatosPrimero)
            {
                printf("Primero deber cargar datos para poder grabar los empleados \n");
                break;
            }
            if(!controller_saveAsText(pathTxt,listaEmpleados))
            {
                printf("EROR AL GRABAR LISTA DE EMPLEADO EN FORMATO TEXTO\n");
            }
            break;
        case 9:
            if(!cargueDatosPrimero)
            {
                printf("Primero deber cargar datos para poder grabar los empleados \n");
                break;
            }
            if(!controller_saveAsBinary(pathBin,listaEmpleados))
            {
                printf("ERROR AL GRABAR LA LISTA DE EMPLEADO EN FORMATO BINARIO\n");
            }
            break;
        case 10:
            printf("El sistema se va a cerrar\n");
            exit = TRUE;
            break;
        }

        if(!exit)
        {
            printf("¿Desea continuar operador? YES 1 NOT 0\n");
            scanf("%d",&exit);
            exit = !exit;
            system("cls");
        }
        if(!exit)
        {
            option =common_getMenu("1 CARGA EMPLEADOS ARH TXT\n2 CARGA EMPLEADOS ARH BIN:\n3 ALTA EMPLEADO\n4 MODIFICA EMPLADO\n5 BAJA EMPLEADO\n6 LISTAR EMPLEADOS\n7 ORDENAR EMPLEADOS\n8 GRABAR EMPLEADOS ARH TXT\n9 GRABAR EMPLEADOS ARH BIN \n10SALIR","Opcion invalida. Reingrese",1,10,3);
        }

    }
    while(!exit && option != 10 );
    // libero la lista de memoria
    ll_deleteLinkedList(listaEmpleados);
    return 0;
}
