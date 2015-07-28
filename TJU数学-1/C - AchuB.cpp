#include <cstdio>
#define mod 9973

int exgcd( int a, int b, int& x, int& y ) {
    if( b == 0 ) {
        x = 1;
        y = 0;
        return a;
    }
    int ret = exgcd( b, a % b, x, y );
    int tmp = x % mod;
    x = y % mod;
    y = ( ( tmp - a / b * y ) % mod + mod ) % mod;
    return ret;
}

int main()
{
    int t, n, b;
    scanf( "%d", &t );
    while( t -- ) {
        scanf( "%d%d", &n, &b );
        int x, y;
        x = y = 0;
        int ret = exgcd( b, mod, x, y );
        printf( "%d\n", ( x * n ) % mod );
    }
}
