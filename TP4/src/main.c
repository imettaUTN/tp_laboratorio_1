/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"


typedef struct
{
    int id;
    char nombre[20];
    char sexo;
} eCliente;

void mostrarCliente(eCliente * clientes)
{
    printf("%d  %s  %c\n",clientes->id,clientes->nombre,clientes->sexo);
}
void mostrarClientes(LinkedList * list)
{
    if(list != NULL)
    {
        for(int i =0; i < ll_len(list) ; i++)
        {
            mostrarCliente(ll_get(list,i));
        }
    }
}

int compararPorId(void * cli1, void * cli2)
{
    eCliente * empa = (eCliente *) cli1;
    eCliente * empb = (eCliente *) cli2;
    return empa->id - empb->id;

}
int filtrarMasculino(void * cli)
{
    int rsta = 0;
    eCliente * c = NULL;
    if(cli != NULL)
    {
        c = (eCliente *) cli;
        if(c ->sexo == 'm')
        {
            rsta = 1;
        }
    }
    return rsta;
}

int main(void)
{
//        startTesting(1);  // ll_newLinkedList
//        startTesting(2);  // ll_len
//        startTesting(3);  // getNode - test_getNode
//        startTesting(4);  // addNode - test_addNode
//        startTesting(5);  // ll_add
//        startTesting(6);  // ll_get
//        startTesting(7);  // ll_set
//        startTesting(8);  // ll_remove
//        startTesting(9);  // ll_clear
//        startTesting(10); // ll_deleteLinkedList
//        startTesting(11); // ll_indexOf
//        startTesting(12); // ll_isEmpty
//        startTesting(13); // ll_push
//        startTesting(14); // ll_pop
//        startTesting(15); // ll_contains
//        startTesting(16); // ll_containsAll
//        startTesting(17); // ll_subList
//        startTesting(18); // ll_clone
//        startTesting(19); // ll_sort


    LinkedList * hombres = ll_newLinkedList();
    eCliente cli1 = {1,"cliente 1",'m'};
    eCliente cli2 = {5,"cliente 2",'f'};
    eCliente cli3 = {3,"cliente 3",'m'};
    eCliente cli4 = {2,"cliente 4",'f'};
    eCliente cli5 = {4,"cliente 5",'m'};


// creo una lista
    LinkedList* list = ll_newLinkedList() ;

//agrego un nodo
    if(test_addNode(list,0,&cli1)== 0)
    {
        printf("ADD NODE CORRECTO \n");
    }

    if(ll_deleteLinkedList(list) == 0)
    {
        printf("Delete list ok \n");
    }

    list = ll_newLinkedList() ;

//agrego un nodo
    test_addNode(list,0,&cli1);

//pregunto por el tamaño
    if(ll_len(list) == 1)
    {
        printf("LEN CORRECTO \n");
    }

// verifico si el conntenido del nodo obtenido es correcto
    eCliente *auxEmp = (eCliente *)(test_getNode(list,0)->pElement);

    if((auxEmp->id) ==1)
    {
        printf("Get Node correcto \n");
    }

//agrego un elemento a la lista
    ll_add(list,&cli2);
    if(ll_len(list) == 2)
    {
        printf("ADD  CORRECTO \n");
    }

//obtengo el contenido del primer nodo de la lista
    eCliente *auxEmp2 = (eCliente *) (ll_get(list,0));
    if(auxEmp2->id == 1)
    {
        printf("LL get correcto \n");
    }

    if(ll_set(list,0,&cli3) == 0)
    {
        printf("ll set correcto \n");
    }

    ll_remove(list,0);

    if(ll_len(list) == 1)
    {
        printf("ll remove correcto \n");
    }

    ll_clear(list);

    if(ll_len(list) == 0)
    {
        printf("ll clear correcto \n");
    }
    ll_add(list,&cli1);

    if(!ll_isEmpty(list))
    {
        printf("ll is empty correcto \n");
    }

    if(ll_indexOf(list,&cli1) >=0)
    {
        printf("ll index of correcto \n");
    }

    int lenAnterior = ll_len(list);
    ll_push(list,0,&cli4);

    if(lenAnterior < ll_len(list))
    {
        printf("ll push correcto \n");
    }
    auxEmp2 = (eCliente *) ll_pop(list,0);

    if(auxEmp2->id == cli4.id)
    {
        printf("ll pop correcto \n");

    }
    if(ll_contains(list,&cli1)>0)
    {
        printf("ll contains correcto \n");

    }

    ll_clear(hombres);
    ll_add(hombres,&cli1);
    ll_add(hombres,&cli2);
    ll_add(hombres,&cli3);
    ll_add(hombres,&cli4);
    ll_add(hombres,&cli5);


    if(ll_containsAll(hombres,list)>=0)
    {
        printf("ll contains all correcto \n");

    }

    LinkedList * list2 = NULL;
    list2 = ll_subList(hombres,0,2);
    if(list2 != NULL)
    {
        if(ll_len(list2) >=0)
        {
            printf("ll sublist  correcto \n");

        }
    }
    ll_clear(list2);
    list2 = ll_clone(hombres);

    if(list2 != NULL)
    {
        if(ll_len(list2) == ll_len(hombres))
        {
            printf("ll clone  correcto \n");

        }
    }


    ll_sort(hombres,compararPorId,1);
    mostrarClientes(hombres);
    printf("ll sort correcto \n");

    LinkedList * list3 = NULL;
    list3 = ll_filter(hombres,filtrarMasculino);
    if(list3 != NULL)
    {
        printf("\n\n");
        mostrarClientes(list3);
        printf("Filter correcto \n");
    }

    free(list);
    free(list2);
    free(list3);
    free(hombres);
    return 0;
}

































