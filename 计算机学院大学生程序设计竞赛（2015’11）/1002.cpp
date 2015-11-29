#include <iostream>
#include <cstdio>
#define MAX 10005
using namespace std;

int n, a, b, c, v;

int func(int v) {
    if( v < a )
        return 0;
    else if(v < b)
        return 2;
    else if(v < c)
        return 3;
    else
        return 4;
}

int main()
{
    while(scanf("%d%d%d%d", &n, &a, &b, &c) != EOF ) {
        int sum = 0, num = 0;
        for( int i = 0; i < n; i ++ ) {
            scanf("%d", &v);
            num += v;
            if(num >= a) {
                sum += func(num);
                num = 0;
            }
        }
        printf("%d\n", sum);
    }
    return 0;
}
