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


Item * criarItem(int chave) {
    Item *I = (Item *)malloc(sizeof(Item));
    if (I == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }
    I->chave = chave;
    I->prox = NULL;
    return I;
}