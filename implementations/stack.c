#include "../libraries/stack.h"

/* ----------------------------------------------------------- PILAS ------------------------------------------------------------ */
/**
 * @brief Función que inicializa una pila.
 * @param pila La pila a inicializar.
 */
Procedure inicializar_pila(Pila* pila)
{
    pila->cabeza = NULL;
    pila->tamanho = 0;
}

/**
 * @brief Función que apila un elemento a la pila.
 * @param pila La pila en la que se quiere apilar un elemento (nodo).
 * @param valor El valor que tendrá el nodo que se apilará a la pila.
 * @return true, si no hay errores al apilar y todo funciona correctamente, false en caso contrario.
 */
bool push(Pila* pila, ElemType valor)
{
    return insertar_nodo_circular_doble_final(pila, valor);
}

/**
 * @brief Función para desapilar un elemento de la pila, eliminándolo.
 * @param pila La pila en la que se quiere desapilar.
 */
Procedure pop(Pila* pila)
{
    eliminar_nodo_circular_doble_final(pila);  // Se elimina del mismo lugar del que se insertó (el final en este caso)
}

/**
 * @brief Función para retornar el elemento que está en la cima de la pila (el último de la lista circular doble).
 * @param pila La pila en la cual se quiere hacer esa operación.
 * @return El nodo de la cima de la pila (el último en ser apilado).
 */
NodoPila* top(Pila pila)
{
    if (pila.tamanho == 0)
    {
        return NULL;
    }

    return pila.cabeza->anterior;
}

/**
 * @brief Función para imprimir una pila.
 * @param pila La pila a imprimir.
 */
Procedure imprimir_pila(Pila pila)
{
    Pila inv;

    inicializar_pila(&inv);

    printf("-----------------------------------------------------\n");

    inv = invertir_pila(pila);

    if (es_pila_vacia(inv))
    {
        return;  // En caso de error
    }

    while (!es_pila_vacia(inv))
    {
        printf("| %d ", top(inv)->dato);
        pop(&inv);
    }
        
    printf("|\n");

    printf("-----------------------------------------------------\n");
}

/**
 * @brief Función que sirve para saber si una pila está vacía o no.
 * @param pila La pila de interés.
 * @return true si está vacía, false en caso contrario.
 */
bool es_pila_vacia(Pila pila)
{
    return pila.tamanho == 0;
}

/**
 * @brief Función para eliminar una pila, liberando todos sus nodos.
 * @param pila La pila a eliminar.
 */
Procedure eliminar_pila(Pila* pila)
{
    if (!pila)
    {
        printf("Error al eliminar: La pila no existe.\n");
        return;
    }

    while (!es_pila_vacia(*pila))
    {
        pop(pila);
    }
}

/**
 * @brief Función para hallar la pila invertida de una lista determinada.
 * @param pila La pila que se quiere invertir.
 * @return Una pila nueva, de tal modo que el elemento que estaba al fondo en la pila original (se colocó primero), ahora queda encima.
 */
Pila invertir_pila(Pila pila)
{
    Pila copia_pila = pila;
    Pila tmp;

    inicializar_pila(&tmp);

    while (!es_pila_vacia(copia_pila))
    {
        if (!push(&tmp, top(copia_pila)->dato))
        {
            return (Pila) {.tamanho = 0, .cabeza = NULL};  // A modo de retornar error en caso de falla.
        }

        printf("Tamaño pila: %hu\n", copia_pila.tamanho);
        pop(&copia_pila);
    }

    return tmp;
}

/**
 * @brief Función para clonar profundamente una pila.
 * @param pila La pila que se quiere clonar.
 * @return Una copia de la pila deseada.
 */
Pila clonar_pila(Pila pila)
{
    Pila pila_invertida;
    Pila copia;

    inicializar_pila(&pila_invertida);
    inicializar_pila(&copia);

    pila_invertida = invertir_pila(pila);

    while (!es_pila_vacia(pila_invertida))
    {
        push(&copia, top(pila_invertida)->dato);
        pop(&pila_invertida);
    }

    return copia;
}
/* ------------------------------------------------------------------------------------------------------------------------------ */
