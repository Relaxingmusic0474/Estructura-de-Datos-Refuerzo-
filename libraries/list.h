#ifndef LIST_H
#define LIST_H

#include "data.h"
#include "types.h"

#define min(x, y) ((x < y) ? x : y)
#define max(x, y) ((x > y) ? x : y)

typedef struct nodo Nodo, NodoCircular;
typedef struct nodoDoble NodoDoble, NodoDobleCircular;
typedef struct lista Lista, ListaCircular;
typedef struct listaDoble ListaDoble;
typedef struct listaDobleCircular ListaDobleCircular;

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

struct listaDobleCircular
{
    NodoDobleCircular* cabeza;
    Natural tamanho;  // Este campo de la estructura se añadió por eficiencia
};

/* ------------ FUNCIONES PARA LISTAS ENLAZADAS SIMPLES ----------- */
Procedure inicializar_lista(Lista* lista);
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
bool crear_lista_circular_vacia(ListaCircular* lista);
bool crear_lista_circular(ListaCircular* lista, Natural nro_elementos);
bool insertar_nodo_circular(ListaCircular* lista, ElemType valor, Index posicion);
bool insertar_nodo_circular_inicio(ListaCircular* lista, ElemType valor);
bool insertar_nodo_circular_final(ListaCircular* lista, ElemType valor);
Procedure modificar_nodo_circular(ListaCircular* lista, Index posicion, ElemType valor);
Index buscar_valor_en_lista_circular(ListaCircular* lista, ElemType valor_buscado);
Procedure imprimir_lista_circular(ListaCircular lista);
Natural tamanho_lista_circular(ListaCircular lista);
Procedure eliminar_nodo_circular(ListaCircular* lista, Index posicion);
Procedure eliminar_nodo_circular_inicio(ListaCircular* lista);
Procedure eliminar_nodo_circular_final(ListaCircular* lista);
Procedure eliminar_lista_circular(ListaCircular* lista, bool liberar);
Procedure vaciar_lista_circular(ListaCircular* lista);
bool es_circular_vacia(ListaCircular lista);
Procedure rotacion_izquierda_lista_circular(ListaCircular* lista);
Procedure rotacion_derecha_lista_circular(ListaCircular* lista);
/* --------------------------------------------------------------- */


/* ------ FUNCIONES PARA LISTAS ENLAZADAS CIRCULARES DOBLES ------ */
bool crear_lista_circular_doble(ListaDobleCircular* lista, Natural nro_elementos);
NodoDobleCircular* nodo_circular_doble_k_esimo(ListaDobleCircular lista, Index k);
bool insertar_nodo_circular_doble(ListaDobleCircular* lista, ElemType valor, Index posicion);
bool insertar_nodo_circular_doble_inicio(ListaDobleCircular* lista, ElemType valor);
bool insertar_nodo_circular_doble_final(ListaDobleCircular* lista, ElemType valor);
Procedure modificar_nodo_circular_doble(ListaDobleCircular* lista, Index posicion, ElemType valor);
Index buscar_valor_en_lista_circular_doble(ListaDobleCircular* lista, ElemType valor_buscado);
Procedure imprimir_lista_circular_doble(ListaDobleCircular lista);
Natural tamanho_lista_circular_doble(ListaDobleCircular lista);
Procedure eliminar_nodo_circular_doble(ListaDobleCircular* lista, Index posicion);
Procedure eliminar_nodo_circular_doble_inicio(ListaDobleCircular* lista);
Procedure eliminar_nodo_circular_doble_final(ListaDobleCircular* lista);
Procedure eliminar_lista_circular_doble(ListaDobleCircular* lista);
Procedure rotacion_izquierda_lista_circular_doble(ListaDobleCircular* lista);
Procedure rotacion_derecha_lista_circular_doble(ListaDobleCircular* lista);
/* --------------------------------------------------------------- */

#endif  // LIST_H