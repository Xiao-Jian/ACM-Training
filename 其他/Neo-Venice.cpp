#include <cstdio>

int main()
{
    int n, t, s;
    int ar[110];
    while( scanf( "%d%d%d", &n, &t, &s ) !=EOF ) {
        for( int i = 0; i < n; i ++ )
            scanf( "%d", &ar[i] );

        for( int i = 0; i < n; i ++ ) {
            printf( "%.6lf\n", ( ar[i] - s + t ) * 1.0 / 2 + s );
        }
    }
    return 0;
}
