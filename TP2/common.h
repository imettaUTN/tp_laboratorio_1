#define MAXLENGHSTRING 51

/** \brief  general errors enumaration
 */
enum Errors{nullPointer = -1,invalidLengt = -2,employeeNotFound =-3,InvalidIndex = -4 , invalidStringLengt =-5, invalidStringFormat = -6,generalError = -7, invalidSalary = -8, invalidID = -9, withOutFreeSpace = -10, isNotNumber= -11, almostMustBe2Emp =-12};
enum orderCriterion{DOWN = 0, UP = 1};


void validarOpcionesMenu(int *opcion, int hasValueOp, char * msj);

int common_getMenu(char * menssager ,char * errorMenssager ,int min , int max , int reintentos);

int common_getInt(int * pResultado, char * menssager);

int common_getFloat(float * pResultado, char * menssager);

int get_index(char* string, char c);

int esNumero(char *s);

/** \brief
 *  validate salary
 * \param salary float
 * \return int
 *
 */
int salaryValidation(float salary);

/** \brief
 * validate a number
 * \param number int
 * \return int
 *
 */
int idValidation(int number);

/** \brief
 * validate string
 * \param str char*
 * \return int
 *
 */
int stringValidation(char str[]);

/** \brief
 * general validation of  a function
 * \param value int retuned value to validate
 * \return int
 * TRUE / FALSE
 */
int isValidReturnedFunctionValue(int returnedValue);