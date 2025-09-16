#include "../../../libraries/list.h"

int main()
{
    ListaDoble lista = {0};
    
    if (!crear_lista_doble(&lista, 5))
    {
        return 1;
    }

    imprimir_lista_doble(lista, false);
    insertar_nodo_doble_final(&lista, 13);
    imprimir_lista_doble(lista, true);
    eliminar_lista_doble(&lista);
    return 0;
}