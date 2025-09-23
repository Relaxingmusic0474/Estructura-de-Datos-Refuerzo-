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
Procedure imprimir_pila(Pila* pila)
{
    Lista lista = {0};
    ElemType valor_a_insertar;

    crear_lista_vacia(&lista);

    while (!es_pila_vacia(*pila))
    {
        valor_a_insertar = top(*pila)->dato;
        pop(pila);
        insertar_nodo_inicio(&lista, valor_a_insertar);
    }
    
    printf("-----------------------------------------------------\n");
    
    while (!esta_vacia(lista))
    {
        valor_a_insertar = nodo_k_esimo(lista, 0)->dato;
        
        printf("| %d ", valor_a_insertar);
        push(pila, valor_a_insertar);
        eliminar_nodo_inicio(&lista);
    }

    eliminar_lista(&lista, true);
        
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
/* ------------------------------------------------------------------------------------------------------------------------------ */
