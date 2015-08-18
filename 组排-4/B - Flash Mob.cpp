#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

int x[1001], y[1001];

int main()
{
    int cas = 1;
    int n;
    while( scanf( "%d", &n ), n ) {
        for( int i = 0; i < n; i ++ )
            scanf( "%d%d", &x[i], &y[i] );
        sort( x, x + n );
        sort( y, y + n );
        int sum = 0;
        for( int i = 0; i < n; i ++ ) {
            sum += abs( x[i] - x[(n-1)/2] );
            sum += abs( y[i] - y[(n-1)/2] );
        }
        printf( "Case %d: (%d,%d) %d\n", cas ++, x[(n-1)/2], y[(n-1)/2], sum );
    }
    return 0;
}
