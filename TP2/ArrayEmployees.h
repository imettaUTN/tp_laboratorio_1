#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED
#define MAXLENGHSTRING 51
struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}typedef Employee;

enum Errors{nullPointer = -1,invalidLengt = -2,employeeNotFound =-3,InvalidIndex = -4 , invalidStringLengt =-5, invalidStringFormat = -6,generalError = -7, invalidSalary = -8, invalidID = -9};

int salaryValidation(float salary);

int StringValidation(char * str);

int generalErrorValidation(int returnedValue);

int validateArray(Employee list[], int len);

int initEmployees(Employee list[], int len);

int addEmployee(Employee list[], int len, int id);

int findEmployeeById(Employee list[], int len,int id);

int findNextFreePosition(Employee list[], int len);

int removeEmployee(Employee list[], int len);

int modifyEmployeeInformation(Employee * emp);

int modifyEmployee(Employee  list[], int len);

int sortEmployees(Employee list[], int len, int order);

void makeSwap(Employee list[], int i, int j);

int printEmployees(Employee list[], int length);

int printEmployee(Employee  list[], int length ,int index);

int menu(int);

int subMenuOpc4();

int order();

float calculateTotalSalary(Employee list[], int length);

float calculateAverageSalary(Employee list[], int length);

int amountOfEmployeesUpsAvg(Employee list[], int lenght , float  salaryAvg);
#endif // ARRAYEMPLOYEES_H_INCLUDED
