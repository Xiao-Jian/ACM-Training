#include <cstdio>
#include <algorithm>
#define MAX 100001
#define INF 1000000007
using namespace std;

int a[MAX];

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF) {
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        sort(a,a+n);
        int x=0,sum=0;
        for(int i=1;i<=n;i++) {
            x+=i;
            x%=INF;
            sum+=x;
            sum%=INF;
        }
        //printf("%d\n",sum);
        int ans=0;
        for(int i=1;i<=n;i++) {
            for(int k=i;k<=n;k++) {
                for(int p=i;p<k;p++)
                    if(a[k]%a[p]==0) {
                        ans++;
                        ans%=INF;
                        break;
                    }
            }
        }
        printf("%d\n",sum-ans-n);
    }
}
