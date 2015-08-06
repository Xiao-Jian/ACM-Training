#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#define S 105
#define T 106
#define INF 0x7fffffff
using namespace std;

int n, np, nc, m;
struct edge {
    int from, to, cap;
    int next;
}e[250*250];
int head[250];
int cnt;
int dfn[250];

void init() {
    memset( head, -1, sizeof(head) );
    memset( e, 0, sizeof(e) );
    cnt = 0;
}

void addedge(int u, int v, int c) {
    e[cnt].from = u;
    e[cnt].to = v;
    e[cnt].cap = c;
    e[cnt].next = head[u];
    head[u] = cnt ++;
}

bool bfs() {
    memset( dfn, -1, sizeof(dfn) );
    queue<int> q;
    q.push(S);
    dfn[S] = 0;

    while( !q.empty() ) {
        int u = q.front();
        q.pop();

        for( int i = head[u]; i != -1; i = e[i].next ) {
            int v = e[i].to;
            if( dfn[v] == -1 && e[i].cap > 0 ) {
                dfn[v] = dfn[u] + 1;
                q.push(v);
            }
        }
    }

    if( dfn[T] == -1 )
        return false;
    return true;
}

int dfs(int u, int cflow) {
    int uu = 0;
    if( u == T ) return cflow;

    for( int i = head[u]; uu < cflow && i != -1; i = e[i].next ) {
        int v = e[i].to;
        if( dfn[v] == dfn[u] + 1 && e[i].cap > 0 ) {
            int tt = min( e[i].cap, cflow - uu );
            tt = dfs( v, tt );

            uu += tt;
            e[i].cap -= tt;
            e[i^1].cap += tt;

        }
    }
    if( uu == 0 ) dfn[u] = -2;
    return uu;
}

int maxflow() {
    int ans = 0, flow;
    while( bfs() ) {
        while( flow = dfs( S, INF ) )
            ans += flow;

    }

    return ans;
}

int main()
{
    while( scanf( "%d%d%d%d", &n, &np, &nc, &m ) != EOF ) {
        init();
        int u, v, z;
        for( int i = 0; i < m; i ++ ) {
            while( getchar() != '(' );
            scanf( "%d,%d)%d", &u, &v, &z );
            addedge( u, v, z );
            addedge( v, u, 0 );
        }

        for( int i = 0; i < np; i ++ ) {
            while( getchar() != '(' );
            scanf( "%d)%d", &u, &z );
            addedge( S, u, z );
            addedge( u, S, 0 );
        }

        for( int i = 0; i < nc; i ++ ) {
            while( getchar() != '(' );
            scanf( "%d)%d", &u, &z );
            addedge( u, T, z );
            addedge( T, u, 0 );
        }

        printf( "%d\n", maxflow() );
    }
    return 0;
}
