#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string.h>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
using namespace std;

long long  pers[100010];
long long  n,m;
long long sum(long long k)
{
    long long  ans = k*(k+1)/2;
    return ans;
}
void solve ()
{
    long long  l, r, pos,minm, maxm;
    long long ans = 0;
    minm = maxm = pers[1];
    l = 1;
    r = 1;
    pos = r;
    while (l <= r && l <= n && r <= n)
    {
        while (maxm - minm < m && r <= n)
        {
            r ++;
            maxm = max(pers[r] , maxm);
            minm = min(pers[r], minm);
        }
        ans += (sum(r - l) - sum(pos - l));
        pos = r;
        if (pers[l] == minm)
        {
            minm = pers[l+1];
            for (int i = l+2; i <= r; i ++)
                minm = min(pers[i],minm);
        }
        if (pers[l] == maxm)
        {
            maxm = pers[l+1];
            for (int i = l+2; i <= r; i ++)
                maxm = max(pers[i],maxm);
        }
        l ++;
    }
    printf("%I64d\n",ans);
}

int main()
{
    int total;
    scanf("%d",&total);
    while (total --)
    {
        scanf("%I64d%I64d",&n,&m);
        for (int i = 1; i <= n; i ++)
            scanf("%I64d",&pers[i]);
        solve();
    }
    return 0;
}
