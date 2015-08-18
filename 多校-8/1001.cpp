#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cmath>
#define MAX 10010
#define ll long long
using namespace std;

ll dp[MAX][MAX], ar[MAX];

ll gcd( int a, int b ) {
    return b == 0 ? a : gcd( b, a%b );
}

int main()
{
    int t, n, q;
    scanf( "%d", &t );
    while( t -- ) {
        scanf( "%d", &n );
        for( int i = 1; i <= n; i ++ ) {
            scanf( "%lld", &ar[i] );
            dp[i][i] = ar[i];
        }

        for( int i = 1; i <= n; i ++ ) {
            for( int j = i + 1; j <= n; j ++ ) {
                dp[i][j] = gcd( dp[i][j-1], ar[j] );
            }
        }

        scanf( "%d", &q );
        while( q -- ) {
            int x, y;
            ll sum = 0;
            scanf( "%d%d", &x, &y );
            for( int i = x; i <= y; i ++ ) {
                for( int j = i; j <= y; j ++ )
                    sum += dp[i][j];
            }
            printf( "%lld\n", sum );
        }
    }
}
