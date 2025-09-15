#include "../../../libraries/list.h"

int main()
{
    Lista lista = {0};
    Natural i;

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
    eliminar_lista(&lista, true);
    
    return 0;
}