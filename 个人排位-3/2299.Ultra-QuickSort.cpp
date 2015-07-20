/*
OJ: POJ
ID: 3013216109
TASK: 2299.Ultra-QuickSort
LANG: C++
NOTE: Ê÷×´Êý×é
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAX 500001
using namespace std;

int re[MAX],ar[MAX];
int n;

struct node {
    int val,pos;
}num[MAX];

bool cmp(const node &a,const node &b) {
    return a.val<b.val;
}

int lowbit(int x) {
    return x&(-x);
}

int sum(int x) {
    int s=0;
    for(;x>0;s+=ar[x],x-=lowbit(x));
    return s;
}

void add(int x) {
    for(;x<=n;ar[x]++,x+=lowbit(x));
}

int main()
{
    while(scanf("%d",&n),n) {
        for(int i=0;i<n;i++) {
            scanf("%d",&num[i].val);
            num[i].pos=i;
        }
        memset(ar,0,sizeof(ar));
        sort(num,num+n,cmp);
        for(int i=0;i<n;i++)
            re[num[i].pos]=i+1;
        long long ans=0;
        for(int i=0;i<n;i++) {
            ans+=sum(n)-sum(re[i]);
            add(re[i]);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
