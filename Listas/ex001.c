#include <stdio.h>

typedef struct
{
    int chave;
} item;

typedef struct
{
    item *Array;
    int tamanho;
    int capacidade;
} lista;

lista * criarLista(int C){
    lista *X = (lista *)malloc(sizeof(lista));
    if(X == NULL){
        printf("Não foi alocada memoria para a estrutura da lista");
        return NULL;
    }

    X->Array = malloc(C * sizeof(item));
    
    if (X->Array == NULL){
        printf("ERRO: Nao foi possivel alocar memoria para o vetor de itens");
        free(X);
        return NULL;
    }

    X->capacidade = C;
    X->tamanho = 0;

    return X;

}