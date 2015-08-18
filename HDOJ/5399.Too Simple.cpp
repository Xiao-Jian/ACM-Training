/*
OJ: HDOJ
ID: forever
TASK: 5399.Too Simple
LANG: C++
NOTE: ÀºøºÃ‚
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#define MAX 101
#define MOD 1000000007
#define ll long long
using namespace std;

int mat[MAX][MAX];
int pos[MAX], vis[MAX];
int n, m;

bool get() {
    int flag;
    for( int i = 1; i <= n; i ++ ) {
        int flag = i;
        for( int j = m; j >= 1; j -- ) {
            flag = mat[j][flag];
        }
        if( flag != i )
            return false;
    }
    return true;
}

ll getn() {
    ll ret = 1;
    for( int i = 1; i <= n; i ++ ) {
        ret = ret * i % MOD;
    }
    return ret;
}

ll multi( ll a, int b ) {
    ll ret = 1;
    while( b > 0 ) {
        if( b & 1 ) ret = ( ret * a ) % MOD;
        a = ( a * a ) % MOD;
        b /= 2;
    }
    return ret;
}

int main()
{
    while( scanf( "%d%d", &n, &m ) != EOF ) {
        int k = 0;
        for( int i = 1; i <= m; i ++ )
            for( int j = 1; j <= n; j ++ ) {
                scanf( "%d", &mat[i][j] );
                if( mat[i][j] == -1 ) {
                    pos[k ++] = i;
                    break;
                }
            }
        int temp = 0, p = 0;
        for( int i = 1; i <= m; i ++ ) {
            if( i == pos[p] ) {
                p ++;
                continue;
            }
            memset( vis, 0, sizeof(vis) );
            for( int j = 1; j <= n; j ++ ) {
                if( vis[mat[i][j]] ) {
                    temp = 1;
                    break;
                }
                vis[mat[i][j]] = 1;
            }
            if( temp ) break;
        }

        if( temp ) {
            puts( "0" );
            continue;
        }

        long long ans = getn();
        if( k == 0 && get() ) {
            puts( "1" );
            continue;
        }
        else if( k == 0 && !get() ) {
            puts( "0" );
            continue;
        }
        else {
            printf( "%lld\n", multi( ans, k-1 ) );
        }

    }
    return 0;
}
