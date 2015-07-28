#include <cstdio>
#include <iostream>
#define Max 1000001

int euler[Max];
void Init(){
     euler[1] = 1;
     for( int i = 2; i < Max; i ++ )
       euler[i] = i;
     for( int i = 2; i < Max; i ++ )
        if( euler[i] == i )
           for( int j = i; j < Max; j += i )
              euler[j] = euler[j] / i * ( i - 1 );
}

int main()
{
    int t,n;
    scanf( "%d", &t);
    Init();
    while( t -- ) {
        scanf( "%d", &n );
        printf( "%d\n", euler[n] );
    }
    return 0;
}
