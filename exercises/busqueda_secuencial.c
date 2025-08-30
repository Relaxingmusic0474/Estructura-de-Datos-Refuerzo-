#include "../libraries/searching.h"

int main(int argc, char* argv[])
{
    Natural i;
    char* nro = "-0";
    Datos data = {0};

    if (!leer_datos_input(argc, argv, &data))
    {
        printf("Uso: %s <lista de datos>\n", argv[0]);
        return 1;
    }

    printf("data.tamanho = %hu\n", data.tamanho);

    for (i=0; i<data.tamanho; i++)
    {
        printf("- Tipo elemento %hu: %i\n", i, data.arreglo[i].elemento.tipo);
    }

    free(data.arreglo);
    return 0;
}