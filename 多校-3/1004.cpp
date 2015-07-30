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
char sq[51][51];
int n, len;
int main()
{
    int T, ans;
    bool flag;
    scanf("%d", &T);
    getchar();
    char c;
    while (T --)
    {
        scanf("%d",&n);
        getchar();
        ans = 0;
        for (int i = 0; i < n ; i ++)
            cin >> sq[i];
        len = strlen(sq[0]);
        int i = 0, temp;
        for (int j = len - 1; j >= 0; j --)
        {
            flag = false;
            i = 0;
            temp = j;
            while (temp < len && i < n)
            {
                if (sq[i][temp] == 'R')
                {
                    i ++; temp ++;
                    flag = true;
                }
                else if (sq[i][temp] == 'G')
                {
                    sq[i][temp] = 'B';
                    i ++; temp ++;
                    flag = true;
                }
                else
                {
                    if (flag)
                        ans ++;
                    flag = false;
                    i ++; temp ++;
                }
            }
            if (flag)
                ans ++;
        }
        for (i = 1; i < n; i ++)
        {
            temp = 0;
            int ti = i;
            flag = false;
            while (ti < n && temp < len)
            {
                if (sq[ti][temp] == 'R')
                {
                    ti ++; temp ++;
                    flag = true;
                }
                else if (sq[ti][temp] == 'G')
                {
                    sq[ti][temp] = 'B';
                    ti ++; temp ++;
                    flag = true;
                }
                else
                {
                    if (flag)
                        ans ++;
                    flag = false;
                    ti ++; temp ++;
                }
            }
            if (flag)
                ans ++;
        }

        i = 0;
        for (int j = 0; j < len; j ++)
        {
            flag = false;
            i = 0;
            temp = j;
            while (temp >= 0 && i < n)
            {
                if (sq[i][temp] == 'B')
                {
                    i ++; temp --;
                    flag = true;
                }
                else
                {
                    if (flag)
                        ans ++;
                    flag = false;
                    i ++; temp --;
                }
            }
            if (flag)
                ans ++;
        }

        for (i = 1; i < n; i ++)
        {
            temp = len - 1;
            int ti = i;
            flag = false;
            while (ti < n && temp >= 0)
            {
                if (sq[ti][temp] == 'B')
                {
                    ti ++; temp --;
                    flag = true;
                }
                else
                {
                    if (flag)
                        ans ++;
                    flag = false;
                    ti ++; temp --;
                }
            }
            if (flag)
                ans ++;
        }

        printf("%d\n", ans);
    }
    return 0;
}
