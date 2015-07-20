//Ê÷×´Êý×é
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAX 1000001
#define ll long long
using namespace std;

struct edge {
    int x,y;
}e[MAX];

int n,m,k;
ll ar[MAX];

bool cmp(edge a,edge b){
    if(a.x!=b.x) return a.x<b.x;
    return a.y<b.y;
}

int lowbit(int x) {
    return x&(-x);
}

ll sum(int i){
    ll s=0;
    for(;i>0;s+=ar[i],i-=lowbit(i));
    return s;
}

void add(int i) {
    for(;i<=m;ar[i]++,i+=lowbit(i));
}

int main()
{
    int t,cnt=1;
    scanf("%d",&t);
    while(t--) {
        scanf("%d%d%d",&n,&m,&k);
        memset(ar,0,sizeof(ar));
        for(int i=0;i<k;i++)
            scanf("%d%d",&e[i].x,&e[i].y);
        sort(e,e+k,cmp);
        ll ans=0;
        for(int i=0;i<k;i++) {
            ans+=sum(m)-sum(e[i].y);
            add(e[i].y);
        }
        printf("Test case %d: ",cnt++);
        printf("%lld\n",ans);
    }
    return 0;
}
