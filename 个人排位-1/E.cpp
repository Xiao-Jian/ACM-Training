//0-1±³°ü+DP
#include <cstdio>
#include <cstring>
using namespace std;

const int MAX_N=3404;
const int MAX_M=12882;
int w[MAX_N],d[MAX_N];
int dp[MAX_M];

int ma(int a,int b) {
    return a>b?a:b;
}

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++) {
        scanf("%d %d",&w[i],&d[i]);
    }

    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++) {
        for(int j=m;j>=0;j--) {
            if(j>=w[i])
                dp[j]=ma(dp[j-w[i]]+d[i],dp[j]);
        }
    }
    printf("%d\n",dp[m]);
    return 0;
}
