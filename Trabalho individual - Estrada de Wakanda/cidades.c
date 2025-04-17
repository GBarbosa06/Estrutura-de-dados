#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cidades.h"

// Função auxiliar para comparar posições (para qsort)
int compararCidades(const void *a, const void *b) {
    Cidade *c1 = (Cidade *)a;
    Cidade *c2 = (Cidade *)b;
    return c1->Posicao - c2->Posicao;
}

// Lê o arquivo e inicializa a estrutura da estrada
Estrada *getEstrada(const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (!arquivo) return NULL;

    int T, N;
    if (fscanf(arquivo, "%d", &T) != 1 || fscanf(arquivo, "%d", &N) != 1) {
        fclose(arquivo);
        return NULL;
    }

    if (T < 3 || T > 1000000 || N < 2 || N > 10000) {
        fclose(arquivo);
        return NULL;
    }

    Estrada *estrada = malloc(sizeof(Estrada));
    if (!estrada) {
        fclose(arquivo);
        return NULL;
    }

    estrada->T = T;
    estrada->N = N;
    estrada->C = malloc(N * sizeof(Cidade));
    if (!estrada->C) {
        free(estrada);
        fclose(arquivo);
        return NULL;
    }

    for (int i = 0; i < N; i++) {
        int pos;
        char nome[256];

        if (fscanf(arquivo, "%d %[^\n]", &pos, nome) != 2 || pos <= 0 || pos >= T) {
            free(estrada->C);
            free(estrada);
            fclose(arquivo);
            return NULL;
        }

        // Verifica duplicação
        for (int j = 0; j < i; j++) {
            if (estrada->C[j].Posicao == pos) {
                free(estrada->C);
                free(estrada);
                fclose(arquivo);
                return NULL;
            }
        }

        estrada->C[i].Posicao = pos;
        strcpy(estrada->C[i].Nome, nome);
    }

    fclose(arquivo);
    return estrada;
}

// Calcula a menor vizinhança entre as cidades
double calcularMenorVizinhanca(const char *nomeArquivo) {
    Estrada *estrada = getEstrada(nomeArquivo);
    if (!estrada) return -1;

    qsort(estrada->C, estrada->N, sizeof(Cidade), compararCidades);

    double menor = estrada->T; // começa com o tamanho total da estrada

    for (int i = 0; i < estrada->N; i++) {
        double esquerda, direita;

        if (i == 0)
            esquerda = 0;
        else
            esquerda = (estrada->C[i].Posicao + estrada->C[i - 1].Posicao) / 2.0;

        if (i == estrada->N - 1)
            direita = estrada->T;
        else
            direita = (estrada->C[i].Posicao + estrada->C[i + 1].Posicao) / 2.0;

        double vizinhanca = direita - esquerda;
        if (vizinhanca < menor)
            menor = vizinhanca;
    }

    free(estrada->C);
    free(estrada);
    return menor;
}

// Retorna o nome da cidade com a menor vizinhança
char *cidadeMenorVizinhanca(const char *nomeArquivo) {
    Estrada *estrada = getEstrada(nomeArquivo);
    if (!estrada) return NULL;

    qsort(estrada->C, estrada->N, sizeof(Cidade), compararCidades);

    double menor = estrada->T;
    int indice = -1;

    for (int i = 0; i < estrada->N; i++) {
        double esquerda = (i == 0) ? 0 : (estrada->C[i].Posicao + estrada->C[i - 1].Posicao) / 2.0;
        double direita = (i == estrada->N - 1) ? estrada->T : (estrada->C[i].Posicao + estrada->C[i + 1].Posicao) / 2.0;

        double vizinhanca = direita - esquerda;

        if (vizinhanca < menor) {
            menor = vizinhanca;
            indice = i;
        }
    }

    // Copia o nome da cidade para retorno
    char *nome = malloc(strlen(estrada->C[indice].Nome) + 1);
    if (nome)
        strcpy(nome, estrada->C[indice].Nome);

    free(estrada->C);
    free(estrada);
    return nome;
}
