#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#define MAX 100005
using namespace std;

int a[MAX], b[MAX];
map<int, int> num;

int main()
{
    int n;
    while( scanf( "%d", &n ) != EOF ) {
        num.clear();
        int ans = 0;
        for( int i = 0; i < n; i ++ ) {
            scanf( "%d", &a[i] );
            ans ^= a[i];
        }
        for( int i = 0; i < n; i ++ ) {
            scanf( "%d", &b[i] );
            ans ^= b[i];
            num[b[i]] ++;
        }

        int i = 0;
        for( ; i < n; i ++ ) {
            if( !num[a[i] ^ ans] )
                break;
        }
        if( i == n )
            printf( "%d\n", ans );
        else
            puts( "-1" );

    }
}
