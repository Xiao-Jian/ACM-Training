#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#define ll __int64
using namespace std;

ll mod;

ll exgcd( ll a,ll b,ll& x,ll & y ) {
    if( b == 0 ) {
        x = 1;
        y = 0;
        return a;
    }
    ll ret = exgcd( b, a % b, x, y );
    ll tmp = x % mod;
    x = y % mod;
    y = ( ( tmp - a / b * y ) % mod + mod ) % mod;
    return ret;
}

int main()
{
    ll a, b, c, x, y;
    ll k;

    while( scanf( "%I64d%I64d%I64d%I64d", &a,&b,&c,&k) ) {
        if( a == 0 && b == 0 && c == 0 && k == 0)
            break;
        mod = (ll)1 << k;
        ll temp = ( ( b - a) % mod + mod ) % mod;
        x = y = 0;
        ll ret = exgcd( c, mod, x, y );
        if( temp % ret == 0) {
            x = ( x * ( temp / ret ) ) % mod;
            x = ( x % ( mod / ret ) + mod / ret ) % ( mod / ret );
            printf( "%I64d\n", x );
        }
        else
            puts( "FOREVER" );
    }
    return 0;
}
