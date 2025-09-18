#include "../../../libraries/list.h"

int main()
{
    ListaCircular lista = {0};

    if (!crear_lista_circular(&lista, 7))
    {
        return 1;
    }

    imprimir_lista_circular(lista);
    insertar_nodo_circular(&lista, 15, 2);
    imprimir_lista_circular(lista);
    printf("El tamaño de la lista circular es %hu\n", tamanho_lista_circular(lista));
    insertar_nodo_circular_final(&lista, 17);
    imprimir_lista_circular(lista);
    insertar_nodo_circular_inicio(&lista, 4);
    imprimir_lista_circular(lista);
    eliminar_nodo_circular(&lista, 5);
    imprimir_lista_circular(lista);
    eliminar_nodo_circular_final(&lista);
    imprimir_lista_circular(lista);
    eliminar_nodo_circular_inicio(&lista);
    imprimir_lista_circular(lista);
    eliminar_lista_circular(&lista, true);
    return 0;
}