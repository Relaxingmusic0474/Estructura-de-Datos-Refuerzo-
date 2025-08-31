#include "../libraries/searching.h"

/**
 * @brief Función que trata de encontrar un cierto elemento dentro de un arreglo, recorriéndolo secuencialmente.
 * @param datos Estructura que contiene el arreglo y su tamaño, además de un indicador que indica si está ordenado o no.
 * @param dato_deseado Es el dato que se desea buscar.
 * @return Un dato (que es una estructura) que contiene información del elemento, y si fue encontrado o no.
 */
Index busqueda_secuencial(Datos* datos, Dato* dato_deseado)
{
    Natural i;

    if (!es_numerico(*dato_deseado) && !es_alpha(*dato_deseado))  // Esto significaría que es de tipo desconocido, así que no se podrá encontrar
    {
        return INDEX_NO_VALIDO;
    }

    for (i=0; i<datos->tamanho; i++)
    {
        if (es_numerico(datos->arreglo[i]) || datos->arreglo[i].elemento.tipo == CARACTER)
        {
            if ((!es_numerico(*dato_deseado) && dato_deseado->elemento.tipo != CARACTER))
            {
                continue;
            }

            else
            {
                if (datos->arreglo[i].elemento.valor_double == dato_deseado->elemento.valor_double)
                {
                    dato_deseado->encontrado = true;
                    dato_deseado->posicion = i;
                    return i;
                }
            }
        }

        else
        {
            if (dato_deseado->elemento.tipo != CADENA)
            {
                continue;
            }

            else
            {
                if (strcmp(datos->arreglo[i].elemento.valor.cadena, dato_deseado->elemento.valor.cadena) == 0)
                {
                    dato_deseado->encontrado = true;
                    dato_deseado->posicion = i;
                    return i;
                }
            }
        }
    }

    return INDEX_NO_VALIDO;
}

/**
 * @brief Función que trata de encontrar un cierto elemento dentro de un arreglo, dividiéndolo en mitades.
 * @param datos Estructura que contiene el arreglo y su tamaño, además de un indicador que indica si está ordenado o no.
 * @param start Indice inicial en el que se comenzará a buscar.
 * @param end Indice final de la búsqueda binaria.
 * @param dato_deseado Es el dato que se buscará en el arreglo de metadatos.
 * @param ordenamiento Algoritmo que se utilizará para ordenar los metadatos antes de comenzar la búsqueda.
 * @return Un dato (que es una estructura) que contiene información del elemento, y si fue encontrado o no.
 */
Index busqueda_binaria(Datos* datos, Index start, Index end, Dato* dato_deseado, TipoOrdenamiento ordenamiento)
{
    Index mid = INDEX_NO_VALIDO;

    if (!datos || !datos->arreglo)
    {
        printf("ERROR: Los datos son NULL o el arreglo que lo contiene es NULL.\n");
        dato_deseado->encontrado = false;
        return INDEX_NO_VALIDO;
    }

    if (!validacion_datos_uniforme(datos))
    {
        printf("ERROR: No es posible hacer búsqueda binaria si no hay uniformidad en la categorización de los datos\n");
        dato_deseado->encontrado = false;
        return INDEX_NO_VALIDO;
    }

    if (!datos->ordenado)
    {
        switch (ordenamiento)
        {
            case MERGESORT:
                mergesort(datos, true);
                break;

            case QUICKSORT:
                qsort(datos->arreglo, datos->tamanho, sizeof(Dato), comparar_qsort);
                datos->ordenado = true;
                break;

            default:
                printf("ERROR: Algoritmo de ordenamiento no reconocido o no implementado aún\n");
                dato_deseado->encontrado = false;
                return INDEX_NO_VALIDO;
        }
    }

    if (start <= end && start < datos->tamanho && end < datos->tamanho)
    {
        mid = (start+end)/2;

        if (datos->arreglo[mid].elemento.tipo == CADENA)
        {
            if (dato_deseado->elemento.tipo == CADENA)
            {
                if (strcmp(datos->arreglo[mid].elemento.valor.cadena, dato_deseado->elemento.valor.cadena) == 0)
                {
                    dato_deseado->posicion = datos->arreglo[mid].posicion;
                    dato_deseado->encontrado = true;
                    return dato_deseado->posicion;
                }

                else if (strcmp(datos->arreglo[mid].elemento.valor.cadena, dato_deseado->elemento.valor.cadena) < 0)
                {
                    return busqueda_binaria(datos, mid+1, end, dato_deseado, ordenamiento);
                }

                else  // cadena > cadena_buscada
                {
                    return busqueda_binaria(datos, start, mid-1, dato_deseado, ordenamiento);
                }
            }
        }

        else
        {
            if (datos->arreglo[mid].elemento.tipo != DESCONOCIDO)
            {
                if (dato_deseado->elemento.tipo != DESCONOCIDO)
                {
                    if (datos->arreglo[mid].elemento.valor_double == dato_deseado->elemento.valor_double)
                    {
                        dato_deseado->posicion = datos->arreglo[mid].posicion;
                        dato_deseado->encontrado = true;
                        return dato_deseado->posicion;
                    }

                    else if (datos->arreglo[mid].elemento.valor_double < dato_deseado->elemento.valor_double)
                    {
                        return busqueda_binaria(datos, mid+1, end, dato_deseado, ordenamiento);
                    }

                    else  // Número o caracter > número buscado
                    {
                        return busqueda_binaria(datos, start, mid-1, dato_deseado, ordenamiento);
                    }
                }
            }
        }
    }

    dato_deseado->encontrado = false;
    return INDEX_NO_VALIDO;
}