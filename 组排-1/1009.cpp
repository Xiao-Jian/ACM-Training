#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string.h>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <climits>
#include <cstring>

using namespace std;

int father[1010], v[1010], w[1010], dp[1010],vis[1010];
int n,m,k;
vector<int> vec[1010];
int getFather(int a)
{
    if (a == father[a])
        return a;
    father[a] = getFather(father[a]);
    return father[a];
}

void init()
{
    for (int i = 1; i <= n; i ++ )
    {
        father[i] = i;
        vec[i].clear();
    }
}

int max(int a,int b)
{
    return a > b ? a :b;
}
int main()
{
    int a, b;
    while (scanf("%d%d%d", &n, &m, &k)!= EOF)
    {
        init();
        memset(dp,0,sizeof(dp));
        memset(vis, 0 , sizeof(vis));
        for (int i = 1; i <= n; i ++)
            scanf("%d%d",&v[i], &w[i]);
        for (int i = 1; i <= k; i ++)
        {
            scanf("%d%d", &a, &b);
            int x = getFather(a);
            int y = getFather(b);
            if (x != y)
                father[x] = y;
        }
        for (int i = 1; i <= n; i ++)
        {
           int tmp = getFather(i);
           vec[tmp].push_back(i);
        }
        for (int i = 1; i <= n; i ++)
        {
            if (!vec[i].size())
                continue;
            for (int j = m; j >= 0; j --)
            {
                for (int k = 0; k < vec[i].size(); k ++)
                    if (j >= w[vec[i][k]])
                        dp[j] = max(dp[j], dp[j-w[vec[i][k]]] + v[vec[i][k]]);
            }
        }
        printf("%d\n", dp[m]);
    }
    return 0;
}
