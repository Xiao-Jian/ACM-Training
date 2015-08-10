#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#define MAX 100010
using namespace std;

int t, n, m;
int vis[MAX];

bool cmp( int a, int b ) {
    return a > b;
}

bool dfs(int now, int num, int obj, int s) {
    if( num == n ) return true;

    int sample = -1;
    for( int i = s; i <= n; i ++ ) {
        if( vis[i] || sample == i ) continue;
        vis[i] = 1;
        if( i + now < obj ) {
            if( dfs( i + now, num + 1, obj, s ) )
                return true;
            else
                sample = i;
        }
        else if( i + now == obj ) {
            if( dfs( 0, num + 1, obj, 0 ) )
                return true;
            else
                sample = i;
        }
        vis[i] = 0;
        if( now == 0 )
            break;
    }
    return false;
}

int main()
{
    /*while( scanf( "%d", &n ), n ) {
        int lmax = 0, sum = 0;
        for( int i = 0; i < n; i ++ ) {
            scanf( "%d", &ar[i] );
            if( lmax < ar[i] )
                lmax = ar[i];
            sum += ar[i];
        }
        sort( ar, ar + n, cmp );
        memset( vis, 0, sizeof(vis) );

        for( int i = lmax; i <= sum; i ++ ) {
            if( sum%i == 0 && dfs(0,0,i,0) ) {
                printf( "%d\n", i );
                break;
            }
        }
    }*/

    scanf( "%d", &t );
    while( t -- ) {
        scanf( "%d%d", &n, &m );
        int sum = (1 + n) * n / 2;
        if( sum % m != 0 ) {
            puts( "NO" );
            continue;
        }

        int obj = sum / m;
        if( dfs( 0, 0, obj, 1 ) ) {
            puts( "YES" );
        }
        else
            puts( "NO" );

    }

    return 0;
}
