#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#define MAX 1000000000
using namespace std;

int ar[44];
int flag[1001];
int father[1001];

int func() {
    ar[0] = 1;
    ar[1] = 1;
    for(int i = 2; i < 44; i ++) {
        ar[i] = ar[i-1] + ar[i-2];
    }
}

int Find(int x) {
    while(x != father[x])
      x = father[x];
    return x;
}

void Union(int x, int y) {
    x = Find(x);
    y = Find(y);
    if( x != y )
        father[x] = y;
}

int main()
{
    int t, n, m, k;
    func();
    while( scanf("%d %d", &n, &m) != EOF ) {
        for( int i = 1; i <= n; i ++) {
            father[i] = i;
            scanf("%d", &k);
            flag[i] = 0;
            for(int j = 0; j < 44; j ++)
                if(ar[j] == k) {
                    flag[i] = 1;
                    break;
                }
        }
        int u, v;
        while( m -- ) {
            scanf("%d%d", &u, &v);
            Union(u, v);
        }
        int num[1001];
        memset(num, 0, sizeof(num));
        for(int i = 1; i <= n; i ++) {
            num[Find(i)] += flag[i];
        }
        int mi = 0;
        for(int i = 1; i <= 1000; i ++)
            if(mi < num[i])
                mi = num[i];
        printf("%d\n", mi);
    }
    return 0;
}
