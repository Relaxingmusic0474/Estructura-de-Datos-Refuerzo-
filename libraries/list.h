#ifndef LIST_H
#define LIST_H

#include "data.h"
#include "types.h"

#define min(x, y) ((x < y) ? x : y)
#define max(x, y) ((x > y) ? x : y)

typedef struct nodo Nodo, NodoCircular;
typedef struct nodoDoble NodoDoble, NodoDobleCircular;
typedef struct lista Lista, ListaCircular;  // Para que sirva la misma estructura para lista y lista circular
typedef struct listaDoble ListaDoble, ListaDobleCircular;  // Para que sirva la misma estructura para lista doble y lista doble circular

struct nodo
{
    ElemType dato;
    Nodo* siguiente;
};

struct lista
{
    Nodo* cabeza;
};

struct nodoDoble
{
    ElemType dato;
    NodoDoble* siguiente;
    NodoDoble* anterior;
};

struct listaDoble
{
    NodoDoble* cabeza;
};

/* ------------ FUNCIONES PARA LISTAS ENLAZADAS SIMPLES ----------- */
bool crear_lista_vacia(Lista* lista);
bool crear_lista(Lista* lista, Natural nro_elementos);
Nodo* nodo_k_esimo(Lista lista, Index k);
bool insertar_nodo(Lista* lista, ElemType valor, Index posicion);
bool insertar_nodo_inicio(Lista* lista, ElemType valor);
bool insertar_nodo_final(Lista* lista, ElemType valor);
Procedure modificar_nodo(Lista* lista, Index posicion, ElemType valor);
Index buscar_valor_en_lista(Lista* lista, ElemType valor_buscado);
Procedure imprimir_lista(Lista lista);
Natural tamanho_lista(Lista lista);
Procedure eliminar_nodo(Lista* lista, Index posicion);
Procedure eliminar_nodo_inicio(Lista* lista);
Procedure eliminar_nodo_final(Lista* lista);
Procedure eliminar_lista(Lista* lista, bool liberar);
Procedure vaciar_lista(Lista* lista);
bool esta_vacia(Lista lista);
Procedure intercambiar_nodos(Lista* lista, Index posicion1, Index posicion2);
Procedure invertir_lista(Lista* lista);
/* --------------------------------------------------------------- */


/* ----------- FUNCIONES PARA LISTAS ENLAZADAS DOBLES ------------ */
bool crear_lista_doble(ListaDoble* lista, Natural nro_elementos);
NodoDoble* nodo_doble_k_esimo(ListaDoble lista, Index k);
bool insertar_nodo_doble(ListaDoble* lista, ElemType valor, Index posicion);
bool insertar_nodo_doble_inicio(ListaDoble* lista, ElemType valor);
bool insertar_nodo_doble_final(ListaDoble* lista, ElemType valor);
Procedure modificar_nodo_doble(ListaDoble* lista, Index posicion, ElemType valor);
Index buscar_valor_en_lista_doble(ListaDoble* lista, ElemType valor_buscado);
Procedure imprimir_lista_doble(ListaDoble lista, bool invertida);
Natural tamanho_lista_doble(ListaDoble lista);
Procedure eliminar_nodo_doble(ListaDoble* lista, Index posicion);
Procedure eliminar_nodo_doble_inicio(ListaDoble* lista);
Procedure eliminar_nodo_doble_final(ListaDoble* lista);
Procedure eliminar_lista_doble(ListaDoble* lista);
/* --------------------------------------------------------------- */


/* --------- FUNCIONES PARA LISTAS ENLAZADAS CIRCULARES ---------- */
bool crear_lista_circular(ListaCircular* lista, Natural nro_elementos);
bool insertar_nodo_circular(ListaCircular* lista, ElemType valor, Index posicion);
Procedure imprimir_lista_circular(ListaCircular lista);
Procedure eliminar_lista_circular(ListaCircular* lista);
/* --------------------------------------------------------------- */

#endif  // LIST_H