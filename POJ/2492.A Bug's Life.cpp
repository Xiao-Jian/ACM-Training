#include <cstdio>
#define MAX 2005

int father[MAX],re[MAX];

int Find(int x) {
    if(father[x]==x)
        return x;
    int tmp=father[x];
    father[x]=Find(father[x]);
    re[x]=(re[x]+re[tmp]+1)%2;
    return father[x];
}

void Union(int x,int y) {
    int fx=Find(x);
    int fy=Find(y);
    father[fx]=fy;
    re[fx]=(re[y]-re[x])%2;
}

int main()
{
    int t,m,n,x,y,k=1;
    scanf("%d",&t);
    while(t--) {
        scanf("%d %d",&m,&n);
        for(int j=1;j<=m;++j) {
            father[j]=j;
            re[j]=1;
        }
        int flag=0;
        while(n--) {
            scanf("%d %d",&x,&y);
            if(Find(x)==Find(y)) {
                if(re[x]==re[y])
                    flag=1;
            }
            else
                Union(x,y);
        }
        printf("Scenario #%d:\n",k++);
        if(flag)
            printf("Suspicious bugs found!\n\n");
        else
            printf("No suspicious bugs found!\n\n");
    }
    return 0;
}
