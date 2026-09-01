#define I 1
#define V 5
#define X 10
#define L 50
#define C 100
#define D 500
#define M 1000

int valorAtual( char atual ) {
    switch ( atual ) {
        case 'I':
            return I;
        case 'V':
            return V;
        case 'X':
            return X;
        case 'L':
            return L;
        case 'C':
            return C;
        case 'D':
            return D;
        default:
            return M;
    }
}

int romanToInt(char* s) {
    int i = 0, resultado = 0;

    while ( s[i] != '\0' ) {
        int letraAtual = valorAtual( s[i] );
        if ( s[i+1] == '\0' ) {
            resultado += letraAtual;
            
            break;
        }

        int proxLetra = valorAtual( s[i+1] );
        if ( letraAtual < proxLetra ) {
            resultado += ( proxLetra - letraAtual );
            i+=2;
        }
        else {
            resultado += letraAtual;
            i++;
        }
    }

    return resultado;
}