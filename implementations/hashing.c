#include "../libraries/hashing.h"

/**
 * @brief Función para inicializar una tabla hash.
 * @param tabla La tabla hash a inicializar.
 * @return true si se pudo inicializar correctamente, false en caso contrario.
 */
bool inicializar_tabla_hash(TablaHash tabla) 
{
    Natural j;

    for (Natural i=0; i<TAMANHO_TABLA_HASH; i++)
    {
        inicializar_lista(&tabla[i]);
        
        if (!crear_lista_vacia(&tabla[i]))
        {
            printf("Error: No se pudo inicializar la tabla hash.\n");

            for (j=0; j<i; j++)
            {
                eliminar_lista(&tabla[j], true);
            }

            return false;
        }
    }

    return true;
}

/**
 * @brief Función para insertar un dato o valor en una tabla hash.
 * @param tabla La tabla hash en la cual se quiere insertar un dato.
 * @param dato El dato que se quiere añadir a la tabla.
 * @return true si se pudo añadir correctamente, false en caso de error.
 */
bool insertar_dato_tabla_hash(TablaHash tabla, ElemType dato) 
{
    if (buscar_dato_tabla_hash(tabla, dato) != -1)
    {
        printf("Error: El dato que se intenta insertar ya está en la tabla hash.\n");
        return false;
    }

    Index posicion = FUNCION_HASH(dato);  // Se le aplica la función hash al dato que se quiere agregar a la tabla.
    return insertar_nodo_inicio(&tabla[posicion], dato);  // Se inserta el dato (se eligió al inicio para mayor eficiencia computacional).
}

/**
 * @brief Función para buscar un dato (un valor) en una determinada tabla hash.
 * @param tabla La tabla en la cual se quiere buscar dicho valor.
 * @param dato El dato que se quiere buscar.
 * @return La posición en la que se encuentra el dato (si no se encuentra, devuelve -1).
 */
int buscar_dato_tabla_hash(TablaHash tabla, ElemType dato) 
{
    Index supuesta_posicion = FUNCION_HASH(dato);  // Se calcula la supuesta posición del arreglo en la que está el dato.

    if (buscar_valor_en_lista(&tabla[supuesta_posicion], dato) != (Index) -1)
    {
        return supuesta_posicion;
    }

    return -1;
}

/**
 * @brief Función para imprimir una tabla hash.
 * @param tabla Tabla hash a imprimir.
 */
Procedure imprimir_tabla_hash(TablaHash tabla)
{
    Natural i;

    for (i=0; i<TAMANHO_TABLA_HASH; i++)
    {
        printf("Casilla %hu:  ", i+1);
        imprimir_lista(tabla[i]);
    }

    printf("\n");
}

/**
 * @brief Función para eliminar un dato o valor de una tabla hash.
 * @param tabla La tabla de la cual se quiere eliminar ese elemento.
 * @param dato EL elemento a eliminar.
 * @return true si el dato fue encontrado y se pudo eliminar, false en caso contrario.
 */
bool eliminar_dato_tabla_hash(TablaHash tabla, ElemType dato) 
{
    Index supuesta_posicion = FUNCION_HASH(dato);  // Se calcula la casilla en la que podría estar ese dato.
    
    if (esta_vacia(tabla[supuesta_posicion]))
    {
        return false;  // Si está vacía, el dato no está, y por lo tanto, no se puede eliminar.
    }

    Nodo* prev = tabla[supuesta_posicion].cabeza;
    Nodo* actual = tabla[supuesta_posicion].cabeza->siguiente;

    while (actual)  // Se recorre toda la lista hasta encontrar el dato deseado, para eliminarlo
    {
        if (actual->dato == dato)
        {
            prev->siguiente = actual->siguiente;
            free(actual);
            actual = NULL;
            return true;
        }

        prev = actual;
        actual = actual->siguiente;
    }

    return false;
}

/**
 * @brief Función para eliminar una tabla hash, liberando toda su memoria.
 * @param tabla La tabla hash a eliminar.
 */
Procedure eliminar_tabla_hash(TablaHash tabla)
{
    Natural i;

    for (i=0; i<TAMANHO_TABLA_HASH; i++)
    {
        eliminar_lista(&tabla[i], true);
    }
}

/**
 * @brief Función para vaciar una tabla hash, pero no eliminarla.  Ideal para su reutilización para operaciones futuras.
 * @param tabla La tabla hash que se quiere vaciar.
 */
Procedure vaciar_tabla_hash(TablaHash tabla)
{
    Natural i;

    for (i=0; i<TAMANHO_TABLA_HASH; i++)
    {
        vaciar_lista(&tabla[i]);
    }
}