#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int Posicao;
    char Estado[32];
    char Time[32];
    int Pontos;
    int J; // N° de jogos
    int V; // N° de vitórias
    int E; // N° de empates
    int D; // N° de derrotas
    int GP; // Gols marcados
    int GC; // Gols sofridos
    int SD; // Saldo de gols
    float Aproveitamento; // % de pontos conquistados em relação ao total de pontos disputados
} equipe;


int main() {

    return 0;
}
equipe *lerDados(const char *nomeArquivo) {
    FILE *fp = fopen(nomeArquivo, "r");
    if (fp == NULL)
    {
        printf("ERRO: arquivo não pode ser aberto \n");
        exit(1);
    }

    equipe *x = malloc(20* sizeof(equipe));
    if (x==NULL)
    {
        printf("ERRO: Não foi possivel alocar memoria para o vator de equipes\n");
        exit(1);
    }
    char L[256];
    fscanf(fp, "%[^\n]", L); // pular a primeira linha

    int n = 0;


    
    
}