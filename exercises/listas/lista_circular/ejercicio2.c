#include "../../../libraries/list.h"

#define VALOR_BUSCADO 15

int main()
{
    ListaDobleCircular lista = {0};

    if (!crear_lista_circular_doble(&lista, 5))
    {
        return 1;
    }

    imprimir_lista_circular_doble(lista);
    insertar_nodo_circular_doble(&lista, 15, 4);
    imprimir_lista_circular_doble(lista);
    insertar_nodo_circular_doble_final(&lista, 5);
    imprimir_lista_circular_doble(lista);
    insertar_nodo_circular_doble_inicio(&lista, 22);
    imprimir_lista_circular_doble(lista);
    eliminar_nodo_circular_doble(&lista, 4);
    imprimir_lista_circular_doble(lista);
    eliminar_nodo_circular_doble(&lista, 0);
    imprimir_lista_circular_doble(lista);
    eliminar_nodo_circular_doble_inicio(&lista);
    imprimir_lista_circular_doble(lista);
    eliminar_nodo_circular_doble_final(&lista);
    imprimir_lista_circular_doble(lista);
    printf("Tamaño de la lista circular doble: %hu.\n", tamanho_lista_circular_doble(lista));
    printf("El %d está en la posición %hu.\n", VALOR_BUSCADO, buscar_valor_en_lista_circular_doble(&lista, VALOR_BUSCADO));
    eliminar_lista_circular_doble(&lista);
    return 0;
}