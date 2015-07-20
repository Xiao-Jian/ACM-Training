//DP
#include <cstdio>
#include <cstring>
#define MAX 121

int dp[MAX][MAX];

int main()
{
    int n;
    memset(dp,0,sizeof(dp));
    for(int i=1;i<121;i++) {
        for(int j=1;j<121;j++) {
            if(i<j)
                dp[i][j]=dp[i][i];
            else if(i==j)
                dp[i][j]=dp[i][j-1]+1;
            else
                dp[i][j]=dp[i][j-1]+dp[i-j][j];
        }
    }
    while(scanf("%d",&n)!=EOF)
        printf("%d\n",dp[n][n]);
    return 0;
}
