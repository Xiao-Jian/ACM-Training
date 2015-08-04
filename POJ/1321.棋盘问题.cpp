/*
OJ: POJ
ID: 3013216109
TASK: 1321.∆Â≈ÃŒ Ã‚
LANG: C++
NOTE: DFS
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int n, k, ans;
char str[10][10];
vector< pair< int, int > > v;
int rvis[100], cvis[100];

void dfs(int s, int rt) {
    if( rt == k ) {
        ans ++;
        return;
    }

    for( int i = s; i < v.size(); i ++ ) {
        pair<int, int> pr = v.front();
        int tmpi = pr.first, tmpj = pr.second;
        if( !rvis[tmpi] && !cvis[tmpj] ) {
            cvis[tmpi] = 1;
            rvis[tmpj] = 1;
            dfs( s + 1, rt + 1 );
            cvis[tmpi] = 0;
            rvis[tmpj] = 0;
        }
    }

}

int main()
{
    while( scanf( "%d%d", &n, &k ) !=EOF ) {
        if( n == -1 && k == -1 ) break;
        for( int i = 0; i < n; i ++ ) {
            scanf( "%s", &str );
            for( int j = 0; j < n; j ++ ) {
                if( str[i][j] =='#' ) {
                    v.push_back( make_pair(i, j) );
                }
            }
        }
        memset( cvis, 0, sizeof(cvis) );
        memset( rvis, 0, sizeof(rvis) );
        ans = 0;
        //if( dfs( 0, 0 ) )
        dfs( 0, 0 );
            printf( "%d\n", ans );
    }
}
