#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#define MAX 110
using namespace std;

int n, m, x1, y1, z1, x2, y2, z2, x;
int ar[MAX][MAX][MAX];

int lowbit(int x) {
    return x & (-x);
}

void add( int x, int y, int z ) {
    for( int i = x; i <= n; i += lowbit(i) )
        for( int j = y; j <= n; j += lowbit(j) )
            for( int k = z; k <= n; k += lowbit(k) )
                ar[i][j][k] ^= 1;
}

int sum( int x, int y, int z ) {
    int ret = 0;
    for( int i = x; i > 0; i -= lowbit(i) )
        for( int j = y; j > 0; j -= lowbit(j) )
            for( int k = z; k > 0; k -= lowbit(k) )
                ret += ar[i][j][k];
    return ret & 1;
}

int main()
{
    while( scanf( "%d%d", &n, &m ) !=EOF ) {
        memset( ar, 0, sizeof( ar ) );
        while( m -- ) {
            scanf( "%d", &x );
            if( x ) {
                scanf( "%d%d%d%d%d%d", &x1,&y1,&z1,&x2,&y2,&z2 );
                add( x1, y1, z1 );
                add( x2 + 1, y1, z1 );
                add( x1, y2 + 1, z1 );
                add( x1, y1, z2 + 1 );
                add( x2 + 1, y2 + 1, z2 + 1 );
                add( x2 + 1, y2 + 1, z1 );
                add( x1, y2 + 1, z2 + 1 );
                add( x2 + 1, y1, z2 + 1 );
                //puts("2");
            }
            else {
                scanf( "%d%d%d", &x1, &y1, &z1 );
                printf( "%d\n", sum(x1, y1, z1) );
                //puts("3");
            }
        }
    }
    return 0;
}
