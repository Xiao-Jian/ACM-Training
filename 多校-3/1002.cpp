#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#define MAX 1000011
using namespace std;

int num[50],f[MAX];
bool isPrime[MAX];

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
}

int gcd( int a, int b ) {
    return b == 0 ? a : gcd( b, a%b );
}

int main()
{
    int t, l, r;
    memset( f, 0, sizeof(f) );
    prime2();
    int flag1=0,flag2=0;
    for ( int i = 2;i < MAX; i ++  ) {
        if( f[i] == 6) flag1 ++;
        if(f[i] == 7) flag2++;
    }

    //2printf("%d %d\n", flag1,flag2);
    scanf( "%d", &t );
    while( t -- ) {
        scanf( "%d%d", &l, &r );
        int ma = 0;
        memset(num, 0 ,sizeof(num));
        for ( int i = l; i <= r; i ++ ) {
            num[f[i]] ++;
        }
        ma = 0;
        for( int i = 1; i < 50; i ++ )
            if(num[i]>=2) ma=i;
            /*
        for( int i = 1; i < 50; i ++ ) {
            for( int j = i + 1; j < 50; j ++ ) {
                if(num[i]&&num[j])
                    ma = max(ma, gcd(i,j));
            }
        }
        */
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
