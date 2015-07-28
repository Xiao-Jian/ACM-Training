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
const int maxm = 100100;
const int pri = 1000000007;
int num[maxm];
bool sushu[100100];
void getsu()
{
    memset(sushu,true,sizeof(sushu));
    sushu[0] = sushu[1] = false;
    for (int i = 2; i <= 100; i ++)
    {
        if (sushu[i])
        {
            for (int j = i*i; j <= 100000; j += i)
                sushu[j] = false;
        }
    }
}
int main()
{
    cout << pri;
    int n;
    while (scanf("%d", &n)!= EOF)
    {
        getsu();
        long long ans = 0, pos = 0;
        bool flag;
        for (int i= 1; i <= n; i++)
            scanf("%d",&num[i]);
        sort(num+1,num + n+1);
        for (int i = 1; i <= n; i ++)
        {
            if (num[i] == 1)
            {
                ans += (n - i + 1) % pri;
                continue;
            }
            pos = 0;
            for (int j = i; j <= n; j ++)
            {
                if (i == j)
                {
                    ans ++;
                    ans %=  pri;
                    pos = 1;
                    continue;
                }
                if (sushu[num[j]])
                {
                    pos ++;
                    pos %= pri;
                    ans += pos;
                    ans %= pri;
                    continue;
                }
                flag = true;
                for (int k = i; k < j; k ++)
                {
                    if (num[j] % num[k] == 0)
                    {
                        flag = false;
                        break;
                    }
                }
                if (flag)
                {
                     pos ++;
                     pos %= pri;
                }

                ans += pos;
                ans %= pri;
            }
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
