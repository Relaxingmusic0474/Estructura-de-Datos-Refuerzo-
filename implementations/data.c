#include "../libraries/data.h"

/**
 * @brief Función que detecta si una cadena es convertible a número decimal.
 * 
 */

/**
 * @brief Función que valida si un caracter es numérico o no.
 * @param ch Caracter que se desea validar.
 * @return true si es numérico, false en caso contrario.
 */
bool es_caracter_numerico(char ch)
{
    return ch >= '0' && ch <= '9';
}

/**
 * @brief Función para leer y crear los datos que ingresa el usuario en forma dinámica.
 * @param argc Cantidad de argumentos.
 * @param argv Arreglo de argumentos.
 * @param datos Estructura donde se almacenarán los datos leídos (aquí se irán creando).
 * @return true en caso que se haya ingresado datos y no haya error en asignación de memoria, false en caso contrario.
 */
bool leer_datos_input(int argc, char* argv[], Datos* datos)
{
    Natural i, j;
    Natural tam = argc-1;
    int entero = 0;
    double real = 0;
    bool es_real = true;
    char* subcadena_positiva = NULL;
    char* subcadena_negativa = NULL;
    char* subcadena = NULL;
    char* ptr = NULL;

    if (!datos)
    {
        printf("Error: Datos es NULL.\n");
        return false;
    }

    if (argc < 2)
    {
        printf("No se ingresaron datos.\n");
        return false;
    }

    datos->tamanho = 0;
    datos->arreglo = (Dato*) calloc(tam, sizeof(Dato));

    if (!datos->arreglo)
    {
        printf("Error de asignación de memoria.\n");
        return false;
    }

    datos->tamanho = tam;
    datos->ordenado = false;

    for (i=0; i<tam; i++)
    {
        datos->arreglo[i].elemento.tipo = DESCONOCIDO;
        datos->arreglo[i].elemento.valor = (Casilla) {0};
        datos->arreglo[i].posicion = i;
        datos->arreglo[i].encontrado = false;

        entero = atoi(argv[i+1]);
        real = atof(argv[i+1]);

        if (entero == 0)  // Dos posibilidades (es 0 o realmente no se puede convertir a entero)
        {
            if (strcmp(argv[i+1], "0") == 0)  // Aquí significa que realmente es un Natural y es 0
            {
                datos->arreglo[i].elemento.tipo = NATURAL;
                datos->arreglo[i].elemento.valor.natural = 0;
            }

            else
            {
                if (real == 0)  // Dos posibilidades (es 0 real o realmente no se puede convertir a real)
                {
                    subcadena_positiva = strstr(argv[i+1], "0.");
                    subcadena_negativa = strstr(argv[i+1], "-0.");

                    if ((subcadena_positiva && strcmp(subcadena_positiva, argv[i+1]) == 0) ||
                        (subcadena_negativa && strcmp(subcadena_negativa, argv[i+1]) == 0))
                    {
                        subcadena = strchr(argv[i+1], '.');

                        if (strcmp(subcadena, ".") == 0)
                        {
                            datos->arreglo[i].elemento.tipo = REAL;
                            datos->arreglo[i].elemento.valor.real = (double) 0;
                            continue;
                        }

                        else
                        {
                            if (strlen(subcadena) >= 2)
                            {
                                ptr = &subcadena[1];
                            }
                        }

                        es_real = true;

                        if (ptr)
                        {
                            while (es_real && *ptr)
                            {
                                if (!es_caracter_numerico(*ptr))
                                {
                                    es_real = false;
                                    datos->arreglo[i].elemento.tipo = CADENA;
                                    strncpy(datos->arreglo[i].elemento.valor.cadena, argv[i+1], LARGO-1);
                                }

                                ptr++;
                            }
                        }

                        if (es_real)
                        {
                            datos->arreglo[i].elemento.tipo = REAL;
                            datos->arreglo[i].elemento.valor.real = (double) 0;
                        }
                    }
                }

                else
                {
                    datos->arreglo[i].elemento.tipo = REAL;
                    datos->arreglo[i].elemento.valor.real = real;
                }
            }
        }

        else
        {
            if (entero >= 0 && entero <= USHRT_MAX)
            {
                datos->arreglo[i].elemento.tipo = NATURAL;
                datos->arreglo[i].elemento.valor.natural = (Natural) entero;
            }

            else
            {
                datos->arreglo[i].elemento.tipo = ENTERO;
                datos->arreglo[i].elemento.valor.entero = entero;
            }
        }
    }

    if (validacion_datos_uniforme(datos))
    {
        for (i=0; i<tam; i++)
        {
            if (es_alpha(datos->arreglo[i]))
            {
                if (strlen(datos->arreglo[i].elemento.valor.cadena) != 1)
                {
                    return true;
                }

                else
                {
                    if (i==tam-1)
                    {
                        for (j=0; j<tam; j++)
                        {
                            datos->arreglo[j].elemento.tipo = CARACTER;
                            datos->arreglo[j].elemento.valor = (Casilla) {0};  // Se limpia
                            datos->arreglo[j].elemento.valor.caracter = argv[j+1][0];
                        }   
                    }
                }
            }
        }
    }

    return true;
}

/**
 * @brief Función que valida si un dato es numérico.
 * @param dato El dato a validar.
 * @return true si lo es, false en caso contrario.
 */
bool es_numerico(Dato dato)
{
    Elemento variable = dato.elemento;
    return (variable.tipo == ENTERO || variable.tipo == NATURAL || variable.tipo == REAL);
}

/**
 * @brief Función que valida si un dato es alfabético (carácter o cadena).
 * @param dato El dato a validar.
 * @return true si lo es, false en caso contrario.
 */
bool es_alpha(Dato dato)
{
    Elemento variable = dato.elemento;
    return (variable.tipo == CARACTER || variable.tipo == CADENA);
}

/**
 * @brief Función que valida si todos los datos en el arreglo son de la misma gran categoría (numéricos o alfabéticos).
 * @param datos Estructura que contiene el arreglo y su tamaño, además de un indicador de si está ordenado o no.
 * @return true si todos los datos son de la misma categoría, false en caso contrario.
 */
bool validacion_datos_uniforme(Datos* datos)
{
    Natural i, j;
    Tipo tipo_base;
    bool base_numerica;
    bool base_alpha;

    if (datos->tamanho == 0)  // El tamaño siempre es mayor o igual a 0 (Natural), nunca será menor, ya que por ejemplo -1 = 65535
    {
        return false;
    }

    tipo_base = datos->arreglo[0].elemento.tipo;
    base_numerica = es_numerico(datos->arreglo[0]);
    base_alpha = es_alpha(datos->arreglo[0]);

    if (!base_numerica && !base_alpha)  // Verifica que sea numérico o alfabético (no tipo personalizado, ya que no habría cómo ordenarlo)
    {
        return false;
    }

    for (i=1; i<datos->tamanho; i++)
    {
        if (base_numerica)
        {
            if (!es_numerico(datos->arreglo[i]))
            {
                return false;  // Basta que uno no sea de la categoría base, para que el arreglo no sea válido para ordenar
            }
        }

        else  // Si la base no es numérica, ya sabemos que es alpha, porque ahora otras opciones están descartadas al inicio
        {
            if (!es_alpha(datos->arreglo[i]))
            {
                return false;  // Basta que uno no sea de la categoría base, para que el arreglo no sea válido para ordenar
            }
        }
    }

    return true;
}