#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#define MAX 100005
using namespace std;

long long ar[MAX];
vector< pair< int, int > > v;

int main()
{
    long long t, n;
    scanf( "%lld", &t );
    while( t -- ) {
        scanf( "%lld", &n );
        long long sum = 0;
        for( int i = 1; i <= n; i ++ ) {
            scanf( "%lld", &ar[i] );
            sum += ar[i];
        }

        long long m = sum % n;
        if( m ) {
            printf( "NO\n");
        }
        else {
            v.clear();
            m = sum / n;
            int flag = 1;
            for( int i = 1; i <= n; i ++ ) {
                if( fabs( ar[i] - m ) > 2 ) {
                    flag = 0;
                    printf( "NO\n" );
                    break;
                }
            }

            if( flag ) {
                int mi = 0;
                int pos = 1;
                ar[n+1] = ar[1];
                for( int i = 1; i <= n + 1; i ++ )
                    if( mi < ar[i] && ar[i+1]<ar[i] ) {
                        mi = ar[i];
                        pos = i;
                    }
                if( pos == n + 1 ) pos = 1;
                for( int i = pos; i <= pos + n - 1; i ++ ) {
                    if( i == n ) {
                        if( ar[i] < m ) {
                            ar[i] ++;
                            ar[1] --;
                            v.push_back( make_pair( 1, i ) );
                            continue;
                        }
                        else if ( ar[i] > m ) {
                            ar[i] --;
                            ar[1] ++;
                            v.push_back( make_pair( i, 1 ) );
                            continue;
                        }
                        else
                            continue;
                    }
                    if( i > n ) {
                        int u = i - n;
                        if( ar[u] < m ) {
                            ar[u] ++;
                            ar[u + 1] --;
                            v.push_back( make_pair( u + 1, u ) );
                            continue;
                        }
                        else if ( ar[u] > m ) {
                            ar[u] --;
                            ar[u + 1] ++;
                            v.push_back( make_pair( u, u + 1 ) );
                            continue;
                        }
                        else
                            continue;
                    }
                    if( ar[i] < m ) {
                        ar[i] ++;
                        ar[i+1] --;
                        v.push_back( make_pair( i + 1, i ) );
                    }
                    else if ( ar[i] > m ) {
                        ar[i] --;
                        ar[i+1] ++;
                        v.push_back( make_pair( i, i + 1 ) );
                    }
                    else
                        continue;
                }
            }

            flag = 1;
            for( int i = 1; i <= n; i ++ ) {
                if( ar[i] != m ) {
                    flag = 0;
                    printf( "NO\n" );
                    break;
                }
            }
            if( flag ) {
                printf( "YES\n" );
                printf( "%d\n", v.size() );
                for( int i = 0; i < v.size(); i ++ )
                    printf( "%d %d\n", v[i].first, v[i].second );
            }
        }

    }
    return 0;
}
