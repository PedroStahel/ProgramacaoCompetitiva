int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int *resposta;
    int esquerda = 0, direita = numsSize - 1;

    if ( !( resposta = malloc( 2 * sizeof( int ) ) ) )
        return NULL;

    resposta[0] = -1;
    resposta[1] = -1;
    *returnSize = 2;

    if (numsSize == 0) {
        return resposta;
    }

    while ( esquerda <= direita ) {
        int meio = esquerda + ( direita - esquerda ) / 2;
        
        if ( nums[meio] < target )
            esquerda = meio + 1;
        else if ( nums[meio] > target )
            direita = meio - 1;
        else
            if ( meio == 0 || nums[meio - 1] != target ) {
                resposta[0] = meio;
                
                break;
            } else
                direita = meio - 1;
    }
    esquerda = 0;
    direita = numsSize - 1;
    while ( esquerda <= direita ) {
        int meio = esquerda + ( direita - esquerda ) / 2;
        
        if ( nums[meio] < target )
            esquerda = meio + 1;
        else if ( nums[meio] > target )
            direita = meio - 1;
         else
            if ( meio == numsSize - 1 || nums[meio + 1] != target ) {
                resposta[1] = meio;
                
                break;
            } else
                esquerda = meio + 1;
    }

    return resposta;
}
