// Troca dois números de lugar
void trocar(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Organiza a parte do vetor com base no pivô (último elemento)
int particionar(int vetor[], int baixo, int alto) {
    int pivo = vetor[alto];
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

// Função principal do Quick Sort
void quickSort(int vetor[], int baixo, int alto) {
    if (baixo < alto) {
        int pi = particionar(vetor, baixo, alto);

        quickSort(vetor, baixo, pi - 1);
        quickSort(vetor, pi + 1, alto);
    }
}

int* sequentialDigits(int low, int high, int* returnSize) {
    int *resposta = malloc(36 * sizeof(int));  // Máximo 36 números
    int i = 0;

    for ( int digIni = 1; digIni <= 8; digIni++ ) {
        for ( int qtdDig = 2; qtdDig <= 10 - digIni; qtdDig++ ) {
            int j = 0, numSequencial = 0;
            
            while ( j < qtdDig ) {
                numSequencial = numSequencial * 10 + digIni + j;
                j++;
            }

            if ( numSequencial >= low && numSequencial <= high ) {
                resposta[i++] = numSequencial;
            }
        }
    }

    quickSort( resposta, 0, i - 1 );
    *returnSize = i;
    return resposta;
}