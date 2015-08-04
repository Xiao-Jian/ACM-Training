#include <cstdio>

int main()
{
    int n, m;
    while( ~scanf( "%d%d", &n, &m ) ) {
        if( n >= m )
            printf( "%d\n", n - m );
        else {
            int cnt = 0;
            while( n < m ) {
                m % 2 ? m++ : m /= 2;
                cnt ++;
            }
            printf( "%d\n", n - m + cnt );
        }
    }
    return 0;
}
