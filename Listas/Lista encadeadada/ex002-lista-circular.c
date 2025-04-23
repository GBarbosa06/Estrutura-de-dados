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

Lista * criarLista () {
    Lista *L = (Lista *)malloc(sizeof(Lista));
    if (L == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }
    L->Inicio = NULL;
    L->Tamanho = 0;
    return L;
}

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

void inserirItem(Lista *l, Item i) {
    Item *novo = criarItem(i.chave);
    if (l->Inicio == NULL) {
        l->Inicio = novo;
        novo->prox = novo; // Aponta para ele mesmo
    } else {
        Item *temp = l->Inicio;
        while (temp->prox != l->Inicio) {
            temp = temp->prox;
        }
        temp->prox = novo;
        novo->prox = l->Inicio; // Faz o novo item apontar para o início
    }
    l->Tamanho++;
}