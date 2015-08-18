#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <iomanip>
#include <string.h>
#include <deque>
#include <queue>
#include <climits>
#include <stack>
using namespace std;
long long num[100001];
long long  sum(long long n)
{
    long long s = (1 + n) * n / 2;
    return s;
}
int main()
{
    long long n, d1, d2,bgn , flag;
    long long ans;
    while (scanf("%I64d %I64d %I64d", &n, &d1, &d2) != EOF)
    {
        ans = n;
        for (int i = 0; i < n; i ++)
            scanf("%I64d", &num[i]);
        flag = 0;
        for (int i = 1; i < n; i ++)
        {
            if (flag == 0)
            {
                if (num[i] - num[i-1] == d1)
                {
                    flag = 1;
                    bgn = i-1;
                    if (i == n-1)
                        ans += sum(i - bgn);
                    continue;
                }
                if (num[i] - num[i-1] == d2)
                {
                    flag = 2;
                    bgn = i-1;
                    if (i == n-1)
                        ans += sum(i - bgn);
                    continue;
                }
            }
            else if(flag == 1)
            {
                if (num[i] - num[i-1] == d1)
                {
                    if (i == n-1)
                        ans += sum(i - bgn);
                    continue;
                }
                if (num[i] - num[i-1] == d2)
                {
                    if (i == n-1)
                        ans += sum(i - bgn);
                    flag = 2;
                    continue;
                }
                flag = 0;
                ans += sum(i - 1 - bgn);
            }
            else
            {
                if (num[i] - num[i-1] == d1)
                {
                    ans += sum(i- 1 -bgn);
                    bgn = i-1;
                    flag = 1;
                    if (i == n-1)
                        ans += sum(i - bgn);
                    continue;
                }
                if (num[i] - num[i-1] == d2)
                {
                    if (i == n-1)
                        ans += sum(i - bgn);
                    continue;
                }
                flag = 0;
                ans += sum(i - 1 - bgn);
            }
        }
        printf("%I64d\n", ans);
    }
    return 0;
}
