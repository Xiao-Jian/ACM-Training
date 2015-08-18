/*
OJ: HDOJ
ID: forever
TASK: 5317.RGCDQ
LANG: C++
NOTE: Range Greatest Common Divisor Query
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#define MAX 1000011
using namespace std;

int num[10],f[MAX];
bool isPrime[MAX];
int dp[10][MAX];

void prime2() {
    memset( isPrime, true, sizeof(isPrime) );
    isPrime[0] = isPrime[1] = false;
    for( int i = 2; i <= MAX; i ++ )
        if( isPrime[i] ) {
            f[i] ++;
            for( int j = 2 * i; j <= MAX; j += i ) {
                isPrime[j] = false;
                f[j] ++;
            }
        }
    for( int i = 1; i <= MAX; i ++ ) {
        for( int j = 1; j <= 8; j ++ ) {
            dp[j][i] = dp[j][i-1] + ( f[i] == j );
        }
    }
}

int gcd( int a, int b ) {
    return b == 0 ? a : gcd( b, a%b );
}

int main()
{
    int t, l, r;
    memset( f, 0, sizeof(f) );
    memset( dp, 0, sizeof(dp) );
    prime2();

    scanf( "%d", &t );
    while( t -- ) {
        scanf( "%d%d", &l, &r );
        int ma = 0;
        memset(num, 0 ,sizeof(num));
        for ( int i = 1; i <= 8; i ++ ) {
            num[i] = dp[i][r] - dp[i][l-1];
        }

        int ret = 1;
        if(num[2] + num[4] + num[6]>=2) ret = 2;
        if(num[3] + num[6] >= 2) ret = 3;
        if(num[4] >= 2) ret = 4;
        if(num[5] >= 2) ret = 5;
        if(num[6] >= 2) ret = 6;
        if(num[7] >= 2) ret = 7;
        printf( "%d\n", ret);
    }
    return 0;
}
