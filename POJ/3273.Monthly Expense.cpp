/*
OJ: POJ
ID: 3013216109
TASK: 3273.Monthly Expense
LANG: C++
NOTE: ¶þ·Ö
*/
#include <cstdio>
#include <algorithm>
#define MAX_N 100001
using namespace std;

int money[MAX_N];
int n,m;

int main()
{
    int l=0,r=0;
    while(scanf("%d%d",&n,&m)!=EOF) {
        for(int i=0;i<n;i++) {
            scanf("%d",&money[i]);
            if(l<money[i]) l=money[i];
            r+=money[i];
        }
        int mid;
        while(l<=r) {
            mid=(l+r)/2;
            int num=1,sum=0;
            for(int i=0;i<n;i++) {
                if(sum+money[i]<=mid)
                    sum+=money[i];
                else {
                    sum=money[i];
                    num++;
                }
            }
            if(num<=m) r=mid-1;
            else l=mid+1;
        }
        printf("%d\n",mid);
    }
    return 0;
}
