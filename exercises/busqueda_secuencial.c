#include "../libraries/searching.h"

int main(int argc, char* argv[])
{
    Natural i;
    Datos data = {0};
    Dato dato_buscado = {.elemento = {.tipo = DESCONOCIDO, .valor = 0, .valor_double = DOUBLE_NO_VALIDO}, .encontrado = false, .posicion = INDEX_NO_VALIDO};
    char* valor = NULL;

    if (!leer_datos_input(argc, argv, &data))
    {
        printf("Uso: %s <lista de datos>\n", argv[0]);
        return 1;
    }

    printf("- Ingrese el valor que desea buscar: ");

    if (scanf("%s", valor) != 1)
    {
        printf("Error al ingresar el dato que se desea buscar\n");
        free(data.arreglo);
        return 2;
    }
    
    // busqueda_secuencial(&data, )

    free(data.arreglo);
    return 0;
}