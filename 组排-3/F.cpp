#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#define ll long long
#define MAX
using namespace std;

typedef struct point {
    ll a, b;
    double val;
    ll sum;
};
char str[20];

int main()
{
    int t;
    scanf( "%d", &t );
    while( t -- ) {
        scanf( "%s", str );
        int len = strlen(str);
        ll x = 0, y = 1;
        int u, v = len;
        int flag = 0;
        for( int i = 0; i < len; i ++ ) {
            if( str[i] == '.' ) {
                flag = 1;
                u = i;
                for( int j = 0; j < i - 1; j ++ ) {
                    x += ( str[j] - '0' );
                    x *= 10;
                }
                x += ( str[i-1] - '0' );
            }
            if( str[i] == '[' ) {
                u = i;
                flag = 2;
            }
            if( str[i] == ']' )
                v = i;
        }
        point num1;
        if( flag == 1 ) {
            num2.b = 1;
            for( int i = u + 1; i < v; i ++ ) {
                x *= 10;
                x += ( str[i] - '0' );
                num2.b *= 10;
            }
            num1.a = x;
            num1.sum = x + num1.b;
            num1.val = ( x * 1.0 ) / ( num1.b * 1.0 );
        }
        else if( flag == 2 ) {

        }
        else {
            num1.a = x;
            num1.b = 1;
            num1.val = x * 1.0;
            num1.sum = x + 1;
        }
    }
}
