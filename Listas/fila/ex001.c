#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó
typedef struct Node {
    int dado;
    struct Node* prox;
} Node;

// Estrutura da fila
typedef struct Fila {
    Node* frente;
    Node* tras;
} Fila;

// Função para criar a fila
Fila* criarFila() {
    Fila* fila = (Fila*)malloc(sizeof(Fila));
    fila->frente = NULL;
    fila->tras = NULL;
    return fila;
}

// Verifica se a fila está vazia
int estaVazia(Fila* fila) {
    return fila->frente == NULL;
}

// adicionarAoFim (inserir no final)
void adicionarAoFim(Fila* fila, int valor) {
    Node* novo = (Node*)malloc(sizeof(Node));
    novo->dado = valor;
    novo->prox = NULL;

    if (estaVazia(fila)) {
        fila->frente = novo;
    } else {
        fila->tras->prox = novo;
    }
    fila->tras = novo;
}

// desadicionarAoFim (remover do início)
int TirarPrimeiro(Fila* fila) {
    if (estaVazia(fila)) {
        printf("Fila vazia!\n");
        return -1; // Valor de erro
    }

    Node* temp = fila->frente;
    int valor = temp->dado;
    fila->frente = fila->frente->prox;

    if (fila->frente == NULL) {
        fila->tras = NULL; // Fila ficou vazia
    }

    free(temp);
    return valor;
}

// Mostrar a fila
void mostrarFila(Fila* fila) {
    Node* atual = fila->frente;
    printf("Fila: ");
    while (atual != NULL) {
        printf("%d ", atual->dado);
        atual = atual->prox;
    }
    printf("\n");
}


int main() {
    Fila* minhaFila = criarFila();

    adicionarAoFim(minhaFila, 10);
    adicionarAoFim(minhaFila, 20);
    adicionarAoFim(minhaFila, 30);

    mostrarFila(minhaFila);

    printf("Removido: %d\n", TirarPrimeiro(minhaFila));
    mostrarFila(minhaFila);

    return 0;
}
