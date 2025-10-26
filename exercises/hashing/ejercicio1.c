#include "../../libraries/hashing.h"
#include "stdlib.h"
#include "time.h"

#define MAX_VALORES 40  // Se generarán 40 VALORES ALEATORIOS y se intentarán agregar a la TABLA HASH

#define VALOR_BUSCADO 37
#define VALOR_ELIMINAR 61

int main()
{
    srand(time(NULL));  // Inicialización de la semilla de números aleatorios

    TablaHash tabla;
    
    inicializar_tabla_hash(tabla);

    for (Natural i=0; i<MAX_VALORES; i++)
    {
        ElemType valor = (rand() % 111) - 40;  // Generará números aleatorios entre -40 y 70
        insertar_dato_tabla_hash(tabla, valor);        
        printf("\n\nIMPRESIÓN NRO %hu:\n\n", i+1);
        imprimir_tabla_hash(tabla);
    }

    printf("El %d está en la posición %d de la tabla hash\n", VALOR_BUSCADO, buscar_dato_tabla_hash(tabla, VALOR_BUSCADO));
    eliminar_dato_tabla_hash(tabla, VALOR_ELIMINAR);
    
    printf("\nIMPRESIÓN FINAL:\n\n");
    imprimir_tabla_hash(tabla);
    eliminar_tabla_hash(tabla);
    return 0;
}