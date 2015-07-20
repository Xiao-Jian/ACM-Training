/*
OJ: Virtual Judge
ID: xiaojian
TASK: TJU数据结构-1 B
LANG: C++
NOTE: 并查集
*/
#include <cstdio>
#include <cstring>

const int MAX=1005;
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
    if(x!=y)
        father[x]=y;
}

int main()
{
    int n,m,x,y;
    while(scanf("%d",&n),n) {
        scanf("%d",&m);
        for(int i=1;i<=n;i++)
            father[i]=i;
        for(int i=0;i<m;i++) {
            scanf("%d %d",&x,&y);
            Union(x,y);
        }
        int ans=0;
        for(int i=1;i<=n;i++) {
            if(father[i]==i)
                ans++;
        }
        printf("%d\n",ans-1);
    }
    return 0;
}
