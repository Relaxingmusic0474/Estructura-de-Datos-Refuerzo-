#include "../../../../libraries/tree.h"
#include "time.h"

int main()
{
    srand(time(NULL));

    Natural n = 32000;

    ElemType* array = malloc(n * sizeof(ElemType));

    for (Natural i = 0; i < n; i++)
    {
        array[i] = rand() % 100000;
    }

    Heap heap = {0};

    construir_heap(&heap, MAX_HEAP, array, n);

    heapsort(&heap);

    eliminar_heap(&heap);
    free(array);

    return 0;
}
