#include "../../libraries/queue.h"

int main()
{
    Cola cola;
    inicializar_cola(&cola);
    printf("Tamaño: %d\n", cola.tamanho);
    imprimir_cola(&cola);
    enqueue(&cola, 15);
    printf("Tamaño: %d\n", cola.tamanho);
    imprimir_cola(&cola);
    enqueue(&cola, 20);
    printf("Tamaño: %d\n", cola.tamanho);
    imprimir_cola(&cola);
    enqueue(&cola, 35);
    printf("Tamaño: %d\n", cola.tamanho);
    imprimir_cola(&cola);
    enqueue(&cola, -1);
    printf("Tamaño: %d\n", cola.tamanho);
    imprimir_cola(&cola);
    enqueue(&cola, 7);
    printf("Tamaño: %d\n", cola.tamanho);
    imprimir_cola(&cola);
    dequeue(&cola);
    printf("Tamaño: %d\n", cola.tamanho);
    imprimir_cola(&cola);
    dequeue(&cola);
    printf("Tamaño: %d\n", cola.tamanho);
    imprimir_cola(&cola);
    vaciar_cola(&cola);
    printf("Tamaño: %d\n", cola.tamanho);
    imprimir_cola(&cola);
    enqueue(&cola, 18);
    printf("Tamaño: %d\n", cola.tamanho);
    imprimir_cola(&cola);
    enqueue(&cola, 34);
    printf("Tamaño: %d\n", cola.tamanho);
    imprimir_cola(&cola);
    enqueue(&cola, 22);
    printf("Tamaño: %d\n", cola.tamanho);
    imprimir_cola(&cola);
    dequeue(&cola);
    printf("Tamaño: %d\n", cola.tamanho);
    imprimir_cola(&cola);
    eliminar_cola(&cola);
}