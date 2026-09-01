int mySqrt(int x) {
    if ( x == 0 )
        return 0;
    for ( int i = 1; ; i++ ) {
        if ( ( float ) ( x / i ) < ( float ) i )
            return i - 1;  
    }
}