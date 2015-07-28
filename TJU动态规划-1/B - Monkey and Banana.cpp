#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

struct node {
    int x, y, z;
    int base;
}block[91];
int n,x,y,z,cnt;
int dp[91];

void add(int x,int y,int z) {
    block[cnt].x = (x>y)?x:y;
    block[cnt].y = (x<y)?x:y;
    block[cnt].base = x * y;
    block[cnt++].z = z;
    block[cnt].x = (y>z)?y:z;
    block[cnt].y = (y<z)?y:z;
    block[cnt].base = z * y;
    block[cnt++].z = x;
    block[cnt].x = (z>x)?z:x;
    block[cnt].y = (z<x)?z:x;
    block[cnt].base = x * z;
    block[cnt++].z = y;
}

bool cmp( node a, node b ) {
    return a.base > b.base;
}

int main()
{
    int s=1;
    while( scanf( "%d", &n ), n ) {
        cnt = 0;
        for( int i = 0; i < n; i ++ ) {
            scanf( "%d%d%d", &x, &y, &z );
            add( x, y, z);
        }
        sort( block, block + cnt, cmp );
        for( int i =0; i < cnt; i ++ )
            dp[i] = block[i].z;

        for( int i = 0; i < cnt; i ++ ) {
            for( int j = 0; j < i; j ++ ) {
                if( block[i].x < block[j].x && block[i].y < block[j].y )
                    dp[i] = max( dp[i], dp[j] + block[i].z);
            }
        }

        int ans = 0;
        for( int i = 0; i < cnt; i ++ )
            if( ans < dp[i] )
                ans = dp[i];
        printf("Case %d: maximum height = %d\n",s++,ans);
    }
    return 0;
}
