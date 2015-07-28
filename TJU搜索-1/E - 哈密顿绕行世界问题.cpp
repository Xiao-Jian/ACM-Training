#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int node[21][21], m, num, cnt, path[21];
bool vis[21];

void dfs(int x) {
    path[cnt] = x;
    if( cnt == 19 ) {
        if( node[x][m] ) {
            printf( "%d:  ", ++ num);
            for( int i = 0; i < 20; i ++ )
                printf( "%d ", path[i] );
            printf( "%d\n", path[0] );
        }
        return;
    }
    for( int i = 1; i <= 20; i ++ ) {
        if( !vis[i] && node[x][i] ) {
            vis[i] = 1;
            cnt ++;
            dfs( i );
            cnt --;
            vis[i] = 0;
        }
    }
    return;
}

int main()
{
    int a, b, c;
    memset( node, 0, sizeof(node) );
    for( int i = 1; i <= 20; i ++ ) {
        scanf( "%d%d%d", &a, &b, &c );
        node[i][a] = 1;
        node[i][b] = 1;
        node[i][c] = 1;
    }
    while( scanf( "%d", &m ), m) {
        num = cnt = 0;
        memset( path, 0, sizeof(path) );
        memset( vis, 0, sizeof(vis) );
        vis[m] = 1;
        dfs( m );

    }
    return 0;
}
