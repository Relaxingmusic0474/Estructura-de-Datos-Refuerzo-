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
    eliminar_lista_circular(&lista);
    return 0;
}