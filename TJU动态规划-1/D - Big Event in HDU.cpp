#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int n, v, x, y;
    int w[51],p[51],dp[250001];
    while( scanf("%d",&n) ) {
        if( n < 0 ) break;
        memset( dp, 0, sizeof(dp) );
        int sum = 0;
        for( int i = 0; i < n; i ++ ) {
            scanf("%d%d", &w[i], &p[i] );
            sum += w[i] * p[i];
        }
        v = sum / 2;
        for( int i = 0; i < n; i ++ )
            for( int j = w[i]; j <= v; j ++ )
                dp[j] = max( dp[j], dp[j - w[i]] + w[i] );
        printf("%d %d\n", sum-dp[v], dp[v] );
    }
    return 0;
}
