#include<cstdio>
#define ll long long
#define INF 1000000007
#define MAX 10010
using namespace std;

ll num[MAX];

int exgcd( ll a, ll b, ll& x, ll& y ) {
    if( b == 0 ) {
        x = 1;
        y = 0;
        return a;
    }
    ll ret = exgcd( b, a % b, x, y );
    ll tmp = x;
    x = y;
    y = tmp - a / b * y;
    //y = ( ( tmp - a / b * y ) % mod + mod ) % mod;
    return ret;
}

int main()
{
    num[2]=1;
    num[3]=1;
    for(int i=3;i<10030;i++){
        ll x,y;
        ll ret = exgcd(i,INF,x,y)%INF;
        num[i+1]=((((4*i-6)*num[i])%INF*x)%INF+INF)%INF;
    }

    int n;
    while(scanf("%d",&n)!=EOF)
        printf("%lld\n",num[n+2]);
    return 0;
}
