/*
OJ: POJ
ID: 3013216109
TASK: 1700.Crossing River
LANG: C++
NOTE: Ì°ÐÄ
*/
#include <cstdio>
#include <algorithm>

int main()
{
    int t, n;
    int ar[1010];
    scanf( "%d", &t );
    while( t -- ) {
        scanf( "%d", &n );
        for( int i = 0; i < n; i ++ )
            scanf( "%d", &ar[i] );
        std::sort( ar, ar + n );

        int ans = 0;
        while( n >= 4 ) {
            int t1 = ar[0] * 2 + ar[n-1] + ar[n-2];
            int t2 = ar[0] + ar[1] * 2 + ar[n-1];
            ans += std::min( t1, t2 );
            n -= 2;
        }
        if( n == 3 )
            ans += ar[0] + ar[1] + ar[2];
        if( n == 2 )
            ans += ar[1];
        if( n == 1 )
            ans += ar[0];
        printf( "%d\n", ans );
    }
}
