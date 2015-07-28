#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
long long n;
long long multi( long long a, long long b ) {
    long long ret = 1;
    while ( b > 0 ) {
        if ( b & 1 ) ret = ( ret * a ) % n;
        a = ( a * a ) % n;
        b /= 2;
    }
    return ret;
}

int main()
{
    while ( scanf( "%I64d", &n ), n ) {
        long long x = ( multi( 2, n-1 ) + 1 ) % n;
        printf ( "%I64d\n", x );
    }
    return 0;
}
