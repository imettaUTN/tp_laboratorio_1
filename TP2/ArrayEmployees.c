#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "ArrayEmployees.h"



/** \brief
 *  validate salary
 * \param salary float
 * \return int
 *
 */
int salaryValidation(float salary)
{
    if(salary < 0)
    {
        return invalidSalary;
    }
    return 1;
}

/** \brief
 * validate a number
 * \param number int
 * \return int
 *
 */
int numberValidation(int number)
{
    if(number < 0)
    {
        return invalidID;
    }
    return 1;
}

/** \brief
 * validate string
 * \param str char*
 * \return int
 *
 */
int StringValidation(char * str)
{
    if(strlen(str) >= MAXLENGHSTRING)
    {
        int i = 0;
        while (str[i] != '\0')
        {
            // Si no es del alfabeto y no es un espacio regresamos false o 0
            if (!isalpha(str[i]) )// El espacio no cuenta como válido
            {
                return invalidStringFormat ;
            }
            i++;
        }
    }
    else
    {
        return invalidStringLengt;
    }
    // Si terminamos de recorrer la cadena y no encontramos errores, regresamos 1
    return 1;
}
/** \brief
 * general validation of  a function
 * \param value int retuned value to validate
 * \return int
 * TRUE 1, FALSE 0
 */
int generalErrorValidation(int value)
{
    switch(value)
    {
        case nullPointer:
            printf("NULL POINTER \n");
            return 0;
            break;
        case invalidLengt:
            printf("INVALID LENGHT \n");
            return 0;
            break;
        case employeeNotFound:
            printf("EMPLOYEE NOT FOUND \n");
            return 0;
            break;
        case InvalidIndex:
            printf("INVALID INDEX \n");
            return 0;
            break;
        case generalError:
            printf("ERROR, RETRAY \n");
            return 0;
            break;
        case invalidSalary:
            printf("Salary invalid \n");
            return 0;
            break;
        case invalidID:
            printf("Invalid ID");
            return 0;
            break;
        default:
            return 1;
            break;
    }

}

/** \brief validate an array
 *
 * \param list[] Employee
 * \param len int
 * \return 0 not valid, 1 valid
 *
 */
int validateArray(Employee list[], int len)
{
    if(list == NULL || len <0)
    {
        return 0;
    }
    return 1;
}

/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param Employee list[] Pointer to array of employees
* \param len int Array length
* \return int Return (0) if Error [Invalid length or NULL pointer] - (1) if Ok
*
*/
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
        isOk =0;
    }

    return isOk;
}

/** \brief Find next free index in the array
 *
 * \param list[] Employee
 * \param len int
 * \return 1 ok, 0 error
 *
 */
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
                index = i ;
                break;
            }
        }
        if(index <0)
        {
            printf(" without free space");
            isOk = 0;
        }

    }
    return isOk;

}


/** \brief
 *  ADD an exployee
 * \param list[] Employee
 * \param len int
 * \param id int
 * \return int
 * TRUE / FALSE
 */
int addEmployee(Employee list[], int len, int id)
{
    int isOk = validateArray(list,len);
    if(isOk)
    {
        char * name = "";
        char * lastName = "";
        float salary;
        int sector;
        int first =1;
        do
        {
            if(!first)
            {
                printf("Error , re-enter");
            }
            first= 0;
            printf("Enter Name \n");
            fflush(stdin);
            gets(name);
        } while(generalErrorValidation(StringValidation(name)));


        do
        {
            if(!first)
            {
                printf("Error , re-enter");
            }
            first= 0;
            printf("Enter Last Name \n");
            fflush(stdin);
            gets(lastName);
        } while(generalErrorValidation(StringValidation(lastName)));

        do
        {
            if(!first)
            {
                printf("Error , re-enter");
            }
            first= 0;
            printf("Enter Salary \n");
            scanf("%f",&salary);
        } while(generalErrorValidation(salaryValidation(salary)));

        printf("Enter Sector \n");
        scanf("%d", &sector);

        int index = findNextFreePosition(list,len);
        if(index >= 0)
        {
            Employee emp ;
            emp.id = id;
            strcpy(emp.name,name);
            strcpy(emp.name,lastName);
            emp.salary = salary;
            emp.sector = sector;
            emp.isEmpty =0;
            list[index] = emp;
        }
        else
        {
            //return error code;
            return index;
        }
    }
    return isOk;
}

/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param Employee list[]
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
 *
 */
int findEmployeeById(Employee list[], int len,int id)
{
    int index = -1;

    for(int i = 0; i < len ; i++)
    {

        if(list[i].id == id)
        {
            index = i;
            break;
        }
    }
    if(index < 0)
    {
        printf("employee not found \n");
        return employeeNotFound;
    }
    return index;
}


/** \brief
 * Remove an exployee
 * \param list[] Employee
 * \param len int
 * \param id int
 * \return int
 * TRUE / FALSE
 */
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
        } while( generalErrorValidation(numberValidation(idToDelete)));

        system("cls");
        index = findEmployeeById(list,len,idToDelete);
        printf("Employee to delete :\n");
        printEmployee(list,len,index);

        do{
            printf("¿Are you sure, you want to delete this employeed id: YES 1 , NOT 0 %d ?", idToDelete);
            scanf("%d",&confirm);
        }while(confirm > 1 || confirm <0);

        if(confirm)
        {
            list[index].isEmpty = 1;
            printf("Employee deleted");
        }
    }
    return isOk;
}

/** \brief
 * Remove an exployee
 * \param list[] Employee
 * \param len int
 * \param id int
 * \return int
 * TRUE / FALSE
 */
int modifyEmployee(Employee  list[], int len)
{
    int isOk = validateArray(list,len);
    int idToModify = -1;
    int index;
    int confirm;
    int first = 1;
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
            printf("Select the employee ID to modify");
            scanf("%d", &idToModify);
        } while( generalErrorValidation(numberValidation(idToModify)));
        // no valido el index porque ya e
        index = findEmployeeById(list,len,idToModify);
        if(index == employeeNotFound)
        {
            return employeeNotFound;
        }
        system("cls");
        printf("Employee to modify :\n");
        printEmployee(list,len,index);
        do{
            printf("¿Are you sure you want to modify this employeed id: YES 1 , NOT 0 %d ?", idToModify);
            scanf("%d",&confirm);
        }while(confirm > 1 || confirm <0);

        if(confirm)
        {
            // change de employee to modify
           return modifyEmployeeInformation(&list[index]);
        }
    }
    return isOk;
}

/** \brief
 * Modify an employee information
 * \param emp employee*
 * \return int
 *
 */
int modifyEmployeeInformation(Employee * emp)
{
  char * name = "";
  char * lastName = "";
  int first = 1;
  float salary;
  int confirm;
  int sector;

  do
  {
    printf("Do you want to change the name?");
    scanf("%d",&confirm);
  }while(confirm > 1 || confirm <0);

  if(confirm)
  {
      do
      {
        if(!first)
        {
            printf("Error , re-enter");
        }
        first= 0;
        printf("Enter Name \n");
        fflush(stdin);
        gets(name);
      } while(generalErrorValidation(StringValidation(name)));
   }

  do
  {
      printf("Do you want to change the last name?");
      scanf("%d",&confirm);
  }while(confirm > 1 || confirm <0);

  if(confirm)
  {
      do
      {
        if(!first)
        {
            printf("Error , re-enter");
        }
        first= 0;
        printf("Enter Last Name \n");
        fflush(stdin);
        gets(lastName);
      } while(generalErrorValidation(StringValidation(lastName)));
  }

  do
  {
    printf("Do you want to change the salary?");
    scanf("%d",&confirm);
  }while(confirm > 1 || confirm <0);

  if(confirm)
  {
      do
      {
        if(!first)
        {
            printf("Error , re-enter");
        }
        first= 0;
       printf("Enter Salary \n");
       scanf("%f",&salary);
      } while(generalErrorValidation(salaryValidation(salary)));
  }

  do
  {
    printf("Do you want to change the sector?");
    scanf("%d",&confirm);
  }while(confirm > 1 || confirm <0);

  if(confirm)
  {
    printf("Enter Sector \n");
    scanf("%d", &sector);
  }

  printf("Employee modifed");
  return 1;
}

/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
*
* \param Employee list[]
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortEmployees(Employee  list[], int len, int order)
{
    int isOk = validateArray(list,len);

    if(isOk)
    {
        for(int i =0; i < len ; i++)
        {
            for(int j = 1+1; j <len; i++)
            {
                //up
                if(order == 1)
                {
                    if(strcmp(list[j].name,list[i]. name) > 0 || (strcmp(list[j].name,list[i].name) == 0 && strcmp(list[j].lastName,list[i]. lastName) >0) )
                    {
                        makeSwap(list,i,j);
                    }
                }
                else
                {
                    //down
                    if(strcmp(list[j].name,list[i]. name) < 0 || (strcmp(list[j].name,list[i].name) == 0 && strcmp(list[j].lastName,list[i]. lastName) <0) )
                    {
                        makeSwap(list,i,j);
                    }
                }
            }
        }
    }
    return isOk;
}

/** \brief
 * Make a swap in a array
 * \param list[] Employee
 * \param i int
 * \param j int
 * \return void
 *
 */
void makeSwap(Employee  list[], int i, int j)
{
    Employee auxEmp;
    auxEmp = list[j];
    list[j] = list[i];
    list[i] = auxEmp;
}
/** \brief print the content of employees array
*
* \param Employee list[]
* \param length int
* \return int
*
*/
int printEmployees(Employee  list[], int length)
{
    int isOk = validateArray(list,length);
    for(int i =0; i < length ; i++)
    {
        if(! list[i].isEmpty )
        {
            printEmployee(list,length,i);
        }
    }
    return isOk;
}


/** \brief
 * Print an employee
 * \param list[] Employee
 * \param length int
 * \param index int
 * \return int
 *
 */
int printEmployee(Employee  list[], int length ,int index)
{
    //VUELVO A VALIDAR X LAS DUDAS
    int isOk = validateArray(list, length);
    if(index < 0)
    {
        return InvalidIndex;
    }
    printf("Name %s \n", list[index].name);
    printf("last Name  %s \n", list[index].lastName);
    printf("salary %f \n", list[index].salary);
    printf("sector %f \n", list[index].sector);
    return isOk;
}


/** \brief
 *
 * \param list[] Employee
 * \param length int
 * \return float
 *
 */
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

/** \brief
 *
 * \param list[] Employee
 * \param length int
 * \return float
 *
 */
float calculateAverageSalary(Employee list[], int length)
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
        {   count++;
            salary += list[i].salary;
        }
    }
    return (float) salary / count;
}

/** \brief
 *  amount of employee whose salaries are up average.
 * \param list[] Employee
 * \param lenght int
 * \param salaryAvg float
 * \return int
 *
 */
int amountOfEmployeesUpsAvg(Employee list[], int lenght , float  salaryAvg)
{
    int isOK = validateArray(list,lenght);
    int count = 0;
    if(! isOK)
    {
        return isOK;
    }

    for(int i = 0; i< lenght; i++)
    {
        if(!list[i].isEmpty && list[i].salary > salaryAvg)
        {
            count++;
        }
    }
    return count;
}

/** \brief
 *  show menu options
 * \param hasValueOp1 int to indicate if opt. 1 has been selected.
 * \return int menu option
 *
 */
int menu(int hasValueOp1)
{
    int opcion  = 0;
    int first = 1;
    do
    {
        if(!first)
        {
            printf("Opcion invalida. Reingrese la operacion a realizar :\n");

        }
        else
        {
            printf("Ingrese la operacion a realizar :\n");

        }
        first = 0;
        printf("1. ALTA");

        if(hasValueOp1)
        {
            printf("2. MODIFICAR \n");
            printf("3. BAJA \n");
            printf("4. INFORMAR: \n");
            scanf("%d", &opcion);
        }
    }while(opcion < 0 || opcion > 4);
    return opcion;
}

/** \brief show the sub menu options of option 4
 *
 * \return int menu sub option of option 4
 *
 */
int subMenuOpc4()
{
    int opcion = 0 ;
    int first = 1;
    do
    {
        if(!first)
        {
            printf("Input error value. :\n");

        }
        else
        {
            printf("Ingrese la operacion a realizar :\n");
            printf("1. Listado de los empleados ordenados alfabeticamente por Apellido y Sector\n");
            printf("2. Total y promedio de los salarios, y cúantos empleados superan el salario promedio\n");

        }
        first = 0;

        scanf("%d", &opcion);
    }while(opcion < 1 || opcion > 2);

    return opcion;
}

/** \brief  show de order options
 *
 * \return int order option
 *
 */
int order()
{
    int opcion = 0 ;
    int first = 1;
    do
    {
        if(!first)
        {
            printf("Input error value. :\n");

        }
        else
        {
            printf("Enter the order to list the employees:\n");
            printf("0. Down\n");
            printf("1. UP\n");
        }
        first = 0;
        scanf("%d", &opcion);
    }while(opcion < 0 || opcion > 1);

    return opcion;
}
