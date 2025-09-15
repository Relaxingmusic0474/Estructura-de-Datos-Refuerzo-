#include "../../../libraries/list.h"

int main()
{
    Lista lista = {0};
    crear_lista_vacia(&lista);
    insertar_nodo(&lista, 23, 0);
    modificar_nodo(&lista, 0, 17);
    eliminar_lista(&lista, true);
    return 0;
}