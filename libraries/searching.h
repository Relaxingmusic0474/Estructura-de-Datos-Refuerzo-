#ifndef SEARCHING_H
#define SEARCHING_H

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stdbool.h"
#include "limits.h"
#include "data.h"
#include "sorting.h"

#define INDEX_NO_VALIDO (USHRT_MAX)

Index busqueda_secuencial(Datos* datos, Dato* dato_deseado);  // Función para buscar secuencialmente un dato
Index busqueda_binaria(Datos* datos, Index start, Index end, Dato* dato_deseado, TipoOrdenamiento ordenamiento);  // Función para buscar binariamente un dato

#endif  // SEARCHING_H