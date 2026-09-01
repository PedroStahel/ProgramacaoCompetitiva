int numberOfSubstrings(char* s) {
    int tamString = strlen(s);
    int cont[3] = { 0 };
    int esquerda = 0;
    int numSub = 0;

    for ( int direita = 0; direita < tamString; direita++ ) {
        cont[s[direita] - 'a']++;

        while ( cont[0] > 0 && cont[1] > 0 && cont[2] > 0 ) {
            numSub += tamString - direita;

            cont[s[esquerda] - 'a']--;
            esquerda++;
        }
    }

    return numSub;
}