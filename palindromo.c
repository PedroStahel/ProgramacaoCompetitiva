bool isPalindrome(int x) {
    if ( x < 0 )
        return false;

    unsigned long long iniX = x, reverso = 0;

    while ( x != 0 ) {
        reverso = reverso * 10 + x % 10;
        x = (int) ( x / 10 );
    }

    return iniX == reverso;
}