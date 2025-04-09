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
    if (l->tamanho == l->capacidade)
    {
        printf("ERRO: a lista esta cheia");
        return;
    }

    l->Array[l->tamanho] = i;
    l->tamanho++;
    
}

void imprimirLista(lista *l){
    printf("Capacidade: %d \n", l->capacidade);
    printf("Tamanho: %d \n", l->tamanho);
    for (int i = 0; i < l->tamanho; i++)
    {
        printf("%d ", l->Array[i].chave);
    }
    
}

int main() {
    lista * exemplo = criarLista(20);
    printf("Endereco de memoria 2: %p \n", exemplo);
    
    destruirLista(exemplo);
    
    lista * exemplo2 = criarLista(20);
    printf("Endereco de memoria 3: %p \n", exemplo2);

    item E1 = {10}; inserirItem(exemplo2, E1);
    item E2 = {17}; inserirItem(exemplo2, E2);
    item E3 = {22}; inserirItem(exemplo2, E3);

    imprimirLista(exemplo2);
    

}