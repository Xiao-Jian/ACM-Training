//DFS
#include <cstdio>
#include <algorithm>
#include <set>
#include <cmath>
#include <cstring>
using namespace std;

set<int> ans;
int visited[10];
char str[10];
int len;

bool is_prime(int x) {
    if(x==0||x==1) return false;
    if(x==2) return true;
    if(x%2==0) return false;
    for(int i=3;i<=sqrt(x);i+=2)
        if(x%i==0) return false;
    return true;
}

void dfs(int x) {
    if(is_prime(x)) ans.insert(x);
    for(int i=0;i<len;i++) {
        if(!visited[i]) {
            visited[i]=1;
            dfs(x*10+str[i]-'0');
            visited[i]=0;
        }
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    getchar();
    while(n--) {
        gets(str);
        len=strlen(str);
        memset(visited,0,sizeof(visited));
        ans.clear();
        dfs(0);
        printf("%d\n",ans.size());
    }
}
