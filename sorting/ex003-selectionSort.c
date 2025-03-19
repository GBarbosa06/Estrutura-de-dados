#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* randNums(int range){

    int *V = (int *)malloc (range * sizeof(int)); //alocação dinâmica em tempo de execução
    srand(time(NULL));
    for (int i = 0; i < range; i++)  V[i] = (rand()%100);
    //for (int i = 0; i < range; i++) printf("%d \t", V[i]%100);
    return V;

}

void selectionSort(int *arr, int n){
    for (int i = 0; i < n-1; i++)
    {
        int minIndex = i; //define o indice a ser comparado

        for (int j = i + 1; j < n; j++) //busca o menor elemento (após os primeiros elementos já ordenados)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }            
        }

        //troca dos comparados
        int aux = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = aux;
    }
    
}

int main() {
    int n = 10;
    int *arr = randNums(n);
    selectionSort(arr, n);
    
    for (int i = 0; i < n; i++)
    {
        printf("%d \n", arr[i]);
    }
       
    free(arr);
    return 0;
}