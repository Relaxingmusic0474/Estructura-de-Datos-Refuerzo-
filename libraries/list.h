#ifndef LIST_H
#define LIST_H

#include "data.h"
#include "types.h"

typedef struct nodo Nodo;
typedef struct nodoDoble NodoDoble;
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

bool crear_lista_vacia(Lista* lista);
bool crear_lista(Lista* lista, Natural nro_elementos);
bool insertar_nodo(Lista* lista, ElemType valor, Index posicion);
bool insertar_nodo_inicio(Lista* lista, ElemType valor);
bool insertar_nodo_final(Lista* lista, ElemType valor);
Procedure modificar_nodo(Lista* lista, Index posicion, ElemType valor);
Procedure imprimir_lista(Lista lista);
Natural tamanho_lista(Lista lista);
Procedure eliminar_nodo(Lista* lista, Index posicion);
Procedure eliminar_nodo_inicio(Lista* lista);
Procedure eliminar_nodo_final(Lista* lista);
Procedure eliminar_lista(Lista* lista, bool liberar);
Procedure vaciar_lista(Lista* lista);
bool esta_vacia(Lista lista);

bool crear_lista_doble(ListaDoble* lista);

#endif  // LIST_H