#include "../../libraries/sorting.h"

int main(int argc, char* argv[])
{
    Datos data = {0};

    if (!leer_datos_input(argc, argv, &data)) {
        printf("Uso: %s <lista de datos>\n", argv[0]);
        return 1;
    }

    mergesort(&data, false);
    printf("Datos ordenados:\n");
    imprimir_datos(data);
    free(data.arreglo);
    return 0;
}