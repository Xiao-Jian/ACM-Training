#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#define MAX 100005
#define MOD 258280327
using namespace std;

int ar[MAX], dp[MAX][10];

int SUM(int x, int y) {
    int tmp = ( x + y ) % 9;
    if( tmp == 0 )
        tmp = 9;
    return tmp;
}

int main()
{
    int t, n, a, b;
    scanf( "%d", &t );
    while( t -- ) {
        int sum = 0;
        scanf( "%d%d%d", &n, &a, &b );
        for( int i = 1; i <= n; i ++ ) {
            scanf( "%d", &ar[i] );
            sum = SUM( ar[i], sum );
        }


        memset( dp, 0, sizeof(dp) );
        dp[0][0] = 1;
        for( int i = 1; i <= n; i ++ ) {
            for( int j = 0; j <= 9; j ++ ) {
                dp[i][j] += dp[i-1][j];
                dp[i][SUM( ar[i], j )] += dp[i-1][j];
                dp[i][j] %= MOD;
                dp[i][SUM( ar[i], j )] %= MOD;
            }
        }

        int ans = 0;
        if( sum == SUM( a, b ) ) {
            ans += dp[n][a];
            if( a == sum )
                ans --;
        }
        if( a == sum ) ans ++;
        if( b == sum ) ans ++;
        printf( "%d\n", ans );
    }
    return 0;
}
