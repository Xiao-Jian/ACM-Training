#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#define MAX 1010
using namespace std;

int t, n, m;
char mat[MAX][MAX];
int vis[MAX][MAX];
int mat2[MAX][MAX];
int str[MAX<<1];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

void bfs() {
    memset( vis, 0, sizeof(vis) );
    vis[1][1] = 1;
    queue<pair<int, int> > q;
    q.push( make_pair(1,1) );

    while( !q.empty() ) {
        pair<int,int> pr;
        pr = q.front();
        q.pop();

        if( mat[pr.first][pr.second] == '0' ) {
            for( int i = 0; i < 4; i ++ ) {
                int x = pr.first + dx[i];
                int y = pr.second + dy[i];
                if( !vis[x][y] && x >= 1 && x <= n && y >= 1 && y <= m ) {
                    vis[x][y] = 1;
                    q.push( make_pair( x, y ) );
                }
            }
        }
    }
    if( vis[n][m] && mat[n][m] == '0' ) {
        printf( "0\n" );
        return;
    }
    int ma = 0;
    for( int i = 1; i <= n; i ++ )
        for( int j = 1; j <= m; j ++ )
            if( vis[i][j] )
                ma = max( ma, i + j );

    printf( "1" );
    for( int i = ma; i < n + m; i ++ ) {
        char mi = '1';
        for( int j = 1; j <= n; j ++ ) {
            if( i - j <= m && i - j >= 1 && vis[j][i - j] ) {
                mi = min( mi, mat[j + 1][i - j] );
                mi = min( mi, mat[j][i - j + 1] );
            }
        }
        printf( "%c", mi );
        for( int j = 1; j <= n; j ++ ) {
            if (1 <= i - j && i - j <= m && vis[j][i - j]) {
				if ( mat[j + 1][i - j] == mi ) vis[j + 1][i - j] = 1;
				if ( mat[j][i - j + 1] == mi ) vis[j][i - j + 1] = 1;
			}
        }
    }
    printf( "\n" );

}

int main()
{
    scanf( "%d", &t );
    while( t -- ) {
        scanf( "%d%d", &n, &m );
        for( int i = 1; i <= n; i ++ ) {
            scanf( "%s", mat[i] + 1 );
        }

        for( int i = 0; i <= n + 1; i ++ )
            mat[i][0] = mat[i][m+1] = '2';
        for( int i = 0; i <= m + 1; i ++ )
            mat[0][i] = mat[n+1][i] = '2';
        bfs();

    }
    return 0;
}
