#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack>
#define MAX 10010
using namespace std;

struct edge {
    int from,to;
    int next;
}e[30010];
int head[MAX], cnt;

int dfn[MAX], low[MAX], vis[MAX], scc[MAX], ans[MAX], id[MAX], in[MAX], ins[MAX];
int time, num, sum;
stack<int> s;

void init() {
    memset( head, -1, sizeof(head) );
    //memset( e, 0, sizeof(e) );
    memset( vis, 0, sizeof(vis) );
    memset( ins, 0, sizeof(ins) );
    cnt = 0;
    time = 0;
}

void addedge(int u, int v) {
    e[cnt].from = u;
    e[cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt ++;
}

void tarjan(int u) {
    dfn[u] = low[u] = time ++;
    s.push(u);
    ins[u] = 1;
    vis[u] = 1;
    for( int i = head[u]; i != -1; i = e[i].next ) {
        int v = e[i].to;
        if( !vis[v] ) {
            tarjan(v);
            low[u] = min( low[u], low[v] );
        }
        else if( ins[v] )
            low[u] = min( low[u], dfn[v] );

    }
    if( low[u] == dfn[u] ) {
        int v = -1;
        while( u != v ) {
            v = s.top();
            s.pop();
            id[v] = num;
            scc[num] ++;
            ins[v] = 0;
        }
        num ++;
    }
}

void dfs(int u) {
    vis[u] = 1;
    sum += scc[u];
    for( int i = head[u]; i != -1; i = e[i].next ) {
        int v = e[i].to;
        if( !vis[v] )
            dfs(v);
    }
}

int main()
{
    int t, n, m, x, y, cas = 1;
    scanf( "%d", &t );
    while( t -- ) {
        init();
        scanf( "%d%d", &n, &m );
        for( int i = 0; i < m; i ++ ) {
            scanf( "%d%d", &x, &y );
            addedge( x, y );
        }

        num = 0;
        while(!s.empty()) s.pop();
        memset( scc, 0, sizeof(scc) );
        for( int i = 0; i < n; i ++ )
            if( !vis[i] )
                tarjan(i);

        init();
        memset( in, 0, sizeof(in) );
        for( int i = 0; i < m; i ++ ) {
            int u = id[e[i].from];
            int v = id[e[i].to];
            if( u != v ) in[u] = 1;
            addedge( v, u );
        }

        int maxans = -1;
        memset( ans, -1, sizeof(ans) );
        for( int i = 0; i < num; i ++ ) {
            if( in[i] ) continue;
            sum = 0;
            memset( vis, 0, sizeof(vis) );
            dfs(i);
            ans[i] = sum;
            maxans = max( sum, maxans );
        }

        printf( "Case %d: %d\n", cas ++, maxans - 1 );
        int flag=0;
        for (int i = 0; i < n; i++)
            if ( ans[id[i]] == maxans) {
                if(!flag){
                printf("%d", i);
                flag=1;
                }
                else printf(" %d",i);
            }
        printf("\n");
    }
    return 0;
}
