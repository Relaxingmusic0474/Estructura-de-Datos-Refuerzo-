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
NodoPila* top(Pila* pila)
{
    return nodo_circular_doble_k_esimo(*pila, (pila->tamanho)-1);
}
/* ------------------------------------------------------------------------------------------------------------------------------ */







