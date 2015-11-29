#include <iostream>
#include <cstdio>
#include <vector>
#define MAX 10001
using namespace std;

vector<int> p;
void prime() {
    p.push_back(2);
    for( int i = 3; i <= MAX ; i ++) {
        bool flag = true;
        for ( int j = 0; j < p.size() && p[j] * p[j] <= i; j ++ ) {
            if( i % p[j] == 0) {
                flag = false;
                break;
            }
        }
        if( flag )
            p.push_back(i);
    }
}

int main()
{
    prime();
    int t, n;
    scanf("%d", &t);
    while( t -- ) {
        scanf("%d", &n);
        int mi, ma;
        //printf("%d\n", p[0]);
        for(int i = 0; i <= MAX; i ++) {
            //printf("%d\n", p[i]);
            if(p[i]*p[i] > n) {
                ma = p[i]*p[i];
                if(i == 0)
                    mi = -MAX;
                else
                    mi = p[i-1]*p[i-1];
                break;
            }
        }
        if( (ma - n) < (n - mi) )
            printf("%d\n", ma);
        else
            printf("%d\n", mi);
    }
    return 0;
}
