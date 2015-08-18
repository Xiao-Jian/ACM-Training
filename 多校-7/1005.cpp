#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#define MAX 5000001
using namespace std;

int num[MAX];
int ar[MAX];

int main()
{
    int t, cas = 1;
    long long n;
    while( scanf( "%I64d %d", &n, &t ) != EOF ) {
        long long sum1 = 0, sum2 = 0;
        if( n == -1 && t == -1 ) break;

        int cnt = 0;
        long long tmp;
        for( int i = 0; n > 0; i ++ ) {
            num[i] = n % 10;
            n /= 10;
            cnt ++;
        }

        for( int i = 0; i < cnt / 2; i ++ ) {
            int tmp1 = num[i];
            num[i] = num[cnt - 1 - i];
            num[cnt - 1 - i] = tmp1;
        }

        int flag = 1;
        for( int i = 0; i < cnt; i ++ ) {
            if( i % 2 == 0 ) {
                flag = 1;
                sum1 += num[i];
            }
            else {
                flag = 0;
                sum2 += num[i];
            }
        }

        for( int i = 0; i < t; i ++ ) {
            n = sum1 + sum2;
            int cnt1 = 0;
            for( int i = 0; n > 0; i ++ ) {
                ar[i] = n % 10;
                n /= 10;
                cnt1 ++;
            }
            tmp = cnt + cnt1;
            for( int j = 1; cnt < tmp; cnt ++, j ++ ) {
                num[cnt] = ar[cnt1 - j];
                if( flag ) {
                    sum2 += num[cnt];
                    flag = 0;
                }
                else {
                    sum1 += num[cnt];
                    flag = 1;
                }
            }

        }
        tmp = sum1 - sum2;
        if( tmp < 0 ) tmp = -tmp;
        if( tmp % 11 == 0 )
            printf( "Case #%d: Yes\n", cas ++ );
        else
            printf( "Case #%d: No\n", cas ++ );
    }
    return 0;
}
