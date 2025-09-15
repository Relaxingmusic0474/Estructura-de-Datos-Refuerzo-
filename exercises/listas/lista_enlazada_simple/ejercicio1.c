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
    eliminar_lista(&lista, true);
    return 0;
}