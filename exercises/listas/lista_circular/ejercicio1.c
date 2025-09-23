#include "../../../libraries/list.h"

int main()
{
    ListaCircular lista = {0};
    Index posicion;
    ElemType buscado = 24;
    bool encontrado;
    char mensaje[50] = {'\0'};

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
    insertar_nodo_circular_final(&lista, 24);
    imprimir_lista_circular(lista);
    posicion = buscar_valor_en_lista_circular(&lista, buscado);
    encontrado = (posicion != (Index) -1);
    encontrado ? snprintf(mensaje, sizeof(mensaje), "Nro %d encontrado en la posición %hu.\n", buscado, posicion) : snprintf(mensaje, sizeof(mensaje), "El %d no fue encontrado.\n", buscado);
    printf("%s", mensaje);
    rotacion_izquierda_lista_circular(&lista);
    imprimir_lista_circular(lista);
    rotacion_derecha_lista_circular(&lista);
    imprimir_lista_circular(lista);  // Volvió a quedar originalmente como estaba luego de las rotaciones
    modificar_nodo_circular(&lista, 4, 14);
    modificar_nodo_circular(&lista, 5, 17);
    imprimir_lista_circular(lista);
    eliminar_lista_circular(&lista, true);
    return 0;
}