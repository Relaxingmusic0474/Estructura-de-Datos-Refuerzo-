#include "../libraries/searching.h"

/**
 * @brief Función que trata de encontrar un cierto elemento dentro de un arreglo, recorriéndolo secuencialmente.
 * @param datos Estructura que contiene el arreglo y su tamaño, además de un indicador que indica si está ordenado o no.
 * @param dato_deseado Es el dato que se desea buscar.
 * @return Un dato (que es una estructura) que contiene información del elemento, y si fue encontrado o no.
 */
Dato busqueda_secuencial(Datos* datos, Dato dato_deseado)
{
    Natural i;
    Dato resultado =  dato_deseado;

    resultado.encontrado = false;
    resultado.posicion = INDEX_NO_VALIDO;

    for (i=0; i<datos->tamanho; i++)
    {
        if (memcmp(&datos->arreglo[i], &dato_deseado, sizeof(Dato)))
        {
            resultado.encontrado = true;
            resultado.posicion = i;
            printf("Elemento encontrado en la posicion %hu\n", resultado.posicion);
            break;
        }
    }

    return resultado;
}

/**
 * @brief Función que trata de encontrar un cierto elemento dentro de un arreglo, dividiéndolo en mitades.
 * @param datos Estructura que contiene el arreglo y su tamaño, además de un indicador que indica si está ordenado o no.
 * @param valor Es el valor que se desea encontrar dentro del arreglo.
 * @return Un dato (que es una estructura) que contiene información del elemento, y si fue encontrado o no.
 */
Dato busqueda_binaria(Datos* datos, Elemento valor)
{
    //qsort(datos->arreglo, datos->tamanho, sizeof(Dato), comparar_datos);
}