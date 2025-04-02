#include <stdio.h>
#include <stdlib.h>

int pesquisaBinaria(int *V, int n, int chave){
    int esquerda = 0;
    int direita = n-1;

    while (esquerda <= direita)
    {
        int meio = (esquerda+direita)/2;
        if (chave == V[meio]) return meio;
        else if (chave < V[meio]) direita = meio-1;
        else esquerda = meio+1;
        
    }
    return -1;
}

int main() {
int numeros[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
11, 12, 13, 15, 14, 15};
int tamanho = sizeof(numeros) / sizeof(numeros[0]);
int elemento = 15;
int posicao = pesquisaBinaria(numeros, tamanho, elemento);
if (posicao != -1) printf("Elemento %d encontrado na posição: %d\n", elemento, posicao);
else printf("Elemento %d não encontrado no vetor.\n", elemento);
return 0;
}