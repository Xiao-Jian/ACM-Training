//种类并查集
#include <cstdio>
#define MAX 100001

int father[MAX],re[MAX];

int Find(int x) {
    if(father[x]==x)
        return x;
    int tmp=father[x];
    father[x]=Find(father[x]);
    re[x]=(re[x]+re[tmp])%2;
    return father[x];
}

void Union(int x,int y) {
    int fx=Find(x);
    int fy=Find(y);
    father[fx]=fy;
    if(re[y]==0)
        re[fx]=1-re[x];
    else
        re[fx]=re[x];
}

int main()
{
    int t,n,m,x,y;
    scanf("%d",&t);
    while(t--) {
        scanf("%d %d",&n,&m);
        for(int j=1;j<=n;++j) {
            father[j]=j;
            re[j]=0;
        }
        while(m--) {
            char a;
            scanf(" %c %d %d",&a,&x,&y);
            if(a=='A') {
                if(Find(x)!=Find(y)) {
                    printf("Not sure yet.\n");
                }
                else if(re[x]==re[y])
                    printf("In the same gang.\n");
                else
                    printf("In different gangs.\n");
            }
            else
                Union(x,y);
        }
    }
    return 0;
}
