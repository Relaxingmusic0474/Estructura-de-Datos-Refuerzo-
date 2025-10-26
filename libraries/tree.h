#ifndef TREE_H
#define TREE_H

#include "types.h"
#include "stdlib.h"
#include "stdbool.h"
#include "limits.h"

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

/* ----------------------- FUNCIONES PARA HEAPS ----------------------- */
bool crear_heap(Heap* heap, TipoHeap tipo, Natural capacidad);

#endif  // TREE_H