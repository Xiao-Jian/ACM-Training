//CompletePack(Exactly filled)
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#define INF 0x7ffffff
using namespace std;

int main()
{
    int t, e, f, n;
    int p[501], w[501];
    int dp[10001];
    scanf( "%d", &t );
    while( t -- ) {
        scanf( "%d%d%d", &e, &f ,&n );
        for( int i = 0; i < n; i ++ )
            scanf( "%d%d", &p[i], &w[i] );

        for( int i = 0; i < 10001; i ++ )
            dp[i] = INF;
        dp[0]=0;
        for( int i = 0; i < n; i ++ ) {
            for( int j = w[i]; j <= f - e; j ++ ) {
                if( dp[j - w[i]] < INF && dp[j - w[i]] + p[i] < dp[j] )
                    dp[j] = dp[j - w[i]] + p[i];
            }
        }
        if( dp[f - e] != INF )
            printf( "The minimum amount of money in the piggy-bank is %d.\n", dp[f - e] );
        else
            puts( "This is impossible." );
    }
    return 0;
}
