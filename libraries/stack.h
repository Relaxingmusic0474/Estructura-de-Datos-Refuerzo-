#ifndef STACK_H
#define STACK_H

#include "list.h"

typedef ListaDobleCircular Pila;  // Debido a su eficiencia en inserciones y eliminaciones (O(1) en vez de O(n) como en listas simples), será el tipo por defecto para pilas
typedef NodoDobleCircular NodoPila;
typedef struct pilaArray PilaArray;

struct pilaArray
{
    ElemType* elementos;
    Natural tamanho;
    Natural capacidad;
};

/* ----------------------- FUNCIONES PARA PILAS ----------------------- */
Procedure inicializar_pila(Pila* pila);
bool push(Pila* pila, ElemType valor);
Procedure pop(Pila* pila);
NodoPila* top(Pila* pila);
/* -------------------------------------------------------------------- */

#endif  // STACK_H