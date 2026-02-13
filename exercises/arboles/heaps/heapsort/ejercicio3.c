#include "../../../../libraries/tree.h"

int main()
{
    // Ejemplo 1
    Heap heap = {0};
    construir_heap(&heap, MIN_HEAP, (ElemType []){2, 3, 10, 5, 14, 8}, 6);
    printf("Antes de la eliminación del 3er nodo:\n");
    imprimir_heap(heap);
    printf("\nTamaño del heap: %hu\n", heap.tamanho);
    eliminar_k_esimo_nodo_heap(&heap, 2);
    printf("\nLuego de la eliminación del 3er nodo:\n");
    imprimir_heap(heap);
    printf("\nTamaño del heap: %hu\n", heap.tamanho);
    eliminar_heap(&heap);

    // Ejemplo 2
    Heap heap2 = {0};
    crear_heap(&heap2, MAX_HEAP, 20);
    insertar_dato_heap(15, &heap2);
    insertar_dato_heap(22, &heap2);
    insertar_dato_heap(12, &heap2);
    insertar_dato_heap(17, &heap2);
    insertar_dato_heap(8, &heap2);
    insertar_dato_heap(11, &heap2);
    insertar_dato_heap(26, &heap2);
    insertar_dato_heap(20, &heap2);
    insertar_dato_heap(13, &heap2);
    insertar_dato_heap(10, &heap2);
    insertar_dato_heap(24, &heap2);
    printf("\nAntes de la eliminación del 2do nodo:\n");
    imprimir_heap(heap2);
    printf("\nTamaño del heap: %hu\n", heap2.tamanho);
    eliminar_k_esimo_nodo_heap(&heap2, 1);
    printf("\nLuego de la eliinacion del 2do nodo:\n");
    imprimir_heap(heap2);
    printf("\nTamaño del heap: %hu\n", heap2.tamanho);
    eliminar_heap(&heap2);
    
    return 0;
}