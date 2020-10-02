#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "menus.h"
#include "common.h"
#define TRUE 1
#define FALSE 0

int validateArray(Employee list[], int len)
{
    if(list == NULL || len <0)
    {
        return FALSE;
    }
    return TRUE;
}

int initEmployees(Employee list[], int len)
{
    int isOk = validateArray(list,len);
    if(isOk)
    {
        for(int i = 0 ; i < len ; i++)
        {
            list[i].isEmpty = 1;
        }
        //all ok
        isOk =TRUE;
    }

    return isOk;
}

int findNextFreePosition(Employee list[], int len)
{
    int isOk = validateArray(list,len);
    int index =  -1;
    if(isOk)
    {
        for(int i=0; i < len ; i++)
        {
            if(list[i].isEmpty)
            {
                return  i ;
            }
        }
        if(index <0)
        {
             return withOutFreeSpace;
        }

    }
    // solo viene aca si hubo un error de prevalidacion
    return isOk;

}

int addEmployee(Employee list[], int len, int id)
{
    int isOk = validateArray(list,len);
    if(isOk)
    {
        char  name[MAXLENGHSTRING];
        char  lastName[MAXLENGHSTRING];
        float salary;
        int sector;
        int first =TRUE;
        do
        {
            if(!first)
            {
                printf("Error , re-enter");
            }
            first= FALSE;
            printf("Enter Name \n");
            fflush(stdin);
            gets(name);

        }
        while(!isValidReturnedFunctionValue(stringValidation(name)));

        first= TRUE;
        do
        {
            if(!first)
            {
                printf("Error , re-enter");
            }
            first= FALSE;
            printf("Enter Last Name \n");
            fflush(stdin);
            gets(lastName);
        }
        while(!isValidReturnedFunctionValue(stringValidation(lastName)));

        first= TRUE;

        do
        {
            if(!first)
            {
                printf("Error , re-enter");
            }
            first= FALSE;
            printf("Enter Salary \n");
            scanf("%f",&salary);
        }
        while(!isValidReturnedFunctionValue(salaryValidation(salary)));

        printf("Enter Sector \n");
        scanf("%d", &sector);

        int index = findNextFreePosition(list,len);
        if(index >= 0)
        {
            Employee emp ;
            emp.id = id;
            strcpy(emp.name,name);
            strcpy(emp.lastName,lastName);
            emp.salary = salary;
            emp.sector = sector;
            emp.isEmpty =FALSE;
            list[index] = emp;
        }
        else
        {
            //return error code;
            return index;
        }
        printf("Alta exitosa del empleado:  \n");
        printEmployee(list,len,index);
    }
    return isOk;
}

void mostrarVector(Employee list[], int len)
{
    for(int i = 0; i< len ; i++)
    {
        printf("Empleado nombre : %s , apellido: %s, salary: %.2f ,sector: %d, empaty: %d \n", list[i].name, list[i].lastName, list[i].salary, list[i].sector, list[i].isEmpty);
    }
}

int findEmployeeById(Employee list[], int len,int id)
{
    int index = -1;

    for(int i = 0; i < len ; i++)
    {
        printf("id parametro %d , id emp %d", id, list[i].id);
        if(list[i].id == id)
        {
            index = i;
            break;
        }
    }
    if(index < 0)
    {
        return employeeNotFound;
    }
    return index;
}

int removeEmployee(Employee  list[], int len)
{
    int isOk = validateArray(list,len);
    int idToDelete = -1;
    int index;
    int first =1;
    int confirm;
    if( isOk)
    {
        //show all employees to select which employee will delete
        printEmployees(list,len);

        do
        {
            if(!first)
            {
                printf("Input error. Re enter");
            }
            first= 0;
            printf("Select the employee ID to delete");
            scanf("%d", &idToDelete);
        }
        while( !isValidReturnedFunctionValue(idValidation(idToDelete)));

        system("cls");
        index = findEmployeeById(list,len,idToDelete);
        printf("Employee to delete :\n");
        printEmployee(list,len,index);

        do
        {
            printf("¿Are you sure, you want to delete this employeed id: %d YES 1 , NOT 0?\n", idToDelete);
            scanf("%d",&confirm);
        }
        while(confirm != TRUE && confirm != FALSE);

        if(confirm)
        {
            list[index].isEmpty = 1;
            printf("Employee deleted \n");
            return TRUE;
        }
    }
    mostrarVector(list,len);
    return isOk;
}

int modifyEmployee(Employee  list[], int len)
{
    int isOk = validateArray(list,len);
    int idToModify = -1;
    int index;
    int confirm;
    int first = TRUE;
    if( isOk)
    {
        //show all employees to select which employee will delete
        printEmployees(list,len);

        do
        {
            if(!first)
            {
                printf("Error re -enter");
            }
            first =0;
            printf("Select the employee ID to modify \n");
            scanf("%d", &idToModify);
        }
        while(! isValidReturnedFunctionValue(idValidation(idToModify)));
        // no valido el index porque ya e
        index = findEmployeeById(list,len,idToModify);
        if(index == employeeNotFound)
        {
            return employeeNotFound;
        }
        system("cls");
        printf("Employee to modify :\n");
        printEmployee(list,len,index);
        do
        {
            printf("¿Are you sure you want to modify this employeed id:%d  YES 1 , NOT 0 ?", idToModify);
            scanf("%d",&confirm);
        }
        while(confirm != FALSE && confirm != TRUE);

        if(confirm)
        {
            // change de employee to modify
            modifyEmployeeInformation(&list[index]);
            printf("Employee modify :\n");
            printEmployee(list,len,index);
            return TRUE;
        }
    }
    return isOk;
}

int modifyEmployeeInformation(Employee * emp)
{
    char name[MAXLENGHSTRING];
    char lastName[MAXLENGHSTRING];
    int first = TRUE;
    float salary;
    int sector;
    int opc ;

    opc = subMenuModify();
    switch(opc)
    {
    case 1:
        do
        {
            if(!first)
            {
                printf("Error , re-enter");
            }
            first= FALSE;
            printf("Enter Name \n");
            fflush(stdin);
            gets(name);
            strcpy(emp->name,name);
        }
        while(!isValidReturnedFunctionValue(stringValidation(name)));
        break;
    case 2:
        do
        {
            if(!first)
            {
                printf("Error , re-enter");
            }
            first= FALSE;
            printf("Enter Last Name \n");
            fflush(stdin);
            gets(lastName);
            strcpy(emp->lastName,lastName);
        }
        while(!isValidReturnedFunctionValue(stringValidation(lastName)));
        break;

    case 3:
        do
        {
            if(!first)
            {
                printf("Error , re-enter");
            }
            first= FALSE;
            printf("Enter Salary \n");
            scanf("%f",&salary);
            emp->salary = salary;
        }
        while(!isValidReturnedFunctionValue(salaryValidation(salary)));
        break;
    case 4:
        printf("Enter Sector \n");
        scanf("%d", &sector);
        emp->sector = sector;
        break;
    }

    return TRUE;
}

int numberOfEmployeesLoaded(Employee  list[], int lenght)
{
    int isOK = validateArray(list,lenght);
    int count = 0;
    if(! isOK)
    {
        return isOK;
    }

    for(int i = 0; i< lenght; i++)
    {
        if((!list[i].isEmpty))
        {
            count++;
        }
    }
    return count;
}

int sortEmployees(Employee  list[], int len, int orderCriter)
{
    int isOk = validateArray(list,len);

    if(numberOfEmployeesLoaded(list,len))
    {

    }
    if(isOk)
    {
        for(int i =0; i < len ; i++)
        {
            if(!list[i].isEmpty)
            {
                for(int j = i+1; j <len; j++)
                {
                    if(!list[j].isEmpty)
                    {
                        //DOWN
                        if(orderCriter == DOWN)
                        {
                            if(strcmp(list[j].name,list[i]. name) < 0 || (strcmp(list[j].name,list[i].name) == 0 && strcmp(list[j].lastName,list[i].lastName) <0) )
                            {
                                makeSwap(list,i,j);
                            }

                        }
                        else if(orderCriter == UP)
                        {
                           if(strcmp(list[j].name,list[i].name) > 0 || (strcmp(list[j].name,list[i].name) == 0 && strcmp(list[j].lastName,list[i].lastName) >0) )
                            {
                                makeSwap(list,i,j);
                            }
                        }
                    }
                }
            }
        }
        printf("Sorted Employees\n");
    }
    return isOk;
}

void makeSwap(Employee  list[], int i, int j)
{
    Employee auxEmp;
    auxEmp = list[j];
    list[j] = list[i];
    list[i] = auxEmp;
}

int printEmployees(Employee  list[], int length)
{
    int isOk = validateArray(list,length);
    printf("List of employees :\n");
    for(int i =0; i < length ; i++)
    {
        if(! list[i].isEmpty )
        {
            printEmployee(list,length,i);
        }
    }
    return isOk;
}

int printEmployee(Employee  list[], int length,int index)
{
    //VUELVO A VALIDAR X LAS DUDAS
    int isOk = validateArray(list, length);
    if(index < 0)
    {
        return InvalidIndex;
    }
    printf("id\tname\tlastName\tsalary\tsector \n");
    printf("%d\t%s\t%s\t%.2f\t\t%d\t\n",list[index].id, list[index].name,list[index].lastName,list[index].salary,list[index].sector);
    return isOk;
}

float calculateTotalSalary(Employee list[], int length)
{
    float salary = 0;
    int isOK = validateArray(list,length);
    if(! isOK)
    {
        return isOK;
    }

    for(int i = 0 ; i < length ; i++)
    {
        if(!list[i].isEmpty)
        {
            salary += list[i].salary;
        }
    }
    return salary;
}

float calculateAverageSalaries(Employee list[], int length)
{
    float salary = 0;
    int count = 0;
    int isOK = validateArray(list,length);
    if(! isOK)
    {
        return isOK;
    }

    for(int i = 0 ; i < length ; i++)
    {
        if(!list[i].isEmpty)
        {
            count++;
            salary += list[i].salary;
        }
    }
    return  salary / count;
}

int amountOfEmployeesUpsAvg(Employee list[], int lenght, float  salaryAvg)
{
    int isOK = validateArray(list,lenght);
    int count = 0;
    if(! isOK)
    {
        return isOK;
    }

    for(int i = 0; i< lenght; i++)
    {
        if((!list[i].isEmpty) && list[i].salary >= salaryAvg)
        {
            count++;
        }
    }
    return count;
}
