// Função para trocar dois valores de posição
void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função de particionamento usando o último elemento como pivô
int particionar(int vetor[], int baixo, int alto) {
    int pivo = vetor[alto];
    int i = (baixo - 1);

    for (int j = baixo; j <= alto - 1; j++) {
        if (vetor[j] <= pivo) {
            i++;
            trocar(&vetor[i], &vetor[j]);
        }
    }
    trocar(&vetor[i + 1], &vetor[alto]);
    return (i + 1);
}

// Função principal do Quicksort
void quicksort(int vetor[], int baixo, int alto) {
    if (baixo < alto) {
        int pi = particionar(vetor, baixo, alto);

        quicksort(vetor, baixo, pi - 1);  // Ordena a parte esquerda
        quicksort(vetor, pi + 1, alto);   // Ordena a parte direita
    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findMissingElements(int* nums, int numsSize, int* returnSize) {
    int *faltantes = NULL;

    *returnSize = 0;
    quicksort( nums, 0, numsSize - 1 );
    
    for ( int i = 0; i < numsSize - 1; i++ ) {
        if ( nums[i] != nums[i + 1] && nums[i] != nums[i+1] - 1 ) {
            int j = nums[i] + 1;

            while ( j < nums[i+1] ) {
                (*returnSize)++;
                faltantes = realloc( faltantes, *returnSize * sizeof( int ) );
                faltantes[*returnSize - 1] = j;
                j++;
            }
        }
    }

    return faltantes;
}