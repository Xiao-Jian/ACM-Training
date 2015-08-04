#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <climits>
#define MAX 100005
using namespace std;

int ans, a, b;
int path[MAX],vis[MAX];

int bfs(int x) {
    ans = 0;
    queue<int> q;
    q.push(x);
    path[x] = 0;
    while( !q.empty() ) {
        int tmp = q.front();
        q.pop();
        if( tmp == b ) break;
        ans ++;
        /*if( tmp + tmp <= b ) {
            if( path[tmp+tmp]>=path[tmp]+1) {
                q.push(tmp+tmp);
                path[tmp + tmp] = path[tmp]+1;
            }
        }*/
        for( int i = 1; i * i <= tmp; i ++ ) {
            if( i * i != tmp ) {
                if( tmp % i == 0 && tmp + i <= b ) {
                    if( path[tmp+i] >= path[tmp]+1 && !vis[tmp+i] ) {
                        vis[tmp + i] = 1;
                        q.push(tmp+i);
                        path[tmp + i] = path[tmp]+1;
                    }
                }
                if( tmp % i == 0 && tmp + tmp/i <= b ) {
                    if( path[tmp+tmp/i] >= path[tmp]+1 && !vis[tmp+tmp/i] ) {
                        vis[tmp + tmp/i] = 1;
                        q.push(tmp+tmp/i);
                        path[tmp + tmp/i] = path[tmp]+1;
                    }
                }
            }
            else {
                if( path[tmp+i] >= path[tmp]+1 && !vis[tmp+i] ) {
                    vis[tmp + i] = 1;
                    q.push(tmp+i);
                    path[tmp + i] = path[tmp]+1;
                }
            }
        }
    }
    return path[b];
}

int main()
{
    while( scanf( "%d%d", &a, &b ) !=EOF ) {
        for( int i = 0; i < MAX; i ++ ) {
            path[i] = MAX;
            vis[i] = 0;
        }
        if( a <= b )
            printf( "%d\n", bfs(a) );
        else
            puts("-1");
    }
    return 0;
}
