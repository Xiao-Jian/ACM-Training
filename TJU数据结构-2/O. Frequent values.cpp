#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int MAX=100005;
int a[MAX],dp[MAX][18];
int cnt[MAX];

struct trip {
    int s,e;
    int num;
}wap[MAX];

int main()
{
    int n,q,x,y,i,j;
    while(scanf("%d",&n),n) {
        scanf("%d",&q);
        memset(wap,0,sizeof(wap));
        memset(cnt,0,sizeof(cnt));
        int k=1;
        scanf("%d",&a[1]);
        wap[k].s=1;
        for(i=2;i<=n;i++) {
            scanf("%d",&a[i]);
            if(a[i]==a[i-1]) {
                cnt[k]++;
                //wap[k].e=i;
                wap[i].s=wap[i-1].s;
            }
            else {
                cnt[k]++;
                wap[i].e=i-1;
                k++;
                wap[i].s=i;
            }
        }
        wap[n+1].e=n;
        cnt[k]++;
        for(i=1,j=1;i<=n;) {
            for(int f=i;f<i+cnt[j];f++)
                wap[f].num=j;
            for(int f=i+1;f<i+cnt[j];f++)
                wap[f].s=wap[f-1].s;
            for(int f=i+cnt[j]-1;f>=i;f--)
                wap[f].e=wap[f+1].e;
            i+=cnt[j];j++;
        }

        int f;
        for(f=17;f>=0;f--)
            if((1<<f)<=k)
                break;
        f++;
        int p=floor(log((double)(n+1))/log(2.0));
        for(i=1;i<=k;i++)
            dp[i][0]=cnt[i];
        for(j=1;j<=p;j++)
            for(i=1;i+(1<<j)-1<=k;i++)
                dp[i][j]=max(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);

        while(q--) {
            scanf("%d %d",&x,&y);
            int i,st,rt,ans;
            st=wap[x].num;
            rt=wap[y].num;
            if((rt-st)==0)
                ans=y-x+1;
            else if((rt-st)==1)
                ans=max(wap[x].e-x+1,y-wap[y].s+1);
            else {
                int p=floor((log((double)(rt-st-1))/log(2.0)));
                ans=max(dp[st+1][p],dp[rt-(1<<p)][p]);
                ans=max(wap[x].e-x+1,ans);
                ans=max(ans,y-wap[y].s+1);
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}
