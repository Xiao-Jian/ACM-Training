#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#define MAX 100010
using namespace std;

int n;
struct edge {
    int to, next;
}e[MAX<<1];
int cnt, ans, head[MAX], vis[MAX], sum[MAX];

void init() {
    memset( head, -1, sizeof(head) );
    memset( vis, 0, sizeof(vis) );
    ans = -1;
    cnt = 0;
}

void addedge(int u, int v) {
    e[cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt ++;
}

int update(int x) {
    vis[x] = 1;
    if (head[x] == -1) {
        return sum[x] = 1;
    } else {
        sum[x] = 1;
        for (int i = head[x]; i != -1; i = e[i].next) {
            if (!vis[e[i].to]) {
                sum[x] += update(e[i].to);
            }
        }
        if (!(sum[x] & 1)) ans ++;
        return sum[x];
    }
}

int main()
{
    while( scanf( "%d", &n ) != EOF ) {
        init();
        int x, y;
        for( int i = 1; i < n; i ++ ) {
            scanf( "%d%d", &x, &y );
            addedge( x, y );
            addedge( y, x );
        }

        update(1);
        printf( "%d\n", ans );
    }
    return 0;
}
