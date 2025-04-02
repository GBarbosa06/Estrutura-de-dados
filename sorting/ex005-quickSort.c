#include <stdio.h>

void swap(int *a, int *b) {// Função para trocar dois elementos de um vetor
int temp = *a;
*a = *b;
*b = temp;
}

int partition(int V[], int esq, int dir){
    int Pivot = V[(esq + dir) / 2];
    int i = esq; // i: índice para percorrer subvetor da esquerda
    int j = dir; // j: índice para percorrer subvetor da direita
    while(i <= j) {
        while (V[i] < Pivot) i++;
        while (V[j] > Pivot) j--;
        if(i <= j) {
            swap(&V[i], &V[j]);
            i++;
            j--;
        }
    }
    return i; // i é a posição do pivô.
}

void quicksort(int Vetor[], int esq, int dir) {
if (esq < dir) {
    // Encontre a posição do pivô
    int p = partition(Vetor, esq, dir);
    // Ordena os elementos antes e depois da partição
    quicksort(Vetor, esq, p - 1);
    quicksort(Vetor, p, dir);
    }
}

int main() {
    int arr[] = {25, 17, 31, 13, 2, 19, 8, 14, 7, 1, 22, 10, 3, 12, 9, 5, 6, 16, 11, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Vetor desordenado:\n");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    quicksort(arr, 0, n - 1);
    printf("\nVetor ordenado:\n");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    return 0;
}