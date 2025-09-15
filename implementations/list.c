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