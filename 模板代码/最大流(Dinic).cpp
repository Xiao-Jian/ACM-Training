//HDOJ1532
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#define MAX_V 5000
#define MAX_E 10000
#define S 1
#define T n
#define INF 0x7fffffff
using namespace std;

struct edge {
    int from, to, cap;
    int next;
}e[MAX_E];
int head[MAX_V];
int cnt;
int dfn[MAX_V];
int n, m;

void init() {
    memset( e, 0, sizeof(e) );
    memset( head, -1, sizeof(head) );
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
        while( flow = dfs( S, INF ) ) {
            ans += flow;
        }
    }
    return ans;
}

int main()
{
    while( scanf( "%d%d", &m, &n ) != EOF ) {
        init();
        int a, b, c;
        for( int i = 0; i < m; i ++ ) {
            scanf( "%d%d%d", &a, &b, &c );
            addedge( a, b, c );
            addedge( b, a, 0 );
        }

        printf( "%d\n", maxflow() );
    }
    return 0;
}
