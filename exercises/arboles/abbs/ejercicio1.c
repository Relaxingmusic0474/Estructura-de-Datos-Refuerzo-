#include "../../../libraries/tree.h"

int main()
{
    ABB abb;
    inicializar_abb(&abb);
    agregar_dato_al_abb(15, &abb);
    printf("- Preorden: ");
    preorden(abb, abb.raiz);
    printf("\n- Inorden: ");
    inorden(abb, abb.raiz);
    agregar_dato_al_abb(23, &abb);
    printf("\n\n- Preorden: ");
    preorden(abb, abb.raiz);
    printf("\n- Inorden: ");
    inorden(abb, abb.raiz);
    agregar_dato_al_abb(2, &abb);
    printf("\n\n- Preorden: ");
    preorden(abb, abb.raiz);
    printf("\n- Inorden: ");
    inorden(abb, abb.raiz);
    agregar_dato_al_abb(17, &abb);
    printf("\n\n- Preorden: ");
    preorden(abb, abb.raiz);
    printf("\n- Inorden: ");
    inorden(abb, abb.raiz);
    agregar_dato_al_abb(20, &abb);
    printf("\n\n- Preorden: ");
    preorden(abb, abb.raiz);
    printf("\n- Inorden: ");
    inorden(abb, abb.raiz);
    agregar_dato_al_abb(8, &abb);
    printf("\n\n- Preorden: ");
    preorden(abb, abb.raiz);
    printf("\n- Inorden: ");
    inorden(abb, abb.raiz);
    vaciar_abb(&abb);
    printf("\n");
    return 0;
}