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
#include <iomanip>

using namespace std;

int fa[110], cp [110];

int k;
bool cmp(int a)
{
    return a == k;
}
int main()
{
    int n,a,b,ans, tm;
    while (scanf("%d%d", &n,&k)!=EOF)
    {
        ans = 0;
        tm = 0;
        memset(cp, 0, sizeof(cp));
        for (int i = 0;  i<= n; i ++)
            fa[i] = i;
        for (int i = 1;  i <= n - 1; i ++)
        {
            scanf("%d%d", &a, &b);
            fa[b] = a;
            cp[a] += cp[b] + 1;
            tm = a;
            while (fa[tm] != tm)
            {
                tm = fa[tm];
                cp[tm] += cp[b] + 1;
            }
        }
        ans = count_if(cp + 1, cp + n + 1, cmp);
        printf("%d\n", ans);
    }

    return 0;
}
