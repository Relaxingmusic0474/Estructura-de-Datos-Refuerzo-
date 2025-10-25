#include "../../libraries/stack.h"

int main()
{
    Pila pila;
    inicializar_pila(&pila);
    crear_pila_vacia(&pila);
    imprimir_pila(&pila);
    push(&pila, 15);
    imprimir_pila(&pila);
    push(&pila, 27);
    imprimir_pila(&pila);
    push(&pila, 17);
    imprimir_pila(&pila);
    push(&pila, 8);
    imprimir_pila(&pila);
    push(&pila, 33);
    imprimir_pila(&pila);
    pop(&pila);
    imprimir_pila(&pila);
    pop(&pila);
    imprimir_pila(&pila);
    pop(&pila);
    imprimir_pila(&pila);
    push(&pila, 4);
    imprimir_pila(&pila);
    vaciar_pila(&pila);
    imprimir_pila(&pila);
    push(&pila, 22);
    imprimir_pila(&pila);
    push(&pila, 55);
    imprimir_pila(&pila);
    push(&pila, -3);
    imprimir_pila(&pila);
    push(&pila, 14);
    imprimir_pila(&pila);
    eliminar_pila(&pila);
    return 0;
}