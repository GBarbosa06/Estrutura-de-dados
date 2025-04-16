#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int chave;
    struct Item *prox;
} Item;

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

int main () {
    Item * E1 = criarItem(15);
    Item * E2 = criarItem(20);
    Item * E3 = criarItem(25);
    Item * E4 = criarItem(30);

    printf("Endereco de E1 = %p\n", E1);
    printf("Endereco de E2 = %p\n", E2);
    printf("Endereco de E3 = %p\n", E3);
    printf("Endereco de E4 = %p\n", E4);

    return 0;
}