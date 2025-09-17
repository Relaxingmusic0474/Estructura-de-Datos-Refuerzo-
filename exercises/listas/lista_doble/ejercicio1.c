#include "../../../libraries/list.h"

int main()
{
    ListaDoble lista = {0};
    Index posicion = 1;
    ElemType buscado = 0;
    bool encontrado;
    char mensaje[50] = {'\0'};
    
    if (!crear_lista_doble(&lista, 5))
    {
        return 1;
    }

    imprimir_lista_doble(lista, false);
    insertar_nodo_doble_final(&lista, 13);
    imprimir_lista_doble(lista, true);
    insertar_nodo_doble(&lista, 18, 2);
    imprimir_lista_doble(lista, false);
    modificar_nodo_doble(&lista, 4, 7);
    imprimir_lista_doble(lista, false);
    eliminar_nodo_doble(&lista, 3);
    imprimir_lista_doble(lista, false);
    eliminar_nodo_doble_inicio(&lista);
    imprimir_lista_doble(lista, false);
    printf("El nodo en la posición %hu de la lista es %d.\n", posicion, nodo_doble_k_esimo(lista, posicion)->dato);  // El 2do nodo
    posicion = buscar_valor_en_lista_doble(&lista, buscado);
    encontrado = (posicion != (Index) -1);
    encontrado ? snprintf(mensaje, sizeof(mensaje), "Nro %d encontrado en la posición %hu.\n", buscado, posicion) : snprintf(mensaje, sizeof(mensaje), "El %d no fue encontrado.\n", buscado);
    printf("%s", mensaje);
    eliminar_lista_doble(&lista);
    return 0;
}