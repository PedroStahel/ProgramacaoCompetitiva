int smallestNumber(int n, int t) {
    int resposta, prodAtual = 1;

    for ( resposta = n;; resposta++ ) {
        n = resposta;
        while ( n != 0 ) {
            prodAtual *= n % 10;
            n = (int) ( n / 10 );
        }
        if ( prodAtual % t == 0 )
            return resposta;
        prodAtual = 1;
    }
}