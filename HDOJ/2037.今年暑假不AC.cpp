#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

struct node {
    int s, e;
} ar[110];

bool cmp( node a, node b ) {
    return a.e < b.e;
}

int main()
{
    int n;
    while( scanf( "%d", &n ) != EOF && n ) {
        for( int i = 0; i < n; i ++ )
            scanf( "%d%d", &ar[i].s, &ar[i].e );

        sort( ar, ar + n, cmp );
        int ans = 0, ma = 0;
        for( int i = 0; i < n; i ++ ) {
            if( ar[i].s >= ma ) {
                ans ++;
                ma = ar[i].e;
            }
        }
        printf( "%d\n", ans );

    }
}
