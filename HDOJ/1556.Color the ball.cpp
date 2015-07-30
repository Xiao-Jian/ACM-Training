/*
OJ: HDOJ
ID: forever
TASK: 1556.Color the ball
LANG: C++
NOTE: Ê÷×´Êý×é
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX 100010
using namespace std;

int t, n, q, x, y, z;
int ar[MAX];

int lowbit(int x) {
    return x & ( -x );
}

void add( int i, int v ) {
    for( ; i <= n; ar[i] += v, i += lowbit(i) );
}

int sum(int i) {
    int ret = 0;
    for( ; i > 0; ret += ar[i], i -= lowbit(i) );
    return ret;
}

int main()
{
    while( scanf( "%d", &n ), n ) {
        memset( ar, 0, sizeof(ar) );
        for( int i = 0; i < n; i ++ ) {
            scanf( "%d%d", &x, &y );
            add( x, 1 );
            add( y + 1, -1 );
        }
        for( int i = 1; i < n; i ++ )
            printf( "%d ", sum(i) );
        printf( "%d\n", sum(n) );
    }
}
