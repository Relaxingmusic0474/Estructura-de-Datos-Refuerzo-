#ifndef SORTING_H
#define SORTING_H

#include "stdio.h"
#include "types.h"
#include "data.h"
#include "tree.h"

typedef enum tipoOrdenamiento TipoOrdenamiento;

enum tipoOrdenamiento
{
    MERGESORT,
    QUICKSORT,
};

Procedure merge(Datos* datos, Datos* data1, Datos* data2, bool ascendente);  // Función para hacer merge (combinar)
Procedure mergesort(Datos* datos, bool ascendente);  // Función para hacer mergesort
Procedure heapsort_data(Datos* datos, bool ascendente);  // Función para hacer heapsort

#endif  // SORTING_H