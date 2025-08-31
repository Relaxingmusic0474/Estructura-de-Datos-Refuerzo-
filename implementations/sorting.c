#include "../libraries/sorting.h"

/**
 * @brief Función que combina dos arreglos en uno solo ordenándolos de menor a mayor o viceversa.
 * @param data_combinado El arreglo en el cual se combinarán ambos subarreglos.
 * @param data1 Es el subarreglo de la izquierda.
 * @param data2 Es el subarreglo de la derecha.
 * @param ascendente Es un booleano que indica si se desea ordenar el arreglo de forma ascendente o descendente. 
 */
Procedure merge(Datos* data_combinado, Datos* data1, Datos* data2, bool ascendente)
{
    Natural i=0, j=0, k=0;
    bool numerico = es_numerico(data1->arreglo[0]);

    if (numerico || data1->arreglo[0].elemento.tipo == CARACTER)  // Como ya se hizo en mergesort la comprobación de uniformidad del arreglo significa que todos los elementos son numéricos
    {
        while (i<data1->tamanho && j<data2->tamanho)
        {
            if (data1->arreglo[i].elemento.valor_double > data2->arreglo[j].elemento.valor_double)
            {
                if (ascendente)
                {
                    data_combinado->arreglo[k] = data2->arreglo[j];
                    j++;
                }

                else
                {
                    data_combinado->arreglo[k] = data1->arreglo[i];
                    i++;
                }
            }

            else  // data1->arreglo[i].elemento.valor_double <= data2->arreglo[j].elemento.valor_double
            {
                if (ascendente)
                {
                    data_combinado->arreglo[k] = data1->arreglo[i];
                    i++;
                }

                else
                {
                    data_combinado->arreglo[k] = data2->arreglo[j];
                    j++;
                }
            }

            k++;
        }

        goto colocar_sobrantes;
    }

    else
    {
        while (i<data1->tamanho && j<data2->tamanho)
        {
            if (strcmp(data1->arreglo[i].elemento.valor.cadena, data2->arreglo[j].elemento.valor.cadena) > 0)
            {
                if (ascendente)
                {
                    data_combinado->arreglo[k] = data2->arreglo[j];
                    j++;
                }

                else
                {
                    data_combinado->arreglo[k] = data1->arreglo[i];
                    i++;
                }
            }

            else
            {
                if (ascendente)
                {
                    data_combinado->arreglo[k] = data1->arreglo[i];
                    i++;
                }

                else
                {
                    data_combinado->arreglo[k] = data2->arreglo[j];
                    j++;
                }
            }

            k++;
        }

        goto colocar_sobrantes;
    }

    colocar_sobrantes:
    {
        while (i<data1->tamanho)
        {
            data_combinado->arreglo[k] = data1->arreglo[i];
            i++, k++;
        }

        while (j<data2->tamanho)
        {
            data_combinado->arreglo[k] = data2->arreglo[j];
            j++, k++;
        }
    }
}

/**
 * @brief Función que divide un arreglo hasta que queden puros subarreglos de un solo elemento.
 * @param datos Arreglo con los datos a ordenar.
 * @param len Tamaño del arreglo.
 * @param ascendente Booleano que le da la libertad al programador (o en algunos casos al usuario) de si quiere que el arreglo se ordene de forma ascendente o descendente.
 */
Procedure mergesort(Datos* datos, bool ascendente)
{
    Natural i, j;
    Natural n, n1, n2;
    Datos data1, data2;

    n = datos->tamanho;

    if (n <= 1)
    {
        datos->ordenado = true;
        return;
    }

    // Con esto se asegura que los datos sean uniformes antes de cualquier intento de ordenamiento
    if (!validacion_datos_uniforme(datos))
    {
        printf("ERROR: Los datos ingresados no son uniformes y no habría un criterio claro o entendido para ordenarlos\n");
        return;
    }

    n1 = n / 2;
    n2 = n - n1;
    
    Dato grupo1[n1], grupo2[n2];

    for (i=0; i<n1; i++)
    {
        grupo1[i] = datos->arreglo[i];
    }

    for (j=0; j<n2; i++, j++)
    {
        grupo2[j] = datos->arreglo[i];
    }
    
    data1 = (Datos) {.arreglo = grupo1, .tamanho = n1, .ordenado = false};
    data2 = (Datos) {.arreglo = grupo2, .tamanho = n2, .ordenado = false};

    mergesort(&data1, ascendente);
    mergesort(&data2, ascendente);
    merge(datos, &data1, &data2, ascendente);
    datos->ordenado = true;
}