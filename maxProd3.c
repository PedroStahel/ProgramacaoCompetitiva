// Função para trocar dois valores de lugar
void trocar(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Função que separa os menores à esquerda e maiores à direita
int particionar(int vetor[], int baixo, int alto) {
    int pivo = vetor[alto]; // Escolhe o último elemento como pivô
    int i = (baixo - 1);

    for (int j = baixo; j <= alto - 1; j++) {
        if (vetor[j] < pivo) {
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

int maximumProduct(int* nums, int numsSize) {
    int prodMax1, prodMax2;
    
    quicksort( nums, 0, numsSize - 1 );

    prodMax1 = nums[0] * nums[1] * nums[numsSize - 1];
    prodMax2 = nums[numsSize - 1] * nums[numsSize - 2] * nums[numsSize - 3];

    if ( prodMax1 > prodMax2 )
        return prodMax1;

    return prodMax2;
}