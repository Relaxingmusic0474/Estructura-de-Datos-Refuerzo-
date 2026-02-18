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
typedef struct nodoABB NodoABB;
typedef struct ABB ABB;
typedef ABB AVL;

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

struct nodoABB
{
    ElemType dato;
    NodoABB* subarbol_izq;
    NodoABB* subarbol_der;
    Natural altura;
};

struct ABB
{
    NodoABB* raiz;
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

/* --------------------------------- FUNCIONES PARA ABBs --------------------------------- */
Procedure inicializar_abb(ABB* abb);
bool agregar_dato_al_abb(ElemType dato, ABB* abb);
NodoABB* buscar_dato_en_abb(ABB* abb, ElemType dato);
Procedure preorden(ABB abb, NodoABB* raiz);
Procedure inorden(ABB abb, NodoABB* raiz);
Procedure postorden(ABB abb, NodoABB* raiz);
Procedure imprimir_abb(ABB abb);
Procedure eliminar_dato_abb(ElemType dato, ABB* abb);
Procedure eliminar_abb(ABB* abb);
Procedure vaciar_abb(ABB* abb);


#endif  // TREE_H