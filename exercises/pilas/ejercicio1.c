#include "../../libraries/stack.h"

int main()
{
    Pila pila;
    inicializar_pila(&pila);
    push(&pila, 15);
    push(&pila, 27);
    push(&pila, 17);
    push(&pila, 8);
    printf("PILA EN SENTIDO NORMAL:\n");
    imprimir_pila(pila);
    push(&pila, 33);
    imprimir_pila(pila);
    eliminar_pila(&pila);
    return 0;
}