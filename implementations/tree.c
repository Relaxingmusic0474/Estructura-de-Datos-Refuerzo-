#include "../libraries/tree.h"

/* ----------------------- FUNCIONES PARA HEAPS ----------------------- */
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

