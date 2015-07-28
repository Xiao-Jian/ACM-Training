#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int t,n,v;
    int w[1001],p[1001],dp[1001];
    scanf("%d",&t);
    while(t--) {
        scanf("%d%d",&n,&v);
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++)
            scanf("%d",&p[i]);
        for(int i=0;i<n;i++)
            scanf("%d",&w[i]);
        for(int i=0;i<n;i++)
            for(int j=v;j>=w[i];j--)
                dp[j]=max(dp[j],dp[j-w[i]]+p[i]);
        printf("%d\n",dp[v]);
    }
    return 0;
}
