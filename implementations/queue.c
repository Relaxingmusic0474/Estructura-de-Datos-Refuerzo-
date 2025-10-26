#include "../libraries/queue.h"

/* ----------------------------------------------------------- COLAS ------------------------------------------------------------ */
/**
 * @brief Función que inicializa una cola.
 * @param cola Cola a inicializar.
 */
Procedure inicializar_cola(Cola* cola) 
{
    cola->cabeza = NULL;
    cola->tamanho = 0;
}

/**
 * @brief Función que encola un elemento a la cola.
 * @param cola La cola en la que se añadirá un elemento en espera.
 * @param valor El valor que tendrá el elemento que se agregará.
 * @return true si el elemento se encola correctamente, false en caso contrario.
 */
bool enqueue(Cola* cola, ElemType valor) 
{
    return insertar_nodo_circular_doble_final(cola, valor);
}

/**
 * @brief Función que descola un elemento de alguna cola existente.
 * @param cola La cola en la cual se descolará un elemento.
 */
Procedure dequeue(Cola* cola) 
{
    eliminar_nodo_circular_doble_inicio(cola);
}

/**
 * @brief Función que devuelve el puntero al nodo del elemento que está al inicio de la cola.
 * @param cola La cola de la cual se quiere saber el nodo front.
 * @return El nodo front de la cola.
 */
NodoCola* front(Cola cola) 
{
    return cola.cabeza;
}

/**
 * @brief Función que devuelve el puntero al nodo del elemento que está último en la cola.
 * @param cola La cola de la cual se quiere saber el nodo rear.
 * @return El nodo rear de la cola.
 */
NodoCola* rear(Cola cola) 
{
    return cola.cabeza->anterior;
}

/**
 * @brief Función que imprime una cola (siguiendo filosofía de la cola).
 * @param cola La cola a imprimir.
 */
Procedure imprimir_cola(Cola* cola) 
{
    if (es_cola_vacia(*cola))
    {
        printf("-------------------------------------------------------------------------------\n");
        printf("(Cola vacía)                                                                   \n");
        printf("-------------------------------------------------------------------------------\n\n");
        return;
    }

    Cola cola_tmp;

    inicializar_cola(&cola_tmp);

    printf("---------------------------------------------------------------------------------\n");
    
    while (!es_cola_vacia(*cola))
    {
        ElemType X = front(*cola)->dato;
        printf(" %d |", X);
        dequeue(cola);
        enqueue(&cola_tmp, X);
    }

    printf("\n--------------------------------------------------------------------------------\n");

    printf("Front");

    if (cola_tmp.tamanho == 1)
    {
        printf("\n\n");
    }

    else
    {
        printf(" ");

        for (Natural i=0; i<cola_tmp.tamanho-2; i++)
        {
            printf("     ");
        }

        printf("Rear\n\n");
    }

    while (!es_cola_vacia(cola_tmp))
    {
        ElemType X = front(cola_tmp)->dato;
        dequeue(&cola_tmp);
        enqueue(cola, X);
    }
}

/**
 * @brief Función que determina si una cola está vacía o no.
 * @param cola La cola que se quiere determinar si está vacía o no.
 * @return true si está vacía, false en caso contrario.
 */
bool es_cola_vacia(Cola cola) 
{
    return cola.cabeza == NULL;

}

/**
 * @brief Función que elimina una cola.
 * @param cola La cola a eliminar.
 */
Procedure eliminar_cola(Cola* cola) 
{
    if (!cola)
    {
        printf("Error: La cola no existe.\n");
        return;
    }

    if (!cola->cabeza)  
    {
        return;  // Si está vacía no hace nada
    }

    NodoDobleCircular* nodo = cola->cabeza;
    NodoDobleCircular* temp;

    while (nodo != cola->cabeza->anterior)
    {
        temp = nodo->siguiente;
        cola->cabeza->anterior->siguiente = temp;
        temp->anterior = cola->cabeza->anterior;
        cola->cabeza = temp;
        free(nodo);
        nodo = temp;
    }

    free(cola->cabeza->anterior);
    cola->tamanho = 0;

}

/**
 * @brief Vacía una cola para comenzar a colocarle elementos.
 * @param cola La cola a vaciar.
 */
Procedure vaciar_cola(Cola* cola)
{
    eliminar_cola(cola);
    inicializar_cola(cola);
}
/* ------------------------------------------------------------------------------------------------------------------------------ */