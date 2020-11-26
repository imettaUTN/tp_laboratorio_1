/** \brief
  * Parsea los datos del archivo a la estructura Employee y lo agrega a la lista de empleados

 * \param pFile FILE* puntero al archivo
 * \param pArrayListEmployee LinkedList* lista
 * \return int error? si[1], no[0]
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);

/** \brief
  * Parsea los datos del archivo a la estructura Employee y lo agrega a la lista de empleados

 * \param pFile FILE* puntero al archivo
 * \param pArrayListEmployee LinkedList* lista
 * \return int error? si[1], no[0]
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);
