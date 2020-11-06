#ifndef COMMON_H_INCLUDED
#define COMMON_H_INCLUDED

int common_get_index(char* string, char c);
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
 * Indicate if a char * is number
 * \param s char* string to validate
 * \return int TRUE / FALSE
 *
 */
int common_esNumero(char *s);

#endif // COMMON_H_INCLUDED
