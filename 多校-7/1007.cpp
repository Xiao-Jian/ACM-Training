#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#define MAX 200001
using namespace std;

char str[MAX];
int ar[MAX];
int dp[MAX][2];

int main()
{
    int t, cas = 1;
    scanf( "%d", &t );
    while( t -- ) {
        memset( dp, -1, sizeof(dp) );
        scanf( "%s", str );
        int n = strlen(str);
        for( int i = 0; i < n; i ++ )
            scanf( "%d", &ar[i] );

        if( str[0] == '1' )
            dp[0][1] = ar[0];
        else if( str[0] == '0' )
            dp[0][0] = 0;
        else {
            dp[0][1] = ar[0];
            dp[0][0] = 0;
        }
        for( int i = 1; i < n; i ++ ) {
            if( str[i] == '1' ) {
                if( dp[i-1][0] >= 0 )
                    dp[i][1] = max( dp[i-1][0] + ar[i], dp[i][1] );
                if( dp[i-1][1] >= 0 )
                    dp[i][1] = max( dp[i-1][1], dp[i][1] );
            }
            else if( str[i] == '0' ) {
                if( dp[i-1][1] >= 0 )
                    dp[i][0] = max( dp[i-1][1] + ar[i], dp[i][0] );
                if( dp[i-1][0] >= 0 )
                    dp[i][0] = max( dp[i-1][0], dp[i][0] );
            }
            else {
                if( dp[i-1][0] >= 0 ) {
                    dp[i][0] = max( dp[i][0], dp[i-1][0] );
                    dp[i][1] = max( dp[i][1], dp[i-1][0] + ar[i] );
                }
                if( dp[i-1][1] >= 0 ) {
                    dp[i][0] = max( dp[i][0], dp[i-1][1] + ar[i] );
                    dp[i][1] = max( dp[i][1], dp[i-1][1] );
                }
            }

        }

        printf( "Case #%d: %d\n", cas ++, max( dp[n-1][0], dp[n-1][1] ) );
    }
    return 0;
}
