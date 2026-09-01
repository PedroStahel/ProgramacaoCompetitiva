typedef struct no {
    int valor;
    int contador;
    struct no *prox;
} No;

int hash( int valor, int tamanho ) {
    return (unsigned int) valor % tamanho;
}

int maxSubarrayLength(int* nums, int numsSize, int k) {
    int tamanhoTabela = numsSize * 2 + 1;
    No **tabela = calloc( tamanhoTabela, sizeof(No *) );

    int esquerda = 0;
    int maiorSeq = 0;

    for ( int direita = 0; direita < numsSize; direita++ ) {
        int indice = hash( nums[direita], tamanhoTabela );
        No *atual = tabela[indice];

        while ( atual != NULL && atual -> valor != nums[direita] )
            atual = atual -> prox;

        if ( atual == NULL ) {
            atual = malloc( sizeof(No) );
            atual -> valor = nums[direita];
            atual -> contador = 0;
            atual -> prox = tabela[indice];
            tabela[indice] = atual;
        }

        atual -> contador++;

        while ( atual -> contador > k ) {
            int indiceEsquerda = hash( nums[esquerda], tamanhoTabela );
            No *remover = tabela[indiceEsquerda];

            while ( remover -> valor != nums[esquerda] )
                remover = remover -> prox;

            remover -> contador--;
            esquerda++;
        }

        int seqAtual = direita - esquerda + 1;

        if ( seqAtual > maiorSeq )
            maiorSeq = seqAtual;
    }

    /* Libera a tabela. */
    for ( int i = 0; i < tamanhoTabela; i++ ) {
        No *atual = tabela[i];

        while ( atual != NULL ) {
            No *proximo = atual -> prox;
            free( atual );
            atual = proximo;
        }
    }

    free( tabela );

    return maiorSeq;
}