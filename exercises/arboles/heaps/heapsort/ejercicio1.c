#include "../../../../libraries/tree.h"

int main()
{
    Heap heap = {0};
    ElemType array[] = {15, 17, 43, 0, 11, 8, 27, 6, 22};
    Natural tamanho = sizeof(array) / sizeof(ElemType);
    construir_heap(&heap, MAX_HEAP, array, tamanho);
    heapsort(&heap);
    imprimir_heap(heap);
    eliminar_heap(&heap);
    return 0;
}