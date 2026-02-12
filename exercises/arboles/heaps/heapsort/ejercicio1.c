#include "../../../../libraries/tree.h"

int main()
{
    Heap heap1 = {0}, heap2 = {0};
    ElemType array1[] = {15, 17, 43, 0, 11, 8, 27, 6, 22};
    ElemType array2[] = {0, -7, 11, 20, 4, 14};
    Natural n1 = sizeof(array1) / sizeof(ElemType);
    Natural n2 = sizeof(array2) / sizeof(ElemType);
    construir_heap(&heap1, MAX_HEAP, array1, n1);
    construir_heap(&heap2, MIN_HEAP, array2, n2);
    heapsort(&heap1);
    heapsort(&heap2);
    printf("HEAP 1 ORDENADO DE MENOR A MAYOR:\n");
    imprimir_heap(heap1);
    printf("\n\nHEAP 2 ORDENADO DE MAYOR A MENOR:\n");
    imprimir_heap(heap2);
    eliminar_heap(&heap1);
    eliminar_heap(&heap2);
    return 0;
}