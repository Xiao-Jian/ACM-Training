#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#define MAX 100050
#define INF 1000000007
#define ll long long
using namespace std;

int n;
ll a[MAX], b[MAX], c[MAX];
ll sumA[MAX], sumB[MAX];

int main()
{
    while( scanf( "%d", &n ) != EOF ) {
        memset( sumA, 0, sizeof(sumA) );
        memset( sumB, 0, sizeof(sumB) );
        for( int i = 1; i <= n; i ++ ) {
            scanf( "%lld", &a[i] );
            sumA[i] = sumA[i-1] + a[i];
        }
        for( int i = 1; i <= n; i ++ ) {
            scanf( "%lld", &b[i] );
            sumB[i] = sumB[i-1] + b[i];
        }
        memset( c, 0, sizeof(c) );
        c[1] = ( a[1] * b[1] ) % INF;
        for( int i = 2; i <= n; i ++ ) {
            c[i] = ( b[i] * (sumA[i-1]%INF) + a[i] * (sumB[i-1]%INF) + a[i]*b[i] ) % INF;
        }
        for( int i = 1; i < n; i ++ )
            printf( "%lld ", c[i] );
        printf( "%lld\n", c[n] );
    }
    return 0;
}
