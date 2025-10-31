#ifndef TREE_H
#define TREE_H

#include "types.h"
#include "stdlib.h"
#include "stdbool.h"
#include "limits.h"

#define MAX(a, b) ((a >= b) ? a : b)
#define MIN(a, b) ((a < b) ? a : b)
#define PADRE(k) (k/2 - 1)
#define HIJO_IZQUIERDO(k) (2*k+1)
#define HIJO_DERECHO(k) (2*k+2)

typedef enum tipo_heap TipoHeap;
typedef struct heap Heap;

enum tipo_heap
{
    MIN_HEAP,
    MAX_HEAP,
    HEAP_NO_VAL = USHRT_MAX,  // PARA HEAPS NO VÁLIDOS
};

struct heap
{
    ElemType* elementos;
    Natural capacidad;
    Natural tamanho;
    TipoHeap tipo;
};


/* ------------------------------------- FUNCIÓN SWAP ------------------------------------- */
Procedure swap(ElemType* a, ElemType* b);


/* --------------------------------- FUNCIONES PARA HEAPS --------------------------------- */
bool crear_heap(Heap* heap, TipoHeap tipo, Natural capacidad);
bool redimensionar_heap(Heap* heap, Natural nueva_capacidad);
Procedure amontonar_heap_secuencial(Heap* heap);
Procedure amontonar_heap_completo(Heap* heap);
bool insertar_dato_heap(ElemType dato, Heap* heap);
Procedure eliminar_heap(Heap* heap);
Procedure vaciar_heap(Heap* heap);

#endif  // TREE_H