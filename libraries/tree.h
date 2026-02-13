#ifndef TREE_H
#define TREE_H

#include "stdio.h"
#include "types.h"
#include "stdlib.h"
#include "string.h"
#include "stdbool.h"
#include "math.h"
#include "limits.h"

#define MAX(a, b) (((a) >= (b)) ? (a) : (b))
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define ES_PAR(x) ((x & 1) ? (0) : (1))
#define INDEX_NO_VALIDO (USHRT_MAX)  // El equivalente a (Natural)-1
#define PADRE(k) (((k)-1) / 2)
#define HIJO_IZQUIERDO(k) (2u*(k)+1u)
#define HIJO_DERECHO(k) (2u*(k)+2u)

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
bool construir_heap(Heap* heap, TipoHeap tipo, ElemType array[], Natural tamanho);
bool redimensionar_heap(Heap* heap, Natural nueva_capacidad);
Procedure amontonar_heap_secuencial(Heap* heap);
Procedure amontonar_heap_completo(Heap* heap);
Procedure eliminar_k_esimo_nodo_heap(Heap* heap, Index k);
Procedure heapsort(Heap* heap);
bool insertar_dato_heap(ElemType dato, Heap* heap);
Procedure imprimir_heap(Heap heap);
Procedure eliminar_heap(Heap* heap);
Procedure vaciar_heap(Heap* heap);

#endif  // TREE_H