#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED
struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}typedef Employee;


/** \brief validate an array
 *
 * \param list[] Employee
 * \param len int lenght
 * \return int  is valid TRUE / FALSE
 *
 */
int validateArray(Employee list[], int len);

/** \brief
 * int list
 * \param list[] Employee
 * \param len int lenght
 * \return int is valid TRUE / FALSE
 *
 */
int initEmployees(Employee list[], int len);

/** \brief
 * add employee to list
 * \param list[] Employee
 * \param len int lenght
 * \param id int
 * \return int all ok TRUE / FALSE
 *
 */
int addEmployee(Employee list[], int len, int id);

/** \brief
 * fin an employee by id
 * \param list[] Employee
 * \param len int lenght
 * \param id int
 * \return int all ok TRUE / FALSE
 *
 */
int findEmployeeById(Employee list[], int len,int id);

/** \brief
 *fin next free position
 * \param list[] Employee
 * \param len int lenght
 * \return int all ok TRUE / FALSE
 *
 */
int findNextFreePosition(Employee list[], int len);

/** \brief
 * remove an employee of list
 * \param list[] Employee
 * \param len int lenght
 * \return int free index on array list
 *
 */
int removeEmployee(Employee list[], int len);

/** \brief
 * modify employes
 * \param list[] Employee
 * \param len int lenght
 * \return int all ok TRUE / FALSE
 *
 */
int modifyEmployee(Employee  list[], int len);

/** \brief
 * modify an employe infromation
 * \param emp Employee*
 * \return int all ok TRUE / FALSE
 *
 */
int modifyEmployeeInformation(Employee * emp);

/** \brief
 * sort an employeed
 * \param list[] Employee
 * \param len int lenght
 * \param order int criterio
 * \return int TRUE / FALSE
 *
 */
/** \brief
 * sort employee by criterial
 * \param list[] Employee
 * \param len int lenght
 * \param order int criterio
 * \return int all ok TRUE / FALSE
 *
 */
int sortEmployees(Employee list[], int len, int order);

/** \brief
 * make swap in array
 * \param list[] Employee
 * \param i int
 * \param j int
 * \return void
 *
 */
void makeSwap(Employee list[], int i, int j);

/** \brief
 * print employees information
 * \param list[] Employee
 * \param length int
 * \return int
 *
 */
int printEmployees(Employee list[], int length);

/** \brief
 *print an employee information
 * \param list[] Employee
 * \param length int
 * \param index int
 * \return int
 *
 */
int printEmployee(Employee  list[], int length ,int index);

/** \brief
 * calculare total salaries
 * \param list[] Employee
 * \param length int
 * \return float total salary
 *
 */
float calculateTotalSalary(Employee list[], int length);

/** \brief
 * calculare average of salaries
 * \param list[] Employee
 * \param length int
 * \return float average salaries
 *
 */
float calculateAverageSalaries(Employee list[], int length);

/** \brief
 * calculate de count of employees salaries up average
 * \param list[] Employee
 * \param lenght int
 * \param salaryAvg float
 * \return int count employees up avg
 *
 */
int amountOfEmployeesUpsAvg(Employee list[], int lenght , float  salaryAvg);
#endif // ARRAYEMPLOYEES_H_INCLUDED
