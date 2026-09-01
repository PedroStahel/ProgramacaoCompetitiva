void inicializaContador( int *cont ) {
    for ( int i = 0; i < 26; i++ )
        cont[i] = 0;
}

int maximumLengthSubstring(char* s) {
    int cont[26], maiorSeq = 0;
    int esquerda = 0;
    int direita = 0;

    inicializaContador( cont );

    while ( s[direita] != '\0' ) {
        /* adiciona string[direita] */
        cont[s[direita] - 'a']++;

        while ( cont[s[direita] - 'a'] > 2 ) {
            /* remove string[esquerda] */
            cont[s[esquerda] - 'a']--;
            esquerda++;
        }

        int seqAtual = direita - esquerda + 1;

        /* atualiza o tamanho máximo */
        if ( seqAtual > maiorSeq )
            maiorSeq = seqAtual;

        direita++;
    }

    return maiorSeq;
}
