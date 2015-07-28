#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#define MAX_V 101
#define MAX_E 10000<<1
using namespace std;

struct edge {
    int from,to,val;
}e[MAX_E];
int n,cnt,length,father[MAX_V];

bool cmp(const edge& a,const edge& b) {
    return a.val<b.val;
}

void init() {
    cnt=0;
    length=0;
    for(int i=0;i<=n;i++)
        father[i]=i;
}

int Find(int x) {
    if(x==father[x])
        return x;
    father[x]=Find(father[x]);
    return father[x];
}

void Union(int i) {
    int x=Find(e[i].from);
    int y=Find(e[i].to);
    if(x!=y) {
        length+=e[i].val;
        father[x]=y;
    }
}

void addedge(int from,int to,int val) {
    e[cnt].from=from;
    e[cnt].to=to;
    e[cnt++].val=val;
}

void Kruskal() {
    init();
    int x,y,val;
    for(int i=1;i<=n*(n-1)/2;i++) {
        scanf("%d%d%d",&x,&y,&val);
        addedge(x,y,val);
        addedge(y,x,val);
    }
    sort(e,e+cnt,cmp);
    for(int i=0;i<cnt;i++) {
        Union(i);
    }
    printf("%d\n",length);
}

int main()
{
    while(scanf("%d",&n),n)
        Kruskal();
    return 0;
}
