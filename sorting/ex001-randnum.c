#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randNums(int range){
    int *V = (int *)malloc (range * sizeof(int)); //alocação dinâmica em tempo de execução
    srand(time(NULL));
    for (int i = 0; i < range; i++)  V[i] = rand();
    for (int i = 0; i < range; i++) printf("%d \t", V[i]%100);


}


int main() {
    randNums(10000);
}