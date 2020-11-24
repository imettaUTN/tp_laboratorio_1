#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this= (LinkedList *) malloc(sizeof(LinkedList));
    if(this != NULL)
    {
        this ->pFirstNode = NULL;
        this -> size = 0;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
        return this ->size;
    }
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node * pNode = NULL;
    int index = 0;
    if(this != NULL && nodeIndex >=0 && nodeIndex <= ll_len(this) )
    {
        // recorro todos los nodos hasta la posicion que estoy buscando
        for(pNode = this -> pFirstNode; index < nodeIndex ; index ++)
        {
            pNode =pNode ->pNextNode;
        }
    }
    return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node * nuevoNode = NULL;
    if(this != NULL && nodeIndex >=0 && nodeIndex <= ll_len(this) )
    {
        nuevoNode = (Node *) malloc(sizeof(Node));
        if(nuevoNode != NULL)
        {
            nuevoNode ->pElement = pElement;
            if(nodeIndex == 0)
            {
                nuevoNode->pNextNode = this->pFirstNode;
                this -> pFirstNode = nuevoNode;
            }
            else
            {
                nuevoNode ->pNextNode = getNode(this,nodeIndex);
                (getNode(this, nodeIndex -1))->pNextNode  = nuevoNode ;
            }
            this ->size ++;
            returnAux = 0;
        }
    }

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
//Agrego al final de la fila
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    if(this != NULL)
    {
        returnAux = addNode(this,ll_len(this),pElement);
    }

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node * pNodo = NULL;

    if(this != NULL && index >=0 && index < ll_len(this))
    {
        pNodo = getNode(this,index);

        if(pNodo != NULL)
        {
            returnAux = pNodo->pElement;
        }
    }

    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node * pNodo = NULL;

    if(this != NULL && index >=0 && index < ll_len(this))
    {
//        if(index == ll_len(this))
//        {
//            returnAux = ll_add(this,pElement);
//        }
        pNodo = getNode(this,index);

        if(pNodo != NULL)
        {
            pNodo->pElement= pElement;
            //todo ok
            returnAux =0;
        }
    }

    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node * pNodoToRemove = NULL;
    Node * pNodoAnterior = NULL;
    if(this != NULL && index >=0 && index < ll_len(this) && !ll_isEmpty(this))
    {

        if(index == 0)
        {
            pNodoToRemove = this-> pFirstNode;
            this -> pFirstNode = pNodoToRemove ->pNextNode;
        }
        else
        {

            pNodoAnterior = getNode(this, index -1);
            pNodoToRemove = pNodoAnterior ->pNextNode;

            if(pNodoAnterior != NULL)
            {
                pNodoAnterior->pNextNode  = pNodoToRemove ->pNextNode ;
            }
        }
        this ->size --;
        free(pNodoToRemove);
        returnAux = 0;
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL )
    {

        // recorro todos los nodos hasta la posicion que estoy buscando
        while(ll_len(this) >0)
        {
            //siempre borro el primer elemento
            ll_remove(this,0);
        }
        returnAux = 0;
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL )
    {
        ll_clear(this);
        free(this);
        returnAux = 0;
    }
    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int retunindex = -1;
    int index = 0;

    Node * pNode = NULL;
    if(this != NULL )
    {
        // arranco en la pos 0 a recorrer la lista
        for(pNode = this -> pFirstNode; index < ll_len(this) ; index ++)
        {
            if(pNode->pElement == pElement)
            {
                retunindex = index;
                break;
            }
            else
            {
                //sigo iterando
                pNode =pNode ->pNextNode;
            }

        }
    }
    return retunindex;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
        returnAux = ll_len(this) == 0 ?1:0;
    }

    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    // las validaciones ya estan echas en el addNode
    return addNode(this,index,pElement);
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux =  ll_get(this,index);
    ll_remove(this,index);
    return returnAux;
}



/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    if(this != NULL )
    {
        returnAux = (ll_indexOf(this,pElement) >=0);
    }

    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    Node * pNode = NULL;
    int index = 0;
    if(this != NULL && this2 != NULL )
    {
        returnAux = 1;
        // recorro todos los nodos de lista 2
        for(pNode = this2 -> pFirstNode; index < ll_len(this2) ; index ++)
        {
            // algun elemento de la lista 2 no esta en la lista 1, devuelvo 0
            if(!ll_contains(this,pNode->pElement))
            {
                return 0;
            }
            else
            {
                pNode =pNode ->pNextNode;
            }
        }
    }
    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    Node * pNode = NULL;
    if(this != NULL && from >=0 && from <= ll_len(this) && to > from  && to <=ll_len(this) )
    {
        cloneArray = ll_newLinkedList();
        if(cloneArray != NULL)
        {
            for(int i = from; i < to ; i++)
            {
                pNode = getNode(this,i);
                if(pNode != NULL)
                {
                    ll_add(cloneArray,pNode->pElement);
                }
            }
        }
    }

    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    return  ll_subList(this,0,ll_len(this));
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void*,void*), int order)
{
    int returnAux =-1;
    void * elemA = NULL;
    void * elemB = NULL;
    void * elemAux = NULL;

    if(this != NULL && pFunc != NULL && (order ==0 || order ==1))
    {
        for(int i =0 ; i < ll_len(this) ; i++)
        {
            for(int j=i+1; j <ll_len(this); j++)
            {
                elemA = ll_get(this,i);
                elemB = ll_get(this,j);

                if((order ==1 && pFunc(elemA,elemB)>0) || (order ==0 && pFunc(elemA,elemB)<0))
                {
                    elemAux = elemA;
                    ll_set(this,i,elemB);
                    ll_set(this,j,elemAux);
                }
            }
        }
        returnAux = 0;

    }
    return returnAux;

}

/** \brief
 * Filtra los elementos de la lista
 * \param lista a filtrar
 * \param funcion que sabe filtrar el elemento, devuelve 1 si la lista debe incluir el elemento o 0 sino
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista filtrada) Si ok
 *
 */
LinkedList* ll_filter(LinkedList* this, int (*pFuncFilter)(void*))
{
    void * elemA = NULL;
    LinkedList* filterArray = NULL;
    if(this != NULL && pFuncFilter != NULL)
    {
        filterArray = ll_newLinkedList();
        if(filterArray != NULL)
        {
            for(int i = 0; i < ll_len(this) ; i++)
            {
                elemA = ll_get(this,i);
                if(pFuncFilter(elemA))
                {
                    ll_add(filterArray,elemA);
                }
            }
        }
    }
    return filterArray;
}
