/** \brief
 * Carga empleados del archivo de texto de empleados
 * \param path char* path de la ubicacon del archivo
 * \param pArrayListEmployee LinkedList* lista empleados
  * \return int resultado de la operacion true ok, false error
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
/** \brief
 * Carga empleados del archivo binario de empleados
 * \param path char* path de la ubicacion del archivo
 * \param pArrayListEmployee LinkedList* lista empleados
 * \return int resultado de la operacion true ok, false error
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
/** \brief
 * Agrega un empleado a lista de empleados
 * \param pArrayListEmployee LinkedList* lista empleados
  * \return int resultado de la operacion true ok, false error
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee);
/** \brief
 * Modifica la informacion de un empleado
 * \param pArrayListEmployee LinkedList* lista empleados
 * \return int resultado de la operacion true ok, false error
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee);
/** \brief
 * Elimina un empleado de la lista
 * \param pArrayListEmployee LinkedList* lista
 * \return int resultado de la operacion true ok, false error
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee);
/** \brief
 * Lista los empleados de la lista
 * \param pArrayListEmployee LinkedList* lista de empleados
 * \return int resultado de la operacion true ok, false error
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee);
/** \brief
 * Ordena una lista s/ un criterio indicado por el usuario
 * \param pArrayListEmployee LinkedList* lista
 * \return int resultado de la operacion true ok, false error
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee);
/** \brief
 * Graba la lista en un archivo de texto
 * \param path char* path del archivo a grabar
 * \param pArrayListEmployee LinkedList* lista
 * \return int resultado de la operacion true ok, false error
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
/** \brief
 *  Graba la lista en un archivo binario
 * \param path char* path del archivo a grabar
 * \param pArrayListEmployee LinkedList* lista
 * \return int resultado de la operacion true ok, false error
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);
/** \brief
 * Obtiene el index de un id en la lista
 * \param pArrayListEmployee LinkedList* lista
 * \param id int id a buscar
 * \return int index en la lista, -1 sino se encuentra
 *
 */
int controller_getIndex(LinkedList * pArrayListEmployee, int id);
/** \brief
* Compara dos estructuras e indica si son mayores, menores o iguales s/ el id
 * \param emp1 void* puntero a la estructura 1
 * \param emp2 void* puntero a la estructura 2
 * \return int 0 iguales, 1 si primero mayor a segundo, -1 sino
 *
 */
int controller_compararId(void * emp1,void * emp2);
int controller_compararNombre(void * emp1,void * emp2);
/** \brief
* Compara dos estructuras e indica si son mayores, menores o iguales s/ el sueldo
 * \param emp1 void* puntero a la estructura 1
 * \param emp2 void* puntero a la estructura 2
 * \return int 0 iguales, 1 si primero mayor a segundo, -1 sino
 *
 */
int controller_compararSueldo(void * emp1,void * emp2);
/** \brief
* Compara dos estructuras e indica si son mayores, menores o iguales s/ el horas trabajadas
 * \param emp1 void* puntero a la estructura 1
 * \param emp2 void* puntero a la estructura 2
 * \return int 0 iguales, 1 si primero mayor a segundo, -1 sino
 *
 */
int controller_compararHorasTrabajadas(void * emp1,void * emp2);

/** \brief
 * Obtiene el ultimo id cargado en la lista
 * \param pArrayListEmployee LinkedList*
 * \return int ultimo id cargado, -1 si lista vacia
 *
 */
int controller_getLastId(LinkedList * pArrayListEmployee);
