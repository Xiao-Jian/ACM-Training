#include <stdio.h>
#include <cstring>
using namespace std;

int father[10002], cnt[10002],size[10002];
int Find(int x) {
    int tmp=father[x];
    if(x!=father[x])
        father[x]=Find(father[x]);
    cnt[x]+=cnt[tmp];
    return father[x];
}
void Union(int x,int y) {
    x=Find(x);
    y=Find(y);
    if(x==y) return;
    cnt[x]++;
    father[x]=y;
    size[y]+=size[x];
}

int main()
{
    int t,n,q,a,b,i=1;
    scanf("%d",&t);
    while(t--) {
        printf("Case %d:\n",i++);
        scanf("%d %d",&n,&q);
        for(int j=1;j<=n;j++) {
            father[j]=j;
            size[j]=1;
            cnt[j]=0;
        }
        while(q--) {
            char str;
            getchar();
            str=getchar();
            if(str=='T') {
                scanf("%d %d",&a,&b);
                Union(a,b);
            }
            else if(str=='Q'){
                scanf("%d",&a);
                int x=Find(a);
                printf("%d %d %d\n",x,size[x],cnt[a]);
            }
        }
    }
    return 0;
}
