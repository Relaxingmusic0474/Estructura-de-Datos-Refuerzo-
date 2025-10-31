#include "../libraries/tree.h"

/* ------------------------------------- FUNCIÓN SWAP ------------------------------------- */
/**
 * @brief Función para intercambiar dos elementos.
 * @param a El primer elemento a intercambiar.
 * @param b El segundo elemento a intercambiar.
 */
Procedure swap(ElemType* a, ElemType* b)
{
    ElemType aux = *a;
    *a = *b;
    *b = aux;
}


/* --------------------------------- FUNCIONES PARA HEAPS --------------------------------- */
/**
 * @brief Función para crear un heap.
 * @param heap El heap a crear.
 * @param tipo El tipo de heap (maxheap o minheap).
 * @param capacidad La capacidad que inicialmente tendrá el heap.
 * @return true si se logró crear el heap correctamente, false en caso contrario.
 */
bool crear_heap(Heap* heap, TipoHeap tipo, Natural capacidad)
{
    if (tipo != MIN_HEAP && tipo != MAX_HEAP)
    {
        printf("Error: No se pudo crear el heap, porque el tipo ingresado de inicialización no es válido.\n");
        return false;
    }

    heap->tipo = tipo;
    heap->tamanho = 0;
    heap->capacidad = capacidad;

    heap->elementos = (ElemType *) calloc(heap->capacidad, sizeof(ElemType));

    if (!heap->elementos)
    {
        printf("Error de asignación de memoria al crear el heap solicitado.\n");
        heap->tipo = HEAP_NO_VAL;
        heap->capacidad = 0;
        return false;
    }
    
    return true;
}

/**
 * @brief Función para redimensionar un heap.
 * @param heap El heap a redimensionar.
 * @param nueva_capacidad La capacidad nueva que soportará el heap.
 * @return true si fue posible redimensionar el heap sin errores, false en caso de error.
 */
bool redimensionar_heap(Heap* heap, Natural nueva_capacidad)
{
    if (!heap)
    {
        printf("Error: El heap no existe.\n");
        return false;
    }

    if (heap->capacidad == nueva_capacidad)
    {
        return true;  // No se hace nada si la capacidad es la misma
    }

    if (nueva_capacidad == 0)
    {
        eliminar_heap(heap);
        return true; 
    }

    ElemType* heap_elems = realloc(heap->elementos, nueva_capacidad * sizeof(ElemType));

    if (!heap_elems)
    {
        printf("Advertencia: No se pudo redimensionar el heap.\n");
        // El heap original no se libera para que se puedan seguir haciendo otro tipo de operaciones en él
        return false;
    }

    if (heap->capacidad < nueva_capacidad)
    {
        for (Natural i=heap->capacidad; i<nueva_capacidad; i++)
        {
            heap_elems[i] = 0;  // Se inicializan en 0 los nuevos elementos, pero simplemente para que no haya basura
        }
    }

    else
    {
        if (heap->capacidad > nueva_capacidad)
        {
            printf("Advertencia: La nueva capacidad del heap será menor, por lo que se truncará.\n");

            if (heap->tamanho > nueva_capacidad)
            {
                heap->tamanho = nueva_capacidad;
            }
        }
    }

    heap->elementos = heap_elems;
    heap->capacidad = nueva_capacidad;
    return true;
}

/**
 * @brief Función para amontonar un heap en que sus elementos se han insertado de forma secuencial.
 * @param heap El heap a amontonar.
 */
Procedure amontonar_heap_secuencial(Heap* heap)
{
    if (!heap || !heap->elementos)
    {
        printf("Error: El heap o sus elementos son NULL.  No puede amontonarse.\n");
        return;
    }

    if (heap->tipo == HEAP_NO_VAL)
    {
        printf("Error: Tipo de heap no válido.  No se puede amontonar.\n");
        return;
    }

    if (heap->tamanho == 0 || heap->tamanho == 1)
    {
        return;  // Heap vacío o con un solo elemento -> No se hace nada
    }

    Index indice_analisis = heap->tamanho-1;  // Este será el índice de análisis inicial

    while (indice_analisis > 0 &&
          ((heap->tipo == MAX_HEAP && heap->elementos[indice_analisis] > heap->elementos[PADRE(indice_analisis)]) ||
          (heap->tipo == MIN_HEAP && heap->elementos[indice_analisis] < heap->elementos[PADRE(indice_analisis)])))
    {
        // Aquí se hace el intercambio
        swap(&heap->elementos[indice_analisis], &heap->elementos[PADRE(indice_analisis)]);
        indice_analisis = PADRE(indice_analisis);
    }

    return;
}

/**
 * @brief Función para amontonar un heap (mantener su propiedad dependiendo de su tipo).
 * @param heap El heap a amontonar.
 */
Procedure amontonar_heap_completo(Heap* heap)
{
    if (!heap || !heap->elementos)
    {
        printf("Error: El heap o sus elementos son NULL.  No puede amontonarse.\n");
        return;
    }

    if (heap->tipo == HEAP_NO_VAL)
    {
        printf("Error: Tipo de heap no válido.  No puede amontonarse.\n");
        return;
    }

    if (heap->tamanho == 0 || heap->tamanho == 1)
    {
        return;  // Heap vacío o con un solo elemento -> No hace nada
    }

    Index indice_inicial = (heap->tamanho-1)/2;

    while (indice_inicial != 0)
    {
        

    }
}

/**
 * @param dato Dato que se desea insertar en el heap.
 * @param heap Heap en el que se quiere insertar el dato.
 * @return true si se insertó correctamente, false en caso contrario.
 */
bool insertar_dato_heap(ElemType dato, Heap* heap)
{
    if (!heap->elementos)
    {
        printf("Error: El heap aún no está creado.  No es posible la inserción.\n");
        return false;
    }

    if (heap->tamanho == heap->capacidad)
    {
        Natural nueva_capacidad = 2*heap->capacidad;

        if (redimensionar_heap(heap, nueva_capacidad))
        {
            
        }
    }


}

/**
 * @brief Función para eliminar un heap, liberando su memoria.
 * @param heap El heap a eliminar.
 */
Procedure eliminar_heap(Heap* heap)
{
    if (!heap)
    {
        printf("Error: No se pudo eliminar el heap ya que es NULL\n");
        return;
    }

    free(heap->elementos);
    heap->elementos = NULL;
    heap->tamanho = 0;
    heap->capacidad = 0;
    heap->tipo = HEAP_NO_VAL;
}

/**
 * @brief Función que deja vacío el heap, con puros datos 0.
 * @param heap El heap a vaciar.
 */
Procedure vaciar_heap(Heap* heap)
{
    if (!heap->elementos || heap->capacidad == 0)
    {
        printf("Error: El heap aún no ha sido creado, por lo tanto, no se puede vaciar.\n");
        return;
    }

    for (Natural i=0; i<heap->tamanho; i++)
    {
        heap->elementos[i] = 0;
    }
}

