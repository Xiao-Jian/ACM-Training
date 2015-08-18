#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cmath>
#define MAX 10010
#define llo long long
using namespace std;

llo ar[MAX];
llo tree[MAX<<2];
llo tree2[MAX<<2];

llo gcd( llo a, llo b ) {
    return b == 0 ? a : gcd( b, a%b );
}

void pushup(int rt) {
    tree[rt] = gcd( tree[rt<<1], tree[rt<<1|1] );
}

void build(int l, int r, int rt) {
    if( l == r ) {
        tree[rt] = ar[l];
        return;
    }
    int m = ( l + r ) >> 1;
    build( l, m, rt<<1 );
    build( m + 1, r, rt<<1|1 );
    pushup(rt);
}

llo query(int ll, int rr, int l, int r, int rt) {
    if( ll<=l && r <= rr )
        return tree[rt];
    int m = ( l + r ) >> 1;
    llo ret = 0;
    if( ll <= m )
        ret = gcd( ret, query( ll, rr, l, m, rt<<1 ) );
    if( rr > m )
        ret = gcd( ret, query( ll, rr, m + 1, r, rt<<1|1 ) );
    return ret;
}

void build2(int l, int r, int rt) {
    if( l == r ) {
        tree2[rt] = ar[l];
        return;
    }

}

int main()
{
    int t, n, q;
    scanf( "%d", &t );
    while( t -- ) {
        scanf( "%d", &n );
        for( int i = 1; i <= n; i ++ )
            scanf( "%lld", &ar[i] );

        build( 1, n, 1 );

        scanf( "%d", &q );
        while( q -- ) {
            int x, y;
            llo sum = 0;
            scanf( "%d%d", &x, &y );
            for( int i = x; i <= y; i ++ ) {
                sum += ar[i];
                for( int j = i + 1; j <= y; j ++ )
                    sum += query( i, j, 1, n, 1 );
            }
            printf( "%lld\n", sum );
        }
    }
}
