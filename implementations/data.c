#include "../libraries/data.h"

/**
 * @brief Función que detecta si una cadena es convertible a número decimal.
 * @param str Cadena a verificar.
 * @param len Longitud de la cadena a verificar.
 * @return true si es posible leerlo como nro decimal, false en caso contrario.
 */
bool es_decimal(char* str, size_t len)
{
    Natural i = 0;
    Natural puntos = 0;

    if (!str || len == 0) 
    {
        return false;
    }
    
    // Permitir signo negativo al inicio
    if (str[0] == '-') 
    {
        i++;
    }

    for (i=i; i<len; i++) 
    {
        if (str[i] == '.') 
        {
            puntos++;

            if (puntos > 1) 
            {
                return false;  // Solo un punto permitido
            } 
        } 
        
        else if (!es_caracter_numerico(str[i])) 
        {
            return false;
        }
    }

    return (puntos == 1 && len > 1);  // Debe tener exactamente un punto y al menos un dígito antes o después
}

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
 * @brief Función que clasifica un dato según tipo.
 * @param dato El dato que se quiere clasificar.
 * @param str_representativo La cadena (string) que representa al dato (ej: "3.1416").
 * @param posicion_inicial Posición inicial en la cual se desea inicializar el dato (normalmente respecto a un arreglo).
 */
Procedure clasificar_dato(Dato* dato, char* str_representativo, Index posicion_inicial)
{
    int entero;
    double real;
    Tipo tipo;

    dato->elemento.tipo = DESCONOCIDO;
    dato->elemento.valor = (Casilla) {0};
    dato->elemento.valor_double = DOUBLE_NO_VALIDO;
    dato->posicion = posicion_inicial;
    dato->encontrado = false;

    entero = atoi(str_representativo);
    real = atof(str_representativo);

    if (es_decimal(str_representativo, strlen(str_representativo)))
    {
        dato->elemento.tipo = REAL;
        dato->elemento.valor.real = real;
    }

    else
    {
        if (entero == 0)
        {
            if (strcmp(str_representativo, "0") == 0)
            {
                dato->elemento.tipo = NATURAL;
                dato->elemento.valor.natural = 0;
            }

            else if (strcmp(str_representativo, "-0") == 0)
            {
                dato->elemento.tipo = ENTERO;
                dato->elemento.valor.entero = 0;
            }

            else
            {
                dato->elemento.tipo = CADENA;
                strncpy(dato->elemento.valor.cadena, str_representativo, LARGO-1);
            }
        }

        else
        {
            if (entero >= 0 && entero <= USHRT_MAX)
            {
                dato->elemento.tipo = NATURAL;
                dato->elemento.valor.natural = (Natural) entero;
            }   

            else
            {
                dato->elemento.tipo = ENTERO;
                dato->elemento.valor.entero = entero;
            }
        }
    }

    if (es_numerico(*dato))
    {
        tipo = dato->elemento.tipo;

        switch (tipo)
        {
            case ENTERO:
                dato->elemento.valor_double = (double) dato->elemento.valor.entero;
                break;

            case NATURAL:
                dato->elemento.valor_double = (double) dato->elemento.valor.natural;
                break;

            default:
                dato->elemento.valor_double = dato->elemento.valor.real;
                break;
        }
    }

    else
    {
        if (dato->elemento.tipo == CARACTER)
        {
            dato->elemento.valor_double = (double) ((int) dato->elemento.valor.caracter);
        }

        else  // CADENA o DESCONOCIDO
        {
            dato->elemento.valor_double = DOUBLE_NO_VALIDO;
        }
    }   
}

/**
 * @brief Función que detecta si todas las entradas son caracteres.
 * @param datos Los datos de entrada.
 * @return true si todas las entradas son de longitud 1 (char), false en caso contrario.
 */
bool son_caracteres_las_entradas(Datos* datos)
{
    Natural i;

    if (validacion_datos_uniforme(datos))
    {
        for (i=0; i<datos->tamanho; i++)
        {
            if (!(datos->arreglo[i].elemento.tipo == CADENA && strlen(datos->arreglo[i].elemento.valor.cadena) == 1))
            {
                return false;
            }
        }

        return true;
    }

    return false;
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
    Tipo tipo = DESCONOCIDO;
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
        clasificar_dato(&datos->arreglo[i], argv[i+1], i);
    }

    if (son_caracteres_las_entradas(datos))
    {
        for (j=0; j<tam; j++)
        {
            datos->arreglo[j].elemento.tipo = CARACTER;
            datos->arreglo[j].elemento.valor = (Casilla) {0};  // Se limpia
            datos->arreglo[j].elemento.valor.caracter = argv[j+1][0];
            datos->arreglo[j].elemento.valor_double = (double) ((int) (argv[j+1][0])); 
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

Procedure imprimir_datos(Datos datos)
{
    Natural i;
    Tipo tipo = DESCONOCIDO;

    for (i=0; i<datos.tamanho; i++)
    {
        tipo = datos.arreglo[i].elemento.tipo;

        switch (tipo)
        {
            case ENTERO:
                printf("%i\t", datos.arreglo[i].elemento.valor.entero);
                break;
            
            case NATURAL:
                printf("%hu\t", datos.arreglo[i].elemento.valor.natural);
                break;

            case REAL:
                printf("%.2f\t", datos.arreglo[i].elemento.valor.real);
                break;

            case CARACTER:
                printf("%c\t", datos.arreglo[i].elemento.valor.caracter);
                break;

            case CADENA:
                printf("%s\t", datos.arreglo[i].elemento.valor.cadena);
                break;

            default:
                printf("ERROR: Dato no válido\t");
                return;
        }
    }

    printf("\n");
}

/**
 * @brief Función que compara 2 metadatos.
 * @param dato1 Dato 1 a comparar.
 * @param dato2 Dato 2 a comparar.
 * @return Un número positivo si dato1 > dato2, y uno negativo (o 0) en caso contrario.
 */
int comparar_metadatos(Dato* dato1, Dato* dato2)
{
    if (dato1->elemento.tipo == CADENA && dato2->elemento.tipo == CADENA)
    {
        return strcmp(dato1->elemento.valor.cadena, dato2->elemento.valor.cadena);
    }

    else
    {
        if ((es_numerico(*dato1) && es_numerico(*dato2)) || (dato1->elemento.tipo == CARACTER && dato2->elemento.tipo == CARACTER))
        {
            return (dato1->elemento.valor_double - dato2->elemento.valor_double);
        }

        else
        {
            return INT_MAX;  // Es como una forma de simular el error
        }
    }
}

/**
 * @brief Función diseñada para encajar con qsort.
 * @param a Primer elemento a comparar.
 * @param b Segundo elemento a comparar.
 * @return El resultado de la función comparar_metadatos.
 */
int comparar_qsort(const void* a, const void* b)
{
    Dato* dato1 = (Dato*) a;
    Dato* dato2 = (Dato*) b;
    return comparar_metadatos(dato1, dato2);
}