/*
OJ: HDOJ
ID: forever
TASK: 2159.FATE
LANG: C++
NOTE: Two-Dimensional Pack
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    int n, m , k, s;
    int dp[101][101];
    while( scanf( "%d%d%d%d", &n, &m, &k, &s ) != EOF ) {
        int a[101], b[101];
        for( int i = 0; i < k; i ++ )
            scanf( "%d%d", &a[i], &b[i] );
        for( int i = 0; i < 101; i ++ )
            for( int j = 0; j < 101; j ++ )
                dp[i][j] = 0;

        for( int i = 0; i < k; i ++ ) {
            for( int j = b[i]; j <= m; j ++ )
                for( int p = 1; p <= s; p ++ )
                    if( dp[j][p] < dp[j - b[i]][p - 1] + a[i] )
                        dp[j][p] = dp[j - b[i]][p - 1] + a[i];
        }
        int flag = 1000000;
        for( int i = 0; i <= m; i ++ )
            for( int j = 0; j <= s; j ++ )
                if( dp[i][j] >= n ) {
                    flag = min( i, flag );
                }
        if(flag != 1000000)
            printf( "%d\n", m - flag );
        else puts( "-1" );
    }
    return 0;
}
