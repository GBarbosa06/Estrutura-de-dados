#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randNums(int range){

    clock_t t0 = clock();

    //codigo cujo tempo sera medido
    int *V = (int *)malloc (range * sizeof(int)); //alocação dinâmica em tempo de execução
    srand(time(NULL));
    for (int i = 0; i < range; i++)  V[i] = rand();
    for (int i = 0; i < range; i++) printf("%d \t", V[i]%100);

    clock_t tf = clock();

    double TempoCPU = ((double)(tf - t0)) / CLOCKS_PER_SEC;
    printf("\nTempo de execucao: %.3lf seg. \n", TempoCPU);
    
}


int main() {
    randNums(1000000);
}