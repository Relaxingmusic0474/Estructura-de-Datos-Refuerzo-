#include "../libraries/list.h"

/**
 * @brief Función que crea una lista vacía (con un único nodo y que apunta a NULL).
 * @param lista La lista que se quiere crear vacía.
 * @return true si se logró crear, false en caso contrario.
 */
bool crear_lista_vacia(Lista* lista)
{
    if (!lista)
    {
        printf("Error: Puntero inválido\n");
        return false;
    }

    if (lista->cabeza)  // Si la lista ya tenía cabeza, simplemente se vacía
    {
        vaciar_lista(lista);
        return true;
    }
    
    Nodo* nodo = (Nodo *) calloc(1, sizeof(Nodo));

    if (!nodo)
    {
        printf("Error de asignación de memoria.\n");
        return false;
    }

    nodo->dato = 0;
    nodo->siguiente = NULL;
    lista->cabeza = nodo;
    return true;
}

/**
 * @brief Función que crea una lista con cierto número de elementos (e inicializa en 0 todos sus nodos).
 * @param nro_elementos Nro de elementos que tendrá la lista.
 * @return true si se creó correctamente, false en caso contrario.
 */
bool crear_lista(Lista* lista, Natural nro_elementos)
{
    Natural i;

    if (!crear_lista_vacia(lista))
    {
        printf("Error: No se pudo crear la lista.  Ni siquiera la vacía.\n");
        return false;
    }

    for (i=0; i<nro_elementos; i++)
    {
        if (!insertar_nodo_inicio(lista, 0))
        {
            eliminar_lista(lista, false);  // Se eliminan los nodos, pero se deja el centinela en caso que haya un error al crear alguno de los nodos
            printf("Error: No se pudo crear la lista completa.  Solo se pudo crear la lista vacía.\n");
            return true;  // True, ya que el nodo centinela igual ocupa memoria.
        }
    }

    return true;
}

/** 
 * @brief Función que inserta un nodo en una cierta posición de la lista enlazada.
 * @param lista La lista en la cual se quiere insertar un elemento.
 * @param valor El valor del nodo que se quiere insertar.
 * @param posicion La posición deseada.
 * @return true si se pudo insertar exitosamente, false si ocurrió algún error en el proceso.
 */
bool insertar_nodo(Lista* lista, ElemType valor, Index posicion)
{
    if (!lista)
    {
        printf("Error: La lista no existe.\n");
        return false;
    }

    //printf("Holi\n");
    Nodo* nodo = calloc(1, sizeof(Nodo));

    if (!nodo)
    {
        printf("Error de asignación de memoria.\n");
        return false;
    }

    nodo->dato = valor;

    Nodo* actual = lista->cabeza->siguiente;
    Nodo* prev = lista->cabeza;

    Index posicion_actual = 0;

    while (posicion_actual < posicion)
    {
        if (actual)
        {
            actual = actual->siguiente;
        }

        if (prev)
        {
            prev = prev->siguiente;
        }

        if (!actual && !prev)
        {
            printf("Error: La lista tiene menos de %hu elementos, por lo que no se puede acceder al índice %hu.\n", posicion+1, posicion);
            return false;
        }

        posicion_actual++;
    }

    nodo->siguiente = actual;
    prev->siguiente = nodo;

    return true;
}

/**
 * @brief Función que inserta un nodo al inicio de una lista.
 * @param lista La lista a la cual se le quiere insertar un elemento al inicio.
 * @param valor Valor que tendrá el nodo que se inserte al inicio.
 * @return El valor de la función insertar_nodo con el parámetro posicion=0.
 */
bool insertar_nodo_inicio(Lista* lista, ElemType valor)
{
    return insertar_nodo(lista, valor, 0);
}

/**
 * @brief Función que inserta un nodo al final de una lista.
 * @param lista La lista a la cual se le quiere insertar un elemento al final.
 * @param valor Valor que tendrá el nodo que se inserte al final.
 * @return El valor de la función insertar_nodo con el parámetro posicion=tamanho_lista(lista).
 */
bool insertar_nodo_final(Lista* lista, ElemType valor)
{
    return insertar_nodo(lista, valor, tamanho_lista(*lista));
}

/**
 * @brief Función que modifica el valor de un nodo de una lista enlazada.
 * @param lista La lista enlazada que se quiere modificar.
 * @param posicion La posición secuencial del nodo que se quiere modificar (0, 1, 2, ...).
 * @param valor El valor nuevo que tendrá el nodo.
 */
Procedure modificar_nodo(Lista* lista, Index posicion, ElemType valor)
{
    if (esta_vacia(*lista))
    {
        printf("Holi\n");
        return;
    }

    Nodo* actual = lista->cabeza->siguiente;
    Nodo* sig = actual->siguiente;

    Index posicion_actual = 0;

    while (posicion_actual < posicion)
    {
        if (sig)
        {
            actual = sig;
            sig = actual->siguiente;
        }

        else
        {
            printf("Error: La lista tiene menos de %hu elementos, por lo que no se puede acceder al índice %hu.\n", posicion+1, posicion);
            return;
        }

        posicion_actual++;
    }

    actual->dato = valor;
}

/**
 * @brief Imprime los valores almacenados en los nodos de una lista enlazada.
 * @param lista La lista que se desea imprimir.
 */
Procedure imprimir_lista(Lista lista)
{
    Nodo* actual = lista.cabeza->siguiente;

    while (actual)
    {
        printf("%d -> ", actual->dato);
        actual = actual->siguiente;
    }

    printf("NULL\n");
}

/** 
 * @brief Función que devuelve el tamaño (nro de nodos de una lista).
 * @param lista La lista de la cual se quiere saber su tamaño.
 * @return El número de nodos que tiene la lista.
 */
Natural tamanho_lista(Lista lista)
{
    Nodo* actual = lista.cabeza->siguiente;
    Natural tamanho = 0;

    while (actual)
    {
        actual = actual->siguiente;
        tamanho++;
    }

    return tamanho;
}

/**
 * @brief Función que elimina un nodo de una lista enlazada.
 * @param lista La lista enlazada de la cual se quiere eliminar un nodo.
 * @param posicion La posición del nodo que se desea eliminar.
 */
Procedure eliminar_nodo(Lista* lista, Index posicion)
{
    Nodo* prev = lista->cabeza;
    Nodo* actual = lista->cabeza->siguiente;
    Index posicion_actual = 0;

    while (posicion_actual < posicion)
    {
        if (actual)
        {
            prev = prev->siguiente;
            actual = actual->siguiente;
        }

        else
        {
            printf("Error: No se pudo eliminar el nodo, ya que no existe un nodo en la posición %hu.\n", posicion);
            return;
        }

        posicion_actual++;
    }
    
    prev->siguiente = actual->siguiente;
    free(actual);
}

/**
 * @brief Función que elimina el primer nodo de una lista enlazada simple.
 * @param lista La lista a la cual se le quiere eliminar el primer nodo.
 */
Procedure eliminar_nodo_inicio(Lista* lista)
{
    eliminar_nodo(lista, 0);
}

/**
 * @brief Función que elimina el último nodo de una lista enlazada simple.
 * @param lista La lista a la cual se le quiere eliminar el último nodo.
 */
Procedure eliminar_nodo_final(Lista* lista)
{
    eliminar_nodo(lista, tamanho_lista(*lista)-1);
}

/**
 * @brief Función que elimina una lista, recorriendo nodo a nodo.
 * @param lista La lista que se quiere eliminar.
 * @param liberar Booleano que indica si se quiere eliminar completamente, liberando toda su memoria e incluso no pudiendo acceder más a ella, o si solo se quiere vaciar.
 */
Procedure eliminar_lista(Lista* lista, bool liberar)
{
    if (!lista)
    {
        return;
    }

    if (!lista->cabeza)
    {
        return;
    }

    Nodo* actual;
    Nodo* sig;

    if (liberar)  // Cuando se quiere eliminar completamente
    {
        actual = lista->cabeza;

        while (actual)
        {
            sig = actual->siguiente;
            free(actual);
            lista->cabeza = sig;
            actual = lista->cabeza;
        }

        lista->cabeza = NULL;
    }

    else  // Cuando se quiere dejar sin nodos pero no liberar completa, sino que dejarla como lista vacía solamente
    {
        actual = lista->cabeza->siguiente;

        while (actual)
        {
            sig = actual->siguiente;
            free(actual);
            actual = sig;
        }

        lista->cabeza->dato = 0;
        lista->cabeza->siguiente = NULL;
    }
}

/**
 * @brief Vacía una lista.
 * @param lista La lista que se vaciará.
 */
Procedure vaciar_lista(Lista* lista)
{
    eliminar_lista(lista, false);
}

/**
 * @brief Función para saber si una lista está vacía.
 * @param lista La lista a verificar.
 * @return true si está vacía, false en caso contrario.
 */
bool esta_vacia(Lista lista)
{
    return (lista.cabeza->siguiente == NULL);
}

/**
 * @brief Función que intercambia los valores de 2 nodos en cierta posición de la lista enlazada.
 * @param lista La lista.
 * @param posicion1 La posición de uno de los nodos involucrados en el intercambio.
 * @param posicion2 La posición del otro de los nodos involucrados en el intercambio.
 */
Procedure intercambiar_nodos(Lista* lista, Index posicion1, Index posicion2)
{
    Natural n = tamanho_lista(*lista);

    if (posicion1 >= n || posicion2 >= n)
    {
        printf("Error: Alguno(s) de los nodos que se quiere intercambiar, no está(n) en la lista.\n");
        return;
    }

    if (posicion1 == posicion2)
    {
        return;
    }

    Nodo* actual = lista->cabeza->siguiente;
    Nodo* nodo1, *nodo2;
    Index i = 0;
    ElemType x, y;

    while (i < min(posicion1, posicion2))
    {
        actual = actual->siguiente;
        i++;
    }

    x = actual->dato;
    nodo1 = actual;

    while (i < max(posicion1, posicion2))
    {
        actual = actual->siguiente;
        i++;
    }

    nodo2 = actual;
    y = actual->dato;

    nodo1->dato = y;
    nodo2->dato = x;

    return;
}

/**
 * @brief Función que invierte una lista.
 * @param lista Puntero a la lista que se quiere invertir.
 */
Procedure invertir_lista(Lista* lista)
{
    Natural i;
    Natural n = tamanho_lista(*lista);

    for (i=0; i<(n+1)/2; i++)
    {
        intercambiar_nodos(lista, i, (n-1)-i);
    }

    return;
}