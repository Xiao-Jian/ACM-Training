/*
OJ: HDOJ
ID: forever
TASK: 5386.Cover
LANG: C++
NOTE: NO
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#define MAX 110
using namespace std;

int ar[MAX][MAX], a[MAX*5], b[MAX*5];
char op[MAX*5];
int ans[MAX*5];

int main()
{
    int t, n, m;
    scanf( "%d", &t );
    char ch;
    while( t -- ) {
        scanf( "%d%d", &n, &m );
        for( int i = 1; i <= n; i ++ )
            for( int j = 1; j <= n; j ++ )
                scanf( "%d", &ar[i][j] );
        for( int i = 1; i <= n; i ++ )
            for( int j = 1; j <= n; j ++ )
                scanf( "%d", &ar[i][j] );

        for( int i = 1; i <= m; i ++ ) {
            for( ch = getchar(); ch != 'H' && ch != 'L'; ch = getchar() );
            op[i] = ch;
            scanf( "%d%d", &a[i], &b[i] );
        }

        int cas = 1;
        memset( ans, 0, sizeof(ans) );
        while( cas <= m ) {
            for( int i = 1; i <= m; i ++ ) {
                if( a[i] ) {
                    int k = a[i];
                    if( op[i] == 'H' ) {
                        int flag = 1;
                        for( int j = 1; j <= n; j ++ )
                            if( ar[k][j] && ar[k][j] != b[i] ) {
                                flag = 0;
                                break;
                            }
                        if( flag ) {
                            ans[cas++] = i;
                            a[i] = 0;
                            for( int j = 1; j <= n; j ++ )
                                ar[k][j] = 0;
                        }
                    }
                    else {
                        int flag = 1;
                        for( int j = 1; j <= n; j ++ )
                            if( ar[j][k] && ar[j][k] != b[i] ) {
                                flag = 0;
                                break;
                            }
                        if( flag ) {
                            ans[cas++] = i;
                            a[i] = 0;
                            for( int j = 1; j <= n; j ++ )
                                ar[j][k] = 0;
                        }
                    }
                }
            }
        }
        for( int i = m; i >= 1; i -- )
            printf( "%d ", ans[i] );
        printf( "\n" );
    }
    return 0;
}
