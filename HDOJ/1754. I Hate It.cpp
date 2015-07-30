#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX 222222
using namespace std;

int ar[MAX<<2];

void pushup(int rt) {
    ar[rt] = max( ar[rt<<1], ar[rt<<1|1] );
}

void build(int l, int r, int rt) {
    if( l == r ) {
        scanf( "%d", &ar[rt] );
        return;
    }
    int m = ( l + r ) >> 1;
    build( l, m, rt<<1 );
    build( m + 1, r, rt<<1|1 );
    pushup(rt);
}

void update(int a, int b, int l, int r, int rt) {
    if( l == r ) {
        ar[rt] = b;
        return;
    }
    int m = ( l + r ) >> 1;
    if( a <= m )
        update( a, b, l, m, rt<<1 );
    else
        update( a, b, m + 1, r, rt<<1|1 );
    pushup(rt);
}

int query(int ll, int rr, int l, int r, int rt) {
    if( ll <= l && rr >= r )
        return ar[rt];
    int m = ( l + r ) >> 1;
    int ret = 0;
    if( ll <= m )
        ret = max( ret, query( ll, rr, l, m, rt<<1 ) );
    if( rr > m )
        ret = max( ret, query( ll, rr, m + 1, r, rt<<1|1 ) );
    return ret;
}

int main()
{
    int n, m, a, b;
    while( ~scanf( "%d%d", &n, &m ) ) {
        build( 1, n, 1 );
        while( m -- ) {
            char str;
            cin >> str;
            scanf( "%d%d", &a, &b );
            if( str == 'U' )
                update( a, b, 1, n, 1 );
            else
                printf( "%d\n", query( a, b , 1, n, 1 ) );
        }
    }
    return 0;
}
