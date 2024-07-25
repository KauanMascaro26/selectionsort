#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <locale.h>

void selectionSort(int *V, int N) {
    int i, j, menor, troca;
    for(i = 0; i < N - 1; i++) {
        menor = i;
        for(j = i + 1; j < N; j++) {
            if(V[j] < V[menor])
                menor = j;
        }
        if(i != menor) {
            troca = V[i];
            V[i] = V[menor];
            V[menor] = troca;
        }
    }
}

void printArray(int *arr, int size) {
	int i;
    for(i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main() {
	
    setlocale(LC_ALL, "portuguese");
    int N, i;

    printf("Digite o número de elementos: ");
    scanf("%d", &N);

    int *arr = (int *)malloc(N * sizeof(int));
    if(arr == NULL) {
        printf("Erro de alocação de memória!\n");
        return 1;
    }

    printf("Digite os elementos:\n");
    for(i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Array original: ");
    printArray(arr, N);

    selectionSort(arr, N);

    printf("Array ordenado: ");
    printArray(arr, N);

    free(arr);

    return 0;
}
