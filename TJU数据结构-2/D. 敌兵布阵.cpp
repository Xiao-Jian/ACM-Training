#include <cstdio>
#include <iostream>
#include <cstring>
#define MAX 50010
using namespace std;

int ar[MAX<<2];

void pushup(int rt) {
    ar[rt] = ar[rt<<1] + ar[rt<<1|1];
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
        ar[rt] += b;
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
    if( ll <= l && rr >= r ) {
        return ar[rt];
    }
    int m = ( l + r ) >> 1;
    int ret = 0;
    if( ll <= m )
        ret += query( ll, rr, l, m, rt<<1 );
    if( rr > m )
        ret += query( ll, rr, m + 1, r, rt<<1|1 );
    return ret;
}

int main()
{
    int t, n, x, y;
    scanf( "%d", &t );
    int k = 1;
    char str[10];
    while( t -- ) {
        scanf( "%d", &n );
        build( 1, n, 1 );
        printf("Case %d:\n",k++);
        while( scanf( "%s", str ) && str[0] != 'E' ) {
            scanf( "%d%d", &x, &y );
            if( str[0] == 'Q' )
                printf( "%d\n", query( x, y, 1, n, 1 ) );
            else if( str[0] == 'A' )
                update( x, y, 1, n, 1 );
            else if( str[0] == 'S' )
                update( x, -y , 1, n, 1 );
        }
    }
    return 0;
}
