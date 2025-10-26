#ifndef HASHING_H
#define HASHING_H

#include "list.h"

#define TAMANHO_TABLA_HASH 17  // Número primo para reducir colisiones (como es código de ejemplo, se deja un número pequeño)
#define FUNCION_HASH(nro) ((unsigned int) nro % TAMANHO_TABLA_HASH)  // Función hash simple para números naturales

typedef Lista TablaHash[TAMANHO_TABLA_HASH];  // Cada entrada de la tabla hash es una lista enlazada simple (hashing abierto)

/* -------------------- FUNCIONES PARA TABLAS HASH (HASHING ABIERTO) -------------------- */
bool inicializar_tabla_hash(TablaHash tabla);
bool insertar_dato_tabla_hash(TablaHash tabla, ElemType dato);
int buscar_dato_tabla_hash(TablaHash tabla, ElemType dato);
Procedure imprimir_tabla_hash(TablaHash tabla);
bool eliminar_dato_tabla_hash(TablaHash tabla, ElemType dato);
Procedure eliminar_tabla_hash(TablaHash tabla);
Procedure vaciar_tabla_hash(TablaHash tabla);

#endif  // HASHING_H