#include <cstdio>
#include <cstring>

int dp[21][21][21];

int func(int a,int b,int c) {
    if(a<=0||b<=0||c<=0)
        return 1;
    if(a>20||b>20||c>20)
        return func(20,20,20);
    if(dp[a][b][c])
        return dp[a][b][c];
    if(a<b&&b<c)
        return (dp[a][b][c]=func(a,b,c-1)+func(a,b-1,c-1)-func(a,b-1,c));
    return (dp[a][b][c]=func(a-1,b,c)+func(a-1,b-1,c)+func(a-1,b,c-1)-func(a-1,b-1,c-1));
}

int main()
{
    int a,b,c;
    while(scanf("%d%d%d",&a,&b,&c)) {
        memset(dp,0,sizeof(dp));
        if(a==-1&&b==-1&&c==-1) break;
        printf("w(%d, %d, %d) = %d\n",a,b,c,func(a,b,c));
    }
    return 0;
}
