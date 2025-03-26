#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* randNums(int range){

    int *V = (int *)malloc (range * sizeof(int));
    srand(time(NULL));
    for (int i = 0; i < range; i++)  V[i] = (rand()%100);
    return V;

}

void insertionSort(int *arr, int n){
    int i, j, key;
    for (i = 1; i < n; i++)
    {
       key = arr[i];
       j = i - 1;

        while (j >= 0 && arr[j] > key) // Para mover os elementos maiores
        {
            arr[j+1] = arr[j];
            j--;
        }

        arr[j + 1] = key; // Insere a chave na posição correta
    }    
}

int main() {
    int n = 10;
    int *arr = randNums(n);
    insertionSort(arr, n);
    
    for (int i = 0; i < n; i++)
    {
        printf("%d \n", arr[i]);
    }
       
    free(arr);
    return 0;
}