#ifndef SEARCHING_H
#define SEARCHING_H

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stdbool.h"
#include "limits.h"
#include "data.h"

#define INDEX_NO_VALIDO (USHRT_MAX)

Dato busqueda_secuencial(Datos* datos, Elemento valor);   // Función para buscar secuencialmente un dato
Dato busqueda_binaria(Datos* datos, Elemento valor);    // Función para buscar binariamente un dato

#endif  // SEARCHING_H