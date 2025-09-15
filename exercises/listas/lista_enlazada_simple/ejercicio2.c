#include "../../../libraries/list.h"

int main()
{
    Lista lista = {0};
    Natural i;
    ElemType dato_buscado = 55;

    if (!crear_lista(&lista, 15))
    {
        return 1;
    }

    imprimir_lista(lista);

    for (i=0; i<tamanho_lista(lista); i++)
    {
        modificar_nodo(&lista, i, 5*i);
    }

    imprimir_lista(lista);
    eliminar_nodo_final(&lista);
    imprimir_lista(lista);
    eliminar_nodo_inicio(&lista);
    imprimir_lista(lista);
    intercambiar_nodos(&lista, 3, 6);
    imprimir_lista(lista);
    invertir_lista(&lista);
    imprimir_lista(lista);
    printf("El %d está en la posición %hu de la lista enlazada.\n", dato_buscado, buscar_valor_en_lista(&lista, dato_buscado));
    printf("El nodo en la posición 4 de la lista es %d.\n", nodo_k_esimo(lista, 4)->dato);  // El 5to nodo
    eliminar_lista(&lista, true);

    return 0;
}