//Tarjan
#include <stdio.h>
#include <string.h>
#define MAX_N 10001
#define MAX_M 100001

struct Edge {
    int to,next;
}e[MAX_M];

int n,m,head[MAX_N],dfn[MAX_N],low[MAX_N],s[MAX_N],num[MAX_N],du[MAX_N],vis[MAX_N];
int cnt,time,top,cut;

void addedge(int u,int v) {
    e[cnt].to=v;
    e[cnt].next=head[u];
    head[u]=cnt;
    cnt++;
}

int min(int a,int b) {
    return a<b?a:b;
}

void dfs(int u,int fa)
{
    dfn[u]=time;
    low[u]=time;
    time++;
    vis[u]=1;
    s[top]=u;
    top++;
    for(int i=head[u]; i!=-1; i=e[i].next)
    {
        int v=e[i].to;
        if(!vis[v])
        {
            dfs(v,u);
            low[u]=min(low[u],low[v]);
        }
        else if(vis[v])
        {
            low[u]=min(low[u],dfn[v]);
        }
    }
    if(low[u]==dfn[u])
    {
        cut++;
        while(top>0&&s[top]!=u)
        {
            top--;
            vis[s[top]]=2;
            num[s[top]]=cut;
        }
    }
}

int main()
{
    int i,x,y;
    scanf("%d%d",&n,&m);
    memset(dfn,0,sizeof(dfn));
    memset(low,0,sizeof(low));
    memset(head,-1,sizeof(head));
    memset(vis,0,sizeof(vis));
    memset(num,0,sizeof(num));
    memset(du,0,sizeof(du));
    cnt=0;
    time=1;
    top=0;
    cut=0;

    for(i=0; i<m; i++) {
        scanf("%d%d",&x,&y);
        addedge(x,y);
    }
    for(int i=1; i<=n; i++) {
        if(!vis[i])
            dfs(i,0);
    }
    for(i=1; i<=n; i++) {
        for(int j=head[i]; j!=-1; j=e[j].next) {
            if(num[i]!=num[e[j].to])
                du[num[i]]++;
        }
    }
    int flag=0,p;
    for(i=1; i<=cut; i++)
        if(!du[i]) {
            flag++;
            p=i;
        }
    if(flag==1) {
        int sum=0;
        for(i=1; i<=n; i++)
            if(num[i]==p)
                sum++;
        printf("%d\n",sum);
    }
    else
        printf("0\n");
    return 0;
}
