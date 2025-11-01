#include "../../../libraries/tree.h"

int main()
{
    ElemType elementos[] = {45, 36, 54, 27, 63, 72, 61, 18};
    Heap heap_completo = {0};
    Natural tamanho = sizeof(elementos) / sizeof(ElemType);

    construir_heap(&heap_completo, MAX_HEAP, elementos, tamanho);
    printf("IMPRESIÓN HEAP COMPLETO:\n");
    imprimir_heap(heap_completo);
    eliminar_heap(&heap_completo);

    Heap heap_secuencial = {0};

    crear_heap(&heap_secuencial, MAX_HEAP, tamanho);

    for (Natural i=0; i<tamanho; i++)
    {
        insertar_dato_heap(elementos[i], &heap_secuencial);
        printf("\n\nIMPRESIÓN N°%hu HEAP SECUENCIAL:\n", i+1);
        imprimir_heap(heap_secuencial);
    }

    eliminar_heap(&heap_secuencial);
    return 0;
}