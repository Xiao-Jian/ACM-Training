#include <cstdio>

int gcd( int a, int b ) {
    return b == 0 ? a : gcd( b, a % b );
}

int lcm( int a, int b ) {
    return ( a / gcd( a, b ) * b );
}

int main()
{
    int t, n, a, b;
    scanf( "%d", &t );
    while( t -- ) {
        scanf( "%d%d", &n, &a );
        for( int i = 0; i < n - 1; i ++ ) {
            scanf( "%d", &b );
            a = lcm( a, b );
        }
        printf( "%d\n", a );
    }
    return 0;
}
