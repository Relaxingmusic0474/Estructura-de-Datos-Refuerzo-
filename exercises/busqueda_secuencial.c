#include "../libraries/searching.h"

int main(int argc, char* argv[])
{
    Natural i, j;
    Datos data = {0};
    Dato dato_buscado = {.elemento = {.tipo = DESCONOCIDO, .valor = 0, .valor_double = DOUBLE_NO_VALIDO}, .encontrado = false, .posicion = INDEX_NO_VALIDO};
    char valor[LARGO];

    if (!leer_datos_input(argc, argv, &data))  // Se leen e interpretan los datos de entrada
    {
        printf("Uso: %s <lista de datos>\n", argv[0]);
        return 1;
    }

    printf("- Ingrese el valor que desea buscar: ");

    if (scanf("%19s", valor) != 1)
    {
        printf("Error al ingresar el dato que se desea buscar\n");
        free(data.arreglo);
        return 2;
    }

    clasificar_dato(&dato_buscado, valor, INDEX_NO_VALIDO);

    if (son_caracteres_las_entradas(&data))
    {
        if (strlen(valor) == 1)
        {
            dato_buscado.elemento.tipo = CARACTER;
            dato_buscado.elemento.valor = (Casilla) {0};
            dato_buscado.elemento.valor.caracter = valor[0];
            dato_buscado.elemento.valor_double = (double) ((int) valor[0]);
        }
    }

    busqueda_secuencial(&data, &dato_buscado);

    if (dato_buscado.encontrado)
    {
        printf("- Dato encontrado en la posicion %hu del arreglo de metadatos.\n", dato_buscado.posicion);
    }

    else
    {
        printf("- Dato no encontrado en el arreglo de metadatos\n");
    }

    free(data.arreglo);
    return 0;
}