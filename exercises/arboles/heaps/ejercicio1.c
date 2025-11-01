#include "../../../libraries/tree.h"

#define CAPACIDAD_HEAP 15

int main()
{
    Heap heap = {0};
    crear_heap(&heap, MAX_HEAP, CAPACIDAD_HEAP);
    insertar_dato_heap(17, &heap);
    printf("IMPRESIÓN N°1:\n");
    imprimir_heap(heap);
    insertar_dato_heap(22, &heap);
    printf("\nIMPRESIÓN N°2:\n");
    imprimir_heap(heap);
    insertar_dato_heap(0, &heap);
    printf("\nIMPRESIÓN N°3:\n");
    imprimir_heap(heap);
    insertar_dato_heap(11, &heap);
    printf("\nIMPRESIÓN N°4:\n");
    imprimir_heap(heap);
    insertar_dato_heap(-3, &heap);
    printf("\nIMPRESIÓN N°5:\n");
    imprimir_heap(heap);
    insertar_dato_heap(45, &heap);
    printf("\nIMPRESIÓN N°6:\n");
    imprimir_heap(heap);
    insertar_dato_heap(8, &heap);
    printf("\nIMPRESIÓN N°7:\n");
    imprimir_heap(heap);
    insertar_dato_heap(4, &heap);
    printf("\nIMPRESIÓN N°8:\n");
    imprimir_heap(heap);
    insertar_dato_heap(15, &heap);
    printf("\nIMPRESIÓN N°9:\n");
    imprimir_heap(heap);
    insertar_dato_heap(-5, &heap);
    printf("\nIMPRESIÓN N°10:\n");
    imprimir_heap(heap);
    insertar_dato_heap(30, &heap);
    printf("\nIMPRESIÓN N°11:\n");
    imprimir_heap(heap);
    insertar_dato_heap(25, &heap);
    printf("\nIMPRESIÓN N°12:\n");
    imprimir_heap(heap);
    eliminar_heap(&heap);
    return 0;
}