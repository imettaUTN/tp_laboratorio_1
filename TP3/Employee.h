#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

/** \brief
 * Solicita memoria para un nuevo empleado
 * \return Employee* puntero a la posicion de memoria solicitada para el empleado
 *
 */
Employee* employee_new();
/** \brief
 * Solicita memoria para un nuevo empleado y carga los datos del mismo
 * \param idStr char* id del empleado
 * \param nombreStr char* nombre empleado
 * \param horasTrabajadasStr char* horas trabajadas
 * \param sueldo char* sueldo empleado
 * \return Employee* puntero al  empleado
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char * sueldo);


/** \brief
  * Solicita memoria para un nuevo empleado y carga los datos del mismo
 * \param id int id del empleado
 * \param nombre char* nombre del empleado
 * \param horasTrabajadas int horas trabajadas
 * \param sueldo int sueldo
 * \return Employee*  empleado
 *
 */
Employee* employee_newParametrosNonString(int id,char* nombre,int horasTrabajadas, int sueldo);

/** \brief
 * Muestra la informacion de un empleado
 * \param this Employee*  puntero al empleado a mostrar
 * \return int error? si[1], no[0]
 *
 */
int employee_showEmployee(Employee* this);
/** \brief
 * Libera la memoria del empleado
 * \param this Employee* puntero al empleado
 * \return void
 *
 */
void employee_delete(Employee* this);

/** \brief
 * Set empleado id validado
 * \param this Employee* puntero al empleado
 * \param id int id empleado
 * \return int error? si[1], no[0]
 *
 */
int employee_setId(Employee* this,int id);
/** \brief
 * Obtiene el id del empleado y lo aloja en la variable id
 * \param this Employee* empleado
 * \param id int* variable id pasada por referencia donde se alojara el mismo
 * \return int error? si[1], no[0]
 *
 */
int employee_getId(Employee* this,int* id);

/** \brief
 * Set del nombre del empleado
 * \param this Employee*  puntero al empleado
 * \param nombre char* nombre
 * \return int error? si[1], no[0]
 *
 */
int employee_setNombre(Employee* this,char* nombre);
/** \brief
 * Obtiene el nombre del empleado
 * \param this Employee* puntero al empleado
 * \param nombre char* variable donde se alojara el nombre del empleado
 * \return int error? si[1], no[0]
 *
 */
int employee_getNombre(Employee* this,char* nombre);

/** \brief
 * set horas trabajadas
 * \param this Employee* puntero al empleado
 * \param horasTrabajadas int horas trabajadas
 * \return int error? si[1], no[0]
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
/** \brief
 * Obtiene las horas trabajadas del empleado
 * \param this Employee* punteor al empleado
 * \param horasTrabajadas int* variable donde se alojara las horas trabajadas
 * \return int error? si[1], no[0]
 *
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

/** \brief
 * Set sueldo empleado
 * \param this Employee*  puntero al empleado
 * \param sueldo int sueldo empleado
 * \return int error? si[1], no[0]
 *
 */
int employee_setSueldo(Employee* this,int sueldo);

/** \brief
 * Get sueldo empleaod
 * \param this Employee* puntero al empleado
 * \param sueldo int* variable donde se alojara el sueldo
 * \return int error? si[1], no[0]
 *
 */
int employee_getSueldo(Employee* this,int* sueldo);

#endif // employee_H_INCLUDED
