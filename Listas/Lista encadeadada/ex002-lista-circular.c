#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Item{
    int chave;
    struct Item *prox;
} Item;

typedef struct Lista{
    Item * Inicio;
    int Tamanho;
} Lista;

Item * criarItem(int chave);
Lista * criarLista ();
void inserirItem(Lista *l, Item i);
void imprimirLista(Lista *l);
void liberarLista(Lista *l);
void liberarItem(Item *i);
void inserirItem(Lista *l, Item i);