#include <stdio.h>

void swap(int *a, int *b) {// Função para trocar dois elementos de um vetor
int temp = *a;
*a = *b;
*b = temp;
}

int particao(int V[], int inf, int sup){
int Pivot = V[(inf + sup) / 2];
int i = inf; // i: índice para percorrer subvetor da esquerda
int j = sup; // j: índice para percorrer subvetor da direita
while(i <= j) {
while (comparar(&V[i], &Pivot) < 0) i++;
while (comparar(&V[j], &Pivot) > 0) j--;
if(i <= j) {
swap(&V[i], &V[j]);
i++;
j--;
}
}
return (i); // i é a posição do pivô.
}

void quicksort(int Vetor[], int inf, int sup) {
if (inf < sup) {
// Encontre a posição do pivô
int p = partition(Vetor, inf, sup);
// Ordena os elementos antes e depois da partição
quicksort(Vetor, inf, p - 1);
quicksort(Vetor, p, sup);
}
}
int main() {
int arr[20] = {25, 17, 31, 13, 2, 19, 8, 14, 7, 1, 22, 10, 3, 12, 9, 5, 6, 16, 11, 4};
int n = sizeof(arr) / sizeof(arr[0]);
printf("Vetor desordenado:\n");
for (int i = 0; i < n; i++) printf("%d ", arr[i]);
quicksort(arr, 0, n - 1);
printf("\nVetor ordenado:\n");
for (int i = 0; i < n; i++) printf("%d ", arr[i]);
return 0;
}