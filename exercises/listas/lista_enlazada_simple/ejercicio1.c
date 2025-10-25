#include "../../../libraries/list.h"

int main()
{
    Lista lista = {0};
    crear_lista_vacia(&lista);
    insertar_nodo(&lista, 23, 0);
    imprimir_lista(lista);
    modificar_nodo(&lista, 0, 17);
    imprimir_lista(lista);
    insertar_nodo(&lista, -1, 0);
    imprimir_lista(lista);
    insertar_nodo(&lista, 45, 2);
    imprimir_lista(lista);
    modificar_nodo(&lista, 1, 28);
    imprimir_lista(lista);
    insertar_nodo(&lista, 8, 2);
    imprimir_lista(lista);
    insertar_nodo(&lista, 5, 4);
    imprimir_lista(lista);
    eliminar_nodo(&lista, 3);
    imprimir_lista(lista);
    insertar_nodo_final(&lista, 15);
    imprimir_lista(lista);
    insertar_nodo_inicio(&lista, 10);
    imprimir_lista(lista);
    modificar_nodo(&lista, 1, 0);
    imprimir_lista(lista);
    vaciar_lista(&lista);
    insertar_nodo_final(&lista, 13);
    imprimir_lista(lista);
    eliminar_lista(&lista, true);
    return 0;
}