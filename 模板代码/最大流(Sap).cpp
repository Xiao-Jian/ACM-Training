//HDOJ 1532
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define MAXN 444 //邻接表要开边数的2倍

struct Edge{
    int v,cap,next;
}edge[MAXN];
int level[MAXN];//标记层次（距离标号）

//间隙优化，定义gap[i]为标号是i的点的个数
//在重标记i时，检查gap[level[i]],若减为0,这算法结束。
int gap[MAXN];

int pre[MAXN];//前驱
int cur[MAXN];
int head[MAXN];
int NV,NE;

//NE为边数，初始化为0；
void Insert(int u,int v,int cap,int cc=0){
    edge[NE].cap=cap;edge[NE].v=v;
    edge[NE].next=head[u];head[u]=NE++;

    edge[NE].cap=cc;edge[NE].v=u;
    edge[NE].next=head[v];head[v]=NE++;
}


//参数，源点，汇点
int SAP(int vs,int vt){
    memset(level,0,sizeof(level));
    memset(pre,-1,sizeof(pre));
    memset(gap,0,sizeof(gap));
    //cur[i]保存的是当前弧
    for(int i=0;i<=NV;i++)cur[i]=head[i];
    int u=pre[vs]=vs;//源点的pre还是其本身
    int maxflow=0,aug=-1;
    gap[0]=NV;
    while(level[vs]<NV){
loop :
        for(int &i=cur[u];i!=-1;i=edge[i].next){
            int v=edge[i].v;//v是u的后继
            //寻找可行弧
            if(edge[i].cap&&level[u]==level[v]+1){
                //aug表示增广路的可改进量
                aug==-1?(aug=edge[i].cap):(aug=min(aug,edge[i].cap));
                pre[v]=u;
                u=v;
                //如果找到一条增广路
                if(v==vt){
                    maxflow+=aug;//更新最大流；
                    //路径回溯更新残留网络
                    for(u=pre[v];v!=vs;v=u,u=pre[u]){
                        //前向弧容量减少，反向弧容量增加
                        edge[cur[u]].cap-=aug;
                        edge[cur[u]^1].cap+=aug;
                    }
                    aug=-1;
                }
                goto loop;
            }
        }
        int minlevel=NV;
        //寻找与当前点相连接的点中最小的距离标号（重标号）
        for(int i=head[u];i!=-1;i=edge[i].next){
            int v=edge[i].v;
            if(edge[i].cap&&minlevel>level[v]){
                cur[u]=i;//保存弧
                minlevel=level[v];
            }
        }
        if((--gap[level[u]])==0)break;//更新gap数组后如果出现断层，则直接退出。
        level[u]=minlevel+1;//重标号
        gap[level[u]]++;//距离标号为level[u]的点的个数+1;
        u=pre[u];//转当前点的前驱节点继续寻找可行弧
    }
    return maxflow;
}

int main(){
    int m;//边的条数
    while(~scanf("%d%d",&m,&NV)){
        memset(head,-1,sizeof(head));
        NE=0;
        for(int i=1;i<=m;i++){
            int u,v,cap;
            scanf("%d%d%d",&u,&v,&cap);
            Insert(u,v,cap);
        }
        printf("%d\n",SAP(1,NV));
    }
    return 0;
}
