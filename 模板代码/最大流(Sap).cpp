//HDOJ 1532
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define MAXN 444 //�ڽӱ�Ҫ��������2��

struct Edge{
    int v,cap,next;
}edge[MAXN];
int level[MAXN];//��ǲ�Σ������ţ�

//��϶�Ż�������gap[i]Ϊ�����i�ĵ�ĸ���
//���ر��iʱ�����gap[level[i]],����Ϊ0,���㷨������
int gap[MAXN];

int pre[MAXN];//ǰ��
int cur[MAXN];
int head[MAXN];
int NV,NE;

//NEΪ��������ʼ��Ϊ0��
void Insert(int u,int v,int cap,int cc=0){
    edge[NE].cap=cap;edge[NE].v=v;
    edge[NE].next=head[u];head[u]=NE++;

    edge[NE].cap=cc;edge[NE].v=u;
    edge[NE].next=head[v];head[v]=NE++;
}


//������Դ�㣬���
int SAP(int vs,int vt){
    memset(level,0,sizeof(level));
    memset(pre,-1,sizeof(pre));
    memset(gap,0,sizeof(gap));
    //cur[i]������ǵ�ǰ��
    for(int i=0;i<=NV;i++)cur[i]=head[i];
    int u=pre[vs]=vs;//Դ���pre�����䱾��
    int maxflow=0,aug=-1;
    gap[0]=NV;
    while(level[vs]<NV){
loop :
        for(int &i=cur[u];i!=-1;i=edge[i].next){
            int v=edge[i].v;//v��u�ĺ��
            //Ѱ�ҿ��л�
            if(edge[i].cap&&level[u]==level[v]+1){
                //aug��ʾ����·�ĿɸĽ���
                aug==-1?(aug=edge[i].cap):(aug=min(aug,edge[i].cap));
                pre[v]=u;
                u=v;
                //����ҵ�һ������·
                if(v==vt){
                    maxflow+=aug;//�����������
                    //·�����ݸ��²�������
                    for(u=pre[v];v!=vs;v=u,u=pre[u]){
                        //ǰ���������٣�������������
                        edge[cur[u]].cap-=aug;
                        edge[cur[u]^1].cap+=aug;
                    }
                    aug=-1;
                }
                goto loop;
            }
        }
        int minlevel=NV;
        //Ѱ���뵱ǰ�������ӵĵ�����С�ľ����ţ��ر�ţ�
        for(int i=head[u];i!=-1;i=edge[i].next){
            int v=edge[i].v;
            if(edge[i].cap&&minlevel>level[v]){
                cur[u]=i;//���满
                minlevel=level[v];
            }
        }
        if((--gap[level[u]])==0)break;//����gap�����������ֶϲ㣬��ֱ���˳���
        level[u]=minlevel+1;//�ر��
        gap[level[u]]++;//������Ϊlevel[u]�ĵ�ĸ���+1;
        u=pre[u];//ת��ǰ���ǰ���ڵ����Ѱ�ҿ��л�
    }
    return maxflow;
}

int main(){
    int m;//�ߵ�����
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
