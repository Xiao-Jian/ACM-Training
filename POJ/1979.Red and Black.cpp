/*
OJ: POJ
ID: 3013216109
TASK: 1979.Red and Black
LANG: C++
NOTE: DFS
*/
#include <cstdio>
#include <algorithm>
#define MAX 21

int w,h,ans;
int fx[4]={-1,1,0,0};
int fy[4]={0,0,-1,1};
char str[MAX][MAX];

void dfs(int a,int b) {
    str[a][b]='#';
    for(int i=0;i<4;i++) {
        a+=fx[i];
        b+=fy[i];
        if(str[a][b]=='.'&&a>=0&&b>=0&&a<h&&b<w) {
            ans++;
            dfs(a,b);
        }
        a-=fx[i];
        b-=fy[i];
    }
}

int main()
{
    while(scanf("%d%d",&w,&h)) {
        if(w==0&&h==0) break;
        for(int i=0;i<h;i++)
            scanf("%s",str[i]);

        for(int i=0;i<h;i++) {
            for(int j=0;j<w;j++) {
                if(str[i][j]=='@') {
                    ans=1;
                    dfs(i,j);
                    printf("%d\n",ans);
                }
            }
        }
    }
}
