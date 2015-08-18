/*
OJ: POJ
ID: 3013216109
TASK: 1659.Frogs' Neighborhood
LANG: C++
NOTE: Havel∂®¿Ì
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int t, n;
int mat[15][15];
struct node {
    int ar;
    int pos;
}e[15];

bool cmp(node a, node b) {
    return a.ar > b.ar;
}

int main()
{
    scanf( "%d", &t );
    while( t -- ) {
        scanf( "%d", &n );
        for( int i = 0; i < n; i ++ ) {
            scanf( "%d", &e[i].ar );
            e[i].pos = i;
        }

        memset( mat, 0, sizeof(mat) );
        sort( e, e + n, cmp );
        int flag = 1;
        for( int i = 0; i < n ; i ++ ) {
            sort( e + i + 1, e + n, cmp );
            for( int j = i + 1; j <= e[i].ar + i; j ++ ) {
                e[j].ar --;
                if( e[j].ar < 0 ) {
                    flag = 0;
                    break;
                }
                mat[e[i].pos][e[j].pos] = mat[e[j].pos][e[i].pos] = 1;
            }
            if( !flag ) break;
        }
        if( !flag )
            printf( "NO\n\n" );
        else {
            printf( "YES\n" );
            for( int i = 0; i < n; i ++ ) {
                for( int j = 0; j < n - 1; j ++ )
                    printf( "%d ", mat[i][j] );
                printf( "%d\n", mat[i][n - 1] );
            }
            printf( "\n" );
        }
    }
    return 0;
}
