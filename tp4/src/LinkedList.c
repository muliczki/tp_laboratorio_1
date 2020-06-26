#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"

Node* newNode (void);
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
    LinkedList* this= NULL;

    this= (LinkedList*) malloc(sizeof(LinkedList));
    if (this!=NULL)
    {
    	this->pFirstNode=NULL;
    	this->size=0;
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

    if(this!=NULL)
    {
    	returnAux= this->size;
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
	int i;
	Node* unNodo=NULL;

	if(this!=NULL && nodeIndex>=0 && nodeIndex<ll_len(this))
	{
		for(i=0; i<=nodeIndex; i++)
		{
			if(i==0)
			{
				unNodo=this->pFirstNode; //posicion 0
			}else{
				unNodo=unNodo->pNextNode;
			}

			if(nodeIndex==i)
			{
				break;
			}
		}

	}

    return unNodo;
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



Node* newNode (void)
{
	Node* newNode=NULL;
	newNode= (Node*) malloc(sizeof(Node));

	if(newNode!=NULL)
	{
		newNode->pNextNode=NULL;
		newNode->pElement=NULL;
	}

	return newNode;
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
	int* len=NULL;
	Node* nodoAnterior=NULL;
	Node* auxNodo=NULL;
	Node* nuevoNodo=NULL;

    if(this!=NULL)
    {

    	if(nodeIndex!=0)
    	{
    	nodoAnterior= getNode(this, nodeIndex-1);
		auxNodo = nodoAnterior->pNextNode;
		nuevoNodo= newNode();
			if(nuevoNodo!=NULL)
			{
				nodoAnterior->pNextNode=nuevoNodo;
				nuevoNodo->pElement=pElement;
				nuevoNodo->pNextNode=auxNodo;
				returnAux=0;
			}
    	}


    	if(nodeIndex==0)
    	{
    	auxNodo= getNode(this,nodeIndex);
   		nuevoNodo= newNode();
    	    if(nuevoNodo!=NULL)
    	    {
    	    	this->pFirstNode=nuevoNodo;
    	    	nuevoNodo->pElement=pElement;
    	    	nuevoNodo->pNextNode=auxNodo;
    	    	returnAux=0;

    		}
    	}


    	if(returnAux==0)
    	{
			len=&(this->size);
			*len=(*len)+1;
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
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int indiceVacio;

    if(this!=NULL)
       {
    	indiceVacio=ll_len(this);
    	returnAux = addNode(this, indiceVacio, pElement );
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
    Node* auxNodo;

	if(this!=NULL && index>=0 && index<ll_len(this))
	{
		auxNodo = getNode(this, index);
		returnAux = (void*) auxNodo->pElement;
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
    Node* auxNodo;

    if(this!=NULL && index>=0 && index<ll_len(this))
    {
    	auxNodo = getNode(this, index);
		auxNodo->pElement= pElement;
		returnAux=0;
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
    int* len;
    Node* anteriorNodo;
    Node* borrarNodo;

    if(this!=NULL && index>=0 && index<ll_len(this))
    {
    	if(index==0)
    	{
    		borrarNodo=getNode(this, index);
   			this->pFirstNode = borrarNodo->pNextNode;
   			returnAux=0;

    	}else{
    		anteriorNodo=getNode(this, index-1);
			borrarNodo=getNode(this, index);
			anteriorNodo->pNextNode = borrarNodo->pNextNode;
			returnAux=0;
   		}

       	if(returnAux==0)
       	{
       		len=&(this->size);
       		*len=(*len)-1;
       	}

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
    int i;

    if(this!=NULL)
    {
    	for(i=0; i<ll_len(this); i++)
    	{
    		ll_remove(this, i);
    	}

    	returnAux=0;
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

    if(this!=NULL)
        {
    	 free(this);
    	 returnAux=0;
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
    int returnAux = -1;
	int i;
    void* auxElemento;

    if(this!=NULL)
    {
    	for(i=0; i<ll_len(this); i++)
    	{
    		auxElemento= ll_get(this, i);

    		if(auxElemento == pElement)
    			{
    				returnAux=i;
    				break;
    			}
      	}
    }

    return returnAux;
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

    if(this!=NULL)
    {
    	if(ll_len(this)==0)
    	{
    		returnAux=1;
    	}else
    	{
    		returnAux=0;
    	}
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
    int returnAux = -1;

    if(this!=NULL && index>=0 && index<=ll_len(this))
    {
   		returnAux = addNode(this, index, pElement);
    }

    return returnAux;
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
    void* returnAux = NULL;

    if(this!=NULL && index>=0 && index<ll_len(this))
       	{
          	returnAux =ll_get(this, index);//guardo el nodo a eliminar en un auxiliar

          	ll_remove(this, index);
       	}

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
    int i;
    void* auxElemento;

    if(this!=NULL)
    {
    	returnAux=0;

       for(i=0; i<ll_len(this); i++)
       {

        auxElemento=ll_get(this, i);

			if(auxElemento == pElement)
			{
				returnAux=1;
				break;
			}
       	}
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
    int i;
    void* auxElemento;

    if(this!=NULL && this2!=NULL)
       {
   		returnAux=0;

    	for(i=0; i<ll_len(this2); i++)
    	{
    		if(i==0 || returnAux==1 )
    		{
    		auxElemento = ll_get(this2, i);
    		returnAux=ll_contains(this,auxElemento);
    		}else{
    			break;
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
	int i;
	void* auxElemento;
    LinkedList* cloneArray = NULL;

    if(this!=NULL && from>=0 && from<=ll_len(this) && to>from && to<=ll_len(this))
    	{
    		cloneArray = ll_newLinkedList();
    		if(cloneArray!=NULL)
    		{
    			for(i=from; i<to; i++)
    			{
    				auxElemento= ll_get(this, i);
    				ll_add(cloneArray, auxElemento);
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
    LinkedList* cloneArray = NULL;

    if(this!=NULL)
       {
       	cloneArray = ll_subList(this, 0, ll_len(this));

       }

    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;
    int i;
    int j;
    int condicion;
    void* pElementoi;
    void* pElementoj;
    void* auxElemento=NULL;

    if(this!=NULL && pFunc!=NULL && (order==1 || order==0))
    {

    	for(i=0;i<ll_len(this)-1;i++)
    	{

     		for(j=i+1;j<ll_len(this);j++)
    	    {
     			pElementoi= ll_get(this, i);
     			pElementoj= ll_get(this, j);

    			condicion=pFunc(pElementoi, pElementoj);
    	  		// condicion=1 >> mayor el 1
     			// condicion=-1 >> menor el 1
       			// condicion=0 >> iguales
       			// ORDER=1 >> ASCENDENTE    >>> ORDENA CUANDO ES MAYOR EL 1 >> COND=1
       			// ORDER=0 >> DESCENDENTE	>>> ORDENA CUANDO ES MENOR EL 1 >> COND=-1

       			if((condicion==-1 && order==0) || (condicion==1 && order==1))
     			{
       				//auxElemento= ll_get(this, i);
       				auxElemento= pElementoi;
    	    		ll_set(this,i,pElementoj);
    				ll_set(this,j,auxElemento);
    	    	}
    	    }
    	}

    	returnAux=0;
    }

    return returnAux;

}

