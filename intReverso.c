#define INT_MAX 2147483647
#define INT_MIN -2147483648

int reverse(int x){
    int resultado = 0;

    while ( x != 0 ) {
        int digito = x % 10;

        if ( resultado > INT_MAX / 10 || resultado < INT_MIN / 10 )
            return 0;

        if ( ( resultado == INT_MAX / 10 && digito > 7 ) || ( resultado == INT_MIN / 10 && digito < -8 ) )
            return 0;
        
        resultado = resultado * 10 + digito;
        x = (int) ( x / 10 );
    }

    return resultado;
}