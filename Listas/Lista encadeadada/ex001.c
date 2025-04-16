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

void inserirItem(Lista *l, Item i) {
    Item *novo = criarItem(i.chave);
    novo->prox = l->Inicio;
    l->Inicio = novo;
    l->Tamanho++;
}


int main () {


    Item * E1 = criarItem(15);
    Item * E2 = criarItem(47);
    Item * E3 = criarItem(25);
    Item * E4 = criarItem(31);

    printf("Endereco de E1 = %p\n", E1);
    printf("Endereco de E2 = %p\n", E2);
    printf("Endereco de E3 = %p\n", E3);
    printf("Endereco de E4 = %p\n", E4);

    /* E1->prox = E2;
    E2->prox = E3;
    E3->prox = E4;
    E4->prox = NULL;

    Item * E = E2;
    printf("%d\n", E->chave);
    Item * aux = E->prox;
    printf("%d\n", aux->chave); */

    free(E1);
    free(E2);
    free(E3);
    free(E4);

    return 0;
}