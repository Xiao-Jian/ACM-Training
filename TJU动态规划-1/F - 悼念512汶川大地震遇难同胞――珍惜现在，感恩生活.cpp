//MultiplePack
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int dp[101];

void ZeroOnePack(int cost,int weight,int power) {
    for(int j = cost; j >= weight; j -- )
        dp[j] = max( dp[j], dp[j-weight] + power);
}

void CompletePack(int cost,int weight,int power) {
    for(int j = weight; j <= cost; j ++ )
        dp[j] = max( dp[j], dp[j-weight] + power);
}

void MultiplePack(int cost,int weight,int power,int amount) {
    if( weight * amount > cost ) {
        CompletePack( cost, weight, power );
    }
    else {
        int k = 1;
        while( k < amount ) {
            ZeroOnePack( k * cost, k * weight ,power );
            amount = amount - k;
            k = k * k;
        }
        ZeroOnePack( amount * cost, amount * weight, power );
    }
}

int main()
{
    int t,n,m,p[101],h[101],c[101];
    scanf( "%d", &t );
    while( t -- ) {
        scanf( "%d%d", &n, &m );
        memset( dp, 0, sizeof(dp) );
        for( int i = 0; i < m; i ++ )
            scanf( "%d%d%d", &p[i], &h[i], &c[i] );
        for( int i = 0; i < m; i ++ ) {
            MultiplePack( n, p[i], h[i], c[i] );
        }
        printf( "%d\n", dp[n] );
    }
    return 0;
}
