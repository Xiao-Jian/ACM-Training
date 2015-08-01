#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#define MAX 32001
using namespace std;

int ar[MAX];
int num[MAX];

int lowbit(int x) {
    return x & (-x);
}

void add(int i, int v) {
    for( ; i <= MAX; ar[i] += v, i += lowbit(i) );
}

int sum(int i) {
    int ret = 0;
    for( ; i > 0; ret += ar[i], i -= lowbit(i) );
    return ret;
}

int main()
{
    int n, x, y;
    while( scanf( "%d", &n ) != EOF ) {
        memset( ar, 0, sizeof(ar) );
        memset( num, 0, sizeof(num) );

        for( int i = 0; i < n; i ++ ) {
            scanf( "%d%d", &x, &y );
            num[sum( x + 1 )] ++;
            add( x + 1, 1 );
        }
        for( int i = 0; i < n; i ++ )
            printf( "%d\n", num[i] );
    }
    return 0;
}
