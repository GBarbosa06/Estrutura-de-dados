#include <stdio.h>
#include <stdlib.h>

void criarArquivo(){
    FILE *f;
        f = fopen("nomes.txt", "w");
        if (f==NULL)
        {
            printf("Erro");
            exit(1);
        }
        fclose(f);
}

void adicionarNomes(){
    FILE *f;
    f = fopen("nomes.txt", "a");
    if (f==NULL)
    {
        printf("Erro");
        exit(1);
    }
    


    char *nomes[20] = {
        "Ana", "Carlos", "Beatriz", "João", "Mariana",
        "Lucas", "Camila", "Felipe", "Sofia", "Gabriel",
        "Larissa", "Eduardo", "Carla", "Ricardo", "Clara",
        "Pedro", "Juliana", "Thiago", "Isabela", "Daniel",};

    for(int i = 0; i < 20; i++){
        fprintf(f, "%d - %s\n", i+1, nomes[i]);
    }
    
    fclose(f);
}

void lerNomes(){
    FILE *f;
    f = fopen("nomes.csv", "r");
    if (f==NULL)
    {
        printf("Erro");
        exit(1);
    }

    char lixo[100];
    fscanf(f, "%s", &lixo);
    int numero;
    char nome[20];
    int idade;
    fscanf(f, "%d,%[^,],%d", &numero, nome, &idade); // [^,] --> para ler ate encontrar virgula
    printf("%d - %s - %d", numero, nome, idade);

    fclose(f);
}

int main() {
    lerNomes();

    return 0;
}