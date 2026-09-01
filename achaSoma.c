int busca( int *nums, int numsSize, int soma, int posIni ) {
    for ( int i = posIni; i < numsSize; i++ )
        if ( nums[i] == soma )
            return 1;

    return 0;
}

int missingInteger(int* nums, int numsSize) {
    int i, soma = 0;

    for ( i = 0; i < numsSize; i++ ) {
        if ( i == numsSize - 1 || nums[i] != nums[i+1] - 1 ) {
            soma += nums[i];

            break;
        }
        
        soma += nums[i];
    }

    while ( busca( nums, numsSize, soma, i ) )
        soma++;

    return soma;
}