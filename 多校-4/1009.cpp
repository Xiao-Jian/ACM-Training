#include <cstdio>
#include <iostream>
#include <cstring>
#define MAX 1001
using namespace std;

int t, n, m, ma, mi, mj, ret;
char mat[MAX][MAX];
int vis[MAX][MAX];
int mat2[MAX][MAX];
int str[MAX<<1];

void dfs(int a, int b) {
    if( b+1<m && !vis[a][b+1] ) {
        vis[a][b+1] = 1;
        if( ma < a + b + 1 ) {
            ma = a + b + 1;
            mi = a;
            mj = b + 1;
        }
        dfs( a, b + 1 );
        vis[a][b+1] = 0;
    }
    if( a+1<n && !vis[a+1][b] ) {
        vis[a+1][b] = 1;
        if( ma < a + b + 1 ) {
            ma = a + b + 1;
            mi = a + 1;
            mj = b;
        }
        dfs( a + 1, b );
        vis[a+1][b] = 0;
    }
    if( b-1>=0 && !vis[a][b - 1] ) {
        vis[a][b - 1] = 1;
        if( ma < a + b - 1 ) {
            ma = a + b - 1;
            mi = a;
            mj = b - 1;
        }
        dfs( a, b - 1 );
        vis[a][b - 1] = 0;
    }
    if( a-1>=0 && !vis[a-1][b] ) {
        vis[a-1][b] = 1;
        if( ma < a + b - 1 ) {
            ma = a + b - 1;
            mi = a - 1;
            mj = b;
        }
        dfs( a + 1, b );
        vis[a-1][b] = 0;
    }
    return;
}

void dfs2(int a, int b, int rt) {

    if( b+1<m && !vis[a][b+1] ) {
        if( mat2[a][b+1] <= str[rt] ) {
            vis[a][b+1] = 1;
            int tmp = str[rt];
            str[rt] = mat2[a][b+1];
            dfs2( a, b+1, rt+1 );
            str[rt] = tmp;
            vis[a][b+1] = 0;
        }
    }
    if( a+1<n && !vis[a+1][b] ) {
        if( mat2[a+1][b] <= str[rt] ) {
            vis[a+1][b] = 1;
            int tmp = str[rt];
            str[rt] = mat2[a+1][b];
            dfs2( a+1, b, rt+1 );
            str[rt] = tmp;
            vis[a+1][b] = 0;
        }
    }
    ret = max( ret, rt );
}

int main()
{
    scanf( "%d", &t );
    while( t -- ) {
        scanf( "%d%d", &n, &m );
        for( int i = 0; i < n; i ++ ) {
            scanf( "%s", mat[i] );
            for( int j = 0; j < m; j ++ ) {
                vis[i][j] = mat[i][j] - '0';
            }
        }

        ma = 0; mi = 0; mj = 0;
        dfs( 0, 0 );
        //printf( "%d %d\n", mi, mj );
        memset( vis, 0, sizeof(vis) );
        for( int i = 0; i < n; i ++ ) {
            for( int j = 0; j < m; j ++ ) {
                mat2[i][j] = mat[i][j] - '0';
            }
        }
        for( int i = 0; i < 2001; i ++ )
            str[i] = 1;

        ret = 0;
        dfs2( mi, mj , 0);
        //printf( "%d\n", ret );
        for( int i = 0; i < ret; i ++ )
            printf( "%d", str[i] );
        printf( "%d\n", str[ret] );

    }
    return 0;
}
