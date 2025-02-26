#include <stdio.h>
#include <stdlib.h>

void lerLista(){
    FILE *f;
    f = fopen("lista.csv", "r");
    if (f==NULL)
    {
        printf("Erro");
        exit(1);
    }

    char lixo[100];
    fscanf(f, "%s", &lixo);

    typedef struct
    {
        char nome[20];
        int qtd;
        float valor;        
    }compra;

    compra item[4];
    float valorFinal = 0;
    for (int i = 0; i < 4; i++)
    {
        fscanf(f, "%[^,],%d,%f", &item[i].nome, &item[i].qtd, &item[i].valor); // [^,] --> para ler ate encontrar virgula
        printf("%s: %d * %.2f = %.2f\n", item[i].nome, item[i].qtd, item[i].valor, item[i].qtd*item[i].valor);
        valorFinal += (item[i].qtd*item[i].valor);
    }
    printf("O valor total da compra e: RS%.2f", valorFinal);
    
       
    fclose(f);
}

int main() {
    lerLista();

    return 0;
}