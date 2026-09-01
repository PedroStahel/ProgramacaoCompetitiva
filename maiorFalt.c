int largestInteger(int* nums, int numsSize, int k) {
    int cont[51] = {0}, esquerda, maior = -1, temResp = 0;

    for ( esquerda = 0; esquerda < numsSize - k + 1; esquerda++ ) {
        int presente[51] = {0};
    
        for ( int i = esquerda; i < esquerda + k; i++ )
            presente[nums[i]] = 1;

        for ( int i = 0; i < 51; i++ )
            if ( presente[i] )
                cont[i]++;
    }

    for ( int i = 0; i < 51; i++ )
        if ( cont[i] == 1 )
            if ( i > maior ) {
                maior = i;
                temResp = 1;
            }

    if ( temResp )
        return maior;

    return -1;
}