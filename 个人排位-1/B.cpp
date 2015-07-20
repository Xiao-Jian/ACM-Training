//最小生成树+并查集
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX_E=80*2;
const int MAX_V=30;

struct edge {
    int from;
    int to;
    int val;
}e[MAX_E];
int cnt;
int father[MAX_V];

void add(int from,int to,int val) {
    e[cnt].from=from;
    e[cnt].to=to;
    e[cnt].val=val;
    cnt++;
}

int cmp(edge i,edge j) {
    return i.val<j.val;
}

int Find(int x) {
    if(father[x]==x)
        return x;
    father[x]=Find(father[x]);
    return father[x];
}

int main()
{
    int n,m,l,ans;
    char a,b;
    while(scanf("%d",&n),n) {
        cnt=0;
        ans=0;
        for(int i=0;i<=n;i++)
            father[i]=i;

        for(int i=1;i<n;i++) {
            cin >>a;
            cin >>m;
            for(int j=0;j<m;j++) {
                cin >>b;
                cin >>l;
                int x=b-64;
                add(i,x,l);
            }
        }
        sort(e,e+cnt,cmp);

        for(int i=0;i<cnt;i++) {
            int x=Find(e[i].from);
            int y=Find(e[i].to);
            if(x!=y) {
                ans+=e[i].val;
                father[x]=y;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
