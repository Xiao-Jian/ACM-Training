#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cmath>
#define MAX 10010
#define ll long long
using namespace std;

typedef struct node {
    int x, y;
}f;

int gcd( int a, int b ) {
    return b == 0 ? a : gcd( b, a%b );
}

int lcm( int a, int b ) {
    return ( a / gcd( a, b ) * b );
}

f jianfa(f a, f b) {
    int lc = lcm(a.y, b.y);
    f ret;
    ret.y = lc;
    ret.x = lc / a.y * a.x - lc / b.y * b.x;
    //if( ret.x < 0 )
    int gc = gcd(ret.x, ret.y);
    if( gc != 1 ) {
        ret.x /= gc;
        ret.y /= gc;
    }
    return ret;
}

void guihua( f a ) {
    if( a.x == 0 ) {
        printf( "0 " );
        return;
    }
    if( a.y == 1 ) {
        printf( "%d ", a.x );
        return;
    }
    //if( )
}

int main()
{
    char str[10];
    int t;
    scanf( "%d", &t );
    while( t -- ) {
        scanf( "%s", str );
        int hh = (str[0]-'0')*10 + (str[1]-'0');
        int mm = (str[3]-'0')*10 + (str[4]-'0');
        int ss = (str[6]-'0')*10 + (str[7]-'0');

        f d1, d2, d3;
        d1.y = 12;
        d2.y = d3.y = 60;
        if( hh > 12 ) hh -= 12;
        d1.x = hh * 360;
        d2.x = mm * 360;
        d3.x = ss * 360;

        f ans1, ans2, ans3;
        ans1 = jianfa( d1, d2 );
        ans2 = jianfa( d1, d3 );
        ans3 = jianfa( d2, d3 );

        guihua(ans1);
        guihua(ans2);
        guihua(ans3);
        printf( "\n" );

    }
}
