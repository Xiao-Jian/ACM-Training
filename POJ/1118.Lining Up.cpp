#include <cstdio>
#include <iostream>
#define MAX 701
using namespace std;

int a[MAX], b[MAX];

int main()
{
    int n;
    while( scanf( "%d", &n ), n ) {
        for( int i = 0; i < n; i ++ ) {
            scanf( "%d%d", &a[i], &b[i] );
        }
        int m = 0, sum;
        for( int i = 0; i < n; i ++ ) {
            for( int j = i + 1; j < n; j ++ ) {
                sum = 2;
                for( int k = j + 1; k < n; k ++ ) {
                    int x = ( a[k] - a[j] ) * ( b[j] - b[i] );
                    int y = ( a[j] - a[i] ) * ( b[k] - b[j] );
                    if( x == y ) sum ++;
                }
                m = ( sum > m ) ? sum : m;
            }
        }
        printf( "%d\n", m );
    }
    return 0;
}
