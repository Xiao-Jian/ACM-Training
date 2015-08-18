#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

struct boxes {
    int x, y, z;
}box[15];
int n, cnt, ans;
int vis[15];

void dfs(int x, int y, int t) {
    if( t > ans )
        ans = t;
    for( int i = 0; i < n; i ++ ) {
        if( !vis[i] ) {
            if( box[i].x >= x && box[i].y >= y ) {
                vis[i] = 1;
                dfs( box[i].x, box[i].y, t + 1 );
                vis[i] = 0;
            }
            else if ( box[i].x >= x && box[i].z >= y ) {
                vis[i] = 1;
                dfs( box[i].x, box[i].z, t + 1 );
                vis[i] = 0;
            }
            else if ( box[i].y >= x && box[i].z >= y ) {
                vis[i] = 1;
                dfs( box[i].y, box[i].z, t + 1 );
                vis[i] = 0;
            }
        }
    }
}

int main()
{
    int cas = 1;
    int dp[4];
    while( scanf( "%d", &n ), n ) {
        cnt = 0;
        int x, y, z;
        for( int i = 0; i < n; i ++ ) {
            for( int j = 0; j < 3; j ++ )
                scanf( "%d", &dp[j] );
            sort( dp, dp + 3 );
            box[i].x = dp[0];
            box[i].y = dp[1];
            box[i].z = dp[2];
        }

        ans = 0;
        memset( vis, 0, sizeof(vis) );
        dfs( 0, 0, 0 );
        printf( "Case %d: %d\n", cas ++, ans );
    }
}
