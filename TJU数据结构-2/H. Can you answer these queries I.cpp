#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#define MAX 50001
using namespace std;

int ar[MAX<<2];
int lmax[MAX<<2],rmax[MAX<<2],mmax[MAX<<2];
struct node {
    int lmax, rmax, mmax;
};

void pushup(int l, int r, int rt) {
    int m = ( l + r ) >> 1;
    lmax[rt] = max( lmax[rt<<1], ar[m] - ar[l - 1] + lmax[rt<<1|1] );
    rmax[rt] = max( rmax[rt<<1|1], ar[r] - ar[m] + rmax[rt<<1] );
    mmax[rt] = max( max(mmax[rt<<1], mmax[rt<<1|1]), rmax[rt<<1] + lmax[rt<<1|1] );

}

void build(int l, int r, int rt) {
    if( l == r ) {
        lmax[rt] = rmax[rt] = mmax[rt] = ar[l] - ar[l - 1];
        return;
    }
    int m = ( l + r ) >> 1;
    build( l, m, rt<<1 );
    build( m + 1, r, rt<<1|1 );
    pushup( l, r, rt );
}

node query(int ll, int rr, int l, int r, int rt) {
    if( ll <= l && rr >= r) {
        node ret;
        ret.lmax = lmax[rt];
        ret.rmax = rmax[rt];
        ret.mmax = mmax[rt];
        return ret;
    }
    int m = ( l + r ) >> 1;
    if( rr <= m ) return query( ll, rr, l, m, rt<<1 );
    if( ll > m) return query( ll, rr, m + 1, r, rt<<1|1 );
    node lret = query( ll, m, l, m, rt<<1 );
    node rret = query( m + 1, rr, m + 1, r, rt<<1|1 );
    node ret;
    ret.lmax = max(lret.lmax, ar[m] - ar[l - 1] + rret.lmax);
    ret.rmax = max(rret.rmax, ar[r] - ar[m] + lret.rmax);
    ret.mmax = max(max(lret.mmax, rret.mmax), lret.rmax + rret.lmax);
    return ret;
}

int main()
{
    int n, m, x, y;
    while( scanf( "%d", &n ) != EOF ) {
        ar[0] = 0;
        for( int i = 1; i <= n; i ++ ) {
            scanf( "%d", &ar[i] );
            ar[i] = ar[i - 1] + ar[i];
        }
        build( 1, n, 1 );
        scanf( "%d", &m );
        while( m -- ) {
            scanf( "%d%d", &x, &y );
            printf( "%d\n", query( x, y, 1, n, 1 ).mmax );
        }
    }
    return 0;
}
