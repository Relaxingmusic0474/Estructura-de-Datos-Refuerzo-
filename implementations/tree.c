#include "../libraries/tree.h"

/* ------------------------------------- FUNCIÓN SWAP ------------------------------------- */
/**
 * @brief Función para intercambiar dos elementos.
 * @param a El primer elemento a intercambiar.
 * @param b El segundo elemento a intercambiar.
 */
Procedure swap(ElemType* a, ElemType* b)
{
    ElemType aux = *a;
    *a = *b;
    *b = aux;
}


/* --------------------------------- FUNCIONES PARA HEAPS --------------------------------- */
/**
 * @brief Función para crear un heap.
 * @param heap El heap a crear.
 * @param tipo El tipo de heap (maxheap o minheap).
 * @param capacidad La capacidad que inicialmente tendrá el heap.
 * @return true si se logró crear el heap correctamente, false en caso contrario.
 */
bool crear_heap(Heap* heap, TipoHeap tipo, Natural capacidad)
{
    if (tipo != MIN_HEAP && tipo != MAX_HEAP)
    {
        printf("Error: No se pudo crear el heap, porque el tipo ingresado de inicialización no es válido.\n");
        return false;
    }

    heap->tipo = tipo;
    heap->tamanho = 0;
    heap->capacidad = capacidad;

    heap->elementos = (ElemType *) calloc(heap->capacidad, sizeof(ElemType));

    if (!heap->elementos)
    {
        printf("Error de asignación de memoria al crear el heap solicitado.\n");
        heap->tipo = HEAP_NO_VAL;
        heap->capacidad = 0;
        return false;
    }
    
    return true;
}

/**
 * @brief Función para construir un heap a partir de un arreglo de elementos.
 * @param heap El heap a construir.
 * @param tipo El tipo de heap a construir (maxheap o minheap).
 * @param array El arreglo o puntero con los elementos que se quieren poner en el heap.
 * @param tamanho El tamaño del arreglo.
 * @return true si se logró construir correctamente el heap, false en caso contrario.
 */
bool construir_heap(Heap* heap, TipoHeap tipo, ElemType array[], Natural tamanho)
{
    if (!crear_heap(heap, tipo, tamanho))
    {
        return false;
    }

    for (Natural i=0; i<tamanho; i++)
    {
        heap->elementos[i] = array[i];
    }

    heap->tamanho = tamanho;
    amontonar_heap_completo(heap);
    return true;
}

/**
 * @brief Función para redimensionar un heap.
 * @param heap El heap a redimensionar.
 * @param nueva_capacidad La capacidad nueva que soportará el heap.
 * @return true si fue posible redimensionar el heap sin errores, false en caso de error.
 */
bool redimensionar_heap(Heap* heap, Natural nueva_capacidad)
{
    if (!heap)
    {
        printf("Error: El heap no existe.\n");
        return false;
    }

    if (heap->capacidad == nueva_capacidad)
    {
        return true;  // No se hace nada si la capacidad es la misma
    }

    if (nueva_capacidad == 0)
    {
        eliminar_heap(heap);
        return true; 
    }

    ElemType* heap_elems = realloc(heap->elementos, nueva_capacidad * sizeof(ElemType));

    if (!heap_elems)
    {
        printf("Advertencia: No se pudo redimensionar el heap.\n");
        // El heap original no se libera para que se puedan seguir haciendo otro tipo de operaciones en él
        return false;
    }

    if (heap->capacidad < nueva_capacidad)
    {
        for (Natural i=heap->capacidad; i<nueva_capacidad; i++)
        {
            heap_elems[i] = 0;  // Se inicializan en 0 los nuevos elementos, pero simplemente para que no haya basura
        }
    }

    else
    {
        if (heap->capacidad > nueva_capacidad)
        {
            printf("Advertencia: La nueva capacidad del heap será menor, por lo que se truncará.\n");

            if (heap->tamanho > nueva_capacidad)
            {
                heap->tamanho = nueva_capacidad;
            }
        }
    }

    heap->elementos = heap_elems;
    heap->capacidad = nueva_capacidad;
    return true;
}

/**
 * @brief Función para amontonar un heap en que sus elementos se han insertado de forma secuencial.
 * @param heap El heap a amontonar.
 */
Procedure amontonar_heap_secuencial(Heap* heap)
{
    if (!heap || !heap->elementos)
    {
        printf("Error: El heap o sus elementos son NULL.  No puede amontonarse.\n");
        return;
    }

    if (heap->tipo == HEAP_NO_VAL)
    {
        printf("Error: Tipo de heap no válido.  No se puede amontonar.\n");
        return;
    }

    if (heap->tamanho == 0 || heap->tamanho == 1)
    {
        return;  // Heap vacío o con un solo elemento -> No se hace nada
    }

    Index indice_analisis = heap->tamanho-1;  // Este será el índice de análisis inicial

    while (indice_analisis > 0 &&
          ((heap->tipo == MAX_HEAP && heap->elementos[indice_analisis] > heap->elementos[PADRE(indice_analisis)]) ||
          (heap->tipo == MIN_HEAP && heap->elementos[indice_analisis] < heap->elementos[PADRE(indice_analisis)])))
    {
        // Aquí se hace el intercambio
        swap(&heap->elementos[indice_analisis], &heap->elementos[PADRE(indice_analisis)]);
        indice_analisis = PADRE(indice_analisis);
    }

    return;
}

/**
 * @brief Función para amontonar un heap (mantener su propiedad dependiendo de su tipo).
 * @param heap El heap a amontonar.
 */
Procedure amontonar_heap_completo(Heap* heap)
{
    if (!heap || !heap->elementos)
    {
        printf("Error: El heap o sus elementos son NULL.  No puede amontonarse.\n");
        return;
    }

    if (heap->tipo == HEAP_NO_VAL)
    {
        printf("Error: Tipo de heap no válido.  No puede amontonarse.\n");
        return;
    }

    if (heap->tamanho == 0 || heap->tamanho == 1)
    {
        return;  // Heap vacío o con un solo elemento -> No hace nada
    }

    Index indice = (heap->tamanho-1) >> 1;
    
    while (true)
    {
        Index posicion = indice;
        bool salir = false;
        
        while (!salir)
        {
            Index hijo_izquierdo = HIJO_IZQUIERDO(posicion);
            Index hijo_derecho = HIJO_DERECHO(posicion);
            
            if (hijo_izquierdo >= heap->tamanho)  //  No existe ninguno de los dos hijos
            {
                salir = true;
            }

            else if (hijo_derecho >= heap->tamanho)  // Solo hijo izquierdo existe
            {
                //if (posicion <= ((heap->tamanho-1) >> 1))
                //{
                if ((heap->tipo == MAX_HEAP && heap->elementos[posicion] < heap->elementos[hijo_izquierdo]) ||
                    (heap->tipo == MIN_HEAP && heap->elementos[posicion] > heap->elementos[hijo_izquierdo]))
                {
                    swap(&heap->elementos[posicion], &heap->elementos[hijo_izquierdo]);
                    posicion = hijo_izquierdo;
                }
                
                else
                {
                    salir = true;
                }
                //}
            }

            else  // Ambos hijos existen
            {
                Index hijo_X;
                
                if (heap->tipo == MAX_HEAP)
                {
                    hijo_X = (MAX(heap->elementos[hijo_izquierdo], heap->elementos[hijo_derecho]) == heap->elementos[hijo_izquierdo]) ? hijo_izquierdo : hijo_derecho;
                }

                else  // MIN_HEAP
                {
                    hijo_X = (MIN(heap->elementos[hijo_izquierdo], heap->elementos[hijo_derecho]) == heap->elementos[hijo_izquierdo]) ? hijo_izquierdo : hijo_derecho;
                }
                
                //if (posicion <= ((heap->tamanho-1) >> 1))
                //{
                if ((heap->tipo == MAX_HEAP && heap->elementos[posicion] < heap->elementos[hijo_X]) ||
                    (heap->tipo == MIN_HEAP && heap->elementos[posicion] > heap->elementos[hijo_X]))
                {
                    swap(&heap->elementos[posicion], &heap->elementos[hijo_X]);
                    posicion = hijo_X;
                }
                    
                else
                {
                    salir = true;
                }
                //}                
            }
        }

        if (indice == 0)
        {
            break;
        }

        indice--;
    }
}

/**
 * @brief Función para amontonar un heap partiendo desde arriba, "eliminando" el nodo raíz, intercambiándolo con el último elemento e ir acomodándolos secuencialmente.
 * @param heap El puntero al heap a amontonar.
 */
Procedure amontonar_heap_hacia_abajo(Heap* heap)
{
    if (!heap || !heap->elementos)
    {
        printf("Error: El heap o sus elementos son NULL.  No puede amontonarse.\n");
        return;
    }

    if (heap->tipo == HEAP_NO_VAL)
    {
        printf("Error: Tipo de heap no válido.  No puede amontonarse.\n");
        return;
    }

    if (heap->tamanho == 0 || heap->tamanho == 1)
    {
        return;  // Heap vacío o con un solo elemento -> No hace nada
    }
    

}

/**
 * @brief Ordena un heap.
 * @param heap El puntero al heap a ordenar.
 */
Procedure heapsort(Heap* heap)
{
    if (!heap || !heap->elementos)
    {
        printf("Error: El heap o sus elementos son NULL.  No puede ordenarse.\n");
        return;
    }

    if (heap->tipo == HEAP_NO_VAL)
    {
        printf("Error: Tipo de heap no válido.  No puede ordenarse.\n");
        return;
    }

    if (heap->tamanho == 0 || heap->tamanho == 1)
    {
        return;  // Heap vacío o con un solo elemento -> No hace nada
    }

    amontonar_heap_completo(heap);

    Natural tamanho = heap->tamanho;

    while (heap->tamanho != 1)
    {
        swap(&heap->elementos[0], &heap->elementos[heap->tamanho-1]);

        heap->tamanho--;

        Index hijo_izquierdo = 1, hijo_derecho = 2;

        while (hijo_izquierdo < heap->tamanho)
        {
            Index padre = PADRE(hijo_izquierdo);
            Index hijoX = hijo_izquierdo;
            
            if (hijo_derecho < heap->tamanho)
            {
                if (heap->tipo == MAX_HEAP)
                {
                    hijoX = (heap->elementos[hijo_izquierdo] >= heap->elementos[hijo_derecho]) ?  hijo_izquierdo : hijo_derecho;
                }

                else  // MIN_HEAP
                {
                    hijoX = (heap->elementos[hijo_izquierdo] <= heap->elementos[hijo_derecho]) ? hijo_izquierdo : hijo_derecho;
                }    
            }

            if (heap->tipo == MAX_HEAP)
            {
                if (heap->elementos[padre] < heap->elementos[hijoX])
                {
                    swap(&heap->elementos[padre], &heap->elementos[hijoX]);
                    padre = hijoX;
                    hijo_izquierdo = HIJO_IZQUIERDO(padre);
                    hijo_derecho = HIJO_DERECHO(padre);
                }

                else
                {
                    break;
                }
            }

            else  // MIN_HEAP
            {
                if (heap->elementos[padre] > heap->elementos[hijoX])
                {
                    swap(&heap->elementos[padre], &heap->elementos[hijoX]);
                    padre = hijoX;
                    hijo_izquierdo = HIJO_IZQUIERDO(padre);
                    hijo_derecho = HIJO_DERECHO(padre);
                }

                else
                {
                    break;
                }
            }
        }
    }

    heap->tamanho = tamanho;  // Se restaura el tamaño original del heap
}

/**
 * @param dato Dato que se desea insertar en el heap.
 * @param heap Heap en el que se quiere insertar el dato.
 * @return true si se insertó correctamente, false en caso contrario.
 */
bool insertar_dato_heap(ElemType dato, Heap* heap)
{
    if (!heap || !heap->elementos)
    {
        printf("Error: El heap es NULL o bien aún no está creado.  No es posible la inserción.\n");
        return false;
    }

    if (heap->tamanho >= heap->capacidad)  // Cuando se alcanza la capacidad máxima
    {
        Natural nueva_capacidad = 2*heap->capacidad;

        if (!redimensionar_heap(heap, nueva_capacidad))
        {
            printf("Error: No se pudo insertar el dato correctamente.\n");
            return false;
        }

        heap->elementos[heap->capacidad] = dato;
        heap->tamanho++;
        heap->capacidad = nueva_capacidad;
    }

    else
    {
        heap->elementos[heap->tamanho] = dato;
        heap->tamanho++;
    }

    amontonar_heap_secuencial(heap);  // El nuevo elemento se acomoda en donde corresponde, para no perder la propiedad de heap.
    return true;
}

/**
 * @brief Función para describir un heap, para que su representación visual sea fácil de dibujar o imaginar.
 * @param heap El heap a imprimir.
 */
Procedure imprimir_heap(Heap heap)
{
    if (!heap.elementos)
    {
        printf("Error: No se pudo imprimir el heap ya que aún no está creado.\n");
        return;
    }

    Index hijo_izq, hijo_der;

    for (Natural i=0; i<heap.tamanho; i++)
    {
        printf("Elemento: %d  ->  ", heap.elementos[i]);

        hijo_izq = HIJO_IZQUIERDO(i);
        hijo_der = HIJO_DERECHO(i);
        
        if (hijo_izq < heap.tamanho)
        {
            printf("Hijo izquierdo: %d", heap.elementos[hijo_izq]);
        }

        if (hijo_der < heap.tamanho)
        {
            printf(", Hijo derecho: %d", heap.elementos[hijo_der]);
        }

        printf("\n");
    }
}

/**
 * @brief Función para eliminar un heap, liberando su memoria.
 * @param heap El heap a eliminar.
 */
Procedure eliminar_heap(Heap* heap)
{
    if (!heap)
    {
        printf("Error: No se pudo eliminar el heap ya que es NULL\n");
        return;
    }

    free(heap->elementos);
    heap->elementos = NULL;
    heap->tamanho = 0;
    heap->capacidad = 0;
    heap->tipo = HEAP_NO_VAL;
}

/**
 * @brief Función que deja vacío el heap, con puros datos 0.
 * @param heap El heap a vaciar.
 */
Procedure vaciar_heap(Heap* heap)
{
    if (!heap->elementos || heap->capacidad == 0)
    {
        printf("Error: El heap aún no ha sido creado, por lo tanto, no se puede vaciar.\n");
        return;
    }

    for (Natural i=0; i<heap->tamanho; i++)
    {
        heap->elementos[i] = 0;
    }
}

