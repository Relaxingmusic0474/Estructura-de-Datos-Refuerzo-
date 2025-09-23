#ifndef QUEUE_H
#define QUEUE_H

#include "list.h"

typedef ListaDobleCircular Cola;  // Debido a su eficiencia en inserciones y eliminaciones (O(1) en vez de O(n) como en listas simples), será el tipo por defecto para colas
typedef NodoDobleCircular NodoCola;
typedef struct colaArray ColaArray;

struct colaArray
{
    ElemType* elementos;
    Natural tamanho;
    Natural capacidad;
};

/* ----------------------- FUNCIONES PARA COLAS ----------------------- */
Procedure inicializar_cola(Cola* cola);
bool enqueue(Cola* cola, ElemType valor);
Procedure dequeue(Cola* cola);
NodoCola* front(Cola cola);
NodoCola* rear(Cola cola);
Procedure imprimir_cola(Cola* cola);
bool es_cola_vacia(Cola cola);
Procedure eliminar_cola(Cola* cola);
/* -------------------------------------------------------------------- */

#endif  // QUEUE_H