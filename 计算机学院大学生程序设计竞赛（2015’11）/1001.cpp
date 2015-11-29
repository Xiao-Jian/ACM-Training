#include <iostream>
#include <cstdio>
using namespace std;

int func(int n) {
    if( n == 1 )
        return 0;
    if( n == 2 )
        return 0;
    if(n&1)
        return func(n/2) + func(n/2+1) +1;
    else
        return func(n/2) + func(n/2);
}

int main()
{
    int t, n;
    scanf("%d", &t);
    while( t -- ) {
        scanf("%d", &n);
        printf("%d\n", func(n));
    }
    return 0;
}
