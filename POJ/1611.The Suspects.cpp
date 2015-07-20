/*
OJ: POJ
ID: 3013216109
TAST: 1611.The Suspects
LANG: C++
NOTE: 并查集
*/
#include <cstdio>
#include <cstring>

const int MAX=30005;
int father[MAX];

int Find(int x) {
    if(father[x]==x)
        return x;
    father[x]=Find(father[x]);
    return father[x];
}

void Union(int x,int y) {
    x=Find(x);
    y=Find(y);
    if(x<y)
        father[y]=x;
    else if(x>y)
        father[x]=y;
}

int main()
{
    int n,m,k,x,y;
    while(scanf("%d %d",&n,&m),n+m) {
        for(int i=0;i<n;i++)
            father[i]=i;
        while(m--) {
            scanf("%d",&k);
            scanf("%d",&y);
            for(int i=1;i<k;i++) {
                scanf("%d",&x);
                Union(x,y);
                y=x;
            }
        }
        int ans=0;
        for(int i=0;i<n;i++) {
            if(Find(i)==0)
                ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
