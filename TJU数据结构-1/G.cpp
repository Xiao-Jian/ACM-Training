/*
OJ: Virtual Judge
ID: xiaojian
TAST: TJU数据结构-1 G
LANG: C++
NOTE: STL堆
*/
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX_M=105,MAX_N=2005;
int a[MAX_M][MAX_N];
int sum[MAX_N],ans[MAX_N];

int main()
{
    int t,m,n,i,j,k;
    scanf("%d",&t);
    while(t--) {
        scanf("%d %d",&m,&n);
        for(i=0;i<m;i++)
            for(j=0;j<n;j++)
                scanf("%d",&a[i][j]);
        for(j=0;j<n;j++)
            sum[j]=a[0][j];

        for(i=1;i<m;i++) {
            sort(sum,sum+n);
            sort(a[i],a[i]+n);
            for(k=0;k<n;k++)
                ans[k]=sum[k]+a[i][0];
            make_heap(ans,ans+n);
            for(j=1;j<n;j++) {
                for(k=0;k<n;k++) {
                    int x=sum[k]+a[i][j];
                    if(x<ans[0]) {
                        pop_heap(ans,ans+n);
                        ans[n-1]=x;
                        push_heap(ans,ans+n);
                    }
                    else break;
                }
            }
            for(j=0;j<n;j++)
                sum[j]=ans[j];
        }
        sort(sum,sum+n);
        for(j=0;j<n-1;j++)
            printf("%d ",sum[j]);
        printf("%d\n",sum[n-1]);
    }
}
