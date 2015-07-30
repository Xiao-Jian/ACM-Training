#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define MAX 100010
using namespace std;

int ar[MAX << 2];
int flag[MAX << 2];

void pushup(int rt) {
    ar[rt] = ar[rt<<1] + ar[rt<<1|1];
}
void pushdown(int rt, int m) {
    if( flag[rt] ) {
        flag[rt<<1] = flag[rt<<1|1] = flag[rt];
        ar[rt<<1] = ( m - ( m >> 1) ) * flag[rt];
        ar[rt<<1|1] = ( m >> 1 ) * flag[rt];
        flag[rt] = 0;
    }
}

void build(int l, int r, int rt) {
    flag[rt] = 0;

    if( l == r ) {
        ar[rt] = 1;
        return;
    }
    int m = ( l + r ) >> 1;
    build( l, m, rt<<1 );
    build( m + 1, r, rt<<1|1 );
    pushup( rt );
}

void update(int x, int y, int z, int l, int r, int rt) {
    if( x <= l && y >= r ) {
        flag[rt] = z;
        ar[rt] = ( r - l + 1 ) * z;
        return;
    }
    pushdown( rt, r - l + 1 );
    int m = ( l + r ) >> 1;
    if( x <= m )
        update( x, y, z, l, m, rt<<1 );
    if( y > m )
        update( x, y, z, m + 1, r, rt<<1|1 );
    pushup( rt );
}

int main()
{
    int t, n, q, x, y, z;
    scanf( "%d", &t );
    int k = 0;
    while( t -- ) {
        scanf( "%d%d", &n, &q );
        build( 1, n, 1 );
        while( q -- ) {
            scanf( "%d%d%d", &x, &y, &z );
            update( x, y, z, 1, n, 1 );
        }
        printf( "Case %d: The total value of the hook is %d.\n", ++k, ar[1] );
    }
    return 0;
}
