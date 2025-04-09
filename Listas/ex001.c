#include <stdio.h>
#include <stdlib.h>


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

    //printf("Endereco de memoria (em hexadecimal): %p \n", X);

    return X;

}

void destruirLista(lista *L){
    free(L->Array);
    free(L);
}

void inserirItem(lista *l, item i){
    
}

int main() {
    lista * exemplo = criarLista(20);
    printf("Endereco de memoria 2: %p \n", exemplo);
    destruirLista(exemplo);
    lista * exemplo2 = criarLista(20);
    printf("Endereco de memoria 3: %p \n", exemplo2);
    

}