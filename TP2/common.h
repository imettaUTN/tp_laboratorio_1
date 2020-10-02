#define MAXLENGHSTRING 51

/** \brief  general errors enumaration
 */
enum Errors{nullPointer = -1,invalidLengt = -2,employeeNotFound =-3,InvalidIndex = -4 , invalidStringLengt =-5, invalidStringFormat = -6,generalError = -7, invalidSalary = -8, invalidID = -9, withOutFreeSpace = -10, isNotNumber= -11, almostMustBe2Emp =-12};
/** \brief  order criterial enum
 */
enum orderCriterion{DOWN = 0, UP = 1};


/** \brief
 * Valid main menu
 * \param opcion int* option to valid
 * \param hasValueOp int indicate if opc 1 was active
 * \param msj char* menssager to display
 * \return void
 *
 */
void common_validarOpcionesMenu(int *opcion, int hasValueOp, char * msj);

/** \brief
 * Get main menu
 * \param menssager char* messager to display
 * \param errorMenssager char* error messager to display
 * \param min int min value
 * \param max int max value
 * \param reintentos int amout of opportunities
 * \return int
 *
 */
int common_getMenu(char * menssager ,char * errorMenssager ,int min , int max , int reintentos);

/** \brief
 * valid if an input is a integer
 * \param pResultado int* result int
 * \param menssager char* messager to display
 * \return int TRUE / FALSE
 *
 */
int common_getInt(int * pResultado, char * menssager);


/** \brief
 * valid if an input is a float
 * \param pResultado float* result float
 * \param menssager char* messager to display
 * \return int TRUE / FALSE
 *
 */
int common_getFloat(float * pResultado, char * menssager);

/** \brief
 * get the index of char in a string
 * \param string char*
 * \param c char
 * \return int index
 *
 */
int common_get_index(char* string, char c);

/** \brief
 * Indicate if a char * is number
 * \param s char* string to validate
 * \return int TRUE / FALSE
 *
 */
int common_esNumero(char *s);

/** \brief
 *  validate salary
 * \param salary float
 * \return int TRUE / FALSE
 *
 */
int common_salaryValidation(float salary);

/** \brief
 * validate a number
 * \param number int
 * \return int TRUE / FALSE
 *
 */
int common_idValidation(int number);

/** \brief
 * validate string
 * \param str char*
 * \return int TRUE / FALSE
 */
int common_stringValidation(char str[]);

/** \brief
 * general validation of  a function
 * \param value int retuned value to validate
 * \return int
 * TRUE / FALSE
 */
int common_isValidReturnedFunctionValue(int returnedValue);
