#ifndef DATA_H
#define DATA_H

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stdbool.h"
#include "limits.h"
#include "float.h"
#include "types.h"

#define LARGO 20
#define DOUBLE_NO_VALIDO (__DBL_MAX__)

typedef union casilla Casilla;
typedef enum tipo Tipo;
typedef struct elemento Elemento;
typedef struct dato Dato;
typedef struct datos Datos;

union casilla
{
    int entero;
    Natural natural;
    double real;
    char caracter;
    char cadena[LARGO];
};

enum tipo
{
    ENTERO,
    NATURAL,
    REAL,
    CARACTER,
    CADENA,
    DESCONOCIDO = -1,
};

struct elemento
{
    Casilla valor;
    double valor_double;
    Tipo tipo;
};

struct dato
{
    Elemento elemento;
    Natural posicion;
    bool encontrado;
};

struct datos
{
    Dato* arreglo;
    Natural tamanho;
    bool ordenado;
};

bool es_decimal(char* str, size_t len);  // Para detectar si un nro es decimal
bool es_caracter_numerico(char ch);  // Detecta si un caracter es numérico o no
bool leer_datos_input(int argc, char* argv[], Datos* datos);  // Para leer datos que ingrese el usuario y ordenarlos por ejemplo.
bool es_numerico(Dato dato);  // Para detectar si un dato es un número.
bool es_alpha(Dato dato);  // Para detectar si un dato es alfabético.
bool validacion_datos_uniforme(Datos* datos);  // Para validar que los elementos del array sean del mismo tipo entre sí.
Procedure imprimir_datos(Datos datos);

#endif  // DATA_H