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
void removerItem(Lista *l, Item i);
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

void removerItem(Lista *l, Item i) {
    if (l->Inicio == NULL) {
        printf("Lista vazia.\n");
        return;
    }
    Item *temp = l->Inicio;
    Item *anterior = NULL;
    do {
        if (temp->chave == i.chave) {
            if (anterior == NULL) { // Removendo o primeiro item
                Item *ultimo = l->Inicio;
                while (ultimo->prox != l->Inicio) {
                    ultimo = ultimo->prox;
                }
                ultimo->prox = temp->prox; // Atualiza o último item
                l->Inicio = temp->prox; // Atualiza o início
            } else {
                anterior->prox = temp->prox; // Remove o item
            }
            free(temp);
            l->Tamanho--;
            return;
        }
        anterior = temp;
        temp = temp->prox;
    } while (temp != l->Inicio);
    printf("Item não encontrado.\n");
}

void imprimirLista(Lista *l) {
    if (l->Inicio == NULL) {
        printf("Lista vazia.\n");
        return;
    }
    Item *temp = l->Inicio;
    do {
        printf("%d -> ", temp->chave);
        temp = temp->prox;
    } while (temp != l->Inicio);
    printf("(início)\n");
}

int main () {
    Item * E1 = criarItem(15);
    Item * E2 = criarItem(47);
    Item * E3 = criarItem(25);
    Item * E4 = criarItem(31);

    Lista * L = criarLista();
    inserirItem(L, *E1);
    inserirItem(L, *E2);
    inserirItem(L, *E3);
    inserirItem(L, *E4);

    printf("Tamanho da lista = %d\n", L->Tamanho);
    printf("Endereco de L = %p\n", L);

    printf("\n");

    printf("Endereco de E1 = %p\n", E1);
    printf("Endereco de E2 = %p\n", E2);
    printf("Endereco de E3 = %p\n", E3);
    printf("Endereco de E4 = %p\n", E4);

    printf("\nImprimindo lista circular:\n");
    imprimirLista(L);

    return 0;
}