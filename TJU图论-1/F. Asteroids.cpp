//二分图的最大覆盖 匈牙利算法
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAX 502
using namespace std;

int flag[MAX];
int link[MAX];
int mat[MAX][MAX];
int n;

bool dfs(int x) {
    for(int i=1;i<=n;i++) {
        if(!flag[i]&&mat[x][i]) {
            flag[i]=1;
            if(link[i]==-1||dfs(link[i])) {
                link[i]=x;
                return true;
            }
        }
    }
    return false;
}

int getNum() {
    int num=0;
    memset(link,-1,sizeof(link));
    for(int i=1;i<=n;i++) {
        memset(flag,0,sizeof(flag));
        if(dfs(i)) num++;
    }
    return num;
}

int main()
{
    int k,x,y;
    scanf("%d%d",&n,&k);
    memset(mat,0,sizeof(mat));
    for(int i=0;i<k;i++) {
        scanf("%d%d",&x,&y);
        mat[x][y]=1;
    }
    printf("%d\n",getNum());
    return 0;
}
