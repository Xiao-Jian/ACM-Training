#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#define MAX 10001
using namespace std;

struct nod {
    int xi;
    int flag;
}node[MAX];

bool cmp(nod a, nod b) {
    if(a.xi == b.xi)
        return a.flag < b.flag;
    return a.xi < b.xi;
}

int main()
{
    int t, n, m, k;
    int pos;
    scanf("%d", &t);
    while( t -- ) {
        memset(node, 0, sizeof(node));
        scanf("%d %d %d", &n, &m, &k);
        for( int i = 1; i <= n; i ++ )
            scanf("%d", &node[i].xi);
        int sum = 0;
        int tmp = m;
        for( int i = 1; i <= m; i ++ ) {
            scanf("%d", &pos);
            sum += node[pos].xi;
            if(node[pos].flag) {
                sum -= node[pos].xi;
                tmp --;
            }
            else
                node[pos].flag = 1;
        }
        sort(node+1, node+n+1, cmp);

        int num = 0;
        if( sum > k )
            puts("-1");
        else {
            k -= sum;
            num += tmp;
            for(int i = 1; i <= n; i ++) {
                if(!node[i].flag) {
                    k -= node[i].xi;
                    if(k < 0)
                        break;
                    num ++;
                }
            }
            printf("%d\n", num);
        }
    }
    return 0;
}
