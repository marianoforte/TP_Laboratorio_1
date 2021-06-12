#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

LinkedList* ll_newLinkedList(void){
    LinkedList* this;
    this = (LinkedList*)calloc(1, sizeof(LinkedList));
    return this;
}

int ll_len(LinkedList* this){
    int returnAux = -1;

    if(this != NULL){
    	returnAux = this->size;
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
static Node* getNode(LinkedList* this, int nodeIndex){
	Node* pNode = NULL;

	if(this != NULL && nodeIndex >= 0 && nodeIndex < ll_len(this)){
		pNode = this->pFirstNode;
		for(int i=0; i<nodeIndex; i++){
			pNode = pNode->pNextNode;
		}
	}
	return pNode;
}

Node* test_getNode(LinkedList* this, int nodeIndex){
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
static int addNode(LinkedList* this, int nodeIndex,void* pElement){
	int returnAux = -1;
	Node* prev;
	Node* next;
	Node* new;

	prev = getNode(this, nodeIndex-1);
	next = getNode(this, nodeIndex); // A next se le asigna el nodo que contiene el indice que recibe la funcion

	if(this != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this)){
		new = (Node*)malloc(sizeof(Node));
		if(new != NULL){
			if(nodeIndex == 0){
				this->pFirstNode = new;
				new->pNextNode = next;
			}
			else{
				new->pNextNode = next;
				prev->pNextNode  = new;
			}
			new->pElement = pElement;
			this->size++;
			returnAux = 0;
		}
	}
	return returnAux;
}

int test_addNode(LinkedList* this, int nodeIndex,void* pElement){
    return addNode(this,nodeIndex,pElement);
}

int ll_add(LinkedList* this, void* pElement){
    int returnAux = -1;

    if(this!= NULL){
        if(!addNode(this, ll_len(this), pElement)){
            returnAux = 0;
        }
    }
    return returnAux;
}

void* ll_get(LinkedList* this, int index){
	void* returnAux = NULL;
	Node* auxNode;

	if(this != NULL && index>=0 && index<ll_len(this)){
		auxNode = getNode(this, index);
		if(auxNode != NULL){
			returnAux = auxNode->pElement;
		}
	}
	return returnAux;
}

int ll_set(LinkedList* this, int index,void* pElement){
	int returnAux = -1;
	Node* actual;

	if(this != NULL && index >= 0 && index < ll_len(this)){
		actual = getNode(this, index);
		if(actual != NULL){
			actual->pElement = pElement;
			returnAux = 0;
		}
	}
	return returnAux;
}

int ll_remove(LinkedList* this,int index){
    int returnAux = -1;
    Node* current;
    Node* previous;

    if(this != NULL && index >= 0){
        for(int i=0;i<ll_len(this);i++){
            current = getNode(this,i);
            if(i == index){
                if(index == 0){
                    this->pFirstNode = current->pNextNode;
                }
                else{
                    previous->pNextNode = current->pNextNode;
                }
                free(current);
                returnAux = 0;
                this->size--;
                break;
            }
            previous = current;
        }
    }
    return returnAux;
}

int ll_clear(LinkedList* this){
	int returnAux = -1;

	if(this != NULL){
		for(int i=0;i<ll_len(this);i++){
			ll_remove(this, 0);
		}
		returnAux = 0;
	}
	return returnAux;
}

int ll_deleteLinkedList(LinkedList* this){
	int returnAux = -1;

	if(this != NULL){
		ll_clear(this);
		free(this);
		returnAux = 0;
	}
	return returnAux;
}

int ll_indexOf(LinkedList* this, void* pElement){
	int returnAux = -1;
	Node* current;

	if(this != NULL){
		for(int i=0;i<ll_len(this);i++){
			current = getNode(this, i);
			if(current->pElement == pElement){
				returnAux = i;
				break;
			}
		}
	}
	return returnAux;
}

int ll_isEmpty(LinkedList* this){
	int returnAux = -1;

	if(this != NULL){
		if(ll_len(this) == 0){
			returnAux = 1;
		}
		else{
			returnAux = 0;
		}
	}
	return returnAux;
}

int ll_push(LinkedList* this, int index, void* pElement){
	int returnAux = -1;

	if(this != NULL){
		if(!addNode(this, index, pElement)){
			returnAux = 0;
		}
	}
	return returnAux;
}

void* ll_pop(LinkedList* this,int index){
	void* returnAux = NULL;

	if(this != NULL){
		returnAux = ll_get(this, index);
		ll_remove(this, index);
	}
	return returnAux;
}

int ll_contains(LinkedList* this, void* pElement){
	int returnAux = -1;

	if(this != NULL){
		returnAux = 0;
		if(ll_indexOf(this, pElement) != -1){
			returnAux = 1;
		}
	}
	return returnAux;
}

int ll_containsAll(LinkedList* this,LinkedList* this2){
	int returnAux = -1;
	Node* current;
	if(this != NULL && this2 != NULL){
		returnAux = 1;
		for(int i=0;i<ll_len(this2);i++){
			current = getNode(this2, i);
			if(ll_contains(this, current->pElement)){
				continue;
			}
			else{
				returnAux = 0;
				break;
			}
		}
	}
	return returnAux;
}

LinkedList* ll_subList(LinkedList* this,int from,int to){
	LinkedList* cloneArray = NULL;
	int len = ll_len(this);
	void* pElement;

	if(this != NULL && from >= 0 && to <= len){
		cloneArray = ll_newLinkedList();
		if(cloneArray != NULL){
			for(int i = from; i < to; i++){
				pElement = ll_get(this, i);
				ll_add(cloneArray, pElement);
			}
		}
	}
	return cloneArray;
}

LinkedList* ll_clone(LinkedList* this){
	LinkedList* cloneArray = NULL;
	if(this != NULL){
		cloneArray = ll_subList(this, 0, ll_len(this));
	}

	return cloneArray;
}

int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order){
	int returnAux = -1;
	int len, i, j;
	void* pAux;
	void* e1;
	void* e2;

	if(this != NULL && pFunc != NULL && (order == 0 || order == 1)){
		len = ll_len(this);
		for(i = 0; i < len-1; i++){
			for(j = i+1; j < len; j++){
				e1 = ll_get(this, i);
				e2 = ll_get(this, j);
				if(order == 0 && pFunc(e1, e2) == -1){ //[0] Indica orden descendente. en comprareBy, si e1>e2, return 1
					pAux = e1;
					ll_set(this, i, e2);
					ll_set(this, j, pAux);
				}
				if(order == 1 && pFunc(e1, e2) == 1){ //[1] Indica orden ascendente. en comprareBy, si e1<e2, return -1
					pAux = e1;
					ll_set(this, i, e2);
					ll_set(this, j, pAux);
				}
			}
		}
		returnAux = 0;
	}
	return returnAux;
}

