/*
OJ: HDOJ
ID: forever
TASK: 1308.Is It A Tree?
LANG: C++
NOTE: ²¢²é¼¯
*/
#include <cstdio>

const int MAX=10005;
int father[MAX],sign[MAX],flag;

int Find(int x) {
    if(father[x]==x)
        return x;
    else
        return Find(father[x]);
}

void Union(int x,int y) {
    x=Find(x);
    y=Find(y);
    if(x!=y)
        father[x]=y;
    else
        flag=0;
}

int main()
{
    int a,b,k=1;
    while(scanf("%d %d",&a,&b)) {
        if(a==-1&&b==-1) break;
        if(a==0&&b==0) {
            printf("Case %d is a tree.\n",k++);
            continue;
        }

        flag=1;
        int m=0;
        for(int i=0;i<MAX;i++) {
            father[i]=i;
            sign[i]=0;
        }
        Union(a,b);
        sign[a]=sign[b]=1;

        while(scanf("%d %d",&a,&b)) {
            if(a==0&&b==0) break;
            if(a>m)
                m=a;
            if(b>m)
                m=b;
            Union(a,b);
            sign[a]=sign[b]=1;
        }
        int sum=0;
        for(int i=1;i<MAX;i++) {
            if(sign[i]&&father[i]==i)
                sum++;
            if(sum>1) {
                flag=0;
                break;
            }
        }
        if(flag)
            printf("Case %d is a tree.\n",k++);
        else
            printf("Case %d is not a tree.\n",k++);
    }
    return 0;
}
